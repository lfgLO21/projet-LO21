#include "reel.h"

Reel::Reel(float r):Constante(REEL)
{
    this->_reel = r;
}

Reel::Reel(const Entier& e):Constante(REEL)
{
    this->_reel = e.getEntier();
}

Reel::Reel(const Rationnel &r):Constante(REEL)
{
    float n=(float)r.getNumerateur();
    float d=(float)r.getDenominateur();
    this->_reel=n/d;
}

Reel::Reel(const Reel& r):Constante(REEL)
{
    this->_reel = r.getReel();
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

std::ostream & operator<<(std::ostream & os, const Reel & c)
{
    c.affiche(os);
    return(os);
}

Constante * Reel::operator+(const Constante & r) const
{
    //verifie l'enum herite de Constante pour connaitre le type de l'objet avec lequel le
    //reel est additionne.
    switch (r.getType())
    {
    case Constante::ENTIER:
    {
        return *this+Reel(static_cast<const Entier&>(r));
        break;
    }
    case Constante::RATIONNEL:
    {
        return *this+Reel(static_cast<const Rationnel&>(r));
        break;
    }
    case Constante::REEL:
    {
        return new Reel(this->_reel + static_cast<const Reel&>(r)._reel);
        break;
    }
    case Constante::EXPRESSION:
    {
        return new Expression("'"+static_cast<const Expression&>(r).getExpression()+this->toString()+"+'");
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
        return *this-Reel(static_cast<const Entier&>(r));
        break;
    }
    case Constante::RATIONNEL:
    {
        return *this-Reel(static_cast<const Rationnel&>(r));
        break;
    }
    case Constante::REEL:
    {
        return new Reel(this->_reel - static_cast<const Reel&>(r)._reel);
        break;
    }
    case Constante::EXPRESSION:
    {
        return new Expression("'"+static_cast<const Expression&>(r).getExpression()+this->toString()+"-'");
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
        return *this*Reel(static_cast<const Entier&>(r));
        break;
    }
    case Constante::RATIONNEL:
    {
        return *this*Reel(static_cast<const Rationnel&>(r));
        break;
    }
    case Constante::REEL:
    {
        return new Reel(this->_reel * static_cast<const Reel&>(r)._reel);
        break;
    }
    case Constante::EXPRESSION:
    {
        return new Expression("'"+static_cast<const Expression&>(r).getExpression()+this->toString()+"*'");
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
        return *this/Reel(static_cast<const Entier&>(r));
        break;
    }
    case Constante::RATIONNEL:
    {
        return *this/Reel(static_cast<const Rationnel&>(r));
        break;
    }
    case Constante::REEL:
    {
        return new Reel(this->_reel / static_cast<const Reel&>(r)._reel);
        break;
    }
    case Constante::EXPRESSION:
    {
        return new Expression("'"+static_cast<const Expression&>(r).getExpression()+this->toString()+"/'");
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

bool Reel::operator==(const Constante & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
    {
        if(this->_reel == static_cast<const Entier&>(c).getEntier())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case Constante::RATIONNEL:
    {
        float tmp = (float)static_cast<const Rationnel&>(c).getNumerateur()/(float)static_cast<const Rationnel&>(c).getDenominateur();
        if(this->_reel == tmp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case Constante::REEL:
    {
        if(this->_reel == static_cast<const Reel&>(c)._reel)
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

bool Reel::operator<(const Constante & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
    {
        if(this->_reel < static_cast<const Entier&>(c).getEntier())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case Constante::RATIONNEL:
    {
        float tmp = (float)static_cast<const Rationnel&>(c).getNumerateur()/(float)static_cast<const Rationnel&>(c).getDenominateur();
        if(this->_reel < tmp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case Constante::REEL:
    {
        if(this->_reel < static_cast<const Reel&>(c)._reel)
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
