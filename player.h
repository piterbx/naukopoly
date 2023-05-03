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
    int nrOfOwnedProperties; //lenght of ownedProperties table
    int *ownedProperties; //consists index of property in fields array
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
    void setNrOfOwnedProperties(int nr);
    int getNrOfOwnedProperties() const;

    void setOwnedProperties(int *properties);
    int *getOwnedProperties();

    void makeMove(QLabel* label); //throw a dice
    void sellProperty(QLabel *label);
    void buyProperty(QLabel *label);
    void buyHouse(QLabel *label);
};

#endif // PLAYER_H
