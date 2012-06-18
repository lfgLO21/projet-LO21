#include "contexte.h"

Etat * Etat::_instance = 0;
Contexte * Contexte::_instance = 0;
/*!
 *\fn Etat::Etat()
 *\brief Constructeur d'etat, l'etat dans lequel la calculatrice est actuellement et dans lequel il peut etre enregistrer pour etre retrouver au demarrage
 *\param void
 *\return void
 */
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

/*!
 *\fn Etat* Etat::getInstance()
 *\brief Il ne peut y avoir qu'un etat pour la calculatrice, l'etat est donc un singleton
 *\param void
 *\return void
 */
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

/*!
 *\fn void Etat::libereInstance()
 *\brief Il ne peut y avoir qu'un etat pour la calculatrice, l'etat est donc un singleton
 *\param void
 *\return void
 */
void Etat::libereInstance()
{
    if (! _instance)
    {
        delete _instance;
    }
}

/*!
 *\fn int Etat::getUseComplexe() const
 *\brief Methode renvoyant l'etat de la checkBox Complexe, soit un enumerer COMPLEXE ou NOCOMPLEXE
 *\param void
 *\return 0 ou 1
 */
int Etat::getUseComplexe() const
{
    return this->_useComplexe;
}


/*!
 *\fn int Etat::getTypeAngle() const
 *\brief Methode renvoyant l'etat de la checbox unite de l'angle, soit un enumerer RADIANS ou DEGRES
 *\param void
 *\return 0 ou 1
 */
int Etat::getTypeAngle() const
{
    return this->_typeAngle;
}

/*!
 *\fn int Etat::getTypeDonnee() const
 *\brief Methode renvoyant l'etat de la checbox le type des donnees gerees, soit un enumerer ENTIER, RATIONNEL, REEL
 *\param void
 *\return 0, 1 ou 2
 */
int Etat::getTypeDonnee() const
{
    return this->_typeDonnee;
}

/*!
 *\fn unsigned int Etat::getNbElementPileAffiche() const
 *\brief Methode renvoyant le nombre d'elements que la pile peut afficher.
 *\param void
 *\return un unsigned int; la pile ne pouvant pas afficher a l'envers
 */
unsigned int Etat::getNbElementPileAffiche() const
{
    return this->_nbElementPileAffiche;
}

/*!
 *\fn void Etat::setUseComplexe(int)
 *\brief Methode permettant de changer la valeur de l'attribut correspondant a l'utilisation ou non des complexes
 *\param un int entre 0 et 1
 *\return void
 */
void Etat::setUseComplexe(int cc)
{
    this->_useComplexe = cc;
}

/*!
 *\fn void Etat::setTypeAngle (int ca)
 *\brief Methode permettant de changer la valeur de l'attribut correspondant a un resultat en degre ou en radian
 *\param un int soit 0 soit 1
 *\return void
 */
void Etat::setTypeAngle (int ca)
{
    this->_typeAngle = ca;
}

/*!
 *\fn void Etat::setTypeDonnee (int)
 *\brief Methode permettant de changer la valeur de l'attribut correspondant a la manipulation d'entiers, de fraction ou e reels
 *\param un int soit 0, soit 1 soit 2
 *\return void
 */
void Etat::setTypeDonnee (int ct)
{
    this->_typeDonnee = ct;
}

/*!
 *\fn void Etat::setNbElementPileAffiche(unsigned int)
 *\brief Methode permettant de changer le nombre d'element que la pile peut afficher
 *\param un unsigned int correspondant au nombre d'element que la pile peut afficher
 *\return void
 */
void Etat::setNbElementPileAffiche(unsigned int n)
{
    this->_nbElementPileAffiche = n;
}

/*!
 *\fn Contexte::Contexte()
 *\brief le contexte est la classe permettant la sauvegarde de l'etat dans lequel est la calculatrice en fin de programme
 *\param void
 *\return void
 */
Contexte::Contexte()
{};

Contexte::~Contexte()
{
    delete _instance;
}

/*!
 *\fn Contexte* Contexte::getInstance()
 *\brief Le contexte est un singleton, il ne peut etre utiliser que dans une version dans toute l'application
 *\param void
 *\return void
 */
Contexte* Contexte::getInstance()
{
    if (! _instance)
    {
        _instance = new Contexte();
    }
    else
        return _instance;
}

/*!
 *\fn void Contexte::libereInstance()
 *\brief Le contexte est un singleton, il ne peut etre utiliser que dans une version dans toute l'application
 *\param void
 *\return void
 */
void Contexte::libereInstance()
{
    if (! _instance)
    {
        delete _instance;
    }
}

/*!
 *\fn void Contexte::saveContexte() const
 *\brief Methode permettant la sauvegarde du contexte
 *\param void
 *\return void
 */
void Contexte::saveContexte() const
{
    /*!
     *\brief on pointe vers les données que l'on va manipuler, ici l'etat de la calculatrice et la pile
     */
    Etat* etat = Etat::getInstance();
    Pile* p = MainWindow::getInstance()->getPile();

    /*!
     *\brief sauvegarde avec QFile en attendant de trouver mieux
     */
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

/*!
 *\fn void Contexte::loadContexte()
 *\brief Methode appelee au demarrage de l'application pour retrouver l'etat dans lequel etait la calculatrice la derniere foid qe l'on l'a quitter
 *\param void
 *\return void
 */
void Contexte::loadContexte()
{
    /*
     *\brief on pointe vers les donnees qu'on va manipuler (etat, pile)
     */
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
    /*!
     *\brief mise a jour des donnees de la calculatrice a l'aide des anciennes valeurs
     */


//MainWindow::getInstance()->setInputLineEdit(e.text());
//MainWindow::getInstance()->enterPressed();
//MainWindow::getInstance()->chargerNouveauContexte();
}
