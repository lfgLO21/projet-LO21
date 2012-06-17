#ifndef REEL_H
#define REEL_H

#include <exception>
#include "constante.h"
#include "expression.h"
#include "rationnel.h"

/*! \class Reel
  * \brief classe repr�sentant les constantes qui sont des r�els
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
      * \param e : r�f�rence sur un Entier existant
      */
    Reel(const Entier& e);

    /*!
      * \brief Constructeur
      * Constructeur de la classe Reel
      * \param r : r�f�rence sur un Rationnel existant
      */
    Reel(const Rationnel& r);

    /*!
      * \brief Constructeur de copie
      * Constructeur de la classe Reel � partir d'un Reel existant d�j�
      * \param e : r�f�rence sur un Reel existant
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
      * M�thode renvoyant la valeur de l'attribut _reel de la classe
      * \return _reel
      */
    float getReel() const;

    //set
    /*!
      * \brief setReel
      * M�thode modifiant la valeur de l'attribut _reel de la classe
      * \param  r : nouvel valeur de _reel
      */
    void setReel(float r);

    /*!
      * \brief toString
      * Methode permettant de transformer le r�el manipul� en une chaine de caract�re
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
      * Methode retournant la somme du Reel manipul� avec la constante pass� en argument
      * \param r
      * \return Constante*
      */
    Constante * operator+(const Constante & r) const;

    /*!
      * \brief operator-
      * Methode retournant la diff�rence du Reel manipul� avec la constante pass� en argument
      * \param r
      * \return Constante*
      */
    Constante * operator-(const Constante & r) const;

    /*!
      * \brief operator*
      * Methode retournant le produit du Reel manipul� avec la constante pass� en argument
      * \param r
      * \return Constante*
      */
    Constante * operator*(const Constante & r) const;

    /*!
      * \brief operator/
      * Methode retournant la division du Reel manipul� avec la constante pass� en argument
      * \param r
      * \return Constante*
      */
    Constante * operator/(const Constante & r) const;

    /*!
      * \brief operator-
      * Methode retournant le contraire du Reel manipul�
      * \return Constante*
      */
    Constante * operator-()const;

    /*!
      * \brief operator==
      * Methode v�rifiant si le Reel manipul� est �gal � la constante pass� en argument
      * \param c
      * \return true si il y a �galit�, false sinon
      */
    bool operator==(const Constante & c) const;

    /*!
      * \brief operator<
      * Methode v�rifiant si le Reel manipul� est inf�rieur � la constante pass� en argument
      * \param c
      * \return true si la constante manipul� est inf�rieur, false sinon
      */
    bool operator<(const Constante & c) const;

};

std::ostream & operator<<(std::ostream & os, const Reel & c);

#endif // REEL_H
