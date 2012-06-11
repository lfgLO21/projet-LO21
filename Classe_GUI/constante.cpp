#include "constante.h"
Constante::~Constante()
{
}

void Constante::setType(int t)
{
    this->_type = t;
}

int Constante::getType(void) const
{
    return this->_type;
}

std::ostream & operator<<(std::ostream & os, const Constante & c)
{
    c.affiche(os);
    return(os);
}
