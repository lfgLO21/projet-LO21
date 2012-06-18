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
/*!
 *\class LogMessage
 *\brief type de messages lancer par les fonction afin de decrire l'activite de la calculatrice
 */
class LogMessage
{
    QString _log;
    unsigned int _degree;
    QDateTime _time;
public:
    LogMessage(const std::string&,unsigned int);
    QString getLog()const;
};
/*!
 *\class LogSysteme
 *\brief Class permettant l'affichage et le staockage des LogMessages
 */
class LogSystem
{
public:
    static void printLog(const LogMessage & l);
};
#endif // LOGSYSTEM_H
