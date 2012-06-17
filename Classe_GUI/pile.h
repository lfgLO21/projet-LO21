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
  * \brief classe permettant de stocker les constantes qui seront manipul� dans la calculette
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
          * Methode renvoyant une constante situ� � un emplacement pr�cis
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
          * Methode renvoyant une constante situ� � un emplacement pr�cis
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
          * m�thode ajoutant au sommet de la pile une constante
          * \param *objet : pointeur de constante
          */
        void push(Constante * objet);

        /*!
          * \brief Retrait d'une constante de la pile
          * Methode qui retire le dernier �l�ment de la pile et le renvoie
          * \return _pile.back()
          */
        Constante * pop();

        /*!
          * \brief impression de la pile
          * Methode qui stock les n premiers �l�ments de la pile dans une chaine de caract�re
          * \param n : nombre d'�l�ment de la pile que l'on souhaite mettre dans la chaine  de caract�re
          * \return std::string str
          */
        std::string print(unsigned int n) const;

        /*!
          * \brief remise � zero de la pile
          * M�thode qui supprime toutes les constantes de la pile
          */
        void clear();

    //SWAP
        /*!
          * \brief inversion de 2 �l�ment de la pile
          * M�thode qui inverse les �l�ments de la pile situ� au position x et y
          * \param x : entier indiquant la position de la premi�re constante
          * \param y : entier indiquant la position de la deuxi�me constante
          */
        void swap(unsigned int x,unsigned int y);

   //SUM
        /*!
          * \brief somme des x derniers �l�ments de la pile
          * M�thode sommant les x derniers �l�ments de la pile, et empile ce r�sultat
          * \param x : nombre de constante � sommer
          */
        void sum(Entier* x);

    //MEAN
        /*!
          * \brief moyenne des x derniers �l�ments de la pile
          * M�thode faisant la moyenne des x derniers �l�ments de la pile, et empile ce r�sultat
          * \param x : nombre de constante pour le calcul
          */
        void mean(Entier* x);

    //DUP
        /*!
          * \brief duplique le dernier �l�ment de la pile
          * M�thode dupliquant le dernier �l�ment de la pile, et l'empile
          */
        void dup();

    //DROP
        /*!
          * \brief retire le dernier �l�ment de la pile
          * M�thode retirant le dernier �l�ment de la pile
          */
        void drop();
};

#endif // PILE_H
