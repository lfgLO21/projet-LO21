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
<<<<<<< HEAD
    void affiche(std::ostream & os = cout) const;
    std::string toString() const;
=======
    void affiche(std::ostream & os = std::cout) const;
>>>>>>> 08b20c2ec3a1d0678a2b42af2692d11c0b27c436

    //operateur
    Constante * operator+(const Constante & r) const;
    Constante * operator-(const Constante & r) const;
    Constante * operator*(const Constante & r) const;
    Constante * operator/(const Constante & r) const;
    Constante * operator-()const;
    
    bool operator==(const Constante & c) const;
    bool operator<(const Constante & c) const;
    
};

#endif // REEL_H
