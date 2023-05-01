#include <random>
#include "player.h"
#include "game.h"

Player::Player()
{
    //setting default values for new game
    position = 0; //idx of start field
    beforeMove = true;
    accountBalance = 400;
    nrOfOwnedProperties = 0;
    ownedProperties = new int[22];
    prisonTime = 0;
}

Player::~Player()
{
    delete [] ownedProperties;
}

void Player::setPosition(int poz)
{
    position = poz%40;
}

int Player::getPosition()
{
    return position;
}

void Player::setBeforeMove(bool bm)
{
    beforeMove = bm;
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

void Player::setNrOfOwnedProperties(int nr)
{
    nrOfOwnedProperties = nr;
}

int *Player::getOwnedProperties()
{
    return ownedProperties;
}

void Player::makeMove(QLabel* label)
{
    //this = current player
    QString info;
    if(this->prisonTime==0){
        this->setBeforeMove(false);

        srand(time(NULL));
        int move = (int)rand()%(6-1+1)+1;
        this->setPosition(this->getPosition()+move); // from 1 to 6
        info = QString::fromStdString("Gracz "+std::to_string(this->id)+" rusza się o "+std::to_string(move)+" na pole "+std::to_string(this->getPosition()));
        label->setText(info);
    } else {
        label->setText("Gracz jest w wiezieniu");
    }
    Game::switchPlayer();
}

void Player::sellProperty(QLabel* label)
{
    Field place = Game::getFields()[this->position];
    QString str;
    if(this->id==place.getOwner()){
        for(int i=0;i<this->nrOfOwnedProperties;i++){
            if(ownedProperties[i]==this->position){
                ownedProperties[i] = 0; //todo deleting item from player inventory
            }
        }

        this->nrOfOwnedProperties--;

        this->accountBalance += place.getPropertyPrice();

        str = QString::fromStdString("Sprzedano posesje. Dodano "+std::to_string(place.getPropertyPrice())+" do konta gracza "+std::to_string(this->id));
        label->setText(str);
    } else {
        str = QString::fromStdString("Nie można sprzedać");
        label->setText(str);
    }
}

void Player::buyProperty(QLabel *label)
{
    Field place = Game::getFields()[this->position];
    QString str;
    if(place.getOwner()==-1){
        if(this->accountBalance>=place.getPropertyPrice()){
            place.setOwner(this->id);
            //todo table of owned properties
            str = QString::fromStdString("Gracz "+std::to_string(this->id)+" kupił ("+std::to_string(this->position) +") "+ place.getFieldName());
        } else {
            str = "Brak wystarczającej ilości pieniędzy";
        }
    } else {
        str = "Nie można kupić pola";
    }
    label->setText(str);
}

int Player::getNrOfOwnedProperties() const
{
    return nrOfOwnedProperties;
}

void Player::setOwnedProperties(int *properties)
{
    ownedProperties = properties;
}
