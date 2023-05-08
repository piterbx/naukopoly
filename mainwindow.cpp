#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "game.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Game g; //musthave !!!
    ui->setupUi(this);

    QObject::connect(ui->pushButtonThrowADice, &QPushButton::clicked, this, &MainWindow::onPushButtonThrowADiceClicked);
    QObject::connect(ui->pushButtonSellProperty, &QPushButton::clicked, this, &MainWindow::onPushButtonSellPropertyClicked);
    QObject::connect(ui->pushButtonBuyProperty, &QPushButton::clicked, this, &MainWindow::onPushButtonBuyPropertyClicked);
    QObject::connect(ui->pushButtonBuyHouse, &QPushButton::clicked, this, &MainWindow::onPushButtonBuyHouseClicked);

    g.getButtons(ui);


    setLabelAccount();
    setLabelCurrentPlayer();
    setLabelPosition();
    displayProperties();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelCurrentPlayer()
{
    QString tmp = QString::fromStdString("Rzuca gracz "+std::to_string(Game::currentPlayer+1));
    ui->labelCurrentPlayerMoveInfo->setText(tmp);
}

void MainWindow::setLabelAccount()
{
    Player &tmp = Game::getPlayersTab()[Game::currentPlayer];
    QString str;
    for(int i=0;i<Game::getNrOfPlayers();i++){
        str = QString::fromStdString("Stan konta: "+std::to_string((int)Game::getPlayersTab()[i].getAccountBalance()));
        switch(i){
        case 0:
            ui->labelAccount1->setText(str);
            break;
        case 1:
            ui->labelAccount2->setText(str);
            break;
        case 2:
            ui->labelAccount3->setText(str);
            break;
        case 3:
            ui->labelAccount4->setText(str);
            break;
        }
    }
}

void MainWindow::setLabelPosition()
{
    Player &tmp = Game::getPlayersTab()[Game::currentPlayer];
    QString str;
    for(int i=0;i<Game::getNrOfPlayers();i++){
        str = QString::fromStdString("Pozycja: "+std::to_string(Game::getPlayersTab()[i].getPosition()));
        switch(i){
        case 0:
            ui->labelPos1->setText(str);
            break;
        case 1:
            ui->labelPos2->setText(str);
            break;
        case 2:
            ui->labelPos3->setText(str);
            break;
        case 3:
            ui->labelPos4->setText(str);
            break;
        }
    }
}

void MainWindow::displayProperties()
{
    SingleList list3 = Game::getPlayersTab()[2].getOwnedProperties();
    ui->listWidget3 = list3.display();
    //next => Game::getPlayersTab()[3].setOwnedProperties() = list3 ?????
}

void MainWindow::onPushButtonThrowADiceClicked()
{
    //making a move on a current player
    Game::getPlayersTab()[Game::getCurrentPlayer()].makeMove(ui->labelNotification);
    //ui->labelNotification->setText("Clicked");

    setLabelAccount();
    setLabelPosition();
    setLabelCurrentPlayer();
}


void MainWindow::onPushButtonSellPropertyClicked()
{
    //sell property
    Game::getPlayersTab()[Game::getCurrentPlayer()].sellProperty(ui->labelNotification);


    setLabelAccount();
    setLabelPosition();
}


void MainWindow::onPushButtonBuyPropertyClicked()
{
    //buy property
    Game::getPlayersTab()[Game::getCurrentPlayer()].buyProperty(ui->labelNotification);


    setLabelAccount();
    setLabelPosition();
}


void MainWindow::onPushButtonBuyHouseClicked()
{
    //buy a house
    Game::getPlayersTab()[Game::getCurrentPlayer()].buyHouse(ui->labelNotification);


    setLabelAccount();
    setLabelPosition();
}

