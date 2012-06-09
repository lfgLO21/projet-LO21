#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <vector>
#include <string>

#include "constante.h"
#include "entier.h"
#include "reel.h"


using namespace std;

class Pile
{
    private:
        vector <Constante*> _pile;

    //methode privee
        Constante* getSommet()const{return _pile.at(_pile.size());}       //renvoie le haut de la pile
        Constante* getElementI(int i)const{return _pile.at(i);}            //renvoie la donnee i de la pile

    public:
        Pile();                         //constructeur de pile
        ~Pile();                        //destructeur de pile

    //methodes get
        int getSize()const{return _pile.size();}
        vector<Constante*> getPile()const{return _pile;}

    //methodes de la classe pile
        void push(Constante * objet);
        const Constante * pop();
        void clear(); //raz

    //SWAP
        void swap(unsigned int x,unsigned int y);

   //SUM
        Constante * sum(unsigned int x);

    //MEAN
        Constante * mean(unsigned int x);

    //DUP
        void dup();

    //DROP
        void drop();
};

#endif // PILE_H
