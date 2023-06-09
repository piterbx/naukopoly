#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game.h"

#include <QCloseEvent>

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

    QObject::connect(ui->actionRules, &QAction::triggered, this, &MainWindow::onActionRulesTriggered);
    QObject::connect(ui->actionAboutAuthors, &QAction::triggered, this, &MainWindow::onActionAboutAuthorsTriggered);

    firstRun = true;
    onActionResetTriggered();
    firstRun = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox msg;
    msg.setWindowTitle("Koniec");
    msg.setText("Czy na pewno chcesz zakończyć działanie programu?");
    msg.setStandardButtons(QMessageBox::Yes);
    msg.addButton(QMessageBox::No);

    msg.setDefaultButton(QMessageBox::No);

    if (msg.exec() != QMessageBox::Yes) event->ignore();
    else event->accept();
}

void MainWindow::setLabelCurrentPlayer()
{
    QString tmp = QString::fromStdString("Trwa rzut gracza "+std::to_string(Game::getInstance()->getCurrentPlayer()+1));
    ui->labelCurrentPlayerMoveInfo->setText(tmp);
}

void MainWindow::setLabelAccount()
{
    Player tmp = Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()];
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
    QString str;
    for(int i=0;i<Game::getInstance()->getNrOfPlayers();i++){
        if(Game::getInstance()->getPlayersTab()[i].getPrisonTime()>0) str = QString::fromStdString("Pozycja: w więzieniu");
        else if(Game::getInstance()->getPlayersTab()[i].getIfBankrupt()) str = QString::fromStdString("Gracz zbankrutował");
        else str = QString::fromStdString("Pozycja: "+std::to_string(Game::getInstance()->getPlayersTab()[i].getPosition()));
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

    Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].makeMove(ui->labelNotification, tmp, ui->labelFieldnfo);
    //ui->labelNotification->setText("Clicked");

    setLabelAccount();
    setLabelPosition();
    setLabelCurrentPlayer();
    Game::getInstance()->setBeforeMove(false);
    updateButtons();
    updateDisplayPropertyList();
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

    //check if only one player has a positive account balance
    int x=0; //is nr of players has negative balance
    for(int i=0;i<Game::getInstance()->getNrOfPlayers();i++) if(Game::getInstance()->getPlayersTab()[i].getIfBankrupt()) x++;
    if(x>=3) onActionResetTriggered();

    setLabelAccount();
    setLabelPosition();
    setLabelCurrentPlayer();
    Game::getInstance()->setBeforeMove(true);
    updateButtons();
}

void MainWindow::updateButtons(){
    Field &place = Game::getInstance()->getFields()[Game::getInstance()->getPlayersTab()[Game::getInstance()->getCurrentPlayer()].getPosition()];
    int curr = Game::getInstance()->getCurrentPlayer();

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

        if(place.getOwner()==-1 && place.getCanBePurchased()){
            ui->pushButtonBuyProperty->setDisabled(false);
        } else {
            ui->pushButtonBuyProperty->setDisabled(true);
        }
    }
}

void MainWindow::makeOkDialog(std::string t, std::string content)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(QString::fromStdString(t));
    msgBox.setText(QString::fromStdString(content));
    msgBox.setWindowIcon(QIcon(":/img/img/icon.png"));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::onActionExitTriggered()
{
    QCoreApplication::quit();
}

void MainWindow::onActionResetTriggered()
{
    QMessageBox proceed;
    std::string txt;

    proceed.setWindowTitle("Rozpocznij nową grę");
    proceed.setWindowIcon(QIcon(":/img/img/icon.png"));

    if(!firstRun){
        proceed.setWindowTitle("Wyniki gry");
        txt += "<b>Tabela wyników:</b>";
        for(int i=0;i<Game::getInstance()->getNrOfPlayers();i++){
            txt+="<p>Gracz "+std::to_string(i+1);
                if(Game::getInstance()->countPlayerFortune(i)<0) txt+= " bankrut";
                else txt+= " majątek: "+std::to_string(Game::getInstance()->countPlayerFortune(i));
            txt+=" posiadłości: +"+std::to_string(Game::getInstance()->getPlayersTab()[i].getNrOfOwnedProperties())+"</p>";
        }
        txt+="<br><br>Rozpocząć nową grę?";
    } else {
        txt+="<p>Start gry po naciśnięciu przycisku</p><p>Zasady gry w zakładce Informacje u góry po rozpoczęciu gry</p>";
    }

    proceed.setText(QString::fromStdString(txt));

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
        ui->labelFieldnfo->setText("");

        ui->listWidget1->clear();
        ui->listWidget2->clear();
        ui->listWidget3->clear();
        ui->listWidget4->clear();

        ui->pushButtonThrowADice->setDisabled(false);
        ui->pushButtonBuyHouse->setDisabled(true);
    }
}

void MainWindow::onActionRulesTriggered()
{
    makeOkDialog("Zasady gry", "Gra jest 4osobowa.\nGracze pokolei rzucają kostką (1-6).\nKażdy gracz podczas swojego rzutu może kupić pole, jeśli nie jest to pole specjalne lub pole nie zostało kupione przez innego gracza.\nPrzed każdym rzutem kostką gracz może kupić dom (gdy znajduje się na tym polu).\nNa jednym polu mogą znajdować się maksymalnie 3 domy.\nGracz może również odsprzedać swoje pole do banku za cenę, za którą je nabył (bez wartości domów), ale musi znajdować na tym polu.\nStanięcie na pole innego gracza wiąże się z zapłatą czynszu temu graczowi w zależności od pola i ilości domów na polu. Gdy gracz stanie na polach: Wygrana na loterii, Kazik, Mała syrenka, losowana jest kwota, która zostanie dodana do konta gracza. Jeśli gracz stanie na polach Bilet na powrót do domu, wylosowana kwota zostanie odjęta od konta tego gracza.\nStając na polu Podatek podbierany jest podatek 10procentowy z majątku gracza.\nPole Idź do więzienie oznacza, że gracz transportowany jest do więzienia na 3 kolejki (nie pobiera kwoty należnej graczom po przejściu przez pole Start).\n\nGracz po przejściu przez pole Start gracz otrzymuje 50monet.\nGra kończy się w momencie w którym ustalą to wspólnie gracze. Wygrywa osoba z największym majątkiem");
}

void MainWindow::onActionAboutAuthorsTriggered()
{
    makeOkDialog("O autorach", "Piotr Bogusz <a href=\"https://github.com/piterbx\">https://github.com/piterbx</a><br>Jakub Biaduń <a href=\"https://github.com/jakubbiadun\">https://github.com/jakubbiadun</a><br><br> Użyte grafiki pochodzą ze strony <a href=\"https://pixabay.com\">https://pixabay.com</a> (logo, elementy planszy)");
}

