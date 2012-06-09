#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "constante.h"
#include <string>

using namespace std;

class Expression : public Constante
{
    private:
        std::string _exp;

    public:
        Expression(const string&);

        Constante* operator+(const Constante&)const;
        Constante* operator*(const Constante&)const;
        Constante* operator-(const Constante&)const;
        Constante* operator/(const Constante&)const;

        void affiche(std::ostream & os = cout) const;
        std::string getExp()const;
};

#endif // EXPRESSION_H
