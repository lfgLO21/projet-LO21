#include "entier.h"

Entier::Entier(int d)
{
    this->_entier = d;
    this->_type = Constante::ENTIER;
}

Entier::Entier(const Entier& e)
{
    this->_entier=e.getEntier();
    this->_type = Constante::ENTIER;
}

/////////
///Get///
/////////

int Entier::getEntier()const
{
    return this->_entier;
}

/////////
///Set///
/////////

void Entier::setEntier(int e)
{
    this->_entier=e;
}

/////////////
///Methode///
////////////

void Entier::affiche(std::ostream & os)const
{
    os<<this->_entier;
}

std::string Entier::toString() const
{

}

//////////////
///operator///
//////////////

Constante * Entier::operator+(Constante const & c) const
{
    if(c.getType() == Constante::ENTIER)
    {
        return new Entier(this->_entier + (static_cast<const Entier&>(c)._entier));
    }
    else
    {
        throw std::domain_error("Type non existant");
    }
}

Constante * Entier::operator-(Constante const & c) const
{
    if(c.getType() == Constante::ENTIER)
    {
        return new Entier(this->_entier - (static_cast<const Entier&>(c)._entier));
    }
    else
    {
        throw std::domain_error("Type non existant");
    }
}

Constante * Entier::operator*(Constante const & c) const
{
    if(c.getType() == Constante::ENTIER)
    {
        return new Entier(this->_entier * (static_cast<const Entier&>(c)._entier));
    }
    else
    {
        throw std::domain_error("Type non existant");
    }
}

Constante * Entier::operator/(Constante const& c) const
{
    if(c.getType() == Constante::ENTIER)
    {
        return new Entier(this->_entier / (static_cast<const Entier&>(c)._entier));
    }
    else
    {
        throw std::domain_error("Type non existant");
    }
}

Constante * Entier::SIGN() const
{
    if(this->_type == Constante::ENTIER)
    {
        return new Entier(-1*this->_entier);
    }
    else
    {
        return new Entier(1);
    }
}
