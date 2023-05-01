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
    Game::getPlayersTab()[Game::getCurrentPlayer()].sellProperty(ui->labelNotification);
}

