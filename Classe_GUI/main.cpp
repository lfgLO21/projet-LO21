#include <QApplication>

#include <iostream>

#include "mainwindow.h"
#include "logsystem.h"
#include "contexte.h"

int main(int argc, char *argv[])
{
    int finaleValue;

    LogSystem::printLog(LogMessage("Demarrage calculette",1));
    QApplication a(argc, argv);

    MainWindow * w = MainWindow::getInstance();
    Contexte::getInstance()->loadContexte();

    w->show();
    finaleValue = a.exec();

    Contexte::getInstance()->saveContexte();
    w->libereInstance();

    LogSystem::printLog(LogMessage("Fin execution calculette",1));
    return finaleValue;

}
