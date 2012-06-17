#ifndef REEL_H
#define REEL_H

#include <exception>
#include "constante.h"
#include "expression.h"
#include "rationnel.h"

/*! \class Reel
  * \brief classe représentant les constantes qui sont des réels
  *
  * La classe comporte un attribut float
  */
class Reel : public Constante
{
    float _reel; /*! valeur du reel */

public:
    /*!
      * \brief Constructeur
      * Constructeur de la classe Reel
      * \param r : valeur de l'attribut _reel
      */
    Reel(float r = 0);

    /*!
      * \brief Constructeur
      * Constructeur de la classe Reel
      * \param e : référence sur un Entier existant
      */
    Reel(const Entier& e);

    /*!
      * \brief Constructeur
      * Constructeur de la classe Reel
      * \param r : référence sur un Rationnel existant
      */
    Reel(const Rationnel& r);

    /*!
      * \brief Constructeur de copie
      * Constructeur de la classe Reel à partir d'un Reel existant déjà
      * \param e : référence sur un Reel existant
      */
    Reel(const Reel& e);

    /*!
      * \brief Destructeur
      * Destructeur de la classe Reel
      */
    ~Reel(){}

    //get
    /*!
      * \brief getReel
      * Méthode renvoyant la valeur de l'attribut _reel de la classe
      * \return _reel
      */
    float getReel() const;

    //set
    /*!
      * \brief setReel
      * Méthode modifiant la valeur de l'attribut _reel de la classe
      * \param  r : nouvel valeur de _reel
      */
    void setReel(float r);

    /*!
      * \brief toString
      * Methode permettant de transformer le réel manipulé en une chaine de caractère
      * \return string
      */
    std::string toString()const{
        std::stringstream ss;
        ss << _reel;
        return ss.str();
    }

    //affiche
    void affiche(std::ostream & os = std::cout) const;

    //operateur
    /*!
      * \brief operator+
      * Methode retournant la somme du Reel manipulé avec la constante passé en argument
      * \param r
      * \return Constante*
      */
    Constante * operator+(const Constante & r) const;

    /*!
      * \brief operator-
      * Methode retournant la différence du Reel manipulé avec la constante passé en argument
      * \param r
      * \return Constante*
      */
    Constante * operator-(const Constante & r) const;

    /*!
      * \brief operator*
      * Methode retournant le produit du Reel manipulé avec la constante passé en argument
      * \param r
      * \return Constante*
      */
    Constante * operator*(const Constante & r) const;

    /*!
      * \brief operator/
      * Methode retournant la division du Reel manipulé avec la constante passé en argument
      * \param r
      * \return Constante*
      */
    Constante * operator/(const Constante & r) const;

    /*!
      * \brief operator-
      * Methode retournant le contraire du Reel manipulé
      * \return Constante*
      */
    Constante * operator-()const;

    /*!
      * \brief operator==
      * Methode vérifiant si le Reel manipulé est égal à la constante passé en argument
      * \param c
      * \return true si il y a égalité, false sinon
      */
    bool operator==(const Constante & c) const;

    /*!
      * \brief operator<
      * Methode vérifiant si le Reel manipulé est inférieur à la constante passé en argument
      * \param c
      * \return true si la constante manipulé est inférieur, false sinon
      */
    bool operator<(const Constante & c) const;

};

std::ostream & operator<<(std::ostream & os, const Reel & c);

#endif // REEL_H
