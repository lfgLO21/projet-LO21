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

void Pile::sum(unsigned int x)
{
    Constante* temp = new Entier(0);
    int s = this->getSize();
    for(unsigned int i = 0; i< x;i++)
    {
        //temp = Addition::application(*temp, *_pile[s-i]);
    }
    this->_pile.push_back(temp);
}

void Pile::mean(unsigned int x)
{
    Constante * temp = new Entier(0);
    int s = this->getSize();
    for(unsigned int i = 0; i< x;i++)
    {
        //temp = Addition::application(*temp, *_pile[s-i]);
    }
    //temp = Division::application(*temp,Entier(x));
    this->_pile.push_back(temp);
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
