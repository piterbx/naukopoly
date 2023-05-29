#include <future>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <iostream>

#include <QFile>

#include "game.h"

Game * Game::ginstance = nullptr;

Game::Game()
{
    resetValues();
}

Game *Game::getInstance()
{
    if(ginstance == nullptr){
        ginstance = new Game();
    }
    return ginstance;
}

std::vector<Player> &Game::getPlayersTab()
{
    return playersTab;
}

int Game::getNrOfPlayers()
{
    return nrOfPlayers;
}

std::vector<Field> &Game::getFields()
{
    return fields;
}

int Game::countPlayerFortune(int id)
{
    Player tmp = playersTab[id];
    int fortune=tmp.getAccountBalance();
    for(int i=0;i<tmp.getNrOfOwnedProperties();i++){
        fortune+=tmp.getOwnedProperties()[i].totalValue;
        fortune+=fields[tmp.getOwnedProperties()[i].fieldIndex].getPropertyPrice();
    }
    return fortune;
}

int Game::getCurrentPlayer()
{
    return currentPlayer;
}

void Game::switchPlayer()
{
    beforeMove = true;
    do {
        currentPlayer = (currentPlayer+1)%nrOfPlayers;
        if(playersTab[currentPlayer].getPrisonTime()>0) playersTab[currentPlayer].setPrisonTime(playersTab[currentPlayer].getPrisonTime()-1);
    } while(playersTab[currentPlayer].getPrisonTime()>0 || playersTab[currentPlayer].getIfBankrupt());
}

bool Game::getBeforeMove()
{
    return beforeMove;
}

void Game::setBeforeMove(bool newBeforeMove)
{
    beforeMove = newBeforeMove;
}

void Game::resetValues()
{
    currentPlayer = 0; // 0 is an index of player 1
    nrOfPlayers = 4;

    beforeMove = true;
    currentPlayer = 0; // set to player 1

    playersTab.clear();
    fields.clear();

    for(int i=0;i<nrOfPlayers;i++){
        Player tmp;
        tmp.setId(i);
        tmp.setAccountBalance(400);
        tmp.setPosition(0);
        tmp.setPrisonTime(0);
        tmp.setNrOfOwnedProperties(0);
        tmp.setIfBankrupt(false);
        playersTab.push_back(tmp);
    }

    fields.resize(40);

    loadFromFile();
}

void Game::loadFromFile()
{
    QFile file(":/files/files/fields.csv");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QByteArray line = file.readLine();//for header of file
        for(int i=0;i<40;i++){
            line = file.readLine();

            QList<QByteArray> tmpArr = line.split(';');

            int idx=0;
            fields[i].setFieldName(tmpArr[idx].toStdString());

            idx++;
            fields[i].setPropertyPrice(tmpArr[idx].toInt());

            idx++;
            if(tmpArr[idx].toInt()){
                fields[i].setCanBePurchased(true);
            } else {
                fields[i].setCanBePurchased(false);
            }
        }
        file.close();
    }

}


void Game::setCurrentPlayer(int newCurrentPlayer)
{
    currentPlayer = newCurrentPlayer;
}

