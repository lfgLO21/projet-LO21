#include "entier.h"

Entier::Entier(int d):Constante(ENTIER)
{
    this->_entier = d;
    this->_type = ENTIER;
}

Entier::Entier(const Entier& e):Constante(ENTIER)
{
    this->_entier=e.getEntier();
    this->_type = ENTIER;
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

std::ostream & operator<<(std::ostream & os, const Entier & c)
{
    c.affiche(os);
    return(os);
}

//////////////
///operator///
//////////////

Constante * Entier::operator+(Constante const & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return new Entier(this->_entier + static_cast<const Entier&>(c)._entier);
        break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c)._expression+this->toString()+"+'");
        break;
    }
}

Constante * Entier::operator-(Constante const & c) const
{
    switch(c.getType()){
            case Constante::ENTIER:
    return new Entier(this->_entier - static_cast<const Entier&>(c)._entier);
            break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c)._expression+this->toString()+"-'");
        break;
    }
}

Constante * Entier::operator*(Constante const & c) const
{
    switch(c.getType()){
            case Constante::ENTIER:
    return new Entier(this->_entier * static_cast<const Entier&>(c)._entier);
            break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c)._expression+this->toString()+"*'");
        break;
    }
}

Constante * Entier::operator/(Constante const& c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return new Entier(this->_entier / static_cast<const Entier&>(c)._entier);
        break;
    case Constante::EXPRESSION:
        return new Expression("'"+static_cast<const Expression&>(c)._expression+this->toString()+"/'");
        break;
    }
}


Constante* Entier::operator%(const Constante& c)const{
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
