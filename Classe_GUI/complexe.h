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

class Complexe : public Constante
{
    private:
        Constante*_r;
        Constante*_i;

    public:
        Complexe();
        Complexe(const Complexe & c);
        Complexe(const Constante& c);
        Complexe(const Constante* r, const Constante* i);
        ~Complexe();

        Constante* getR() const;
        Constante* getI() const;

        void setR(const Constante& r);
        void setI(const Constante& i);

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
