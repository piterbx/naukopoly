
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "field.h"
#include <vector>

class Game
{
    bool beforeMove;
    int nrOfPlayers;
    std::vector<Player> playersTab; // tab of players
    std::vector<Field> fields;

    //---- implementing singleton
    static Game *ginstance;
protected:
    Game();
    ~Game(){};
public:
    //should have 1 instance (not many clones)
    Game(Game &other) = delete;
    void operator=(const Game &) = delete;

    static Game *getInstance();

    std::vector<Player> & getPlayersTab();
    int getNrOfPlayers();
    std::vector<Field> & getFields();

    int countPlayerFortune(int id);

    int currentPlayer; // is an index of player in playersTab
    void setCurrentPlayer(int newCurrentPlayer);
    int getCurrentPlayer();

    void switchPlayer();


    bool getBeforeMove();
    void setBeforeMove(bool newBeforeMove);

    void resetValues();
};

#endif // GAME_H
