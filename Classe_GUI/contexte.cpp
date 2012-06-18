#include "contexte.h"

Etat * Etat::_instance = 0;
Contexte * Contexte::_instance = 0;

Etat::Etat()
{
    this->_useComplexe = Etat::NOCOMPLEXE;
    this->_typeAngle = Etat::DEGRES;
    this->_typeDonnee = Etat::ENTIER;
    this->_nbElementPileAffiche = 10;
}

Etat::Etat(int cc, int ca, int ct, unsigned int nbA, std::string p)
{
    this->_useComplexe = cc;
    this->_typeAngle = ca;
    this->_typeDonnee = ct;
    this->_nbElementPileAffiche = nbA;
}

Etat::~Etat()
{}

Etat* Etat::getInstance()
{
    if(! _instance)
    {
        _instance = new Etat();
    }
    else
    {
        return _instance;
    }
}

void Etat::libereInstance()
{
    if (! _instance)
    {
        delete _instance;
    }
}

int Etat::getUseComplexe() const
{
    return this->_useComplexe;
}


int Etat::getTypeAngle() const
{
    return this->_typeAngle;
}

int Etat::getTypeDonnee() const
{
    return this->_typeDonnee;
}

unsigned int Etat::getNbElementPileAffiche() const
{
    return this->_nbElementPileAffiche;
}

void Etat::setUseComplexe(int cc)
{
    this->_useComplexe = cc;
}

void Etat::setTypeAngle (int ca)
{
    this->_typeAngle = ca;
}

void Etat::setTypeDonnee (int ct)
{
    this->_typeDonnee = ct;
}

void Etat::setNbElementPileAffiche(unsigned int n)
{
    this->_nbElementPileAffiche = n;
}

Contexte::Contexte()
{};

Contexte::~Contexte()
{
    delete _instance;
}

Contexte* Contexte::getInstance()
{
    if (! _instance)
    {
        _instance = new Contexte();
    }
    else
        return _instance;
}

void Contexte::libereInstance()
{
    if (! _instance)
    {
        delete _instance;
    }
}

void Contexte::saveContexte() const
{
    Etat* etat = Etat::getInstance();
    Pile* p = MainWindow::getInstance()->getPile();

    QFile file("sauvegardeContexte");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        LogSystem::printLog(LogMessage("Errreur d'ouverture de fichier",2));
        return;
    }

    QTextStream flux(&file);
    flux.setCodec("UTF-8");

    flux << etat->getUseComplexe() << endl;
    flux << etat->getTypeAngle() << endl;
    flux << etat->getTypeDonnee() << endl;
    flux << etat->getNbElementPileAffiche() << endl;

    Pile temp;
    std::string stringPile;
    unsigned int i = 0;
    while((i < etat->getNbElementPileAffiche()) && (p->getSize() != 0))
    {
        Constante * tmp = p->pop();
        temp.push(tmp);
        stringPile = tmp->toString() + " " + stringPile;
        i++;
    }
    while(i > 0 && temp.getSize() != 0) {
        p->push(temp.pop());
        i--;
    }

    flux << stringPile.c_str() << endl;
}


void Contexte::loadContexte()
{
    Etat* etat = Etat::getInstance();
    Pile * p = MainWindow::getInstance()->getPile();

    QFile file("sauvegardeContexte");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);

    QString ligne;
    std::vector<QString> lecture;
    while(! flux.atEnd())
    {
        ligne = flux.readLine();
        lecture.push_back(ligne);
    }
    for (unsigned int i = 0; i < lecture.size(); i++)
    {
        cout << lecture[i].toStdString() << endl;
    }



//MainWindow::getInstance()->setInputLineEdit(e.text());
//MainWindow::getInstance()->enterPressed();
//MainWindow::getInstance()->chargerNouveauContexte();
}
