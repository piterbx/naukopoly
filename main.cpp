
#include "mainwindow.h"

#include <QApplication>
#include <time.h>


int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("naukopoly");
    w.setWindowIcon(QIcon(":/img/img/icon.png"));
    w.show();
    return a.exec();
}
