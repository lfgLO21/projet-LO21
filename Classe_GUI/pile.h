#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <string>

#include "constante.h"
#include "entier.h"
#include "reel.h"


using namespace std;

class Pile
{
    unsigned int _max;
    unsigned int _it;
    int* _pile;

    //methode privee
    int getInfo()const{int i=_it-1; return _pile[i];} //renvoie le haut de la pile
    int getInfo(int i)const{return _pile[i];}        //renvoie la donn�e i de la pile

public:
    Pile(unsigned int t);           //constructeur de pile
    ~Pile();                        //destructeur de pile

    //methodes get
    int getMax()const{return _max;}
    int* getPile()const{return _pile;}
    int getIt()const{return _it;}

    int size()const{return _it;}       //getIt et size sont les meme methodes, mais size est une methode qui sera vraisemblablement plus parlante que getIt

    //methodes de la classe pile
    void push(int objet);
    const int pop();
    const void affiche() const;
    void CLEAR(); //raz

    //verification de la pile
    const bool full()const;
    const bool empty()const;

    //SWAP
    void SWAP(unsigned int x,unsigned int y);

    //SUM
    void SUM(unsigned int x);

    //MEAN
    void MEAN(unsigned int x);

    //DUP
    void DUP();

    //DROP
    void DROP();
};

#endif // PILE_H
