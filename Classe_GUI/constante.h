#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class Constante
{
    protected:
        int _type;
    public:
        enum Types {ENTIER = 0, RATIONNEL = 1 , REEL = 2, COMPLEXE = 3};
        Constante(int t = 0): _type(t){};
        virtual ~Constante();

        void setType(int t = 0);

        int getType(void) const;

        virtual void affiche(std::ostream & os = cout) const = 0;

        virtual Constante * operator+(const Constante & c) const = 0;
        virtual Constante * operator-(const Constante & c) const = 0;
        virtual Constante * operator*(const Constante & c) const = 0;
        virtual Constante * operator/(const Constante & c) const = 0;
        
        virtual Constante * SIGN()const = 0;
};

#endif // CONSTANTE_H