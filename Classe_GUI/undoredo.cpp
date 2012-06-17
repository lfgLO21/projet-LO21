/**
 * \file undoredo.cpp
 * \brief Methode de la class UndoRedo
 */

#include "undoredo.h"

/*!
 * \fn std::string getUndoRedo(int t)const
 * \brief getUndoRedo
 * permet d'avoir les informations contenues dans la file � l'emplacement t
 *
 * \param t : entier pour connaitre l'emplacement de l'information
 * \return _FileUndoRedo[t]
 * " " sinon
 */
std::string UndoRedo::getUndoRedo(int t)const
{
    if(_FileUndoRedo.empty())
    {
        return " ";
    }
    return _FileUndoRedo[t];
}

/*!
 * \fn void addSave(std::string UR)
 * \brief ajout d'un contexte
 *  permet d'ajouter l'etat UR dans la file
 *
 * modifie la file en lui ajoutant la chaine UR
 * si la taille de la file est sup�rieur � _taille, on enl�ve les premiers �l�ments de la file
 * si en revanche le pointeur _point n'est pas � la fin de la file, c'est que l'on souhaite modifier les informations situ� au del� de _point dans la file
 * donc on retire les �l�mentes de la file situ� avant _point
 * puis enfin on rajoute la chaine UR dans la file
 * et on modifie _point pour que celui ci se situe � la fin de la file
 *
 * \param UR : chaine de caract�re contenant des informations de contexte
 */
void UndoRedo::addSave(std::string UR)
{
    if(_FileUndoRedo.size()>_taille)
    {
        _FileUndoRedo.pop_front();
        _point--;
    }
    while(_FileUndoRedo.size()!=_point)
    {
        _FileUndoRedo.pop_back();
    }
    _FileUndoRedo.push_back(UR);
    _point=_FileUndoRedo.size();
}

/*!
 * \fn std::string Undo()
 * \brief obtention des informations situ� pr�c�dement dans la file
 *
 *  Modifie la valeur de _point si celui ci ne pointe pas encore le d�but de la file et renvoie la valeur de la file situ� � l'emplacement _point
 *
 * \return getUndoRedo(_point-1)
 */
std::string UndoRedo::Undo()
{
    if(_point>1)
    {
        _point--;
    }
    return getUndoRedo(_point-1);
}

/*!
 * \fn std::string Redo()
 * \brief obtention des informations situ� apr�s dans la file
 *
 *  Modifie la valeur de _point si celui ci ne pointe pas la fin de la file et renvoie la valeur de la file situ� � l'emplacement _point
 *
 * \return getUndoRedo(_point-1)
 */
std::string UndoRedo::Redo()
{
    if(_point<_FileUndoRedo.size())  //si le pointeur est inf�rieur � la taille max, on l'incr�mente.
    {
        _point++;
    }
    return getUndoRedo(_point-1);
}
