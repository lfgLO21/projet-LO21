/**
 * \brief Classe Complexe
 * Permet les op�rations simples sur les complexes.
 * \author moi
 * \date 21.V.12
 * \version 1.0
 */
#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <cmath>
#include <exception>
#include <iostream>
#include "constante.h"
#include "operation.h"
#include "reel.h"
#include "rationnel.h"
#include "entier.h"


/*! \class Complexe
  * \brief classe repr�sentant les constantes qui sont des complexes
  *
  * La classe comporte deux attribut de type Constante*
  */
class Complexe : public Constante
{
    private:
        Constante*_r; /*! valeur de la partie reel du complexe */
        Constante*_i; /*! valeur de la partie imaginaire du complexe */

    public:
        /*!
          * \brief Constructeur
          * Constructeur de la classe Complexe
          */
        Complexe();

        /*!
          * \brief Constructeur de copie
          * Constructeur de la classe Complexe � partir d'un complexe d�ja existant
          * \param c : r�f�rence sur un complexe existant
          */
        Complexe(const Complexe & c);

        /*!
          * \brief Constructeur
          * Constructeur de la classe Complexe
          * \param c : r�f�rence sur une constante
          */
        Complexe(const Constante& c);

        /*!
          * \brief Constructeur
          * Constructeur de la classe Complexe
          * \param r : pointeur sur une constante qui sera la partie r�el
          * \param i : pointeur sur une constante qui sera la partie imaginaire
          */
        Complexe(const Constante* r, const Constante* i);

        /*!
          * \brief Destructeur
          * Destructeur de la classe Complexe
          */
        ~Complexe();

        /*!
          * \brief getR
          * M�thode renvoyant la valeur de l'attribut _r de la classe
          * \return _r
          */
        Constante* getR() const;

        /*!
          * \brief getI
          * M�thode renvoyant la valeur de l'attribut _i de la classe
          * \return _i
          */
        Constante* getI() const;

        /*!
          * \brief setR
          * M�thode modifiant la valeur de l'attribut _r de la classe
          * \param  r : nouvel valeur de _r
          */
        void setR(const Constante& r);

        /*!
          * \brief setI
          * M�thode modifiant la valeur de l'attribut _i de la classe
          * \param  i : nouvel valeur de _i
          */
        void setI(const Constante& i);

        /*!
          * \brief toString
          * Methode permettant de transformer le complexe manipul� en une chaine de caract�re
          * \return string
          */
        std::string toString()const{
            std::stringstream ss;
            ss<<_r->toString()<<"$"<<_i->toString();
            return ss.str();
        }

        /*!
          * \brief affiche
          * Methode permettant un affichage du complexe manipul�
          * \param os
          */
        void affiche(std::ostream & os = std::cout) const;

        /*!
          * \brief operator+
          * Methode retournant la somme du complexe manipul� avec la constante pass� en argument
          * \param c
          * \return Constante*
          */
        Constante * operator+(const Constante & c) const;

        /*!
          * \brief operator-
          * Methode retournant la diff�rence du complexe manipul� avec la constante pass� en argument
          * \param c
          * \return Constante*
          */
        Constante * operator-(const Constante & c) const;

        /*!
          * \brief operator*
          * Methode retournant le produit du complexe manipul� avec la constante pass� en argument
          * \param c
          * \return Constante*
          */
        Constante * operator*(const Constante & c) const;

        /*!
          * \brief operator/
          * Methode retournant la division du complexe manipul� avec la constante pass� en argument
          * \param c
          * \return Constante*
          */
        Constante * operator/(const Constante & c) const;

        /*!
          * \brief operator-
          * Methode retournant le contraire du complexe manipul�
          * \return Constante*
          */
        Constante * operator-()const;

        /*!
          * \brief operator==
          * Methode v�rifiant si le complexe manipul� est �gal � la constante pass� en argument
          * \param c
          * \return true si il y a �galit�, false sinon
          */
        bool operator==(const Constante & c) const;

        /*!
          * \brief operator<
          * Methode v�rifiant si le complexe manipul� est inf�rieur � la constante pass� en argument
          * \param c
          * \return true si la constante manipul� est inf�rieur, false sinon
          */
        bool operator<(const Constante & c) const;

};

std::ostream & operator<<(std::ostream & os, const Complexe & c);

class ComplexeException
{
    private:
        int _numero;
        std::string _info;
    public:
        ComplexeException(int n, std::string const & info) throw();
        virtual ~ComplexeException() throw();

        virtual const char* what() const throw();
};

#endif // COMPLEXE_H
