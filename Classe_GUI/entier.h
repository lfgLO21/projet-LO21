#ifndef Entier_H
#define Entier_H

#include "constante.h"
#include <string>
#include <sstream>

class Rationnel;

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
    void affiche(std::ostream & os = std::cout) const;

    Constante * operator+(const Constante & c) const;
    Constante * operator-(const Constante & c) const;
    Constante * operator*(const Constante & c) const;
    Constante * operator/(const Constante & c) const;
    Constante * operator-()const;

    bool operator==(const Constante & c) const;
    bool operator<(const Constante & c) const;

    Constante* operator%(const Constante& c)const;
    Constante* operator!()const;
};

std::ostream & operator<<(std::ostream & os, const Entier & c);

#endif // Entier_H
