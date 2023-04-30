
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "field.h"

class Game
{
    int time; //in seconds
    int timeLeft;
    static int nrOfPlayers;
    static Player* playersTab;
    Field* fields;

public:
    Game();
    ~Game();
    static Player* getPlayersTab();
    int getNrOfPlayers();
    Field* getFields();

    void checkForWin(); //todo it will be executed after single move
    void countTime(); //this function updates timeLeft of the game

    static int currentPlayer; // is an index of player in playersTab
    static void setCurrentPlayer(int newCurrentPlayer);
    static int getCurrentPlayer();

    static void switchPlayer();


};

#endif // GAME_H
