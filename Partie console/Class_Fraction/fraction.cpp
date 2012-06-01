#include "fraction.h"

Fraction::Fraction(const Fraction& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    _numerateur=n;
    _denominateur=d;
}

Fraction::~Fraction()
{

}

/////////
///Get///
/////////

int Fraction::getDenominateur()const
{
    return _denominateur;
}

int Fraction::getNumerateur()const
{
    return _numerateur;
}

/////////
///Set///
/////////

void Fraction::setNumerateur(int n)
{
    _numerateur=n;
}

void Fraction::setDenominateur(int d)
{
    _denominateur=d;
}

/////////////
///Méthode///
/////////////

void Fraction::affiche()const
{
    std::cout << getNumerateur() << "/" << getDenominateur() << std::endl;
}

void Fraction::simplification()
{
    if (_denominateur < 0)
    {
        _denominateur = -_denominateur;
        _numerateur = -_numerateur;
    }
    int diviseur = _denominateur;
    while (diviseur != 1)
    {
        if(_numerateur%diviseur == 0 && _denominateur%diviseur == 0)
        {
            _numerateur /= diviseur;
            _denominateur /=diviseur;
        }
        diviseur--;
    }
}

//////////////
///operator///
//////////////

Fraction& Fraction::operator+=(Fraction const& a)
{
    int d=_denominateur;
    _numerateur*=a.getDenominateur();
    d*=a.getNumerateur();
    _numerateur+=d;
    _denominateur*=a.getDenominateur();
    simplification();
    return *this;
}

Fraction& Fraction::operator-=(Fraction const& a)
{
    int d=_denominateur;
    _numerateur*=a.getDenominateur();
    d*=a.getNumerateur();
    _numerateur-=d;
    _denominateur*=a.getDenominateur();
    simplification();
    return *this;
}

Fraction& Fraction::operator*=(Fraction const& a)
{
    _numerateur*=a.getNumerateur();
    _denominateur*=a.getDenominateur();
    simplification();
    return *this;
}

Fraction& Fraction::operator/=(Fraction const& a)
{
    _numerateur*=a.getDenominateur();
    _denominateur*=a.getNumerateur();
    simplification();
    return *this;
}

Fraction operator+(Fraction const& a, Fraction const& b)
{
    Fraction c(a);
    c+=b;
    return c;
}


Fraction operator-(Fraction const& a, Fraction const& b)
{
    Fraction c(a);
    c-=b;
    return c;
}

Fraction operator*(Fraction const& a, Fraction const& b)
{
    Fraction c(a);
    c*=b;
    return c;
}

Fraction operator/(Fraction const& a, Fraction const& b)
{
    Fraction c(a);
    c/=b;
    return c;
}

///////////////
///puissance///
///////////////
Fraction POW(Fraction const& a, int x)
{
    int n=pow(a.getNumerateur(),x);
    int d=pow(a.getDenominateur(),x);
    Fraction tmp(n,d);
    return tmp;

}

///////////
///signe///
///////////
void Fraction::SIGN()
{
    _numerateur*=-1;
}

Fraction SIGN(Fraction const& a)
{
    Fraction tmp(-a.getNumerateur(),a.getDenominateur());
    return tmp;
}

/////////////////
///sin,cos,tan///
/////////////////

float SIN(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=sin(b);
    return tmp;
}

float COS(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=cos(b);
    return tmp;
}

float TAN(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=tan(b);
    return tmp;
}

////////////////////
///sinh,cosh,tanh///
////////////////////

float SINH(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=sinh(b);
    return tmp;
}

float COSH(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=cosh(b);
    return tmp;
}

float TANH(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=tanh(b);
    return tmp;
}

////////////
///ln,log///
////////////

float LN(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=log(b);
    return tmp;
}

float LOG(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=log10(b);
    return tmp;
}

////////////////////
///inv,sqrt,^2,^3///
////////////////////

Fraction INV(Fraction const& a)
{
    Fraction tmp(a.getDenominateur(),a.getNumerateur());
    return tmp;
}

float SQRT(Fraction const& a)
{
    int n=a.getNumerateur();
    int d=a.getDenominateur();
    float b=(float)n/d;
    float tmp=sqrt(b);
    return tmp;
}

Fraction SQR(Fraction const& a)
{
    Fraction tmp(a.getNumerateur()*a.getNumerateur(),a.getDenominateur()*a.getDenominateur());
    return tmp;
}

Fraction CUBE(Fraction const& a)
{
    Fraction tmp(a.getNumerateur()*a.getNumerateur()*a.getNumerateur(),a.getDenominateur()*a.getDenominateur()*a.getDenominateur());
    return tmp;
}
