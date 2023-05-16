#include <random>
#include "player.h"
#include "game.h"

Player::Player()
{
    //setting default values for new game
    position = 0; //idx of start field
    accountBalance = 400;
    ownedProperties.clear();
    prisonTime = 0;
}

Player::~Player()
{

}

void Player::setPosition(int poz)
{
    position = poz%40;
}

int Player::getPosition()
{
    return position;
}

void Player::setAccountBalance(double ab)
{
    accountBalance = ab;
}

double Player::getAccountBalance()
{
    return accountBalance;
}

void Player::setId(int id)
{
    this->id = id;
}

int Player::getId()
{
    return id;
}

void Player::setPrisonTime(int time)
{
    prisonTime = time;
}

int Player::getPrisonTime()
{
    return prisonTime;
}

void Player::setNrOfOwnedProperties(int n)
{
    if(n==0) ownedProperties.clear();
    else ownedProperties.resize(n);
}

void Player::makeMove(QLabel* label)
{
    //this = current player
    QString info;
    if(this->prisonTime==0){

        srand(time(NULL));
        int move = (int)rand()%(6-1+1)+1;
        this->setPosition(this->getPosition()+move); // from 1 to 6
        info = QString::fromStdString("Gracz "+std::to_string(this->id+1)+" rusza się o "+std::to_string(move)+" na pole "+std::to_string(this->getPosition()));
        label->setText(info);
    } else {
        label->setText("Gracz jest w wiezieniu");
    }
    Game::getInstance()->setBeforeMove(false);
//    Game::updateButtons();
    Game::getInstance()->switchPlayer();
}

void Player::sellProperty(QLabel* label)
{
    Field &place = Game::getInstance()->getFields()[this->position]; //we want to work on original not on copy
    QString str;
    if(this->id==place.getOwner()){

        //erase element from vector tables
        for(auto i=this->ownedProperties.begin();i<this->ownedProperties.end();i++){
            if(i->fieldIndex==this->position) this->ownedProperties.erase(i);
        }

        place.setOwner(-1);
        place.setHouses(0);
        this->accountBalance += place.getPropertyPrice();

        str = QString::fromStdString("Sprzedano posesje. Dodano "+std::to_string(place.getPropertyPrice())+" do konta gracza "+std::to_string(this->id+1));
        label->setText(str);
//        Game::getBtn1()->setDisabled(true); ???????
    } else {
        str = QString::fromStdString("Nie można sprzedać");
        label->setText(str);
    }
}

void Player::buyProperty(QLabel *label)
{
    Field &place = Game::getInstance()->getFields()[this->position];
    QString str;
    if(place.getOwner()==-1 && place.getCanBePurchased()){
        if(this->accountBalance>=place.getPropertyPrice()){
            place.setOwner(this->id);

            //adding element to vector table
            listElement tmp;
            tmp.fieldIndex = this->position;
            tmp.boughtHouses = place.getHouses();
            tmp.propertyName = place.getFieldName();
            tmp.totalValue = place.getTotalValue();

            this->ownedProperties.push_back(tmp);

            str = QString::fromStdString("Gracz "+std::to_string(this->id+1)+" kupił ("+std::to_string(this->position) +") "+ place.getFieldName());
            this->accountBalance -= place.getPropertyPrice();
        } else {
            str = "Brak wystarczającej ilości pieniędzy";
        }
    } else {
        str = "Nie można kupić pola";
    }
    label->setText(str);
}

void Player::buyHouse(QLabel *label)
{
    Field &place = Game::getInstance()->getFields()[this->position];
    QString str;
    if(place.getOwner()==this->getId()){
        if(this->accountBalance>=place.getHousePrice()){
            if(place.canIUpgradeHouses()){
                str = QString::fromStdString("Gracz "+std::to_string(this->id+1)+" kupił dom w "+place.getFieldName());
                this->accountBalance -= place.getHousePrice();

                //adding info (updating) to vector array
                for(listElement &el : ownedProperties){
                    if(el.fieldIndex==this->position) {
                        el.boughtHouses++;
                        el.totalValue = place.getTotalValue();
                        break;
                    }
                }
            }
        }
    } else {
        str = "Nie jesteś właścicielem tej działki";
    }
    label->setText(str);
}

int Player::getNrOfOwnedProperties() const
{
    return ownedProperties.size();
}

std::vector<listElement> Player::getOwnedProperties() const
{
    return ownedProperties;
}
