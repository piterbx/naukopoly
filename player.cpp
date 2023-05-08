#include <random>
#include "player.h"
#include "game.h"

Player::Player()
{
    //setting default values for new game
    position = 0; //idx of start field
    accountBalance = 400;
    ownedProperties.setHeadAndTailToNull();
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

void Player::setNrOfOwnedProperties()
{
    nrOfOwnedProperties = ownedProperties.getSize();
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
    Game::setBeforeMove(false);
    Game::updateButtons();
    Game::switchPlayer();
}

void Player::sellProperty(QLabel* label)
{
    Field &place = Game::getFields()[this->position]; //we want to work on original not on copy
    QString str;
    if(this->id==place.getOwner()){
        /*for(int i=0;i<this->nrOfOwnedProperties;i++){
            if(ownedProperties[i]==this->position){
                ownedProperties[i] = 0; //todo deleting item from player inventory
            }
        }*/

        place.setOwner(-1);
        this->accountBalance += place.getPropertyPrice();

        str = QString::fromStdString("Sprzedano posesje. Dodano "+std::to_string(place.getPropertyPrice())+" do konta gracza "+std::to_string(this->id+1));
        label->setText(str);
        Game::getBtn1()->setDisabled(true);
    } else {
        str = QString::fromStdString("Nie można sprzedać");
        label->setText(str);
    }
}

void Player::buyProperty(QLabel *label)
{
    Field &place = Game::getFields()[this->position];
    QString str;
    if(place.getOwner()==-1 && place.getCanBePurchased()){
        if(this->accountBalance>=place.getPropertyPrice()){
            place.setOwner(this->id);
            //todo table of owned properties && disabling buttons before move
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
    Field &place = Game::getFields()[this->position];
    QString str;
    if(place.getOwner()==this->getId()){
        if(this->accountBalance>=20){
            if(place.canIUpgradeHouses()){
                str = QString::fromStdString("Gracz "+std::to_string(this->id+1)+" kupił dom w "+place.getFieldName());
            }
        }
    } else {
        str = "Nie jesteś właścicielem tej działki";
    }
    label->setText(str);
}

int Player::getNrOfOwnedProperties() const
{
    return nrOfOwnedProperties;
}
