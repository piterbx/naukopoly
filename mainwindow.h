
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setLabelCurrentPlayer();
    void setLabelAccount();
    void setLabelPosition();
    void updateDisplayPropertyList();
    void updateButtons();
    bool firstRun;

private slots:
    void onPushButtonThrowADiceClicked();

    void onPushButtonSellPropertyClicked();

    void onPushButtonBuyPropertyClicked();

    void onPushButtonBuyHouseClicked();

    void onPushButtonEndMoveClicked();

    void onActionExitTriggered();

    void onActionResetTriggered();

    void onActionRulesTriggered();

    void onActionAboutAuthorsTriggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
