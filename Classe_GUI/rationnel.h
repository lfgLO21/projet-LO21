#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include "expression.h"
#include "entier.h"
#include "reel.h"

class Rationnel_exception
{
    std::string _infos;

public:
    Rationnel_exception(const std::string& i):_infos(i){}

    const std::string& getInfos()const{return _infos;}


};

/*! \class Rationnel
  * \brief class repr�sentant les constantes qui sont des rationnels
  *
  * La classe comporte deux attribut integer
  */
class Rationnel:public Constante
{
    int _numerateur; /*! valeur du num�rateur */
    int _denominateur; /*! valeur du d�nominateur */

    //m�thode priv�e
    /*!
      * \brief simplification
      * M�thode priv� permettante de simplifier quand cel� est possible la fraction manipul�
      */
    void simplification();

public:

    /*!
      * \brief Constructeur
      * Constructeur de la classe Rationnel
      * \param n : valeur de l'attribut _numerateur
      * \param d : valeur de l'attribut _denominateur
      */
    Rationnel(int n=0, int d=1);

    /*!
      * \brief Constructeur
      * Constructeur de la classe Rationnel
      * \param e : r�f�rence sur un Entier existant
      */
    Rationnel(const Entier& e);

    /*!
      * \brief Constructeur
      * Constructeur de la classe Rationnel
      * \param n : valeur de l'attribut _numerateur � partir d'un entier existant
      * \param d : valeur de l'attribut _denominateur � partir d'un entier existant
      */
    Rationnel(const Entier& n, const Entier& d);

    /*!
      * \brief Constructeur de copie
      * Constructeur de la classe Rationnel � partir d'un Rationnel existant d�j�
      * \param r : r�f�rence sur un Rationnel existant
      */
    Rationnel(const Rationnel& r);

    /*!
      * \brief Destructeur
      * Destructeur de la classe Rationnel
      */
    ~Rationnel(){}

    //get
    /*!
      * \brief getNumerateur
      * M�thode renvoyant la valeur de l'attribut _numerateur de la classe
      * \return _numerateur
      */
    int getNumerateur()const;

    /*!
      * \brief getDenominateur
      * M�thode renvoyant la valeur de l'attribut _denominateur de la classe
      * \return _denominateur
      */
    int getDenominateur()const;

    //set
    /*!
      * \brief setNumerateur
      * M�thode modifiant la valeur de l'attribut _numerateur de la classe
      * \param  n : nouvel valeur de _numerateur
      */
    void setNumerateur(int n);

    /*!
      * \brief setDenominateur
      * M�thode modifiant la valeur de l'attribut _denominateur de la classe
      * \param  e : nouvel valeur de _denominateur
      */
    void setDenominateur(int d);

    /*!
      * \brief toString
      * Methode permettant de transformer le rationnel manipul� en une chaine de caract�re
      * \return string
      */
    std::string toString()const{
        std::stringstream ss;
        ss<<_numerateur<<"/"<<_denominateur;
        return ss.str();
    }

    //affiche
    /*!
      * \brief affiche
      * Methode permettant un affichage du rationnel manipul�
      * \param os
      */
    void affiche(std::ostream & os = std::cout) const;

    //operateur
    /*!
      * \brief operator+
      * Methode retournant la somme du rationnel manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante * operator+(const Constante & c) const;

    /*!
      * \brief operator-
      * Methode retournant la diff�rence du rationnel manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante * operator-(const Constante & c) const;

    /*!
      * \brief operator*
      * Methode retournant le produit du rationnel manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante * operator*(const Constante & c) const;

    /*!
      * \brief operator/
      * Methode retournant la division du rationnel manipul� avec la constante pass� en argument
      * \param c
      * \return Constante*
      */
    Constante * operator/(const Constante & c) const;

    /*!
      * \brief operator-
      * Methode retournant le contraire du rationnel manipul�
      * \return Constante*
      */
    Constante * operator-()const;

    /*!
      * \brief operator==
      * Methode v�rifiant si le rationnel manipul� est �gal � la constante pass� en argument
      * \param c
      * \return true si il y a �galit�, false sinon
      */
    bool operator==(const Constante & c) const;

    /*!
      * \brief operator<
      * Methode v�rifiant si le rationnel manipul� est inf�rieur � la constante pass� en argument
      * \param c
      * \return true si la constante manipul� est inf�rieur, false sinon
      */
    bool operator<(const Constante & c) const;

};

std::ostream & operator<<(std::ostream & os, const Rationnel & c);

#endif // RATIONNEL_H
