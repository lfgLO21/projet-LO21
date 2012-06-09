#include "reel.h"

Reel::Reel(float r)
{
    this->_reel = r;
    this->_type = Constante::REEL;
}

Reel::Reel(const Entier& e)
{
    this->_reel = e.getEntier();
    this->_type = Constante::REEL;
}

Reel::Reel(const Rationnel &r):Constante(REEL)
{
    float n=(float)r.getNumerateur();
    float d=(float)r.getDenominateur();
    this->_reel=n/d;
}

Reel::Reel(const Reel& r)
{
    this->_reel = r.getReel();
    this->_type = Constante::REEL;
}

/////////
///Get///
/////////

float Reel::getReel()const
{
    return this->_reel;
}

/////////
///Set///
/////////

void Reel::setReel(float r)
{
    this->_reel = r;
}

/////////////
///Methode///
/////////////

void Reel::affiche(std::ostream & os) const
{
    os<<this->_reel;
}

std::string Reel::toString() const
{
}

Constante * Reel::operator+(const Constante & r) const
{
    //verifie l'enum herite de Constante pour connaitre le type de l'objet avec lequel le
    //reel est additionne.
    switch (r.getType())
    {
        case Constante::ENTIER:
        {
            return *this + Reel(static_cast<const Entier&>(r));
            break;
        }
        case Constante::RATIONNEL:
        {
            return *this + Reel(static_cast<const Rationnel&>(r));
            break;
        }
        case Constante::REEL:
        {
            return new Reel(this->_reel + static_cast<const Reel&>(r)._reel);
            break;
        }
        default:
        {
            throw std::domain_error("Type non existant");
        }
    }
}

Constante * Reel::operator-(const Constante & r) const
{
    switch (r.getType())
    {
        case Constante::ENTIER:
        {
            return *this - Reel(static_cast<const Entier&>(r));
            break;
        }
        case Constante::RATIONNEL:
        {
            return *this - Reel(static_cast<const Rationnel&>(r));
            break;
        }
        case Constante::REEL:
        {
            return new Reel(this->_reel - static_cast<const Reel&>(r)._reel);
            break;
        }
        default:
        {
            throw std::domain_error("Type non existant");
        }
    }
}

Constante * Reel::operator*(const Constante & r) const
{
    switch (r.getType())
    {
        case Constante::ENTIER:
        {
            return *this * Reel(static_cast<const Entier&>(r));
            break;
        }
        case Constante::RATIONNEL:
        {
            return *this * Reel(static_cast<const Rationnel&>(r));
            break;
        }
        case Constante::REEL:
        {
            return new Reel(this->_reel * static_cast<const Reel&>(r)._reel);
            break;
        }
        default:
        {
            throw std::domain_error("Type non existant");
        }
    }
}

Constante * Reel::operator/(const Constante & r) const
{
    switch (r.getType())
    {
        case Constante::ENTIER:
        {
            return *this / Reel(static_cast<const Entier&>(r));
            break;
        }
        case Constante::RATIONNEL:
        {
            return *this / Reel(static_cast<const Rationnel&>(r));
            break;
        }
        case Constante::REEL:
        {
            return new Reel(this->_reel / static_cast<const Reel&>(r)._reel);
            break;
        }
        default:
        {
            throw std::domain_error("Type non existant");
        }
    }
}

<<<<<<< HEAD
Constante * Reel::SIGN()const
{
    if(this->_type == Constante::REEL)
    {
        return new Reel(-1*this->_reel);
    }
    else
    {
        return new Reel(1);
    }
=======
Constante* Reel::operator-()const{
        return new Reel(-this->_reel);
>>>>>>> 08b20c2ec3a1d0678a2b42af2692d11c0b27c436
}
