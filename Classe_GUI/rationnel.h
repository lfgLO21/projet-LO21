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
  * \brief class représentant les constantes qui sont des rationnels
  *
  * La classe comporte deux attribut integer
  */
class Rationnel:public Constante
{
    int _numerateur; /*! valeur du numérateur */
    int _denominateur; /*! valeur du dénominateur */

    //méthode privée
    /*!
      * \brief simplification
      * Méthode privé permettante de simplifier quand celà est possible la fraction manipulé
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
      * \param e : référence sur un Entier existant
      */
    Rationnel(const Entier& e);

    /*!
      * \brief Constructeur
      * Constructeur de la classe Rationnel
      * \param n : valeur de l'attribut _numerateur à partir d'un entier existant
      * \param d : valeur de l'attribut _denominateur à partir d'un entier existant
      */
    Rationnel(const Entier& n, const Entier& d);

    /*!
      * \brief Constructeur de copie
      * Constructeur de la classe Rationnel à partir d'un Rationnel existant déjà
      * \param r : référence sur un Rationnel existant
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
      * Méthode renvoyant la valeur de l'attribut _numerateur de la classe
      * \return _numerateur
      */
    int getNumerateur()const;

    /*!
      * \brief getDenominateur
      * Méthode renvoyant la valeur de l'attribut _denominateur de la classe
      * \return _denominateur
      */
    int getDenominateur()const;

    //set
    /*!
      * \brief setNumerateur
      * Méthode modifiant la valeur de l'attribut _numerateur de la classe
      * \param  n : nouvel valeur de _numerateur
      */
    void setNumerateur(int n);

    /*!
      * \brief setDenominateur
      * Méthode modifiant la valeur de l'attribut _denominateur de la classe
      * \param  e : nouvel valeur de _denominateur
      */
    void setDenominateur(int d);

    /*!
      * \brief toString
      * Methode permettant de transformer le rationnel manipulé en une chaine de caractère
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
      * Methode permettant un affichage du rationnel manipulé
      * \param os
      */
    void affiche(std::ostream & os = std::cout) const;

    //operateur
    /*!
      * \brief operator+
      * Methode retournant la somme du rationnel manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante * operator+(const Constante & c) const;

    /*!
      * \brief operator-
      * Methode retournant la différence du rationnel manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante * operator-(const Constante & c) const;

    /*!
      * \brief operator*
      * Methode retournant le produit du rationnel manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante * operator*(const Constante & c) const;

    /*!
      * \brief operator/
      * Methode retournant la division du rationnel manipulé avec la constante passé en argument
      * \param c
      * \return Constante*
      */
    Constante * operator/(const Constante & c) const;

    /*!
      * \brief operator-
      * Methode retournant le contraire du rationnel manipulé
      * \return Constante*
      */
    Constante * operator-()const;

    /*!
      * \brief operator==
      * Methode vérifiant si le rationnel manipulé est égal à la constante passé en argument
      * \param c
      * \return true si il y a égalité, false sinon
      */
    bool operator==(const Constante & c) const;

    /*!
      * \brief operator<
      * Methode vérifiant si le rationnel manipulé est inférieur à la constante passé en argument
      * \param c
      * \return true si la constante manipulé est inférieur, false sinon
      */
    bool operator<(const Constante & c) const;

};

std::ostream & operator<<(std::ostream & os, const Rationnel & c);

#endif // RATIONNEL_H
