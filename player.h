#include "qlabel.h"
#include <iostream>


#ifndef PLAYER_H
#define PLAYER_H




class Player
{
    int id;
    int position; //on the board
    bool beforeMove; //required for buying a house
    double accountBalance;
    int nrOfOwnedProperties; //lenght of ownedProperties table
    int *ownedProperties; //consists index of property in fields array
    int prisonTime;
public:
    Player();
    ~Player();
    void setPosition(int poz);
    int getPosition();
    void setBeforeMove(bool bm);
    void setAccountBalance(double ab);
    double getAccountBalance();
    void setId(int id);
    int getId();
    void setPrisonTime(int time);
    int getPrisonTime();
    int *getOwnedProperties();

    void makeMove(QLabel* label); //todo throw a dice
    void sellProperty(); //todo
    void buyProperty(); //todo
    void buyHouse(); //todo
};

#endif // PLAYER_H
