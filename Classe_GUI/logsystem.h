#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QString>
#include <sstream>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QDateTime>

using namespace std;

class LogMessage
{
    QString _log;
    unsigned int _degree;
    QDateTime _time;
public:
    LogMessage(const std::string&,unsigned int);
    QString getLog()const;
};

class LogSystem
{
public:
    static void printLog(const LogMessage & l);
};
#endif // LOGSYSTEM_H
