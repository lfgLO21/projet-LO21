/*!
 * \file constante.cpp
 * \brief Methode de la class Constante
 */

#include "constante.h"

/*!
  * \fn void setType(int t)
  * \brief setType
  * Methode modifiant le type de la constante manipulé
  * \param t : nouveau type de la constante
  */
void Constante::setType(int t)
{
    this->_type = t;
}

/*!
  * \fn int getType(void) const
  * \brief getType
  * Methode renvoyant le type de la constante manipulé
  * \return _type
  */
int Constante::getType(void) const
{
    return this->_type;
}

/*!
  * \fn std::ostream& operator<<(std::ostream & os, const Constante & c)
  * \brief operator<<
  * surcharge de l'operator<<
  * \param os : ostream
  * \param c : Constante
  */
std::ostream & operator<<(std::ostream & os, const Constante & c)
{
    c.affiche(os);
    return(os);
}
