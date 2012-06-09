#include "pile.h"

using namespace std;

Pile::Pile()
{}

Pile::~Pile()
{}

void Pile::push(Constante * objet)
{
    this->_pile.push_back(objet);
}

void Pile::clear()
{
    this->_pile.clear();
}

void Pile::swap(unsigned int x, unsigned int y)
{
    Constante * tmp = this->_pile.at(x);
    _pile[x] = _pile[y];
    _pile[y] = tmp;
}

void sum(unsigned int x)
{
    //Constante * temp = new Entier(0);
    for(unsigned int i = 0; i< x;i++)
    {
    //    temp = *temp + *this->_pile.at(i);
    }
    //this->_pile.push_back(temp);
}

void mean(unsigned int x)
{
    //Constante * temp = new Entier(0);
    for(unsigned int i = 0; i < x; i++)
    {
    //    temp = *temp + *this->_pile.at(i);
    }
    //temp = *temp / x;
    //this->_pile.push_back(temp);
}

void Pile::dup()
{
    Constante * tmp;
    switch (this->_pile.back()->getType())
    {
        case Constante::ENTIER :
        {
            tmp = new Entier(static_cast<Entier&>(*tmp));
            break;
        }
        case Constante::RATIONNEL :
        {
            //tmp = new Rationnel(static_cast<Rationnel&>(*tmp));
            break;
        }
        case Constante::REEL :
        {
            tmp = new Reel(static_cast<Reel&>(*tmp));
            break;
        }
        case Constante::COMPLEXE :
        {
            //tmp = new Complexe(static_cast<Complexe&>(*tmp));
            break;
        }
    }
    this->_pile.push_back(tmp);
}

void Pile::drop()
{
    this->_pile.pop_back();
}
