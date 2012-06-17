#include "expression.h"

Expression::Expression(const std::string & str):Constante(EXPRESSION)
{
    this->_type = Constante::EXPRESSION;
    this->_expression=str;
    this->_expression[0]=' ';
    this->_expression[this->_expression.size()-1]=' ';
}

Expression::~Expression()
{}

std::string Expression::getExpression() const
{
    return this->_expression;
}

void Expression::setExpression(const std::string & str)
{
    this->_expression = str;
}

std::string Expression::toString() const
{
    return "'"+_expression+"'";
}

void Expression::affiche(std::ostream &os) const
{
    os<<_expression;
}

Constante * Expression::operator+(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+_expression+"+'");
}

Constante * Expression::operator-(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+_expression+"-'");
}

Constante * Expression::operator*(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+_expression+"*'");
}

Constante * Expression::operator/(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+_expression+"/'");
}

Constante * Expression::operator-()const
{
    return new Expression("'"+_expression+" "+"SIGN'");
}
