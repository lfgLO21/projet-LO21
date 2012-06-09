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
///Mthode///
/////////////

void Reel::affiche(std::ostream & os) const
{
    os<<this->_reel;
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

Constante* Reel::operator-()const{
        return new Reel(-this->_reel);
}
