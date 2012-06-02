#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <cmath>

class Fraction_exception
{
    std::string info;

public:
    Fraction_exception(const std::string& s):info(s){}
    const std::string& getInfo()const{return info;}
};


class Fraction
{
    int _numerateur;
    int _denominateur;

    //méthode privée
    void simplification();

public:
    //constructeur
    Fraction(int n=0, int d=1):_numerateur(n),_denominateur(d){
        if (d==0)throw Fraction_exception("numerateur nul");
        else simplification();}
    Fraction(const Fraction& a);

    //destructeur
    ~Fraction();

    //get
    int getNumerateur()const;
    int getDenominateur()const;

    //set
    void setNumerateur(int n);
    void setDenominateur(int d);

    //méthode
    void affiche()const;


    Fraction& operator+=(const Fraction& a);
    Fraction& operator-=(const Fraction& a);
    Fraction& operator *=(const Fraction& a);
    Fraction& operator /=(const Fraction& a);

    void SIGN();

};
//operateur
Fraction operator+(Fraction const& a, Fraction const& b);
Fraction operator-(Fraction const& a, Fraction const& b);
Fraction operator*(Fraction const& a, Fraction const& b);
Fraction operator/(Fraction const& a, Fraction const& b);

//puissance
Fraction POW(Fraction const& a, int x);

//signe
Fraction SIGN(Fraction const& a);

//sin
float SIN(Fraction const& a);

//cos
float COS(Fraction const& a);

//tan
float TAN(Fraction const& a);

//sinh
float SINH(Fraction const& a);

//cosh
float COSH(Fraction const& a);

//tanh
float TANH(Fraction const& a);

//ln
float LN(Fraction const& a);

//LOG
float LOG(Fraction const& a);

//inverse
Fraction INV(Fraction const& a);

//racine carré
float SQRT(Fraction const& a);

//fonction carré
Fraction SQR(Fraction const& a);

//fonction cube
Fraction CUBE(Fraction const& a);

#endif // FRACTION_H
