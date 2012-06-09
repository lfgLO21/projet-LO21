#ifndef Entier_H
#define Entier_H

#include <iostream>
#include <string>
#include <cmath>

#include "constante.h"

class Entier : public Constante
{
    int _entier;

public:
    Entier(int d=0);
    Entier(const Entier& e);

    //get
    int getEntier()const;

    //set
    void setEntier(int e);

    //affiche
    void affiche(std::ostream & os = cout) const;

    Constante * operator+(const Constante & c) const;
    Constante * operator-(const Constante & c) const;
    Constante * operator*(const Constante & c) const;
    Constante * operator/(const Constante & c) const;
};

#endif // Entier_H
