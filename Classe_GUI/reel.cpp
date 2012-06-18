/*!
 * \file reel.cpp
 * \brief Methode de la class Reel
 */

#include "reel.h"

/*!
  * \fn Reel(float r)
  * \brief Constructeur
  * Constructeur de la classe Reel
  * \param r : valeur de l'attribut _reel
  */
Reel::Reel(float r):Constante(REEL)
{
    this->_reel = r;
}

/*!
  * \fn Reel(const Entier& e)
  * \brief Constructeur
  * Constructeur de la classe Reel
  * \param e : référence sur un Entier existant
  */
Reel::Reel(const Entier& e):Constante(REEL)
{
    this->_reel = e.getEntier();
}

/*!
  * \fn Reel(const Rationnel &r)
  * \brief Constructeur
  * Constructeur de la classe Reel
  * \param r : référence sur un Rationnel existant
  */
Reel::Reel(const Rationnel &r):Constante(REEL)
{
    float n=(float)r.getNumerateur();
    float d=(float)r.getDenominateur();
    this->_reel=n/d;
}

/*!
  * \fn Reel(const Reel& e)
  * \brief Constructeur de copie
  * Constructeur de la classe Reel à partir d'un Reel existant déjà
  * \param e : référence sur un Reel existant
  */
Reel::Reel(const Reel& r):Constante(REEL)
{
    this->_reel = r.getReel();
}

/////////
///Get///
/////////
/*!
  * \fn float getReel()const
  * \brief getReel
  * Méthode renvoyant la valeur de l'attribut _reel de la classe
  * \return _reel
  */
float Reel::getReel()const
{
    return this->_reel;
}

/////////
///Set///
/////////
/*!
  \fn void setReel(float r)
  * \brief setReel
  * Méthode modifiant la valeur de l'attribut _reel de la classe
  * \param  r : nouvel valeur de _reel
  */
void Reel::setReel(float r)
{
    this->_reel = r;
}

/////////////
///Methode///
/////////////
/*!
  * \fn void affiche(std::ostream & os) const
  * \brief affiche
  * Methode permettant un affichage du reel manipulé
  * \param os
  */
void Reel::affiche(std::ostream & os) const
{
    os<<this->_reel;
}

/*!
  * \fn std::ostream& operator<<(std::ostream & os, const Reel & c)
  * \brief operator<<
  * surcharge de l'operator<<
  * \param os : ostream
  * \param c : Reel
  */
std::ostream & operator<<(std::ostream & os, const Reel & c)
{
    c.affiche(os);
    return(os);
}

/*!
  * \fn Constante* operator+(const Constante& c) const
  * \brief operator+
  * Methode retournant la somme du reel manipulé avec la constante passé en argument
  * Si la constante est un reel, alors on effectue l'operation adequate
  * si c'est une expression, on applique l'addition pour l'expression et on renvoie une expression
  * sinon, on transforme la constante en un reel en fonction de son type
  * \param c
  * \return Constante*
  */
Constante * Reel::operator+(const Constante & r) const
{
    //verifie l'enum herite de Constante pour connaitre le type de l'objet avec lequel le
    //reel est additionne.
    switch (r.getType())
    {
    case Constante::ENTIER:
    {
        return *this+Reel(static_cast<const Entier&>(r));
        break;
    }
    case Constante::RATIONNEL:
    {
        return *this+Reel(static_cast<const Rationnel&>(r));
        break;
    }
    case Constante::REEL:
    {
        return new Reel(this->_reel + static_cast<const Reel&>(r)._reel);
        break;
    }
    case Constante::EXPRESSION:
    {
        return new Expression("'"+static_cast<const Expression&>(r).toString()+this->toString()+"+'");
        break;
    }
    default:
    {
        throw std::domain_error("Type non existant");
    }
    }

}

/*!
  * \fn Constante* operator-(const Constante& c) const
  * \brief operator-
  * Methode retournant la différence du reel manipulé avec la constante passé en argument
  * Si la constante est un reel, alors on effectue l'operation adequate
  * si c'est une expression, on applique l'addition pour l'expression et on renvoie une expression
  * sinon, on transforme la constante en un reel en fonction de son type
  * \param c
  * \return Constante*
  */
