#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "constante.h"
#include <string>

using namespace std;

class Expression : public Constante
{
    private:
        Expression(const string & str);
        ~Expression();

    public:
        std::string toString() const;
        void affiche(std::ostream &os) const;

        Constante * operator+(const Constante & c) const;
        Constante * operator-(const Constante & c) const;
        Constante * operator*(const Constante & c) const;
        Constante * operator/(const Constante & c) const;

        Constante * SIGN()const;
};

#endif // EXPRESSION_H
