#include "field.h"
#include <iostream>
#include "game.h"

#include <QFile>

int Field::getTotalValue() const
{
    return totalValue;
}

int Field::getHousePrice()
{
    return housePrice;
}

void Field::makeAction(QLabel *labelField)
{
    srand(time(NULL));
    Player &player = Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()];

    QString str;
    string currPlIdStr = to_string(player.getId()+1);
    string ownPlIdStr = to_string(this->owner+1);

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

            string tmpStr = to_string(this->totalValue);
            str = QString::fromStdString("Gracz "+currPlIdStr+" stanął na polu gracza "+ownPlIdStr+". Czynsz wynosi "+tmpStr+" monet.\nGracz "+currPlIdStr+": -"+tmpStr+" monet\nGracz "+ownPlIdStr+": +"+tmpStr+" monet");
        }
        break;
    }
        // plus fields
    case 2:
    case 28:
    case 33:{
        int price = rand()%101+30;
        //Wygrałeś na loterii: price

        player.setAccountBalance(player.getAccountBalance() + price);
        str = QString::fromStdString("Gracz "+currPlIdStr+": +"+to_string(price)+" monet");
        break;
    }
    case 7:
    case 17:
    case 38:{
        //negative fields

        int price = rand()%101+30;

        player.setAccountBalance(player.getAccountBalance() + price);
        str = QString::fromStdString("Gracz "+currPlIdStr+": -"+to_string(price)+" monet");
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
        string tmpStd = "Treść karty: "+tmp.info+"\nGracz "+currPlIdStr+": ";
        if(idx>9) tmpStd += "-";
        else tmpStd += "+";
        tmpStd+=to_string(tmp.money)+" monet";
        str = QString::fromStdString(tmpStd);
        break;
    }
        //tax
    case 5:
    case 15:
    case 25:
    case 35:{
        int tax =(Game::getInstance()->countPlayerFortune(player.getId()))*0.1;
        player.setAccountBalance(player.getAccountBalance()-tax);
        str = QString::fromStdString("Gracz "+currPlIdStr+" stanął na polu Podatek \nGracz "+currPlIdStr+": -"+to_string(tax)+" monet");
        break;

    }
    case 30:
        //go to prison
        player.setPrisonTime(4);
        player.setPosition(10);
        str = QString::fromStdString("Gracz "+currPlIdStr+" idzie do więzienia na 3 rundy");
    }

    labelField->setText(str);
}

void Field::loadCards()
{
    QFile file(":/files/files/cards.csv");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QByteArray line = file.readLine(); //for header of file
        for(int i=0;i<20;i++){//eof
            line = file.readLine();

            QList<QByteArray> tmpArray = line.split(';');

            int idx=0;
            Card tmp;
            tmp.info = tmpArray[idx].toStdString();
            idx++;
            tmp.money = tmpArray[idx].toInt();

            cards.push_back(tmp);
        }
        file.close();
    }
}

Field::Field()
{
    rent = 20;
    owner = -1; //bank
    houses = 0;
    housePrice = 10;
    totalValue = rent;

    //cards
    loadCards();
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




