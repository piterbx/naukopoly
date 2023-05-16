#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Game::getInstance();
    ui->setupUi(this);

    QObject::connect(ui->pushButtonThrowADice, &QPushButton::clicked, this, &MainWindow::onPushButtonThrowADiceClicked);
    QObject::connect(ui->pushButtonSellProperty, &QPushButton::clicked, this, &MainWindow::onPushButtonSellPropertyClicked);
    QObject::connect(ui->pushButtonBuyProperty, &QPushButton::clicked, this, &MainWindow::onPushButtonBuyPropertyClicked);
    QObject::connect(ui->pushButtonBuyHouse, &QPushButton::clicked, this, &MainWindow::onPushButtonBuyHouseClicked);

    Game::getInstance()->getButtons(ui);


    setLabelAccount();
    setLabelCurrentPlayer();
    setLabelPosition();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelCurrentPlayer()
{
    QString tmp = QString::fromStdString("Rzuca gracz "+std::to_string(Game::getInstance()->currentPlayer+1));
    ui->labelCurrentPlayerMoveInfo->setText(tmp);
}

void MainWindow::setLabelAccount()
{
    Player &tmp = Game::getInstance()->getPlayersTab()[Game::getInstance()->currentPlayer];
    QString str;
    for(int i=0;i<Game::getInstance()->getNrOfPlayers();i++){
        str = QString::fromStdString("Stan konta: "+std::to_string((int)Game::getInstance()->getPlayersTab()[i].getAccountBalance()));
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
    Player &tmp = Game::getInstance()->getPlayersTab()[Game::getInstance()->currentPlayer];
    QString str;
    for(int i=0;i<Game::getInstance()->getNrOfPlayers();i++){
        str = QString::fromStdString("Pozycja: "+std::to_string(Game::getInstance()->getPlayersTab()[i].getPosition()));
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

void MainWindow::updateDisplayPropertyList()
{
    switch(Game::getInstance()->getCurrentPlayer()){
    case 0:
        ui->listWidget1->clear();
        break;
    case 1:
        ui->listWidget2->clear();
        break;
    case 2:
        ui->listWidget3->clear();
        break;
    case 3:
        ui->listWidget4->clear();
        break;
    }

    std::vector<listElement> tmpList = Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].getOwnedProperties();
    QString str;
    for(listElement &el : tmpList){
        str = QString::fromStdString(el.propertyName+" domy: "+std::to_string(el.boughtHouses)+" czynsz: "+std::to_string(el.totalValue));
        switch(Game::getInstance()->getCurrentPlayer()){
        case 0:
            ui->listWidget1->addItem(str);
            break;
        case 1:
            ui->listWidget2->addItem(str);
            break;
        case 2:
            ui->listWidget3->addItem(str);
            break;
        case 3:
            ui->listWidget4->addItem(str);
            break;
        }
    }
}


void MainWindow::onPushButtonThrowADiceClicked()
{
    //making a move on a current player
    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].makeMove(ui->labelNotification);
    //ui->labelNotification->setText("Clicked");

    setLabelAccount();
    setLabelPosition();
    setLabelCurrentPlayer();
}


void MainWindow::onPushButtonSellPropertyClicked()
{
    //sell property
    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].sellProperty(ui->labelNotification);


    setLabelAccount();
    setLabelPosition();
    updateDisplayPropertyList();
}


void MainWindow::onPushButtonBuyPropertyClicked()
{
    //buy property
    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].buyProperty(ui->labelNotification);

    setLabelAccount();
    setLabelPosition();
    updateDisplayPropertyList();
}


void MainWindow::onPushButtonBuyHouseClicked()
{
    //buy a house
    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].buyHouse(ui->labelNotification);


    setLabelAccount();
    setLabelPosition();
    updateDisplayPropertyList();
}

