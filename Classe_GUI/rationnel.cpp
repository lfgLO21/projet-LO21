#include "rationnel.h"

Rationnel::Rationnel(int n, int d):Constante(RATIONNEL)
{
    if(d==0)
    {
        throw Rationnel_exception("erreur:denominateur nul");
    }
    this->_numerateur=n;
    this->_denominateur=d;
    this->simplification();
}

Rationnel::Rationnel(const Entier &e):Constante(RATIONNEL)
{
    this->_numerateur=e.getEntier();
    this->_denominateur=1;
}

Rationnel::Rationnel(const Entier &n, const Entier &d):Constante(RATIONNEL)
{
    if(d.getEntier()==0)
    {
        throw Rationnel_exception("erreur:denominateur nul");
    }
    this->_numerateur=n.getEntier();
    this->_denominateur=d.getEntier();
}

Rationnel::Rationnel(const Rationnel &r):Constante(RATIONNEL)
{
    this->_numerateur=r.getNumerateur();
    this->_denominateur=r.getDenominateur();
}

/////////
///Get///
/////////

int Rationnel::getDenominateur()const
{
    return this->_denominateur;
}

int Rationnel::getNumerateur()const
{
    return this->_numerateur;
}

/////////
///Set///
/////////

void Rationnel::setDenominateur(int d)
{
    this->_denominateur=d;
}

void Rationnel::setNumerateur(int n)
{
    this->_numerateur=n;
}

/////////////
///Methode///
/////////////

void Rationnel::affiche(std::ostream & os)const
{
    os<<this->_numerateur<<"/"<<_denominateur;
}

void Rationnel::simplification()
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

///////////////
///Operateur///
///////////////
Constante * Rationnel::operator+(Constante const & c) const
{
    switch(c.getType()){
            case Constante::ENTIER:
    return *this+Rationnel(static_cast<const Entier& >(c));
            break;
            case Constante::RATIONNEL:
    return new Rationnel(this->_numerateur*static_cast<const Rationnel&>(c)._denominateur+static_cast<const Rationnel&>(c)._numerateur*this->_denominateur,
                    this->_denominateur*static_cast<const Rationnel&>(c)._denominateur);
            break;
    }
}

Constante * Rationnel::operator-(Constante const & c) const
{
    switch(c.getType()){
            case Constante::ENTIER:
    return *this-Rationnel(static_cast<const Entier& >(c));
            break;
            case Constante::RATIONNEL:
    return new Rationnel(this->_numerateur*
                         static_cast<const Rationnel&>(c)._denominateur-
                         static_cast<const Rationnel&>(c)._numerateur*
                         this->_denominateur,
                    this->_denominateur*
                         static_cast<const Rationnel&>(c)._denominateur);
            break;
    }
}

Constante * Rationnel::operator*(Constante const & c) const
{
    switch(c.getType()){
            case Constante::ENTIER:
    return *this*Rationnel(static_cast<const Entier& >(c));
            break;
            case Constante::RATIONNEL:
    return new Rationnel(this->_numerateur*
                         static_cast<const Rationnel&>(c)._numerateur,
                    this->_denominateur*
                         static_cast<const Rationnel&>(c)._denominateur);
            break;
    }
}

Constante * Rationnel::operator/(Constante const & c) const
{
    switch(c.getType()){
            case Constante::ENTIER:
    return *this/Rationnel(static_cast<const Entier& >(c));
            break;
            case Constante::RATIONNEL:
    return new Rationnel(this->_numerateur*
                         static_cast<const Rationnel&>(c)._denominateur,
                    this->_denominateur*
                         static_cast<const Rationnel&>(c)._numerateur);
            break;

    }
}


Constante* Rationnel::operator-()const{
        return new Rationnel(-this->_numerateur,this->_denominateur);
}
