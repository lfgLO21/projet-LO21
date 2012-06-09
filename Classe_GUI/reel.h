#ifndef REEL_H
#define REEL_H

#include <exception>
#include "constante.h"
#include "entier.h"

class Reel : public Constante
{
    float _reel;

public:
    Reel(float r = 0);

    Reel(const Entier & e);
    Reel(const Reel & e);

    //get
    float getReel() const;

    //set
    void setReel(float r);

    //affiche
    void affiche(std::ostream & os = std::cout) const;

    //operateur
    Constante * operator+(const Constante & r) const;
    Constante * operator-(const Constante & r) const;
    Constante * operator*(const Constante & r) const;
    Constante * operator/(const Constante & r) const;

    Constante * operator-()const;
};

#endif // REEL_H
