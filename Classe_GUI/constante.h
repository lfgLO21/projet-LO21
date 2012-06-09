#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

class Constante
{
    protected:
        int _type;
    public:
        enum Types {ENTIER = 0, RATIONNEL = 1 , REEL = 2, COMPLEXE = 3, EXPRESSION = 4};
        Constante(int t = 0): _type(t){};
        virtual ~Constante();

        void setType(int t = 0);

        int getType(void) const;

<<<<<<< HEAD
        virtual std::string toString() const = 0;
        virtual void affiche(std::ostream & os)const = 0;
=======
        virtual void affiche(std::ostream & os = std::cout) const = 0;
>>>>>>> 08b20c2ec3a1d0678a2b42af2692d11c0b27c436

        virtual Constante * operator+(const Constante & c) const = 0;
        virtual Constante * operator-(const Constante & c) const = 0;
        virtual Constante * operator*(const Constante & c) const = 0;
        virtual Constante * operator/(const Constante & c) const = 0;
        
        virtual Constante * operator-()const = 0;
};
std::ostream & operator<<(std::ostream & os, const Constante & c);
#endif // CONSTANTE_H
