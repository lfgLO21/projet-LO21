#include "expression.h"
/*!
 *\fn Expression::Expression(string)
 *\brief Constructeur d'expression, prend une chaine de caractere et la stocke en attendant la suite
 */
Expression::Expression(const std::string & str):Constante(EXPRESSION)
{
    this->_type = Constante::EXPRESSION;
    this->_expression=str;
    this->_type = Constante::EXPRESSION;
}

Expression::~Expression()
{}

/*!
 *\fn string Expression::getExpression()
 *\brief Methode renvoyant l'attribut contenant la chaine de caractere correspondant a l'expression
 */
const std::string Expression::getExpression() const
{
    return this->_expression;
}

/*!
 *\fn void Expression::setExpression(string)
 *\brief Methode permettant de modifier la valeur de l'expression a l'aide d'une reference de chaine de caracteres
 */
void Expression::setExpression(const std::string & str)
{
    this->_expression = str;
}

/*!
 *\fn string Expression::toString() const
 * \brief Methode tranformant l'expression en une chaine de caractere en vue d'un traitemet de type affichage ou concatenation avec une chaine de caracteres
 */
std::string Expression::toString() const
{
    std::string res = _expression;
    res[0]=' ';
    res[res.size()-1]=' ';
    return res;
}

/*!
 *\fn void Expression::affiche(ostream)
 *\brief Methode d'affichage de l'Expression dans un flux
 */
void Expression::affiche(std::ostream &os) const
{
    os<<_expression;
}

/*!
 *\fn Constante * Expression::operator+(Constante)
 *\brief Operateur d'addition d'une expression avec une autre variable de type constante, il s'agit en fait d'une concatenation de la variable, de l'expression et de l'operation
 */
Constante * Expression::operator+(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+this->toString()+"+'");
}
/*!
 *\fn Constante * Expression::operator-(Constante)
 *\brief Operateur de soustraction d'une expression avec une autre variable de type constante, il s'agit en fait d'une concatenation de la variable, de l'expression et de l'operation
 */
Constante * Expression::operator-(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+this->toString()+"-'");
}

/*!
 *\fn Constante * Expression::operator*(Constante)
 *\brief Operateur de muliplication d'une expression avec une autre variable de type constante, il s'agit en fait d'une concatenation de la variable, de l'expression et de l'operation
 */
Constante * Expression::operator*(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+this->toString()+"*'");
}

/*!
 *\fn Constante * Expression::operator/(Constante)
 *\brief Operateur de division d'une expression avec une autre variable de type constante, il s'agit en fait d'une concatenation de la variable, de l'expression et de l'operation
 */
Constante * Expression::operator/(const Constante & c) const
{
    return new Expression("'"+c.toString()+" "+this->toString()+"/'");
}

/*!
 *\fn Constante * Expression::operator-()
 *\brief Operateur de mise au negatif d'une expression, il s'agit en fait d'une concatenation de l'expression et de l'operation SIGN
 */
Constante * Expression::operator-()const
{
    return new Expression("'"+this->toString()+" "+"SIGN'");
}
