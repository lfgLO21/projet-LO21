#ifndef UNDOREDO_H
#define UNDOREDO_H

#include <QQueue>
#include <string>

/*! \class UndoRdeo
 * \brief classe representant le retour arriere, retour avant
 *
 *  La classe gere une file qui contient les informations des précédents états de la pile que l'on manipule
 */

class UndoRedo
{
    QQueue<std::string> _FileUndoRedo; /*! File d'information des précédents états */
    int _taille;    /*! taille maximale de la file */
    int _point;     /*! pointeur permettant de parcourir la file selon les actions réalisé */

public:
    /*!
      * \brief Constructeur
      * Constructeur de la classe UndoRedo
      * \param t : taille de la file initialisé à 10 si pas de paramètre
      */
    UndoRedo(int t=10):_taille(t),_point(0){}

    /*!
      * \brief getTaille
      * Methode retournant la taille max de la file
      * \return _taille
      */
    const int getTaille()const{return _taille;}

    /*!
      * \brief setTaille
      * Methode permettant de modifier la taille max de la file
      * \param t : nouvelle taille max de la file
      */
    void setTaille(int t){_taille=t;}

    /*!
      * \brief getUndoRedo
      * permet d'avoir les informations contenues dans la file à l'emplacement t
      * \param t : position de l'information voulue dans la pile
      * \return _FileUndoRedo[t] si la file n'est pas vie
      * " " sinon
      */
    std::string getUndoRedo(int t)const;

    /*!
      * \brief ajout d'un contexte
      * permet d'ajouter l'etat UR dans la file
      * \param UR : chaine de caractère contenant les informations de l'etat de la pile
      */
    void addSave(std::string UR);

    /*!
      * \brief Undo
      * ben Ctrl+z quoi....
      * plus sérieusement, modifie la position du pointeur _point sauf si celui si est au début de la file
      * et renvoie le contenue de la file situé à la position _point
      * \return getUndoRedo(_point-1)
      */
    std::string Undo();

    /*!
      * \brief Redo
      * ben Ctrl+y quoi....
      * plus sérieusement, modifie la position du pointeur _point sauf si celui si est à la fin de la file
      * et renvoie le contenue de la file situé à la position _point
      * \return getUndoRedo(_point-1)
      */
    std::string Redo();

};

#endif // UNDOREDO_H
