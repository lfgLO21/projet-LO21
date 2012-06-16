#ifndef UNDOREDO_H
#define UNDOREDO_H

#include <QQueue>
#include <string>

class UndoRedo
{
    QQueue<std::string> _FileUndoRedo;
    int _taille;
    int _point;

public:
    UndoRedo(int t=10):_taille(t),_point(0){}

    const int getTaille()const{return _taille;}
    void setTaille(int t){_taille=t;}

    std::string getUndoRedo(int t)const;

    void addSave(std::string UR);

    std::string Undo();
    std::string Redo();

};

#endif // UNDOREDO_H
