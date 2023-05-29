#include "qlabel.h"
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
    bool ifBankrupt;
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
    void setIfBankrupt(bool b);
    bool getIfBankrupt();

    void setNrOfOwnedProperties(int n);
    int getNrOfOwnedProperties() const;

    std::vector<listElement> &getOwnedProperties();

    void makeMove(QLabel* label, QLabel* pawn, QLabel *labelField); //throw a dice
    void sellProperty(QLabel *label);
    void buyProperty(QLabel *label);
    void buyHouse(QLabel *label);

    std::string handleBankrupt(int cost); //returns info what must be sold
private:
    void updatePawnPosition(QLabel *pawn, int move);
};

#endif // PLAYER_H
