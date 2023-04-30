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
    std::string *ownedProperties; //? which type of this array (I'm thinking about FieldProperty array type
    int prisonTime;
public:
    Player() {}; //default constructor for creating table of Players in Game class
    Player(int id);
    void setPosition(int poz);
    int getPosition();
    void setBeforeMove(bool bm);
    double getAccountBalance();
    int getId();
    int getPrisonTime();
    //getOwnedProperties(); //todo and ? which type

    void makeMove(QLabel* label); //todo throw a dice
    void sellProperty(); //todo
    void buyProperty(); //todo
    void buyHouse(); //todo
};

#endif // PLAYER_H
