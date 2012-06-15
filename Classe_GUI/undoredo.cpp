#include "undoredo.h"

std::string UndoRedo::getUndoRedo(int t)const  //renvoie le string contenue dans la file � la position t
{
    return _FileUndoRedo[t];
}

void UndoRedo::addSave(std::string UR)
{
    while(_FileUndoRedo.size()>_taille)     //si la file d�passe la taille maximal voulue, on enl�ve les premiers �l�ments de la file
    {
        _FileUndoRedo.pop_front();
    }
    while(_FileUndoRedo.size()!=_point)     //si en revanche le pointeur _point n'est pas � la fin de la file, cel� signifie qu'un undo a �t� fait, et qu'il faut supprimer les donn�es situ�es au del� du pointeur
    {
        _FileUndoRedo.pop_back();
    }
    _FileUndoRedo.push_back(UR);        //sinon on ajoute le nouveau string en bout de liste
    _point=_FileUndoRedo.size();        //et on place le pointeur � la fin de la file
}

std::string UndoRedo::Undo()
{
    if(_point>1)    //si on a encore des donn�es dans la file, on d�cr�mente le pointeur
    {
        _point--;
    }
    return getUndoRedo(_point-1);
}

std::string UndoRedo::Redo()
{
    if(_point<_FileUndoRedo.size())  //si le pointeur est inf�rieur � la taille max, on l'incr�mente.
    {
        _point++;
    }
    return getUndoRedo(_point-1);
}
