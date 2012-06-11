#ifndef REEL_H
#define REEL_H

#include <exception>
#include "constante.h"
#include "expression.h"
#include "rationnel.h"

class Reel : public Constante
{
    float _reel;

public:
    Reel(float r = 0);
    Reel(const Entier& e);
    Reel(const Rationnel& r);
    Reel(const Reel& e);

    //get
    float getReel() const;

    //set
    void setReel(float r);

    std::string& toString()const{
        std::stringstream ss;
        ss << _reel;
        return ss.str();
    }

    //affiche
    void affiche(std::ostream & os = std::cout) const;

    //operateur
    Constante * operator+(const Constante & r) const;
    Constante * operator-(const Constante & r) const;
    Constante * operator*(const Constante & r) const;
    Constante * operator/(const Constante & r) const;
    Constante * operator-()const;

    bool operator==(const Constante & c) const;
    bool operator<(const Constante & c) const;

};

std::ostream & operator<<(std::ostream & os, const Reel & c);

#endif // REEL_H
