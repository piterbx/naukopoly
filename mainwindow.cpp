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
    QObject::connect(ui->pushButtonEndMove, &QPushButton::clicked, this, &MainWindow::onPushButtonEndMoveClicked);

    QObject::connect(ui->actionExit, &QAction::triggered, this, &MainWindow::onActionExitTriggered);
    QObject::connect(ui->actionReset, &QAction::triggered, this, &MainWindow::onActionResetTriggered);
    QObject::connect(ui->actionEndGame, &QAction::triggered, this, &MainWindow::onActionResetTriggered);

    firstRun = true;
    onActionResetTriggered();
    firstRun = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelCurrentPlayer()
{
    QString tmp = QString::fromStdString("Trwa rzut gracza "+std::to_string(Game::getInstance()->currentPlayer+1));
    ui->labelCurrentPlayerMoveInfo->setText(tmp);
}

void MainWindow::setLabelAccount()
{
    Player tmp = Game::getInstance()->getPlayersTab()[Game::getInstance()->currentPlayer];
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
    Player tmp = Game::getInstance()->getPlayersTab()[Game::getInstance()->currentPlayer];
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

    std::vector<listElement> & tmpList = Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].getOwnedProperties();
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
    QLabel *tmp = ui->labelP1Img;
    switch(Game::getInstance()->getCurrentPlayer()){
    case 0:
        tmp = ui->labelP1Img;
        break;
    case 1:
        tmp = ui->labelP2Img;
        break;
    case 2:
        tmp = ui->labelP3Img;
        break;
    case 3:
        tmp = ui->labelP4Img;
        break;
    }

    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].makeMove(ui->labelNotification, tmp);
    //ui->labelNotification->setText("Clicked");

    setLabelAccount();
    setLabelPosition();
    setLabelCurrentPlayer();
    Game::getInstance()->setBeforeMove(false);
    updateButtons();
}


void MainWindow::onPushButtonSellPropertyClicked()
{
    //sell property
    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].sellProperty(ui->labelNotification);


    setLabelAccount();
    setLabelPosition();
    updateDisplayPropertyList();
    updateButtons();
    ui->pushButtonBuyProperty->setDisabled(true);
}


void MainWindow::onPushButtonBuyPropertyClicked()
{
    //buy property
    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].buyProperty(ui->labelNotification);

    setLabelAccount();
    setLabelPosition();
    updateDisplayPropertyList();
    updateButtons();
}


void MainWindow::onPushButtonBuyHouseClicked()
{
    //buy a house
    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].buyHouse(ui->labelNotification);


    setLabelAccount();
    setLabelPosition();
    updateDisplayPropertyList();
    updateButtons();

}

void MainWindow::onPushButtonEndMoveClicked(){
    //end move and switch player
    Game::getInstance()->switchPlayer();
    setLabelAccount();
    setLabelPosition();
    setLabelCurrentPlayer();
    Game::getInstance()->setBeforeMove(true);
    updateButtons();
}

void MainWindow::updateButtons(){
    Field &place = Game::getInstance()->getFields()[Game::getInstance()->getPlayersTab()[Game::getInstance()->currentPlayer].getPosition()];
    int curr = Game::getInstance()->currentPlayer;

    if(Game::getInstance()->getBeforeMove()){
        ui->pushButtonEndMove->setDisabled(true);
        ui->pushButtonSellProperty->setDisabled(true);
        ui->pushButtonThrowADice->setDisabled(false);
        ui->pushButtonBuyProperty->setDisabled(true);

        if(place.getOwner()==curr){
            ui->pushButtonBuyHouse->setDisabled(false);
        } else {
            ui->pushButtonBuyHouse->setDisabled(true);
        }
    } else {
        ui->pushButtonEndMove->setDisabled(false);
        if(place.getOwner()==curr){
            ui->pushButtonSellProperty->setDisabled(false);
        } else {
            ui->pushButtonSellProperty->setDisabled(true);
        }
        ui->pushButtonThrowADice->setDisabled(true);
        ui->pushButtonBuyHouse->setDisabled(true);

        if(place.getOwner()==-1){
            ui->pushButtonBuyProperty->setDisabled(false);
        } else {
            ui->pushButtonBuyProperty->setDisabled(true);
        }
    }
}

void MainWindow::onActionExitTriggered()
{
    QMessageBox proceed;
    proceed.setWindowTitle("Koniec");
    proceed.setText("Czy na pewno chcesz zakończyć działanie programu?");
    proceed.setStandardButtons(QMessageBox::Yes);
    proceed.addButton(QMessageBox::No);

    proceed.setDefaultButton(QMessageBox::No);

    if(proceed.exec() == QMessageBox::Yes){
        QCoreApplication::quit();
    }
}

void MainWindow::onActionResetTriggered()
{
    QMessageBox proceed;
    QString txt;

    proceed.setWindowTitle("Rozpocznij nową grę");

    if(!firstRun){
        proceed.setWindowTitle("Wyniki gry");
        txt += "<b>Tabela wyników:</b>";
            for(int i=0;i<Game::getInstance()->getNrOfPlayers();i++){
            txt+="<p>Gracz "+std::to_string(i+1)+" majątek: "+std::to_string(Game::getInstance()->countPlayerFortune(i))+" posiadłości: +"+std::to_string(Game::getInstance()->getPlayersTab()[i].getNrOfOwnedProperties())+"</p>";
        }
        txt+="<br><br>Rozpocząć nową grę?";
    } else {
        txt+="<p>Start gry po naciśnięciu przycisku</p><p>Zasady gry w zakładce Informacje u góry po rozpoczęciu gry</p>";
    }

    proceed.setText(txt);

    proceed.setStandardButtons(QMessageBox::Yes);
    if(!firstRun) proceed.addButton(QMessageBox::No);

    proceed.setDefaultButton(QMessageBox::Yes);

    if(proceed.exec() == QMessageBox::Yes){
        Game::getInstance()->resetValues();

        ui->labelP1Img->setGeometry(890, 600, 16, 16);
        ui->labelP2Img->setGeometry(910, 600, 16, 16);
        ui->labelP3Img->setGeometry(890, 580, 16, 16);
        ui->labelP4Img->setGeometry(910, 580, 16, 16);
        setLabelAccount();
        setLabelPosition();

        updateButtons();
        updateDisplayPropertyList();

        ui->labelCurrentPlayerMoveInfo->setText("Trwa rzut gracza 1");
        ui->labelNotification->setText("");

        ui->listWidget1->clear();
        ui->listWidget2->clear();
        ui->listWidget3->clear();
        ui->listWidget4->clear();

        ui->pushButtonThrowADice->setDisabled(false);
        ui->pushButtonBuyHouse->setDisabled(true);
    }
}
