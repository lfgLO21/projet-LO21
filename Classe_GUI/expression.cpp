#include "expression.h"

Expression::Expression(const std::string & str):Constante(EXPRESSION)
{
    this->_type = Constante::EXPRESSION;
    this->_expression=str;
    this->_type = Constante::EXPRESSION;
}

Expression::~Expression()
{}

const std::string Expression::getExpression() const
{
    return this->_expression;
}

void Expression::setExpression(const std::string & str)
{
    this->_expression = str;
}

std::string Expression::toString() const
{
    std::string res = _expression;
    res[0]=' ';
    res[res.size()-1]=' ';
    return res;
}

void Expression::affiche(std::ostream &os) const
{
    os<<_expression;
}

Constante * Expression::operator+(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+this->toString()+"+'");
}

Constante * Expression::operator-(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+this->toString()+"-'");
}

Constante * Expression::operator*(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+this->toString()+"*'");
}

Constante * Expression::operator/(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+this->toString()+"/'");
}

Constante * Expression::operator-()const
{
    return new Expression("'"+this->toString()+" "+"SIGN'");
}
