/**
 * \file pile.cpp
 * \brief Methode de la class Pile
 */

#include "pile.h"

using namespace std;

/*!
  * \fn void push(Constante * objet)
  * \brief Ajout d'une constante dans la pile
  * m�thode ajoutant au sommet de la pile une constante
  * \param *objet : pointeur de constante
  */
void Pile::push(Constante * objet)
{
    this->_pile.push_back(objet);
}

/*!
  * \fn Constante* pop()
  * \brief Retrait d'une constante de la pile
  * Methode qui retire le dernier �l�ment de la pile et le renvoie
  *
  * Si la pile est vide, renvoie 0, sinon renvoie le dernier �l�ment de la pile
  * \return _pile.back()
  */
Constante* Pile::pop()
{
    if(_pile.size()==0)
        return 0;
    Constante* tmp = _pile.back();
    _pile.pop_back();
    return tmp;
}

/*!
  * \fn std::string print(unsigned int n)const
  * \brief impression de la pile
  * Methode qui stock les n premiers �l�ments de la pile dans une chaine de caract�re
  * \param n : nombre d'�l�ment de la pile que l'on souhaite mettre dans la chaine  de caract�re
  * \return std::string str
  */
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

/*!
  * \fn void clear()
  * \brief remise � zero de la pile
  * M�thode qui supprime toutes les constantes de la pile
  */
void Pile::clear()
{
    this->_pile.clear();
}

/*!
  * \fn void swap(unsigned int x, unsigned int y)
  * \brief inversion de 2 �l�ment de la pile
  * M�thode qui inverse les �l�ments de la pile situ� au position x et y
  * \param x : entier indiquant la position de la premi�re constante
  * \param y : entier indiquant la position de la deuxi�me constante
  */
void Pile::swap(unsigned int x, unsigned int y)
{
    Constante * tmp = this->_pile.at(x);
    _pile[x] = _pile[y];
    _pile[y] = tmp;
}

/*!
  * \fn void sum(Entier* x)
  * \brief somme des x derniers �l�ments de la pile
  * M�thode sommant les x derniers �l�ments de la pile, et empile ce r�sultat
  *
  * Cr�er un pointeur de constante qui stockera le r�sultat, r�cup�re la taille actuelle de la pile
  * et le nombre de constante que l'on souhaite sommer
  * Puis une boucle sommant les x constante de la pile en partant du haut
  * puis on empile
  * \param x : nombre de constante � sommer
  */
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

/*!
  * \fn void mean(Entier* x)
  * \brief moyenne des x derniers �l�ments de la pile
  * M�thode faisant la moyenne des x derniers �l�ments de la pile, et empile ce r�sultat
  *
  * m�me principe que pour sum, mais en divisant par x le r�sultat de la somme
  * \param x : nombre de constante pour le calcul
  */
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

/*!
  * \fn void dup()
  * \brief duplique le dernier �l�ment de la pile
  * M�thode dupliquant le dernier �l�ment de la pile, et l'empile
  */
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

/*!
  * \fn void drop()
  * \brief retire le dernier �l�ment de la pile
  * M�thode retirant le dernier �l�ment de la pile
  */
void Pile::drop()
{
    this->_pile.pop_back();
}
