
#include "player.h"

Player::Player(int id):id(id)
{
    //setting default values for new game
    position = 0; //idx of start field
    beforeMove = true;
    accountBalance = 0;
    //todo ownedProperties = empty array;
    prisonTime = 0;
}

void Player::setPosition(int poz)
{
    position = poz%40;
}

int Player::getPosition()
{
    return position;
}

double Player::getAccountBalance()
{
    return accountBalance;
}
