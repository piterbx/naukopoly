
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "field.h"

class Game
{
    int time; //in seconds
    int timeLeft;
    static const int nrOfPlayers;
    static Player playersTab[4];
    static Field fields[40];

public:
    Game();
    ~Game();
    static Player* getPlayersTab();
    static int getNrOfPlayers();
    static Field* getFields();

    void checkForWin(); //todo it will be executed after single move
    void countTime(); //this function updates timeLeft of the game

    static int currentPlayer; // is an index of player in playersTab
    static void setCurrentPlayer(int newCurrentPlayer);
    static int getCurrentPlayer();

    static void switchPlayer();


};

#endif // GAME_H
