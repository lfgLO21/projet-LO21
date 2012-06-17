#include "entier.h"

/*!
  * \fn Entier(int d)
  * \brief Constructeur
  * Constructeur de la classe Entier
  * \param d : valeur de l'attribut _entier
  */
Entier::Entier(int d):Constante(ENTIER)
{
    this->_entier = d;
    this->_type = ENTIER;
}

/*!
  * \fn Entier(const Entier& e)
  * \brief Constructeur de copie
  * Constructeur de la classe Entier à partir d'un Entier existant déjà
  * \param e : référence sur un Entier existant
  */
Entier::Entier(const Entier& e):Constante(ENTIER)
{
    this->_entier=e.getEntier();
    this->_type = ENTIER;
}

/////////
///Get///
/////////

/*!
  * \fn int getEntier()const
  * \brief getEntier
  * Méthode renvoyant la valeur de l'attribut _entier de la classe
  * \return _entier
  */
int Entier::getEntier()const
{
    return this->_entier;
}

/////////
///Set///
/////////

/*!
  * \fn void setEntier(int e)
  * \brief setEntier
  * Méthode modifiant la valeur de l'attribut _entier de la classe
  * \param  e : nouvel valeur de _entier
  */
void Entier::setEntier(int e)
{
    this->_entier=e;
}

/////////////
///Methode///
////////////

/*!
  * \fn affiche(std::ostream& os)
  * \brief affiche
  * Methode permettant un affichage de l'Entier manipulé
  * \param os
  */
void Entier::affiche(std::ostream & os)const
{
    os<<this->_entier;
}

/*!
  * \fn std::ostream& operator<<(std::ostream & os, const Entier & c)
  * \brief operator<<
  * surcharge de l'operator<<
  * \param os : ostream
  * \param c : Entier
  */
std::ostream & operator<<(std::ostream & os, const Entier & c)
{
    c.affiche(os);
    return(os);
}

//////////////
///operator///
//////////////
/*!
  * \fn Constante* operator+(const Constante& c) const
  * \brief operator+
  * Methode retournant la somme de l'entier manipulé avec la constante passé en argument
  * Si la constante est un entier, alors on effectue l'operation adequate
  * si c'est une expression, on applique l'addition pour l'expression et on renvoie une expression
  * \param c
  * \return Constante*
  */
Constante * Entier::operator+(Constante const & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return new Entier(this->_entier + static_cast<const Entier&>(c)._entier);
        break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c).toString()+this->toString()+"+'");
        break;
    }
}

/*!
  * \fn Constante* operator-(const Constante& c) const
  * \brief operator-
  * Methode retournant la différence de l'entier manipulé avec la constante passé en argument
  * Si la constante est un entier, alors on effectue l'operation adequate
  * si c'est une expression, on applique la différence pour l'expression et on renvoie une expression
  * \param c
  * \return Constante*
  */
Constante * Entier::operator-(Constante const & c) const
{
    switch(c.getType()){
            case Constante::ENTIER:
    return new Entier(this->_entier - static_cast<const Entier&>(c)._entier);
            break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c).toString()+this->toString()+"-'");
        break;
    }
}

/*!
  * \fn Constante* operator*(const Constante& c) const
  * \brief operator*
  * Methode retournant le produit de l'entier manipulé avec la constante passé en argument
  * Si la constante est un entier, alors on effectue l'operation adequate
  * si c'est une expression, on applique le produit pour l'expression et on renvoie une expression
  * \param c
  * \return Constante*
  */
Constante * Entier::operator*(Constante const & c) const
{
    switch(c.getType()){
            case Constante::ENTIER:
    return new Entier(this->_entier * static_cast<const Entier&>(c)._entier);
            break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c).toString()+this->toString()+"*'");
        break;
    }
}

/*!
  * \fn Constante* operator/(const Constante& c) const
  * \brief operator/
  * Methode retournant la division de l'entier manipulé avec la constante passé en argument
  * Si la constante est un entier, alors on effectue l'operation adequate
  * si c'est une expression, on applique la division pour l'expression et on renvoie une expression
  * \param c
  * \return Constante*
  */
Constante * Entier::operator/(Constante const& c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return new Entier(this->_entier / static_cast<const Entier&>(c)._entier);
        break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c).toString()+this->toString()+"/'");
        break;
    }
}

/*!
  * \fn Constante* operator%(const Constante& c) const
  * \brief operator%
  * Methode retournant le modulo de l'entier manipulé avec la constante passé en argument
  * Si la constante est un entier, alors on effectue l'operation adequate
  * \param c
  * \return Constante*
  */
Constante* Entier::operator%(const Constante& c)const{
   switch(c.getType()){
       case Constante::ENTIER:
        return new Entier(_entier % static_cast<const Entier&>(c)._entier);
   }
}

/*!
  * \fn Constante* operator!(const Constante& c) const
  * \brief operator!
  * Methode retournant la factoriel de l'entier manipulé
  * \return Constante*
  */
Constante* Entier::operator!()const{
    int tmp=1;
    for(int i=0;i<_entier-1;i++)
        tmp*=_entier-i;
    return new Entier(tmp);
}

/*!
  * \fn  Constante* operator-()const
  * \brief operator-
  * Methode retournant le contraire de l'Entier manipulé
  * \return Constante*
  */
Constante* Entier::operator-()const{
        return new Entier(-this->_entier);
}

/*!
  * bool operator==(const Constante& c) const
  * \brief operator==
  * Methode vérifiant si l'entier manipulé est égal à la constante passé en argument
  * Si la constante est un entier, alors on effectue l'operation adequate
  * \param c
  * \return true si il y a égalité, false sinon
  */
bool Entier::operator==(const Constante & c) const
{
    switch(c.getType()){
        case Constante::ENTIER:
        {
            if(this->_entier == static_cast<const Entier&>(c)._entier)
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
  * bool operator<(const Constante& c) const
  * \brief operator<
  * Methode vérifiant si l'entier manipulé est inférieur à la constante passé en argument
  * Si la constante est un entier, alors on effectue l'operation adequate
  * \param c
  * \return true si l'entier manipulé est inférieur, false sinon
  */
bool Entier::operator<(const Constante & c) const
{
    switch(c.getType()){
        case Constante::ENTIER:
        {
            if(this->_entier < static_cast<const Entier&>(c)._entier)
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
