#include <future>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <iostream>

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
    currentPlayer = (currentPlayer+1)%nrOfPlayers;
    beforeMove = true;
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
        playersTab.push_back(tmp);
    }

    fields.resize(40);

    fields[0].setFieldName("Start");
    fields[0].setPropertyPrice(0);
    fields[0].setCanBePurchased(false);
    fields[0].setOwner(-2);//nonbuyable

    fields[1].setFieldName("Uniwersytet Rzeszowski");
    fields[1].setPropertyPrice(60);
    fields[1].setCanBePurchased(true);

    fields[2].setFieldName("Wygrana na Loterii");
    fields[2].setPropertyPrice(100);
    fields[2].setCanBePurchased(false);
    fields[2].setOwner(-2);

    fields[3].setFieldName("Politechnika Rzeszowska");
    fields[3].setPropertyPrice(100);
    fields[3].setCanBePurchased(true);

    fields[4].setFieldName("Karta specjalna");
    fields[4].setPropertyPrice(0);
    fields[4].setCanBePurchased(false);
    fields[4].setOwner(-2);

    fields[5].setFieldName("Podatek");
    fields[5].setPropertyPrice(200);
    fields[5].setCanBePurchased(false);
    fields[5].setOwner(-2);

    fields[6].setFieldName("Uniwersytet Łódzki");
    fields[6].setPropertyPrice(120);
    fields[6].setCanBePurchased(true);

    fields[7].setFieldName("Bilet na powrót do domu");
    fields[7].setPropertyPrice(50);
    fields[7].setCanBePurchased(false);
    fields[7].setOwner(-2);

    fields[8].setFieldName("Politechnika Łódzka");
    fields[8].setPropertyPrice(100);
    fields[8].setCanBePurchased(true);

    fields[9].setFieldName("Akademia Sztuk Pięknych");
    fields[9].setPropertyPrice(130);
    fields[9].setCanBePurchased(true);

    fields[10].setFieldName("Więzienie");
    fields[10].setPropertyPrice(0);
    fields[10].setCanBePurchased(false);
    fields[10].setOwner(-2);

    fields[11].setFieldName("Politechnika Gdańska");
    fields[11].setPropertyPrice(150);
    fields[11].setCanBePurchased(true);

    fields[12].setFieldName("Karta specjalna");
    fields[12].setPropertyPrice(0);
    fields[12].setCanBePurchased(false);
    fields[12].setOwner(-2);

    fields[13].setFieldName("Uniwersytet Gdański");
    fields[13].setPropertyPrice(120);
    fields[13].setCanBePurchased(true);

    fields[14].setFieldName("Akademia Muzyczna");
    fields[14].setPropertyPrice(130);
    fields[14].setCanBePurchased(true);

    fields[15].setFieldName("Podatek");
    fields[15].setPropertyPrice(200);
    fields[15].setCanBePurchased(false);
    fields[15].setOwner(-2);

    fields[16].setFieldName("Politechnika Poznańska");
    fields[16].setPropertyPrice(170);
    fields[16].setCanBePurchased(true);

    fields[17].setFieldName("Bilet na powrót do domu");
    fields[17].setPropertyPrice(50);
    fields[17].setCanBePurchased(false);
    fields[17].setOwner(-2);

    fields[18].setFieldName("Uniwersytet Przyrodniczy");
    fields[18].setPropertyPrice(90);
    fields[18].setCanBePurchased(true);

    fields[19].setFieldName("Uniwersytet Ekonomiczny");
    fields[19].setPropertyPrice(80);
    fields[19].setCanBePurchased(true);

    fields[20].setFieldName("Płatny parking");
    fields[20].setPropertyPrice(80);
    fields[20].setCanBePurchased(false);
    fields[20].setOwner(-2);

    fields[21].setFieldName("Uniwersytet Jagielloński");
    fields[21].setPropertyPrice(200);
    fields[21].setCanBePurchased(true);

    fields[22].setFieldName("Karta specjalna");
    fields[22].setPropertyPrice(0);
    fields[22].setCanBePurchased(false);
    fields[22].setOwner(-2);

    fields[23].setFieldName("AGH");
    fields[23].setPropertyPrice(210);
    fields[23].setCanBePurchased(true);

    fields[24].setFieldName("Politechnika Krakowska");
    fields[24].setPropertyPrice(190);
    fields[24].setCanBePurchased(true);

    fields[25].setFieldName("Podatek");
    fields[25].setPropertyPrice(200);
    fields[25].setCanBePurchased(false);
    fields[25].setOwner(-2);

    fields[26].setFieldName("UMCS");
    fields[26].setPropertyPrice(160);
    fields[26].setCanBePurchased(true);

    fields[27].setFieldName("Politechnika Lubelska");
    fields[27].setPropertyPrice(220);
    fields[27].setCanBePurchased(true);

    fields[28].setFieldName("Kazik");
    fields[28].setPropertyPrice(40);
    fields[28].setCanBePurchased(false);
    fields[28].setOwner(-2);

    fields[29].setFieldName("Uniwersytet Medyczny");
    fields[29].setPropertyPrice(140);
    fields[29].setCanBePurchased(true);

    fields[30].setFieldName("Idź do więzienia");
    fields[30].setPropertyPrice(0);
    fields[30].setCanBePurchased(false);
    fields[30].setOwner(-2);

    fields[31].setFieldName("Politechnika Warszawska");
    fields[31].setPropertyPrice(150);
    fields[31].setCanBePurchased(true);

    fields[32].setFieldName("SGH");
    fields[32].setPropertyPrice(230);
    fields[32].setCanBePurchased(true);

    fields[33].setFieldName("Syrenka warszawska");
    fields[33].setPropertyPrice(50);
    fields[33].setCanBePurchased(false);
    fields[33].setOwner(-2);

    fields[34].setFieldName("WAT");
    fields[34].setPropertyPrice(80);
    fields[34].setCanBePurchased(true);

    fields[35].setFieldName("Podatek");
    fields[35].setPropertyPrice(200);
    fields[35].setCanBePurchased(false);
    fields[35].setOwner(-2);

    fields[36].setFieldName("Karta specjalna");
    fields[36].setPropertyPrice(0);
    fields[36].setCanBePurchased(false);
    fields[36].setOwner(-2);

    fields[37].setFieldName("Uniwersytet Wrocławski");
    fields[37].setPropertyPrice(90);
    fields[37].setCanBePurchased(true);

    fields[38].setFieldName("Bilet na powrót do domu");
    fields[38].setPropertyPrice(50);
    fields[38].setCanBePurchased(false);
    fields[38].setOwner(-2);

    fields[39].setFieldName("Politechnika Wrocławska");
    fields[39].setPropertyPrice(140);
    fields[39].setCanBePurchased(true);
}

void Game::setCurrentPlayer(int newCurrentPlayer)
{
    currentPlayer = newCurrentPlayer;
}

