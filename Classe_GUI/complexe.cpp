#include "complexe.h"

Complexe::Complexe() : Constante(COMPLEXE)
{
        this->_r = new Entier(0);
        this->_i = new Entier(1);
}

Complexe::Complexe(const Complexe& c):Constante(COMPLEXE)
{
    switch(c._r->getType()){
             case Constante::ENTIER:
     this->_r = new Entier(*static_cast<Entier*>(c._r));
             break;
             case Constante::RATIONNEL:
     this->_r = new Rationnel(*static_cast<Rationnel*>(c._r));
             break;
             case Constante::REEL:
     this->_r = new Reel(*static_cast<const Reel*>(c._r));
             break;
     }

     switch(c._i->getType()){
             case Constante::ENTIER:
     this->_i = new Entier(*static_cast<const Entier*>(c._i));
             break;
             case Constante::RATIONNEL:
     this->_i = new Rationnel(*static_cast<const Rationnel*>(c._i));
             break;
             case Constante::REEL:
     this->_i = new Reel(*static_cast<const Reel*>(c._i));
             break;
     }
}

Complexe::Complexe(const Constante& c):Constante(COMPLEXE)
{
    switch(c.getType()){
             case Constante::ENTIER:
     this->_r = new Entier(static_cast<const Entier&>(c));
             break;
             case Constante::RATIONNEL:
     this->_r = new Rationnel(static_cast<const Rationnel&>(c));
             break;
             case Constante::REEL:
     this->_r = new Reel(static_cast<const Reel&>(c));
             break;
     }

    this->_i = new Entier(0);

}

Complexe::Complexe(const Constante* r, const Constante* i) : Constante(COMPLEXE)
{
    switch(r->getType()){
             case Constante::ENTIER:
     this->_r = new Entier(*static_cast<const Entier*>(r));
             break;
             case Constante::RATIONNEL:
     this->_r = new Rationnel(*static_cast<const Rationnel*>(r));
             break;
             case Constante::REEL:
     this->_r = new Reel(*static_cast<const Reel*>(r));
             break;
     }

    switch(i->getType()){
             case Constante::ENTIER:
     this->_i = new Entier(*static_cast<const Entier*>(i));
             break;
             case Constante::RATIONNEL:
     this->_i = new Rationnel(*static_cast<const Rationnel*>(i));
             break;
             case Constante::REEL:
     this->_i = new Reel(*static_cast<const Reel*>(i));
             break;
     }
}

Complexe::~Complexe()
{
    delete this->_r;
    delete this->_i;
}

Constante* Complexe::getR() const
{
    return this->_r;
}

Constante* Complexe::getI() const
{
    return this->_i;
}

void Complexe::setR(const Constante& r)
{
    switch(r.getType()){
        case Constante::ENTIER:
        {
            delete this->_r;
            this->_r = new Entier(static_cast<const Entier&>(r));
                 break;
        }
        case Constante::RATIONNEL:
        {
            delete this->_r;
            this->_r = new Rationnel(static_cast<const Rationnel&>(r));
                 break;
        }
        case Constante::REEL:
        {
            delete this->_r;
            this->_r = new Reel(static_cast<const Reel&>(r));
                 break;
        }
     }
}

void Complexe::setI(const Constante& i)
{
    switch(i.getType()){
        case Constante::ENTIER:
        {
            delete this->_i;
            this->_i = new Entier(static_cast<const Entier&>(i));
                 break;
        }
        case Constante::RATIONNEL:
        {
            delete this->_i;
            this->_i = new Rationnel(static_cast<const Rationnel&>(i));
                 break;
        }
        case Constante::REEL:
        {
            delete this->_i;
            this->_i = new Reel(static_cast<const Reel&>(i));
                 break;
        }
     }
}

