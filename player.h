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
    Player(int id);
    void setPosition(int poz);
    int getPosition();
    double getAccountBalance();
    //getOwnedProperties(); //todo and ? which type

    void sellProperty(); //todo
    void buyProperty(); //todo
    void buyHouse(); //todo
};

#endif // PLAYER_H
