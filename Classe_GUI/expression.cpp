#include "expression.h"

Expression::Expression(const string & str)
{
    this->_expression=str;
    this->_type = Constante::EXPRESSION;
}

Expression::~Expression()
{

}

std::string Expression::toString() const
{

}

void Expression::affiche(std::ostream &os) const
{
    os<<_expression;
}

Constante * Expression::operator+(const Constante & c) const
{
    switch(c.getType()){
    case Constante::ENTIER:
        return new Expression(this->_expression+" "+"+");
    }

}

Constante * Expression::operator-(const Constante & c) const
{

}

Constante * Expression::operator*(const Constante & c) const
{

}

Constante * Expression::operator/(const Constante & c) const
{

}

Constante * Expression::SIGN()const
{

}
