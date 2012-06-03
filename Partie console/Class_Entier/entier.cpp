#include "entier.h"

entier::entier(const entier& e)
{
    _entier=e.getEntier();
}

/////////
///Get///
/////////

int entier::getEntier()const
{
    return _entier;
}

/////////
///Set///
/////////

void entier::setEntier(int e)
{
    _entier=e;
}

/////////////
///Méthode///
/////////////

void entier::affiche()const
{
    std::cout<<_entier<<std::endl;
}

//////////////
///operator///
//////////////

entier& entier::operator +=(entier const& e)
{
    _entier+=e.getEntier();
    return *this;
}

entier& entier::operator -=(entier const& e)
{
    _entier-=e.getEntier();
    return *this;
}

entier& entier::operator *=(entier const& e)
{
    _entier*=e.getEntier();
    return *this;
}

entier& entier::operator /=(entier const& e)
{
    _entier/=e.getEntier();
    return *this;
}

entier operator+(entier const& a, entier const& b)
{
    entier c(a);
    c+=b;
    return c;
}

entier operator-(entier const& a, entier const& b)
{
    entier c(a);
    c-=b;
    return c;
}

entier operator*(entier const& a, entier const& b)
{
    entier c(a);
    c*=b;
    return c;
}

entier operator/(entier const& a, entier const& b)
{
    entier c(a);
    c/=b;
    return c;
}

///////////////
///Puissance///
///////////////
entier POW(entier const& a, int x)
{
    entier tmp=pow(a.getEntier(),x);
    return tmp;
}

////////////
///Modulo///
////////////
entier& entier::MOD(entier const& e)
{
    _entier%=e.getEntier();
    return *this;
}

entier MOD(entier const& a, entier const& b)
{
    entier c(a);
    c.MOD(b);
    return c;
}

//////////
///SIGN///
//////////
void entier::SIGN()
{
    _entier*=-1;
}

entier SIGN(entier const& a)
{
    entier tmp=a.getEntier();
    tmp.SIGN();;
    return tmp;
}

/////////////////
///sin,cos,tan///
/////////////////

float SIN(entier const& a)
{
    int b = a.getEntier();
    float c=(float)b;
    float tmp=sin(c);
    return tmp;
}

float COS(entier const& a)
{
    int b = a.getEntier();
    float c=(float)b;
    float tmp=cos(c);
    return tmp;
}

float TAN(entier const& a)
{
    int b = a.getEntier();
    float c=(float)b;
    float tmp=tan(c);
    return tmp;
}

////////////////////
///sinh,cosh,tanh///
////////////////////

float SINH(entier const& a)
{
    int b = a.getEntier();
    float c=(float)b;
    float tmp=sinh(c);
    return tmp;
}

float COSH(entier const& a)
{
    int b = a.getEntier();
    float c=(float)b;
    float tmp=cosh(c);
    return tmp;
}

float TANH(entier const& a)
{
    int b = a.getEntier();
    float c=(float)b;
    float tmp=tanh(c);
    return tmp;
}

////////////
///ln,log///
////////////

float LN(entier const& a)
{
    int b = a.getEntier();
    float c=(float)b;
    float tmp=log(c);
    return tmp;
}

float LOG(entier const& a)
{
    int b = a.getEntier();
    float c=(float)b;
    float tmp=log10(c);
    return tmp;
}

////////////////////
///inv,sqrt,^2,^3///
////////////////////

/*Fraction INV(entier const& a)
{
    Fraction tmp(1,a.getEntier());
    return tmp;
}*/

float SQRT(entier const& a)
{
    int b = a.getEntier();
    float tmp=sqrt(b);
    return tmp;
}

entier SQR(entier const& a)
{
    entier tmp(a.getEntier()*a.getEntier());
    return tmp;
}

entier CUBE(entier const& a)
{
    entier tmp(a.getEntier()*a.getEntier()*a.getEntier());
    return tmp;
}

/////////////////
///factorielle///
/////////////////
entier fact(entier const& a)
{
    int tmp(a.getEntier()), tmp2(1);
    while(tmp > 1) tmp2*=tmp--;
    entier r(tmp2);
    return r;
}
