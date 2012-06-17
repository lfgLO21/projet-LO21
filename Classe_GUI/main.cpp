#include <QApplication>

#include <iostream>

#include "mainwindow.h"
#include "logsystem.h"

int main(int argc, char *argv[])
{
    int finaleValue;

    LogSystem::printLog(LogMessage("Demarrage calculette",1));
    QApplication a(argc, argv);
    MainWindow w;

    w.show();


    finaleValue = a.exec();
    LogSystem::printLog(LogMessage("Fin execution calculette",1));

    return finaleValue;

}
