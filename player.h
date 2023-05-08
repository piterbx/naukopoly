#include "singlelist.h"
#include "qlabel.h"
#include <iostream>


#ifndef PLAYER_H
#define PLAYER_H




class Player
{
    int id;
    int position; //on the board
    double accountBalance;
    int prisonTime;
    int nrOfOwnedProperties; //length of ownedProperties
    SingleList ownedProperties; //list! of property indexes
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

    void setNrOfOwnedProperties();
    int getNrOfOwnedProperties() const;

    void setOwnedProperties(); // ?????? unused??
    SingleList getOwnedProperties() const;

    void makeMove(QLabel* label); //throw a dice
    void sellProperty(QLabel *label);
    void buyProperty(QLabel *label);
    void buyHouse(QLabel *label);
};

#endif // PLAYER_H
