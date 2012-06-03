#ifndef REEL_H
#define REEL_H

#include <iostream>
#include <string>
#include <cmath>

class reel
{
    float _reel;

public:
    reel(float d=0):_reel(d){}
    reel(const reel& e);

    //get
    float getReel()const;

    //set
    void setReel(float e);

    //affiche
    void affiche()const;

    reel& operator+=(const reel& e);
    reel& operator-=(const reel& e);
    reel& operator*=(const reel& e);
    reel& operator/=(const reel& e);

    //SIGN
    void SIGN();
};
//operateur
reel operator+(reel const& a, reel const& b);
reel operator-(reel const& a, reel const& b);
reel operator*(reel const& a, reel const& b);
reel operator/(reel const& a, reel const& b);

//puissance
reel POW(reel const& a, int x);

//sign
reel SIGN(reel const& a);

//cos
reel COS(reel const& a);

//tan
reel TAN(reel const& a);

//sinh
reel SINH(reel const& a);

//cosh
reel COSH(reel const& a);

//tanh
reel TANH(reel const& a);

//ln
reel LN(reel const& a);

//LOG
reel LOG(reel const& a);

//inverse
//reel INV(reel const& a);

//racine carré
reel SQRT(reel const& a);

//fonction carré
reel SQR(reel const& a);

//fonction cube
reel CUBE(reel const& a);

#endif // REEL_H
