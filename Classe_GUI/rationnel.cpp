/*!
 * \file rationnel.cpp
 * \brief Methode de la class Rationnel
 */

#include "rationnel.h"

/*!
  * \fn Rationnel(int n, int d)
  * \brief Constructeur
  * Constructeur de la classe Rationnel
  * \param n : valeur de l'attribut _numerateur
  * \param d : valeur de l'attribut _denominateur
  */
Rationnel::Rationnel(int n, int d):Constante(RATIONNEL)
{
    if(d==0)
    {
        throw Rationnel_exception("erreur:denominateur nul");
    }
    this->_numerateur=n;
    this->_denominateur=d;
    this->simplification();
}

/*!
  * \fn Rationnel(const Entier& e)
  * \brief Constructeur
  * Constructeur de la classe Rationnel
  * \param e : référence sur un Entier existant
  */
Rationnel::Rationnel(const Entier &e):Constante(RATIONNEL)
{
    this->_numerateur=e.getEntier();
    this->_denominateur=1;
}

/*!
  * \fn Rationnel(const Entier& n, const Entier& d)
  * \brief Constructeur
  * Constructeur de la classe Rationnel
  * \param n : valeur de l'attribut _numerateur à partir d'un entier existant
  * \param d : valeur de l'attribut _denominateur à partir d'un entier existant
  */
Rationnel::Rationnel(const Entier &n, const Entier &d):Constante(RATIONNEL)
{
    if(d.getEntier()==0)
    {
        throw Rationnel_exception("erreur:denominateur nul");
    }
    this->_numerateur=n.getEntier();
    this->_denominateur=d.getEntier();
}

/*!
  * \fn Rationnel(const Rationnel &r)
  * \brief Constructeur de copie
  * Constructeur de la classe Rationnel à partir d'un Rationnel existant déjà
  * \param r : référence sur un Rationnel existant
  */
Rationnel::Rationnel(const Rationnel &r):Constante(RATIONNEL)
{
    this->_numerateur=r.getNumerateur();
    this->_denominateur=r.getDenominateur();
}

/////////
///Get///
/////////
/*!
  * \fn int getNumerateur
  * \brief getNumerateur
  * Méthode renvoyant la valeur de l'attribut _numerateur de la classe
  * \return _numerateur
  */
int Rationnel::getDenominateur()const
{
    return this->_denominateur;
}

/*!
  * \fn getDenominateur
  * \brief getDenominateur
  * Méthode renvoyant la valeur de l'attribut _denominateur de la classe
  * \return _denominateur
  */
int Rationnel::getNumerateur()const
{
    return this->_numerateur;
}

/////////
///Set///
/////////
/*!
  * \fn void setDenominateur(int d)
  * \brief setNumerateur
  * Méthode modifiant la valeur de l'attribut _numerateur de la classe
  * \param  n : nouvel valeur de _numerateur
  */
void Rationnel::setDenominateur(int d)
{
    this->_denominateur=d;
}

/*!
  * \fn void Rationnel::setNumerateur(int n)
  * \brief setDenominateur
  * Méthode modifiant la valeur de l'attribut _denominateur de la classe
  * \param  e : nouvel valeur de _denominateur
  */
void Rationnel::setNumerateur(int n)
{
    this->_numerateur=n;
}

/////////////
///Methode///
/////////////
/*!
  * \fn void Rationnel::affiche(std::ostream & os)const
  * \brief affiche
  * Methode permettant un affichage du rationnel manipulé
  * \param os
  */
void Rationnel::affiche(std::ostream & os)const
{
    os<<this->_numerateur<<"/"<<_denominateur;
}

/*!
  * \fn std::ostream& operator<<(std::ostream & os, const Rationnel & c)
  * \brief operator<<
  * surcharge de l'operator<<
  * \param os : ostream
  * \param c : Rationnel
  */
std::ostream & operator<<(std::ostream & os, const Rationnel & c)
{
    c.affiche(os);
    return(os);
}

/*!
  * \fn void simplification()
  * \brief simplification
  * Méthode privé permettante de simplifier quand celà est possible la fraction manipulé
  */
void Rationnel::simplification()
{
    if (_denominateur < 0)
    {
        _denominateur = -_denominateur;
        _numerateur = -_numerateur;
    }
    int diviseur = _denominateur;
    while (diviseur != 1)
    {
        if(_numerateur%diviseur == 0 && _denominateur%diviseur == 0)
        {
            _numerateur /= diviseur;
            _denominateur /=diviseur;
        }
        diviseur--;
    }
}

///////////////
///Operateur///
///////////////
/*!
  * \fn Constante* operator+(const Constante& c) const
  * \brief operator+
  * Methode retournant la somme du rationnel manipulé avec la constante passé en argument
  * Si la constante est un rationnel, alors on effectue l'operation adequate
  * si c'est une expression, on applique l'addition pour l'expression et on renvoie une expression
  * sinon, on transforme la constante en un rationnel en fonction de son type
  * \param c
  * \return Constante*
  */
