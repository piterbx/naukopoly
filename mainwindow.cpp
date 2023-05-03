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

    g.getButtons(ui->pushButtonThrowADice, ui->pushButtonBuyProperty, ui->pushButtonSellProperty, ui->pushButtonBuyHouse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushButtonThrowADiceClicked()
{
    //making a move on a current player
    Game::getPlayersTab()[Game::getCurrentPlayer()].makeMove(ui->labelNotification);
    //ui->labelNotification->setText("Clicked");
}


void MainWindow::onPushButtonSellPropertyClicked()
{
    //sell property
    Game::getPlayersTab()[Game::getCurrentPlayer()].sellProperty(ui->labelNotification);
}


void MainWindow::onPushButtonBuyPropertyClicked()
{
    //buy property
    Game::getPlayersTab()[Game::getCurrentPlayer()].buyProperty(ui->labelNotification);
}


void MainWindow::onPushButtonBuyHouseClicked()
{
    //buy a house
    Game::getPlayersTab()[Game::getCurrentPlayer()].buyHouse(ui->labelNotification);
}

