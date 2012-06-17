#include "logsystem.h"

LogMessage::LogMessage(const std::string& s,unsigned int i){
    this->_log = QString(s.c_str());
    this->_degree = i;
    this->_time = QDateTime::currentDateTime();
}

QString LogMessage::getLog()const
{

    std::stringstream ss;
    ss<<" : [";
    ss<<this->_degree;
    ss<<"]";
    return QString(this->_time.toString("dd/MM/yyyy - hh:mm:ss")+ss.str().c_str()+this->_log);

}

void LogSystem::printLog(const LogMessage& l){

    cerr<<l.getLog().toStdString()<<endl;

    QFile file("stderr");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    flux << l.getLog().toStdString().c_str() << endl;
}