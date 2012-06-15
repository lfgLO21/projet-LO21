#include "undoredo.h"

std::string UndoRedo::getUndoRedo(int t)const  //renvoie le string contenue dans la file à la position t
{
    return _FileUndoRedo[t];
}

void UndoRedo::addSave(std::string UR)
{
    while(_FileUndoRedo.size()>_taille)     //si la file dépasse la taille maximal voulue, on enlève les premiers éléments de la file
    {
        _FileUndoRedo.pop_front();
    }
    while(_FileUndoRedo.size()!=_point)     //si en revanche le pointeur _point n'est pas à la fin de la file, celà signifie qu'un undo a été fait, et qu'il faut supprimer les données situées au delà du pointeur
    {
        _FileUndoRedo.pop_back();
    }
    _FileUndoRedo.push_back(UR);        //sinon on ajoute le nouveau string en bout de liste
    _point=_FileUndoRedo.size();        //et on place le pointeur à la fin de la file
}

std::string UndoRedo::Undo()
{
    if(_point>1)    //si on a encore des données dans la file, on décrémente le pointeur
    {
        _point--;
    }
    return getUndoRedo(_point-1);
}

std::string UndoRedo::Redo()
{
    if(_point<_FileUndoRedo.size())  //si le pointeur est inférieur à la taille max, on l'incrémente.
    {
        _point++;
    }
    return getUndoRedo(_point-1);
}
