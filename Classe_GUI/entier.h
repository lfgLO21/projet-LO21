#ifndef Entier_H
#define Entier_H

#include "constante.h"
#include "expression.h"
#include <string>
#include <sstream>

class Rationnel;

/*! \class Entier
  * \brief classe représentant les constantes qui sont des entiers
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
      * Constructeur de la classe Entier à partir d'un Entier existant déjà
      * \param e : référence sur un Entier existant
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
      * Méthode renvoyant la valeur de l'attribut _entier de la classe
      * \return _entier
      */
    int getEntier()const;

    //set
    /*!
      * \brief setEntier
      * Méthode modifiant la valeur de l'attribut _entier de la classe
      * \param  e : nouvel valeur de _entier
      */
    void setEntier(int e);

    /*!
      * \brief toString
      * Methode permettant de transformer l'entier manipulé en une chaine de caractère
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
      * Methode permettant un affichage de l'Entier manipulé
      * \param os
      */
    void affiche(std::ostream & os = std::cout) const;

    /*!
      * \brief operator+
      * Methode retournant la somme de l'Entier manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante * operator+(const Constante & c) const;

    /*!
      * \brief operator-
      * Methode retournant la différence de l'Entier manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante * operator-(const Constante & c) const;

    /*!
      * \brief operator*
      * Methode retournant le produit de l'Entier manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante * operator*(const Constante & c) const;

    /*!
      * \brief operator/
      * Methode retournant la division de l'Entier manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante * operator/(const Constante & c) const;

    /*!
      * \brief operator-
      * Methode retournant le contraire de l'Entier manipulé
      * \return Constante*
      */
    Constante * operator-()const;

    /*!
      * \brief operator==
      * Methode vérifiant si l'Entier manipulé est égal à la constante passé en argument
      * \param c
      * \return true si il y a égalité, false sinon
      */
    bool operator==(const Constante & c) const;

    /*!
      * \brief operator<
      * Methode vérifiant si l'Entier manipulé est inférieur à la constante passé en argument
      * \param c
      * \return true si la constante manipulé est inférieur, false sinon
      */
    bool operator<(const Constante & c) const;

    /*!
      * \brief operator%
      * Methode retournant le modulo de l'Entier manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante* operator%(const Constante& c)const;

    /*!
      * \brief operator!
      * Methode retournant la factoriel de l'Entier manipulé
      * \return Constante*
      */
    Constante* operator!()const;
};

std::ostream & operator<<(std::ostream & os, const Entier & c);

#endif // Entier_H
