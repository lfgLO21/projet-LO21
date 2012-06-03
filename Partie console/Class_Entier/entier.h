#ifndef ENTIER_H
#define ENTIER_H

#include <iostream>
#include <string>
#include <cmath>

class entier
{
    int _entier;

public:
    entier(int d=0):_entier(d){}
    entier(const entier& e);

    //get
    int getEntier()const;

    //set
    void setEntier(int e);

    //affiche
    void affiche()const;

    entier& operator+=(const entier& e);
    entier& operator-=(const entier& e);
    entier& operator*=(const entier& e);
    entier& operator/=(const entier& e);
    entier& MOD(entier const& e);

    //SIGN
    void SIGN();
};
//operateur
entier operator+(entier const& a, entier const& b);
entier operator-(entier const& a, entier const& b);
entier operator*(entier const& a, entier const& b);
entier operator/(entier const& a, entier const& b);

//puissance
entier POW(entier const& a, int x);

//modulo
entier MOD(entier const& a, entier const& b);

//sign
entier SIGN(entier const& a);

//cos
float COS(entier const& a);

//tan
float TAN(entier const& a);

//sinh
float SINH(entier const& a);

//cosh
float COSH(entier const& a);

//tanh
float TANH(entier const& a);

//ln
float LN(entier const& a);

//LOG
float LOG(entier const& a);

//inverse
//Fraction INV(entier const& a);

//racine carré
float SQRT(entier const& a);

//fonction carré
entier SQR(entier const& a);

//fonction cube
entier CUBE(entier const& a);

//factorielle
entier fact(entier const& a);

#endif // ENTIER_H
