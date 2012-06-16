#ifndef UNDOREDO_H
#define UNDOREDO_H

#include <QQueue>
#include <string>

/*! \class UndoRdeo
 * \brief classe representant le retour arriere, retour avant
 *
 *  La classe gere une file qui contient les informations des pr�c�dents �tats de la pile que l'on manipule
 */

class UndoRedo
{
    QQueue<std::string> _FileUndoRedo; /*! File d'information des pr�c�dents �tats */
    int _taille;    /*! taille maximale de la file */
    int _point;     /*! pointeur permettant de parcourir la file selon les actions r�alis� */

public:
    /*!
      * \brief Constructeur
      * Constructeur de la classe UndoRedo
      * \param t : taille de la file initialis� � 10 si pas de param�tre
      */
    UndoRedo(int t=10):_taille(t),_point(0){}

    /*!
      * \brief Obtention de la taille max de la file
      * Methode retournant la taille max de la file
      * \return _taille
      */
    const int getTaille()const{return _taille;}

    /*!
      * \brief Modifiaction taille max de la file
      * Methode permettant de modifier la taille max de la file
      */
    void setTaille(int t){_taille=t;}

    /*!
      * \brief Obtention des informations de la file
      * permet d'avoir les informations contenues dans la file � l'emplacement t
      * \param t : position de l'information voulue dans la pile
      * \return std::string
      */
    std::string getUndoRedo(int t)const;

    /*!
      * \brief ajout d'un nouvel etat dans la file
      * permet d'ajouter l'etat UR dans la file
      * \param UR : chaine de caract�re contenant les informations de l'etat de la pile
      */
    void addSave(std::string UR);

    /*!
      * \brief obtention du pr�c�dent �tat du context actuelle
      * ben Ctrl+z quoi....
      * plus s�rieusement, modifie la position du pointeur _point sauf si celui si est au d�but de la file
      * et renvoie le contenue de la file situ� � la position _point
      */
    std::string Undo();

    /*!
      * \brief obtention du pr�c�dent �tat du context actuelle
      * ben Ctrl+y quoi....
      * plus s�rieusement, modifie la position du pointeur _point sauf si celui si est � la fin de la file
      * et renvoie le contenue de la file situ� � la position _point
      */
    std::string Redo();

};

#endif // UNDOREDO_H
