#include "field.h"
#include <iostream>

int Field::getTotalValue() const
{
    return totalValue;
}

int Field::getHousePrice()
{
    return housePrice;
}

void Field::makeAction()
{
    struct Card{
        string info;
        int money;
    };

    int player = &currentPlayer;
    //pobierz tablice i currentplayer
    //int player &getPlayersTab; nie wiem jeszcze jak
    // grasz musi byc referencja player zmienna = getcos tam xd po typie player &
    //kto jest wlascicielem
    switch(player){
    case 0: // start;
    case 1: {
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 2:{
        player.setAccountBalance(player.getAccountBalance - Card.money);


    }
    case 3:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 4:
    case 5:{
        //podatek

    }
    case 6:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 7:
    case 8:
    case 9:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 10:
    case 11:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 12:
    case 13:
    case 14:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 15:{
        //podatek
    }
    case 16:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 17:
    case 18:
    case 19:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 20:
    case 21:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 22:
    case 23:
    case 24:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 25:{
        //podatek
    }
    case 26:
    case 27:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 28:
    case 29:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 30:
    case 31:
    case 32:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 33:
    case 34:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 35:{
        //podatek
    }
    case 36:
    case 37:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }
    case 38:
    case 39:{
        if(this->owner != currentPlayer && this->owner !=1){
            player.setAccountBalance(player.getAccountBalance - this->totalValue);
            Game::getInstance()->getPlayersTab();
            [this.owner].setAccountBalance(Game::getInstance().getPlayersTab()[this.owner].getAccountBalance()+this.totalValue);
        }
    }


    }
}

Field::Field()
{
    rent = 20;
    owner = -1; //bank or none
    houses = 0;
    housePrice = 10;
    totalValue = rent;
}

void Field::setFieldName(string inputName)
{
    fieldName = inputName;
}

void Field::setPropertyPrice(int inputPrice)
{
    price = inputPrice;
}

void Field::setOwner(int owner)
{
    this->owner = owner;
}

void Field::setCanBePurchased(bool canBePurchased)
{
    this->canBePurchased = canBePurchased;
}

void Field::setHouses(int inputHouses)
{
    houses = inputHouses;
    totalValue = rent * ((houses + 2) * 0.5);
}

void Field::setHousePrice(int housePrice)
{
    this->housePrice = housePrice;
}

bool Field::canIUpgradeHouses()
{
    if(houses < 3){
        houses++;
        totalValue = rent * ((houses + 2) * 0.5);
        return true;
    }
    else{
        return false;
    }
}

int Field::getPropertyPrice()
{
    return price;
}

int Field::getOwner()
{
    return owner;
}

bool Field::getCanBePurchased()
{
    return canBePurchased;
}

int Field::getHouses()
{
    return houses;
}

string Field::getFieldName()
{
    return fieldName;
}




