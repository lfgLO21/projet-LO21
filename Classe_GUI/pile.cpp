/**
 * \file pile.cpp
 * \brief Methode de la class Pile
 */

#include "pile.h"

using namespace std;

/*!
  * \fn void push(Constante * objet)
  * \brief Ajout d'une constante dans la pile
  * méthode ajoutant au sommet de la pile une constante
  * \param *objet : pointeur de constante
  */
void Pile::push(Constante * objet)
{
    this->_pile.push_back(objet);
}

/*!
  * \fn Constante* pop()
  * \brief Retrait d'une constante de la pile
  * Methode qui retire le dernier élément de la pile et le renvoie
  *
  * Si la pile est vide, renvoie 0, sinon renvoie le dernier élément de la pile
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
  * Methode qui stock les n premiers éléments de la pile dans une chaine de caractère
  * \param n : nombre d'élément de la pile que l'on souhaite mettre dans la chaine  de caractère
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
  * \brief remise à zero de la pile
  * Méthode qui supprime toutes les constantes de la pile
  */
void Pile::clear()
{
    this->_pile.clear();
}

/*!
  * \fn void swap(unsigned int x, unsigned int y)
  * \brief inversion de 2 élément de la pile
  * Méthode qui inverse les éléments de la pile situé au position x et y
  * \param x : entier indiquant la position de la première constante
  * \param y : entier indiquant la position de la deuxième constante
  */
void Pile::swap(unsigned int x, unsigned int y)
{
    Constante * tmp = this->_pile.at(x);
    _pile[x] = _pile[y];
    _pile[y] = tmp;
}

/*!
  * \fn void sum(Entier* x)
  * \brief somme des x derniers éléments de la pile
  * Méthode sommant les x derniers éléments de la pile, et empile ce résultat
  *
  * Créer un pointeur de constante qui stockera le résultat, récupère la taille actuelle de la pile
  * et le nombre de constante que l'on souhaite sommer
  * Puis une boucle sommant les x constante de la pile en partant du haut
  * puis on empile
  * \param x : nombre de constante à sommer
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
  * \brief moyenne des x derniers éléments de la pile
  * Méthode faisant la moyenne des x derniers éléments de la pile, et empile ce résultat
  *
  * même principe que pour sum, mais en divisant par x le résultat de la somme
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
  * \brief duplique le dernier élément de la pile
  * Méthode dupliquant le dernier élément de la pile, et l'empile
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
  * \brief retire le dernier élément de la pile
  * Méthode retirant le dernier élément de la pile
  */
void Pile::drop()
{
    this->_pile.pop_back();
}
