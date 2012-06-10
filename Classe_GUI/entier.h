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
<<<<<<< HEAD
    std::string toString() const;
    void affiche(std::ostream & os)const;
=======
    void affiche(std::ostream & os = std::cout) const;
>>>>>>> 08b20c2ec3a1d0678a2b42af2692d11c0b27c436

    Constante * operator+(const Constante & c) const;
    Constante * operator-(const Constante & c) const;
    Constante * operator*(const Constante & c) const;
    Constante * operator/(const Constante & c) const;
    Constante * operator-() const;
    
    bool operator==(const Constante & c) const;
    bool operator<(const Constante & c) const;
    
    Constante * operator%(const Constante& c) const;
    Constante * operator!()const;
};

#endif // Entier_H
