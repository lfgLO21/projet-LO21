#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <vector>
#include <string>

#include "complexe.h"
#include "constante.h"
#include "entier.h"
#include "expression.h"
#include "operation.h"
#include "rationnel.h"
#include "reel.h"

using namespace std;

/*! \class Pile
  * \brief classe permettant de stocker les constantes qui seront manipulé dans la calculette
  *
  * la classe gere un vector de pointeur de constante
  *
  */

class Pile
{
    private:
        vector<Constante*> _pile; /*! vector de pointeur de constante */

    //methode privee
        /*!
          * \brief getSommet
          * Methode renvoyant le sommet de la pile
          * \return _pile.at(_pile.size)
          */
        Constante* getSommet()const{return _pile.at(_pile.size());}

        /*!
          * \brief getElementI
          * Methode renvoyant une constante situé à un emplacement précis
          * \return _pile.at(i)
          */
        Constante* getElementI(int i)const{return _pile.at(i);}            //renvoie la donnee i de la pile

    public:
        /*!
          * \brief Constructeur
          * Constructeur de la classe Pile
          */
        Pile(){}
        /*!
          * \brief Destructeur
          * Destructeur de la classe Pile
          */
        ~Pile(){}

    //methodes get
        /*!
          * \brief getSize
          * Permet de connaitre la taille actuelle de la pile
          * \return _pile.size()
          */
        int getSize()const{return _pile.size();}

        /*!
          * \brief getConst
          * Methode renvoyant une constante situé à un emplacement précis
          * \return _pile[i]
          */
        Constante* getConst(int i)const{return _pile[i];}

        /*!
          * \brief getPile
          * Methode renvoyant le vector de la pile
          * \return _pile
          */
        vector<Constante*> getPile()const{return _pile;}

    //methodes de la classe pile

        /*!
          * \brief Ajout d'une constante dans la pile
          * méthode ajoutant au sommet de la pile une constante
          * \param *objet : pointeur de constante
          */
        void push(Constante * objet);

        /*!
          * \brief Retrait d'une constante de la pile
          * Methode qui retire le dernier élément de la pile et le renvoie
          * \return _pile.back()
          */
        Constante * pop();

        /*!
          * \brief impression de la pile
          * Methode qui stock les n premiers éléments de la pile dans une chaine de caractère
          * \param n : nombre d'élément de la pile que l'on souhaite mettre dans la chaine  de caractère
          * \return std::string str
          */
        std::string print(unsigned int n) const;

        /*!
          * \brief remise à zero de la pile
          * Méthode qui supprime toutes les constantes de la pile
          */
        void clear();

    //SWAP
        /*!
          * \brief inversion de 2 élément de la pile
          * Méthode qui inverse les éléments de la pile situé au position x et y
          * \param x : entier indiquant la position de la première constante
          * \param y : entier indiquant la position de la deuxième constante
          */
        void swap(unsigned int x,unsigned int y);

   //SUM
        /*!
          * \brief somme des x derniers éléments de la pile
          * Méthode sommant les x derniers éléments de la pile, et empile ce résultat
          * \param x : nombre de constante à sommer
          */
        void sum(Entier* x);

    //MEAN
        /*!
          * \brief moyenne des x derniers éléments de la pile
          * Méthode faisant la moyenne des x derniers éléments de la pile, et empile ce résultat
          * \param x : nombre de constante pour le calcul
          */
        void mean(Entier* x);

    //DUP
        /*!
          * \brief duplique le dernier élément de la pile
          * Méthode dupliquant le dernier élément de la pile, et l'empile
          */
        void dup();

    //DROP
        /*!
          * \brief retire le dernier élément de la pile
          * Méthode retirant le dernier élément de la pile
          */
        void drop();
};

#endif // PILE_H