Constante * Rationnel::operator+(Constante const & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return *this+Rationnel(static_cast<const Entier& >(c));
        break;
    case Constante::RATIONNEL:
        return new Rationnel(this->_numerateur*static_cast<const Rationnel&>(c)._denominateur+static_cast<const Rationnel&>(c)._numerateur*this->_denominateur,
                             this->_denominateur*static_cast<const Rationnel&>(c)._denominateur);
        break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c).toString()+this->toString()+"+'");
        break;
    }
}

/*!
  * \fn Constante* operator-(const Constante& c) const
  * \brief operator-
  * Methode retournant la différence du rationnel manipulé avec la constante passé en argument
  * Si la constante est un rationnel, alors on effectue l'operation adequate
  * si c'est une expression, on applique la différence pour l'expression et on renvoie une expression
  * sinon, on transforme la constante en un rationnel en fonction de son type
  * \param c
  * \return Constante*
  */
Constante * Rationnel::operator-(Constante const & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return *this-Rationnel(static_cast<const Entier& >(c));
        break;
    case Constante::RATIONNEL:
        return new Rationnel(this->_numerateur*
                             static_cast<const Rationnel&>(c)._denominateur-
                             static_cast<const Rationnel&>(c)._numerateur*
                             this->_denominateur,
                             this->_denominateur*
                             static_cast<const Rationnel&>(c)._denominateur);
        break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c).toString()+this->toString()+"-'");
        break;
    }
}

/*!
  * \fn Constante* operator*(const Constante& c) const
  * \brief operator*
  * Methode retournant le produit du rationnel manipulé avec la constante passé en argument
  * Si la constante est un rationnel, alors on effectue l'operation adequate
  * si c'est une expression, on applique le produit pour l'expression et on renvoie une expression
  * sinon, on transforme la constante en un rationnel en fonction de son type
  * \param c
  * \return Constante*
  */
Constante * Rationnel::operator*(Constante const & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return *this*Rationnel(static_cast<const Entier& >(c));
        break;
    case Constante::RATIONNEL:
        return new Rationnel(this->_numerateur*
                             static_cast<const Rationnel&>(c)._numerateur,
                             this->_denominateur*
                             static_cast<const Rationnel&>(c)._denominateur);
        break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c).toString()+this->toString()+"*'");
        break;
    }
}

/*!
  * \fn Constante* operator/(const Constante& c) const
  * \brief operator/
  * Methode retournant la division du rationnel manipulé avec la constante passé en argument
  * Si la constante est un rationnel, alors on effectue l'operation adequate
  * si c'est une expression, on applique la division pour l'expression et on renvoie une expression
  * sinon, on transforme la constante en un rationnel en fonction de son type
  * \param c
  * \return Constante*
  */
Constante * Rationnel::operator/(Constante const & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return *this/Rationnel(static_cast<const Entier& >(c));
        break;
    case Constante::RATIONNEL:
        return new Rationnel(this->_numerateur*
                             static_cast<const Rationnel&>(c)._denominateur,
                             this->_denominateur*
                             static_cast<const Rationnel&>(c)._numerateur);
        break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c).toString()+this->toString()+"/'");
        break;

    }
}

/*!
  * \fn  Constante* operator-()const
  * \brief operator-
  * Methode retournant le contraire du rationnel manipulé
  * \return Constante*
  */
Constante* Rationnel::operator-()const{
        return new Rationnel(-this->_numerateur,this->_denominateur);
}

/*!
  * \fn bool operator==(const Constante& c) const
  * \brief operator==
  * Methode vérifiant si le rationnel manipulé est égal à la constante passé en argument
  * Si la constante est un rationnel, alors on effectue l'operation adequate
  * sinon, on transforme la constante en un rationnel en fonction de son type
  * \param c
  * \return true si il y a égalité, false sinon
  */
bool Rationnel::operator==(const Constante & c) const
{
    float tmp = (float)this->_numerateur/(float)this->_denominateur;
    switch(c.getType()){
    case Constante::ENTIER:
    {
        if(tmp == static_cast<const Entier&>(c).getEntier())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case Constante::RATIONNEL:
    {
        float tmp2 = (float)static_cast<const Rationnel&>(c)._numerateur/(float)static_cast<const Rationnel&>(c)._denominateur;
        if(tmp == tmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    }
}

/*!
  * \fn bool operator<(const Constante& c) const
  * \brief operator<
  * Methode vérifiant si le rationnel manipulé est inférieur à la constante passé en argument
  * Si la constante est un rationnel, alors on effectue l'operation adequate
  * sinon, on transforme la constante en un rationnel en fonction de son type
  * \param c
  * \return true si l'entier manipulé est inférieur, false sinon
  */
bool Rationnel::operator<(const Constante & c) const
{
    float tmp = (float)this->_numerateur/(float)this->_denominateur;
    switch(c.getType()){
    case Constante::ENTIER:
    {
        if(tmp < static_cast<const Entier&>(c).getEntier())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case Constante::RATIONNEL:
    {
        float tmp2 = (float)static_cast<const Rationnel&>(c)._numerateur/(float)static_cast<const Rationnel&>(c)._denominateur;
        if(tmp < tmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    }
}
