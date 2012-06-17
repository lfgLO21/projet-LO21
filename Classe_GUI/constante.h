#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

/*! \class Constante
  * \brief classe representant les elements manipul� par la pile
  *
  * La classe est abstraite et ne contient q'un attribut type qui permet de connaitre le type de constante manipule
  */
class Constante
{
    protected:
        int _type; /*! type de la constante */
    public:
        enum Types {ENTIER = 0, RATIONNEL = 1 , REEL = 2, COMPLEXE = 3, EXPRESSION = 4}; /*! les diff�rents types qui sont des constantes */

        /*!
          * \brief Constructeur
          * Constructeur de la classe Constante
          * \param t : type de la constante cr�e
          */
        Constante(int t = 0): _type(t){}

        /*!
          * \brief Destructeur
          * Destructeur de la classe Constante
          */
        virtual ~Constante(){}

        /*!
          * \brief setType
          * Methode modifiant le type de la constante manipul�
          * \param t : nouveau type de la constante
          */
        void setType(int t = 0);

        /*!
          * \brief getType
          * Methode renvoyant le type de la constante manipul�
          * \return _type
          */
        int getType(void) const;

        /*!
          * \brief toString
          * Methode virtuel pure permettant de transformer la constante manipule en une chaine de caract�re
          * \return string
          */
        virtual std::string toString()const = 0;

        /*!
          * \brief affiche
          * Methode virtuel pure permettant un affichage de la constante manipul�
          * \param os
          */
        virtual void affiche(std::ostream & os = std::cout) const = 0;

        /*!
          * \brief operator+
          * Methode virtuel pure retournant la somme de la constante manipul� avec la constante pass� en argument
          * \param c
          * \return Constante*
          */
        virtual Constante * operator+(const Constante & c) const = 0;

        /*!
          * \brief operator-
          * Methode virtuel pure retournant la diff�rence de la constante manipul� avec la constante pass� en argument
          * \param c
          * \return Constante*
          */
        virtual Constante * operator-(const Constante & c) const = 0;

        /*!
          * \brief operator*
          * Methode virtuel pure retournant le produit de la constante manipul� avec la constante pass� en argument
          * \param c
          * \return Constante*
          */
        virtual Constante * operator*(const Constante & c) const = 0;

        /*!
          * \brief operator/
          * Methode virtuel pure retournant la division de la constante manipul� avec la constante pass� en argument
          * \param c
          * \return Constante*
          */
        virtual Constante * operator/(const Constante & c) const = 0;

        /*!
          * \brief operator-
          * Methode virtuel pure retournant le contraire de la constante manipul�
          * \return Constante*
          */
        virtual Constante * operator-()const = 0;

        /*!
          * \brief operator==
          * Methode virtuel pure v�rifiant si la constante manipul� est �gal � la constante pass� en argument
          * \param c
          * \return true si il y a �galit�, false sinon
          */
        virtual bool operator==(const Constante & c) const = 0;

        /*!
          * \brief operator<
          * Methode virtuel pure v�rifiant si la constante manipul� est inf�rieur � la constante pass� en argument
          * \param c
          * \return true si la constante manipul� est inf�rieur, false sinon
          */
        virtual bool operator<(const Constante & c) const = 0;
};

std::ostream & operator<<(std::ostream & os, const Constante & c);

#endif // CONSTANTE_H
