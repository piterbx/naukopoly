#include <unistd.h>
#include <iostream>

#include <QPropertyAnimation>

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

void Player::makeMove(QLabel* label, QLabel *pawn)
{
    //this = current player
    QString info;

    if(this->prisonTime==0){

        srand(time(NULL));
        int move = (int)rand()%(6-1+1)+1;
        this->setPosition(this->getPosition()+move); // from 1 to 6
        info = QString::fromStdString("Gracz "+std::to_string(this->id+1)+" rusza się o "+std::to_string(move)+" na pole "+std::to_string(this->getPosition()));
        label->setText(info);

        updatePawnPosition(pawn, move);
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

void Player::updatePawnPosition(QLabel *pawn, int move)
{
    QRect geomet = pawn->geometry();
    QPropertyAnimation *anim = new QPropertyAnimation(pawn, "geometry");

    int xx, yy;
    anim->setDuration(200*move);
    anim->setStartValue(geomet); // before visual move
    switch(this->position){
    case 0: xx=890; yy=600; break;
    case 1: xx=850; yy=600; break;
    case 2: xx=790; yy=600; break;
    case 3: xx=730; yy=600; break;
    case 4: xx=680; yy=600; break;
    case 5: xx=620; yy=600; break;
    case 6: xx=560; yy=600; break;
    case 7: xx=510; yy=600; break;
    case 8: xx=450; yy=600; break;
    case 9: xx=390; yy=600; break;
    case 10: xx=300; yy=600; break;
    case 11: xx=300; yy=510; break;
    case 12: xx=300; yy=460; break;
    case 13: xx=300; yy=410; break;
    case 14: xx=300; yy=360; break;
    case 15: xx=300; yy=310; break;
    case 16: xx=300; yy=250; break;
    case 17: xx=300; yy=200; break;
    case 18: xx=300; yy=150; break;
    case 19: xx=300; yy=100; break;
    case 20: xx=300; yy=30; break;
    case 21: xx=390; yy=20; break;
    case 22: xx=450; yy=20; break;
    case 23: xx=510; yy=20; break;
    case 24: xx=570; yy=20; break;
    case 25: xx=620; yy=20; break;
    case 26: xx=680; yy=20; break;
    case 27: xx=730; yy=20; break;
    case 28: xx=790; yy=20; break;
    case 29: xx=850; yy=20; break;
    case 30: xx=920; yy=20; break;
    case 31: xx=940; yy=90; break;
    case 32: xx=940; yy=140; break;
    case 33: xx=940; yy=200; break;
    case 34: xx=940; yy=250; break;
    case 35: xx=940; yy=300; break;
    case 36: xx=940; yy=350; break;
    case 37: xx=940; yy=400; break;
    case 38: xx=940; yy=460; break;
    case 39: xx=940; yy=510; break;
    }
    switch(Game::getInstance()->currentPlayer){
        // dla 0 normalne
    case 1: xx+=2; break;
    case 2: yy-=2; break;
    case 3: xx-=2; break;
    }
    anim->setEndValue(QRect(xx, yy, geomet.width(), geomet.height()));
    anim->start();

    pawn->setGeometry(xx, yy, geomet.width(), geomet.height());
}

int Player::getNrOfOwnedProperties() const
{
    return ownedProperties.size();
}

std::vector<listElement> Player::getOwnedProperties() const
{
    return ownedProperties;
}
