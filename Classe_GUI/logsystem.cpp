#include "logsystem.h"

/*!
 *\fn void LogSystem::printLog(LogMessage)
 *\brief Methode de creation d'un nouveau message de LogSystem decrivant une action efectuee par une procedure
 */
LogMessage::LogMessage(const std::string& s,unsigned int i)
{
    this->_log = QString(s.c_str());
    this->_degree = i;
    this->_time = QDateTime::currentDateTime();
}

/*!
 *\fn void LogSystem::printLog(LogMessage)
 *\brief Methode d'affichage d'un LogMessage dans un format lisible, comprenant le moment ou est apparu le LogSystem, son intitule et son niveau
 */
QString LogMessage::getLog()const
{

    std::stringstream ss;
    ss<<" : [";
    ss<<this->_degree;
    ss<<"]";
    return QString(this->_time.toString("dd/MM/yyyy - hh:mm:ss")+ss.str().c_str()+this->_log);

}

/*!
 *\fn void LogSystem::printLog(LogMessage)
 *\brief Methode d'ecriture du LogSystem dans un fichier recapitulatif lisible hors fonctionnement
 */
void LogSystem::printLog(const LogMessage& l)
{

    cerr<<l.getLog().toStdString()<<endl;

    QFile file("stderr.pony");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    flux << l.getLog().toStdString().c_str() << endl;
}
