
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "field.h"
#include "qpushbutton.h"
#include "ui_mainwindow.h"
#include <vector>

class Game
{
    int time; //in seconds
    int timeLeft;
    bool beforeMove;
    int nrOfPlayers;
    std::vector<Player> playersTab; // tab of players
    std::vector<Field> fields;

    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;

    //---- implementing singleton
    static Game *ginstance;
protected:
    Game();
    ~Game() {}
public:
    //should have 1 instance (not many clones)
    Game(Game &other) = delete;
    void operator=(const Game &) = delete;

    static Game *getInstance();

    std::vector<Player> & getPlayersTab();
    int getNrOfPlayers();
    std::vector<Field> & getFields();

    void checkForWin(); //todo it will be executed after single move
    void countTime(); //this function updates timeLeft of the game
    void getButtons(Ui::MainWindow *ui);
    void updateButtons();

    int currentPlayer; // is an index of player in playersTab
    void setCurrentPlayer(int newCurrentPlayer);
    int getCurrentPlayer();

    void switchPlayer();


    bool getBeforeMove();
    void setBeforeMove(bool newBeforeMove);
    QPushButton *getBtn1();
};

#endif // GAME_H
