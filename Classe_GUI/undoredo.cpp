/**
 * \file undoredo.cpp
 * \brief Methode de la class UndoRedo
 */

#include "undoredo.h"

/*!
 * \fn std::string getUndoRedo(int t)const
 * \brief getUndoRedo
 * permet d'avoir les informations contenues dans la file à l'emplacement t
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
 * si la taille de la file est supérieur à _taille, on enlève les premiers éléments de la file
 * si en revanche le pointeur _point n'est pas à la fin de la file, c'est que l'on souhaite modifier les informations situé au delà de _point dans la file
 * donc on retire les élémentes de la file situé avant _point
 * puis enfin on rajoute la chaine UR dans la file
 * et on modifie _point pour que celui ci se situe à la fin de la file
 *
 * \param UR : chaine de caractère contenant des informations de contexte
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
 * \brief obtention des informations situé précédement dans la file
 *
 *  Modifie la valeur de _point si celui ci ne pointe pas encore le début de la file et renvoie la valeur de la file situé à l'emplacement _point
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
 * \brief obtention des informations situé après dans la file
 *
 *  Modifie la valeur de _point si celui ci ne pointe pas la fin de la file et renvoie la valeur de la file situé à l'emplacement _point
 *
 * \return getUndoRedo(_point-1)
 */
std::string UndoRedo::Redo()
{
    if(_point<_FileUndoRedo.size())  //si le pointeur est inférieur à la taille max, on l'incrémente.
    {
        _point++;
    }
    return getUndoRedo(_point-1);
}
