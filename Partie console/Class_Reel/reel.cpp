#include "reel.h"

reel::reel(const reel& r)
{
    _reel=r.getReel();
}

/////////
///Get///
/////////

float reel::getReel()const
{
    return _reel;
}

/////////
///Set///
/////////

void reel::setReel(float r)
{
    _reel=r;
}

/////////////
///Méthode///
/////////////

void reel::affiche()const
{
    std::cout<<_reel<<std::endl;
}

//////////////
///operator///
//////////////

reel& reel::operator+=(reel const& r)
{
    _reel+=r.getReel();
    return *this;
}

reel& reel::operator-=(reel const& r)
{
    _reel-=r.getReel();
    return *this;
}

reel& reel::operator*=(reel const& r)
{
    _reel*=r.getReel();
    return *this;
}

reel& reel::operator/=(reel const& r)
{
    _reel/=r.getReel();
    return *this;
}

reel operator+(reel const& a, reel const& b)
{
    reel c(a);
    c+=b;
    return c;
}

reel operator-(reel const& a, reel const& b)
{
    reel c(a);
    c-=b;
    return c;
}

reel operator*(reel const& a, reel const& b)
{
    reel c(a);
    c*=b;
    return c;
}

reel operator/(reel const& a, reel const& b)
{
    reel c(a);
    c/=b;
    return c;
}

///////////////
///Puissance///
///////////////
reel POW(reel const& a, int x)
{
    reel tmp=pow(a.getReel(),x);
    return tmp;
}

//////////
///SIGN///
//////////
void reel::SIGN()
{
    _reel*=-1;
}

reel SIGN(reel const& a)
{
    reel tmp=a.getReel();
    tmp.SIGN();;
    return tmp;
}

/////////////////
///sin,cos,tan///
/////////////////

reel SIN(reel const& a)
{
    float b = a.getReel();
    reel tmp(sin(b));
    return tmp;
}

reel COS(reel const& a)
{
    float b = a.getReel();
    reel tmp(cos(b));
    return tmp;
}

reel TAN(reel const& a)
{
    float b = a.getReel();
    reel tmp(tan(b));
    return tmp;
}

////////////////////
///sinh,cosh,tanh///
////////////////////

reel SINH(reel const& a)
{
    float b = a.getReel();
    reel tmp(sinh(b));
    return tmp;
}

reel COSH(reel const& a)
{
    float b = a.getReel();
    reel tmp(cosh(b));
    return tmp;
}

reel TANH(reel const& a)
{
    float b = a.getReel();
    reel tmp(tanh(b));
    return tmp;
}

////////////
///ln,log///
////////////

reel LN(reel const& a)
{
    float b = a.getReel();
    reel tmp(log(b));
    return tmp;
}

reel LOG(reel const& a)
{
    float b = a.getReel();
    reel tmp(log10(b));
    return tmp;
}

////////////////////
///inv,sqrt,^2,^3///
////////////////////

/*reel INV(reel const& a)
{
    reel tmp(1/(a.getReel()));
    return tmp;
}*/

reel SQRT(reel const& a)
{
    int b = a.getReel();
    reel tmp(sqrt(b));
    return tmp;
}

reel SQR(reel const& a)
{
    reel tmp(a.getReel()*a.getReel());
    return tmp;
}

reel CUBE(reel const& a)
{
    reel tmp(a.getReel()*a.getReel()*a.getReel());
    return tmp;
}
