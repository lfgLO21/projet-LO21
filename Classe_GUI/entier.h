#ifndef Entier_H
#define Entier_H

#include "constante.h"
#include "expression.h"
#include <string>
#include <sstream>

class Rationnel;

/*! \class Entier
  * \brief classe repr�sentant les constantes qui sont des entiers
  *
  * La classe comporte un attribut integer
  */
class Entier : public Constante
{
    int _entier; /*! valeur de l'entier */

public:

    /*!
      * \brief Constructeur
      * Constructeur de la classe Entier
      * \param d : valeur de l'attribut _entier
      */
    Entier(int d=0);

    /*!
      * \brief Constructeur de copie
      * Constructeur de la classe Entier � partir d'un Entier existant d�j�
      * \param e : r�f�rence sur un Entier existant
      */
    Entier(const Entier& e);

    /*!
      * \brief Destructeur
      * Destructeur de la classe Entier
      */
    ~Entier(){}

    //get
    /*!
      * \brief getEntier
      * M�thode renvoyant la valeur de l'attribut _entier de la classe
      * \return _entier
      */
    int getEntier()const;

    //set
    /*!
      * \brief setEntier
      * M�thode modifiant la valeur de l'attribut _entier de la classe
      * \param  e : nouvel valeur de _entier
      */
    void setEntier(int e);

    /*!
      * \brief toString
      * Methode permettant de transformer l'entier manipul� en une chaine de caract�re
      * \return string
      */
    std::string toString()const{
        std::stringstream ss;
        ss <<_entier;
        return ss.str();
    }

    //affiche
    /*!
      * \brief affiche
      * Methode permettant un affichage de l'Entier manipul�
      * \param os
      */
    void affiche(std::ostream & os = std::cout) const;

    /*!
      * \brief operator+
      * Methode retournant la somme de l'Entier manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante * operator+(const Constante & c) const;

    /*!
      * \brief operator-
      * Methode retournant la diff�rence de l'Entier manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante * operator-(const Constante & c) const;

    /*!
      * \brief operator*
      * Methode retournant le produit de l'Entier manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante * operator*(const Constante & c) const;

    /*!
      * \brief operator/
      * Methode retournant la division de l'Entier manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante * operator/(const Constante & c) const;

    /*!
      * \brief operator-
      * Methode retournant le contraire de l'Entier manipul�
      * \return Constante*
      */
    Constante * operator-()const;

    /*!
      * \brief operator==
      * Methode v�rifiant si l'Entier manipul� est �gal � la constante pass� en argument
      * \param c
      * \return true si il y a �galit�, false sinon
      */
    bool operator==(const Constante & c) const;

    /*!
      * \brief operator<
      * Methode v�rifiant si l'Entier manipul� est inf�rieur � la constante pass� en argument
      * \param c
      * \return true si la constante manipul� est inf�rieur, false sinon
      */
    bool operator<(const Constante & c) const;

    /*!
      * \brief operator%
      * Methode retournant le modulo de l'Entier manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante* operator%(const Constante& c)const;

    /*!
      * \brief operator!
      * Methode retournant la factoriel de l'Entier manipul�
      * \return Constante*
      */
    Constante* operator!()const;
};

std::ostream & operator<<(std::ostream & os, const Entier & c);

#endif // Entier_H