void Complexe::affiche(std::ostream & os) const
{
    Entier zero(0);
    switch (this->_i->getType())
    {
        case Constante::ENTIER:
    {
        Entier tmp(static_cast<const Entier*>(this->_i)->getEntier());
        if (tmp < zero)
            os<<*(this->_r)<<" - "<< *(-tmp) <<"i";
        else if (tmp == zero)
            os<<*(this->_r);
        else
            os<<*(this->_r)<<" + "<< *(this->_i) <<"i";
        break;
    }
    case Constante::RATIONNEL:
    {
        Rationnel tmp(static_cast<const Rationnel*>(this->_i)->getNumerateur(),
                      static_cast<const Rationnel*>(this->_i)->getDenominateur());
        if (tmp < zero)
            os<<*(this->_r)<<" - "<< *(-tmp) <<"i";
        else if (tmp == zero)
            os<<*(this->_r);
        else
            os<<*(this->_r)<<" + "<< tmp <<"i";
        break;
    }
    case Constante::REEL:
    {
        Reel tmp(static_cast<const Reel*>(this->_i)->getReel());
        if (tmp < zero)
            os<<*(this->_r)<<" - "<< *(-tmp) <<"i";
        else if (tmp == zero)
            os<<*(this->_r);
        else
            os<<*(this->_r)<<" + "<< tmp <<"i";
        break;
    }
    }
}

std::ostream & operator<<(std::ostream & os, const Complexe & c)
{
    c.affiche(os);
    return(os);
}

Constante* Complexe::operator+(const Constante& c) const
{
    switch (c.getType())
    {
        case Constante::ENTIER:
    return *this+Complexe(static_cast<const Entier&>(c));
            break;
        case Constante::RATIONNEL:
    return *this+Complexe(static_cast<const Rationnel&>(c));
            break;
        case Constante::REEL:
    return *this+Complexe(static_cast<const Reel&>(c));
            break;
        case Constante::COMPLEXE:
    return new Complexe(static_cast<Constante*>(Addition::application(*this->_r,*static_cast<const Complexe&>(c)._r)),
                            static_cast<Constante*>(Addition::application(*this->_i,*static_cast<const Complexe&>(c)._i)));
            break;
    }
}

Constante* Complexe::operator-(const Constante & c) const
{
    switch (c.getType())
    {
        case Constante::ENTIER:
        {
            return *this-Complexe(static_cast<const Entier&>(c));
            break;
        }
        case Constante::RATIONNEL:
        {
            return *this-Complexe(static_cast<const Rationnel&>(c));
            break;
        }
        case Constante::REEL:
        {
            return *this-Complexe(static_cast<const Reel&>(c));
            break;
        }
        case Constante::COMPLEXE:
        {
            return new Complexe(static_cast<Constante*>(
                                    Soustraction::application(
                                        *this->_r,
                                        *static_cast<const Complexe&>(c)._r)),
                                static_cast<Constante*>(
                                    Soustraction::application(
                                        *this->_i,
                                        *static_cast<const Complexe&>(c)._i)));
            break;
        }
    }
}

Constante* Complexe::operator*(const Constante & c) const
{
    switch (c.getType())
    {
        case Constante::ENTIER:
        {
        return new Complexe(static_cast<Constante*>(Multiplication::application(*this->_r,static_cast<const Entier&>(c))),
                            static_cast<Constante*>(Multiplication::application(*this->_i,static_cast<const Entier&>(c))));
            break;
        }
        case Constante::RATIONNEL:
        {
        return new Complexe(static_cast<Constante*>(Multiplication::application(*this->_r,static_cast<const Rationnel&>(c))),
                           static_cast<Constante*>(Multiplication::application(*this->_i,static_cast<const Rationnel&>(c))));
            break;
        }
        case Constante::REEL:
        {
        return new Complexe(static_cast<Constante*>(Multiplication::application(*this->_r,static_cast<const Reel&>(c))),
                           static_cast<Constante*>(Multiplication::application(*this->_i,static_cast<const Reel&>(c))));
            break;
        }
        case Constante::COMPLEXE:
        {
            return new Complexe(static_cast<Constante*>(
                                    Soustraction::application(
                                        *Multiplication::application(*this->_r,*static_cast<const Complexe&>(c)._r),
                                        *Multiplication::application(*this->_i,*static_cast<const Complexe&>(c)._i)
                                        )
                                    ),
                                static_cast<Constante*>(
                                    Addition::application(
                                        *Multiplication::application(*this->_r,*static_cast<const Complexe&>(c)._i),
                                        *Multiplication::application(*this->_i,*static_cast<const Complexe&>(c)._r)))
                                                                                     );
            break;
        }
    }
}

