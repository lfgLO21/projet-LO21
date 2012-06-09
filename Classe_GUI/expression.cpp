#include "expression.h"

Expression::Expression(const string& str)
{
    this->_type = EXPRESSION;
    this->_exp = str;
    this->_exp[0]= ' ';
    this->_exp[this->_exp.size()-1]= ' ';
}

Constante* Expression::operator+(const Constante& c)const
{
    return new Expression("'"+c.print()+this->_exp+"+'");
}

Constante* Expression::operator*(const Constante& c)const
{
    return new Expression("'"+c.print()+this->_exp+"*'");
}

Constante* Expression::operator-(const Constante& c)const
{
    return new Expression("'"+c.print()+this->_exp+"-'");
}

Constante* Expression::operator/(const Constante& c)const
{
    return new Expression("'"+c.print()+this->_exp+"/'");
}


std::string getExp()const
{
    return this->_exp;
}

void affiche(std::ostream & os = cout) const
{
    os << this->getExp();
}

