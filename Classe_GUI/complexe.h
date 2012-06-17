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
          * \param d : valeur de l'attribut _entier
          */
        Complexe(const Constante& c);
        Complexe(const Constante* r, const Constante* i);
        ~Complexe();

        Constante* getR() const;
        Constante* getI() const;

        void setR(const Constante& r);
        void setI(const Constante& i);

        std::string toString()const{
            std::stringstream ss;
            ss<<_r->toString()<<"$"<<_i->toString();
            return ss.str();
        }

        void affiche(std::ostream & os = std::cout) const;

        Constante * operator+(const Constante & c) const;
        Constante * operator-(const Constante & c) const;
        Constante * operator*(const Constante & c) const;
        Constante * operator/(const Constante & c) const;
        Constante * operator-()const;

        bool operator==(const Constante & c) const;
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
