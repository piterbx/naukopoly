#include "qlabel.h"
#include "mainwindow.h"
#include <iostream>


#ifndef PLAYER_H
#define PLAYER_H

struct listElement {
    int fieldIndex;
    std::string propertyName; //to display on screen name; = fields[propertyFieldIndex].fieldName
    int boughtHouses; //=fields[propertyFieldIndex].houses; to display on screen how many houses
    int totalValue;
};

class Player
{
    int id;
    int position; //on the board
    double accountBalance;
    int prisonTime;
    int nrOfOwnedProperties; //length of ownedProperties
    std::vector<listElement> ownedProperties; //list! of property indexes
public:
    Player();
    ~Player();
    void setPosition(int poz);
    int getPosition();
    void setAccountBalance(double ab);
    double getAccountBalance();
    void setId(int id);
    int getId();
    void setPrisonTime(int time);
    int getPrisonTime();

    void setNrOfOwnedProperties(int n);
    int getNrOfOwnedProperties() const;

    std::vector<listElement> getOwnedProperties() const;

    void makeMove(QLabel* label); //throw a dice
    void sellProperty(QLabel *label);
    void buyProperty(QLabel *label);
    void buyHouse(QLabel *label);
};

#endif // PLAYER_H
