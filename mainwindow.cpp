#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game.h"

bool MainWindow::firstClick = true;

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

void MainWindow::onAddDisplayProperty()
{
    std::vector<listElement> tmpList = Game::getPlayersTab()[Game::getCurrentPlayer()].getOwnedProperties();
    QString str;
    for(listElement &el : tmpList){
        str = QString::fromStdString(el.propertyName+" domy: "+std::to_string(el.boughtHouses)+" czynsz: "+std::to_string(el.totalValue));
        switch(Game::getCurrentPlayer()){
        case 0:
            if(firstClick) ui->listWidget1->addItem(str);
            break;
        case 1:
            if(firstClick) ui->listWidget2->addItem(str);
            break;
        case 2:
            if(firstClick) ui->listWidget3->addItem(str);
            break;
        case 3:
            if(firstClick) ui->listWidget4->addItem(str);
            break;
        }
    }
}

void MainWindow::onRemoveDisplayProperty()
{
    std::vector<listElement> tmpList = Game::getPlayersTab()[Game::getCurrentPlayer()].getOwnedProperties();
    int idx = Game::getPlayersTab()[Game::getCurrentPlayer()].getPosition();
    QString str = QString::fromStdString(tmpList[idx].propertyName);
//    QList<QListWidgetItem *> items;


//    switch(Game::getCurrentPlayer()){
//    case 0:
//        items = ui->listWidget1->findItems(str, Qt::MatchContains);
//        for (QListWidgetItem *item : items)
//            delete ui->listWidget1->takeItem(ui->listWidget1->row(item));
//        //        ui->listWidget1->removeItemWidget(item);
//        break;
//    case 1:
//        items = ui->listWidget2->findItems(str, Qt::MatchContains);
//        for (QListWidgetItem *item : items)
//        ui->listWidget2->takeItem(ui->listWidget2->row(item));
//        //ui->listWidget2->removeItemWidget(item);
//        break;
//    case 2:
//        items = ui->listWidget3->findItems(str, Qt::MatchContains);
//        for (QListWidgetItem *item : items)
//        ui->listWidget3->takeItem(ui->listWidget3->row(item));
//        //ui->listWidget3->removeItemWidget(item);
//        break;
//    case 3:
//        items = ui->listWidget4->findItems(str, Qt::MatchContains);
//        for (QListWidgetItem *item : items)
//        ui->listWidget4->takeItem(ui->listWidget4->row(item));
//        //ui->listWidget4->removeItemWidget(item);
//        break;
//    }

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
    onRemoveDisplayProperty();
}


void MainWindow::onPushButtonBuyPropertyClicked()
{
    //buy property
    Game::getPlayersTab()[Game::getCurrentPlayer()].buyProperty(ui->labelNotification);

    setLabelAccount();
    setLabelPosition();
    onAddDisplayProperty();

    firstClick=false;
}


void MainWindow::onPushButtonBuyHouseClicked()
{
    //buy a house
    Game::getPlayersTab()[Game::getCurrentPlayer()].buyHouse(ui->labelNotification);


    setLabelAccount();
    setLabelPosition();
}

