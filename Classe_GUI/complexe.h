/**
 * \brief Classe Complexe
 * Permet les opï¿½rations simples sur les complexes.
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
  * \brief classe représentant les constantes qui sont des complexes
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
          * Constructeur de la classe Complexe à partir d'un complexe déja existant
          * \param c : référence sur un complexe existant
          */
        Complexe(const Complexe & c);

        /*!
          * \brief Constructeur
          * Constructeur de la classe Complexe
          * \param c : référence sur une constante
          */
        Complexe(const Constante& c);

        /*!
          * \brief Constructeur
          * Constructeur de la classe Complexe
          * \param r : pointeur sur une constante qui sera la partie réel
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
          * Méthode renvoyant la valeur de l'attribut _r de la classe
          * \return _r
          */
        Constante* getR() const;

        /*!
          * \brief getI
          * Méthode renvoyant la valeur de l'attribut _i de la classe
          * \return _i
          */
        Constante* getI() const;

        /*!
          * \brief setR
          * Méthode modifiant la valeur de l'attribut _r de la classe
          * \param  r : nouvel valeur de _r
          */
        void setR(const Constante& r);

        /*!
          * \brief setI
          * Méthode modifiant la valeur de l'attribut _i de la classe
          * \param  i : nouvel valeur de _i
          */
        void setI(const Constante& i);

        /*!
          * \brief toString
          * Methode permettant de transformer le complexe manipulé en une chaine de caractère
          * \return string
          */
        std::string toString()const{
            std::stringstream ss;
            ss<<_r->toString()<<"$"<<_i->toString();
            return ss.str();
        }

        /*!
          * \brief affiche
          * Methode permettant un affichage du complexe manipulé
          * \param os
          */
        void affiche(std::ostream & os = std::cout) const;

        /*!
          * \brief operator+
          * Methode retournant la somme du complexe manipulé avec la constante passé en argument
          * \param c
          * \return Constante*
          */
        Constante * operator+(const Constante & c) const;

        /*!
          * \brief operator-
          * Methode retournant la différence du complexe manipulé avec la constante passé en argument
          * \param c
          * \return Constante*
          */
        Constante * operator-(const Constante & c) const;

        /*!
          * \brief operator*
          * Methode retournant le produit du complexe manipulé avec la constante passé en argument
          * \param c
          * \return Constante*
          */
        Constante * operator*(const Constante & c) const;

        /*!
          * \brief operator/
          * Methode retournant la division du complexe manipulé avec la constante passé en argument
          * \param c
          * \return Constante*
          */
        Constante * operator/(const Constante & c) const;

        /*!
          * \brief operator-
          * Methode retournant le contraire du complexe manipulé
          * \return Constante*
          */
        Constante * operator-()const;

        /*!
          * \brief operator==
          * Methode vérifiant si le complexe manipulé est égal à la constante passé en argument
          * \param c
          * \return true si il y a égalité, false sinon
          */
        bool operator==(const Constante & c) const;

        /*!
          * \brief operator<
          * Methode vérifiant si le complexe manipulé est inférieur à la constante passé en argument
          * \param c
          * \return true si la constante manipulé est inférieur, false sinon
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
