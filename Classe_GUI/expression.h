#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "constante.h"
#include <string>
/*!
 *\class ExpressionException
 *\brief lance une exception lorsque l'expression ne peut pas etre evaluee
 */
class Expression_exception
{
    std::string _infos;

public:
    Expression_exception(const std::string& i):_infos(i){}

    const std::string& getInfos()const{return _infos;}
};

/*!
 *\class Expression
 *\brief type de constante permettant de remettre a plus tard un calcul en le mettant entre simples quotes
 */
class Expression : public Constante
{

    std::string _expression;

public:
    Expression(const std::string & str="");
    ~Expression();

    std::string getExpression()const;
    void setExpression(const std::string & str = "");

    std::string toString() const;
    void affiche(std::ostream &os=std::cout) const;

    Constante * operator+(const Constante & c) const;
    Constante * operator-(const Constante & c) const;
    Constante * operator*(const Constante & c) const;
    Constante * operator/(const Constante & c) const;
    Constante * operator-()const;

    bool operator==(const Constante & c) const{throw Expression_exception("fonction inexistante");}
    bool operator<(const Constante & c) const{throw Expression_exception("fonction inexistante");}
};

#endif // EXPRESSION_H
