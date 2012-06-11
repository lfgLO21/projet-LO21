#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include "expression.h"
#include "entier.h"
#include "reel.h"

class Rationnel_exception
{
    std::string _infos;

public:
    Rationnel_exception(const std::string& i):_infos(i){}

    const std::string& getInfos()const{return _infos;}


};

class Rationnel:public Constante
{
    int _numerateur;
    int _denominateur;

    //méthode privée
    void simplification();

public:
    Rationnel(int n=0, int d=1);
    Rationnel(const Entier& e);
    Rationnel(const Entier& n, const Entier& d);
    Rationnel(const Rationnel& r);

    //get
    int getNumerateur()const;
    int getDenominateur()const;

    //set
    void setNumerateur(int n);
    void setDenominateur(int d);

    std::string& toString()const{
        std::stringstream ss;
        ss<<_numerateur<<"/"<<_denominateur;
        return ss.str();
    }

    //affiche
    void affiche(std::ostream & os = std::cout) const;

    //operateur
    Constante * operator+(const Constante & c) const;
    Constante * operator-(const Constante & c) const;
    Constante * operator*(const Constante & c) const;
    Constante * operator/(const Constante & c) const;
    Constante * operator-()const;

    bool operator==(const Constante & c) const;
    bool operator<(const Constante & c) const;

};

std::ostream & operator<<(std::ostream & os, const Rationnel & c);

#endif // RATIONNEL_H
