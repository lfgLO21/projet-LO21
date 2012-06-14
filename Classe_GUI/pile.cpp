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

Constante* Pile::pop()
{
    if(_pile.size()==0)
        return 0;
    Constante* tmp = _pile.back();
    _pile.pop_back();
    return tmp;
}

std::string Pile::print(unsigned int n) const
{
    std::string str = "";

    int size = this->_pile.size();

    for (unsigned int i = 0; i < size && i < n; i++)
    {
        str += this->_pile[size - 1 - i]->toString() + "\n";
    }

    return str;
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

void Pile::sum(Entier* x)
{
    Constante* temp = new Entier(0);
    unsigned int s = _pile.size();
    unsigned int i = x->getEntier();
    while(i!=0)
    {
        temp = Addition::application(*temp, *_pile[s-i]);
        i--;
    }
    this->_pile.push_back(temp);
}

void Pile::mean(Entier* x)
{
    Constante * temp = new Reel(0);
    unsigned int s = _pile.size();
    unsigned int i = x->getEntier();
    while(i!=0)
    {
        temp = Addition::application(*temp, *_pile[s-i]);
        i--;
    }
    temp = Division::application(*temp,*x);
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
            tmp = new Rationnel(static_cast<Rationnel&>(*tmp));
            break;
        }
        case Constante::REEL :
        {
            tmp = new Reel(static_cast<Reel&>(*tmp));
            break;
        }
        case Constante::COMPLEXE :
        {
            tmp = new Complexe(static_cast<Complexe&>(*tmp));
            break;
        }
    }
    this->_pile.push_back(tmp);
}

void Pile::drop()
{
    this->_pile.pop_back();
}
