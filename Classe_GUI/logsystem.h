#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QString>
#include <sstream>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <iostream>

using namespace std;

class LogMessage
{
    QString log;
    unsigned int degree;
public:
    LogMessage(const std::string&,unsigned int);
    QString getLog()const{

        std::stringstream ss;
        ss<<"[";
        ss<<degree;
        ss<<"]";
        return QString(ss.str().c_str()+log);

        }
};

class LogSystem
{
public:
    static void printLog(const LogMessage & l);
};
#endif // LOGSYSTEM_H
