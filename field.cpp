#include "field.h"
#include <iostream>
#include "game.h"

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

    Player &player = Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()];

    switch(player.getPosition()){
    case 0: // start;
        break;
    case 1:
    case 3:
    case 6:
    case 8:
    case 9:
    case 11:
    case 13:
    case 14:
    case 16:
    case 18:
    case 19:
    case 21:
    case 23:
    case 24:
    case 26:
    case 27:
    case 29:
    case 31:
    case 32:
    case 34:
    case 37:
    case 39: {
        if(this->owner != player.getId() && this->owner !=-1){
            player.setAccountBalance(player.getAccountBalance() - this->totalValue);

            vector<Player> tab = Game::getInstance()->getPlayersTab();
            tab[this->owner].setAccountBalance(tab[this->owner].getAccountBalance()+this->totalValue);
        }
        break;
    }
        // plus fields
    case 2:
    case 28:
    case 33:{
        int price = rand()%10;//cause from 0-9 the is positive cards
        //Wygrałeś na loterii: price
        Card tmp = this->cards[price];

        player.setAccountBalance(player.getAccountBalance() + tmp.money);
        break;
    }
    case 7:
    case 17:
    case 38:{
        //negative fields

        int price = rand()%10+10; //from 10-19
        Card tmp = this->cards[price];

        player.setAccountBalance(player.getAccountBalance() - tmp.money); //not price but money
        break;
    }

        // cards
    case 4:
    case 12:
    case 22:
    case 36:{
        int idx = rand()%20; //all cards (20) from 0 to 19

        Card tmp = this->cards[idx];
        //display on screen info
        player.setAccountBalance(player.getAccountBalance() + tmp.money);
        break;
    }
        //tax
    case 5:
    case 15:
    case 25:
    case 35:{
        //podatek
        int tax =(int)player.getAccountBalance()*0.1;
        player.setAccountBalance(player.getAccountBalance()-tax);
        break;

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

    //cards
    Card c;
    c.info = "Wygrałeś na loterii!";
    c.money = 130;
    cards.push_back(c);
    c.info = "Przylepił Ci się banknot do buta";
    c.money = 20;
    cards.push_back(c);
    c.info = "Znalazłeś banknot";
    c.money = 10;
    cards.push_back(c);
    c.info = "Wygrałeś w konkursie";
    c.money = 50;
    cards.push_back(c);
    c.info = "Stary znajomy oddał ci pieniądze";
    c.money = 30;
    cards.push_back(c);
    c.info = "Kolega stawia Ci soczek";
    c.money = 15;
    cards.push_back(c);
    c.info = "Wygrałeś zakład";
    c.money = 40;
    cards.push_back(c);
    c.info = "Znalezisko z Juwenalii";
    c.money = 10;
    cards.push_back(c);
    c.info = "Dostałeś stypendium";
    c.money = 120;
    cards.push_back(c);
    c.info = "Banknot przyczepił się do szyby";
    c.money = 20;
    cards.push_back(c);
    //negative
    c.info = "Masz dziurą kieszeń!";
    c.money = 30;
    cards.push_back(c);
    c.info = "Oddałeś koledze pieniądze";
    c.money = 20;
    cards.push_back(c);
    c.info = "Wyszedłeś na Juwenalia";
    c.money = 50;
    cards.push_back(c);
    c.info = "";
    c.money = 50;
    cards.push_back(c);
    c.info = "";
    c.money = 30;
    cards.push_back(c);
    c.info = "";
    c.money = 15;
    cards.push_back(c);
    c.info = "";
    c.money = 40;
    cards.push_back(c);
    c.info = "";
    c.money = 10;
    cards.push_back(c);
    c.info = "Kupiłeś ECTSY";
    c.money = 100;
    cards.push_back(c);
    c.info = "";
    c.money = 20;
    cards.push_back(c);
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




