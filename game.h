
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "field.h"
#include "qpushbutton.h"
#include "ui_mainwindow.h"

class Game
{
    int time; //in seconds
    int timeLeft;
    static bool beforeMove;
    static const int nrOfPlayers;
    static Player playersTab[4];
    static Field fields[40];

    static QPushButton *btn1;
    static QPushButton *btn2;
    static QPushButton *btn3;
    static QPushButton *btn4;

public:
    Game();
    ~Game();
    static Player* getPlayersTab();
    static int getNrOfPlayers();
    static Field* getFields();

    void checkForWin(); //todo it will be executed after single move
    void countTime(); //this function updates timeLeft of the game
    void getButtons(Ui::MainWindow *ui);
    static void updateButtons();

    static int currentPlayer; // is an index of player in playersTab
    static void setCurrentPlayer(int newCurrentPlayer);
    static int getCurrentPlayer();

    static void switchPlayer();


    static bool getBeforeMove();
    static void setBeforeMove(bool newBeforeMove);
    static QPushButton *getBtn1();
};

#endif // GAME_H