Constante * Reel::operator-(const Constante & r) const
{
    switch (r.getType())
    {
    case Constante::ENTIER:
    {
        return *this-Reel(static_cast<const Entier&>(r));
        break;
    }
    case Constante::RATIONNEL:
    {
        return *this-Reel(static_cast<const Rationnel&>(r));
        break;
    }
    case Constante::REEL:
    {
        return new Reel(this->_reel - static_cast<const Reel&>(r)._reel);
        break;
    }
    case Constante::EXPRESSION:
    {
        return new Expression("'"+static_cast<const Expression&>(r).toString()+this->toString()+"-'");
        break;
    }
    default:
    {
        throw std::domain_error("Type non existant");
    }
    }
}


/*!
  * \fn Constante* operator*(const Constante& c) const
  * \brief operator*
  * Methode retournant le produit du reel manipulé avec la constante passé en argument
  * Si la constante est un reel, alors on effectue l'operation adequate
  * si c'est une expression, on applique l'addition pour l'expression et on renvoie une expression
  * sinon, on transforme la constante en un reel en fonction de son type
  * \param c
  * \return Constante*
  */
Constante * Reel::operator*(const Constante & r) const
{
    switch (r.getType())
    {
    case Constante::ENTIER:
    {
        return *this*Reel(static_cast<const Entier&>(r));
        break;
    }
    case Constante::RATIONNEL:
    {
        return *this*Reel(static_cast<const Rationnel&>(r));
        break;
    }
    case Constante::REEL:
    {
        return new Reel(this->_reel * static_cast<const Reel&>(r)._reel);
        break;
    }
    case Constante::EXPRESSION:
    {
        return new Expression("'"+static_cast<const Expression&>(r).toString()+this->toString()+"*'");
        break;
    }
    default:
    {
        throw std::domain_error("Type non existant");
    }
    }
}

/*!
  * \fn Constante* operator/(const Constante& c) const
  * \brief operator/
  * Methode retournant la division du reel manipulé avec la constante passé en argument
  * Si la constante est un reel, alors on effectue l'operation adequate
  * si c'est une expression, on applique l'addition pour l'expression et on renvoie une expression
  * sinon, on transforme la constante en un reel en fonction de son type
  * \param c
  * \return Constante*
  */
Constante * Reel::operator/(const Constante & r) const
{
    switch (r.getType())
    {
    case Constante::ENTIER:
    {
        return *this/Reel(static_cast<const Entier&>(r));
        break;
    }
    case Constante::RATIONNEL:
    {
        return *this/Reel(static_cast<const Rationnel&>(r));
        break;
    }
    case Constante::REEL:
    {
        return new Reel(this->_reel / static_cast<const Reel&>(r)._reel);
        break;
    }
    case Constante::EXPRESSION:
    {
        return new Expression("'"+static_cast<const Expression&>(r).toString()+this->toString()+"/'");
        break;
    }
    default:
    {
        throw std::domain_error("Type non existant");
    }
    }
}

/*!
  * \fn  Constante* operator-()const
  * \brief operator-
  * Methode retournant le contraire du reel manipulé
  * \return Constante*
  */
Constante* Reel::operator-()const{
        return new Reel(-this->_reel);
}

/*!
  * \fn bool operator==(const Constante& c) const
  * \brief operator==
  * Methode vérifiant si le reel manipulé est égal à la constante passé en argument
  * Si la constante est un reel, alors on effectue l'operation adequate
  * sinon, on transforme la constante en un reel en fonction de son type
  * \param c
  * \return true si il y a égalité, false sinon
  */
bool Reel::operator==(const Constante & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
    {
        if(this->_reel == static_cast<const Entier&>(c).getEntier())
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
        float tmp = (float)static_cast<const Rationnel&>(c).getNumerateur()/(float)static_cast<const Rationnel&>(c).getDenominateur();
        if(this->_reel == tmp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case Constante::REEL:
    {
        if(this->_reel == static_cast<const Reel&>(c)._reel)
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
  * Methode vérifiant si le reel manipulé est inférieur à la constante passé en argument
  * Si la constante est un reel, alors on effectue l'operation adequate
  * sinon, on transforme la constante en un rationnel en fonction de son type
  * \param c
  * \return true si l'entier manipulé est inférieur, false sinon
  */
bool Reel::operator<(const Constante & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
    {
        if(this->_reel < static_cast<const Entier&>(c).getEntier())
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
        float tmp = (float)static_cast<const Rationnel&>(c).getNumerateur()/(float)static_cast<const Rationnel&>(c).getDenominateur();
        if(this->_reel < tmp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case Constante::REEL:
    {
        if(this->_reel < static_cast<const Reel&>(c)._reel)
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