Constante* Complexe::operator/(const Constante & c) const
{
    switch (c.getType())
    {
        case Constante::ENTIER:
        {
            return *this/Complexe(static_cast<const Entier&>(c));
            break;
        }
        case Constante::RATIONNEL:
        {
            return *this/Complexe(static_cast<const Rationnel&>(c));
            break;
        }
        case Constante::REEL:
        {
            return *this/Complexe(static_cast<const Reel&>(c));
            break;
        }
        case Constante::COMPLEXE:
        {
        return new Complexe(static_cast<Constante*>(
                                 Division::application(
                                         *Addition::application(
                                              *Multiplication::application(*this->_r,*static_cast<const Complexe&>(c)._r),
                                              *Multiplication::application(*this->_i,*static_cast<const Complexe&>(c)._i)
                                        ),
                                         *Addition::application(
                                                 *Multiplication::application(*static_cast<const Complexe&>(c)._r,*static_cast<const Complexe&>(c)._r),
                                                 *Multiplication::application(*static_cast<const Complexe&>(c)._i,*static_cast<const Complexe&>(c)._i)))
                                ),
                            static_cast<Constante*>(
                                Division::application(
                                    *Soustraction::application(
                                        *Multiplication::application(*this->_i,*static_cast<const Complexe&>(c)._r),
                                        *Multiplication::application(*this->_r,*static_cast<const Complexe&>(c)._i)
                                        ),
                                    *Addition::application(
                                            *Multiplication::application(*static_cast<const Complexe&>(c)._r,*static_cast<const Complexe&>(c)._r),
                                            *Multiplication::application(*static_cast<const Complexe&>(c)._i,*static_cast<const Complexe&>(c)._i)))
                                ));
            break;
        }
    }
}

Constante* Complexe::operator-()const{
        return new Complexe((const Constante*)-(*this->_r),(const Constante*)-(*this->_i));
}

bool Complexe::operator==(const Constante& c) const
{
    switch (c.getType())
    {
        case Constante::ENTIER:
    return *this==Complexe(static_cast<const Entier&>(c));
            break;
        case Constante::RATIONNEL:
    return *this==Complexe(static_cast<const Rationnel&>(c));
            break;
        case Constante::REEL:
    return *this==Complexe(static_cast<const Reel&>(c));
            break;
        case Constante::COMPLEXE:
    {
        if(Egal::application(*this->_r,*static_cast<const Complexe&>(c)._r) && Egal::application(*this->_i,*static_cast<const Complexe&>(c)._i))
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

bool Complexe::operator <(const Constante& c)const
{
    switch (c.getType())
    {
        case Constante::ENTIER:
    return *this==Complexe(static_cast<const Entier&>(c));
            break;
        case Constante::RATIONNEL:
    return *this==Complexe(static_cast<const Rationnel&>(c));
            break;
        case Constante::REEL:
    return *this==Complexe(static_cast<const Reel&>(c));
            break;
        case Constante::COMPLEXE:
    {
        if(Inferieur::application(*this->_r,*static_cast<const Complexe&>(c)._r) && Inferieur::application(*this->_i,*static_cast<const Complexe&>(c)._i))
        {
            return true;
        }
        else
        {
            return false;
        }
            break;
    }
    }
}

ComplexeException::ComplexeException(int n, std::string const & info) throw()
{
    this->_numero = n;
    this->_info = info;
}

ComplexeException::~ComplexeException() throw(){}

const char* ComplexeException::what() const throw()
{
    return this->_info.c_str();
}
