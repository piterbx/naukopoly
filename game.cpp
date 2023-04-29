
#include "game.h"

int Game::currentPlayer = 0; // 0 is an index of player 1

Game::Game()
{
    currentPlayer = 0; // set to player 1
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

int Game::getCurrentPlayer()
{
    return currentPlayer;
}

void Game::switchPlayer()
{
    int idxOfCurrentPlr = getCurrentPlayer();
    int i = 1; // set to 1 because in next line it checks for next player (current+1)
    while(playersTab[(idxOfCurrentPlr+i)%nrOfPlayers].getPrisonTime()!=0){
        i++;
        //todo send message to the screen (player idx in prison)
    } //check if next player is in prison (if is -> next player)

    setCurrentPlayer(i);
}

void Game::setCurrentPlayer(int newCurrentPlayer)
{
    currentPlayer = newCurrentPlayer;
}

