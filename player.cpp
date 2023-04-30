#include <random>
#include "player.h"
#include "game.h"

Player::Player(int id):id(id)
{
    //setting default values for new game
    position = 0; //idx of start field
    beforeMove = true;
    accountBalance = 400;
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

void Player::setBeforeMove(bool bm)
{
    beforeMove = bm;
}

double Player::getAccountBalance()
{
    return accountBalance;
}

int Player::getId()
{
    return id;
}

int Player::getPrisonTime()
{
    return prisonTime;
}

void Player::makeMove(QLabel* label)
{
    //this = current player
    QString info;
    if(this->getPrisonTime()==0){
        this->setBeforeMove(false);

        srand(time(NULL));
        int move = (int)rand()%(6-1+1)+1;
        this->setPosition(this->getPosition()+move); // from 1 to 6
        info = QString::fromStdString("Gracz "+std::to_string(this->getId()+1)+" rusza się o "+std::to_string(move)+" na pole "+std::to_string(this->getPosition()));
        label->setText(info);
    } else {
        label->setText("Gracz jest w wiezieniu");
    }
    Game::switchPlayer();
}
