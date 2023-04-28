
#ifndef GAME_H
#define GAME_H

#include "player.h"


class Game
{
    int time; //in seconds
    int timeLeft;
    int nrOfPlayers;
    Player* playersTab;


public:
    Game();
    ~Game();
    Player* getPlayersTab();
    int getNrOfPlayers();
    void checkForWin(); //todo it will be executed after single move
    void countTime(); //this function updates timeLeft of the game

    static int currentPlayer; // is an index of player in playersTab
    static void setCurrentPlayer(int newCurrentPlayer);
    static int getCurrentPlayer();

    void switchPlayer();
};

#endif // GAME_H
