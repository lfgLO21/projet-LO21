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

CConstante* Entier::operator%(const Constante& c)const{
   switch(c.getType()){
       case Constante::ENTIER:
        return new Entier(_entier % static_cast<const Entier&>(c)._entier);
   }
}
Constante* Entier::operator!()const{
    int tmp=1;
    for(int i=0;i<_entier-1;i++)
        tmp*=_entier-i;
    return new Entier(tmp);
}

Constante* Entier::operator-()const{
        return new Entier(-this->_entier);
}
}

bool Entier::operator==(const Constante & c) const
{
    switch(c.getType()){
        case Constante::ENTIER:
        {
            if(this->_entier == static_cast<const Entier&>(c)._entier)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool Entier::operator<(const Constante & c) const
{
    switch(c.getType()){
        case Constante::ENTIER:
        {
            if(this->_entier < static_cast<const Entier&>(c)._entier)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}