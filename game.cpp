
#include "game.h"

Game::Game()
{
    time = 900; //15min = 900s
    timeLeft = time;
    nrOfPlayers = 4;
    playersTab = new Player[nrOfPlayers];
    for(int i=0;i<nrOfPlayers;i++){
        playersTab[i] = Player(i);
    }
}

Game::~Game()
{
    delete [] playersTab;
}

Player *Game::getPlayersTab()
{
    return playersTab;
}

int Game::getNrOfPlayers()
{
    return nrOfPlayers;
}

