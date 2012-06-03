#include "pile.h"

using namespace std;

Pile::Pile(unsigned int t)
{
    _max=t;
    _it=0;
    _pile=new int[t];
}

Pile::~Pile()
{
    delete[] _pile;
}

void Pile::push(int objet)
{
    if(!full())
    {
        _pile[_it]=objet;
        _it++;                                  //on retire le  nombre de place libre restante
    }
    else                                        //il faut augmenter la taille de la pile
    {
        int* tmp=new int[_max];                 //on fait une copie de la pile actuelle, et l'on récupère les données de celle ci
        for(unsigned int i=0;i<_max;i++)
        {
            tmp[i]=_pile[i];
        }
        _max+=10;                               //on augmente la taille max de 10
        delete[] _pile;                         //on supprime la pile actuelle
        _pile=new int[_max];                    //et on en créer une nouvelle avec la bonne taille
        for(unsigned int j=0;j<_max-10;j++)     //on récupère les données sauvegardé dans la pile temporaire
        {
            _pile[j]=tmp[j];
        }
        delete[] tmp;                           //on supprime la pile temporaire
        _pile[_it]=objet;
        _it++;                                  //on retire le  nombre de place libre restante

    }

}

const int Pile::pop()
{
    if(!empty())
    {
        _it--;          //il y a une place de libre supplémentaire dans la pile
        int tmp=_pile[_it];
        _pile[_it]=NULL;
        return tmp;      //on renvoie le string que l'on vient de retirer
    }
    else
    {
        std::cout<<"ERREUR: pile vide!"<<std::endl;
        return 0;
    }

}

const void Pile::affiche() const
{
    if (empty())
    {
        std::cout<<"Pile vide"<<endl;
    }
    else
    {
       for (unsigned int i=0;i <_it; i++)
       {
           std::cout<<getInfo(i)<<std::endl;
       }
    }
}

const bool Pile::full()const
{
    if(_it==_max)           //la pile est pleine, _it est de mï¿½me valeur que _max
    {
        return true;
    }
    else
    {
        return false;
    }
}

const bool Pile::empty()const
{
    if(_it==0)              //la pile est vide, _it est égale 0
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Pile::CLEAR()
{
    for(unsigned int i=0;i<_it;i++)
    {
        _pile[i]=NULL;
    }
}

void Pile::SWAP(unsigned int x, unsigned int y)
{
    int tmp = getInfo(x);
    _pile[x]=_pile[y];
    _pile[y]=tmp;
}

void Pile::SUM(unsigned int x)
{
    int tmp=0;
    for(unsigned int i=1; i<=x;i++)
    {
        tmp+=pop();
    }
    push(tmp);
}

void Pile::MEAN(unsigned int x)
{
    int tmp=0;
    for(unsigned int i=1; i<=x;i++)
    {
        tmp+=pop();
    }
    tmp/=x;
    push(tmp);
}

void Pile::DUP()
{
    int tmp=getInfo();
    push(tmp);
}

void Pile::DROP()
{
    if(!empty())
    {
        _it--;
        _pile[_it]=NULL;
    }
    else
    {
        std::cout<<"ERREUR: pile vide!"<<std::endl;
    }
}
