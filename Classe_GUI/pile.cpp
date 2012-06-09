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

const Constante * Pile::pop()
{

}

void Pile::clear()
{
    while(this->_pile.size() > 0)
    {
        delete this->_pile.back();
        this->_pile.pop_back();
    }
}

void Pile::swap(unsigned int x, unsigned int y)
{
    Constante * tmp = this->_pile.at(x);
    _pile[x] = _pile[y];
    _pile[y] = tmp;
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
