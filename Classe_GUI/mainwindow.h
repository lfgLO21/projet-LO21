#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QActionGroup>
#include <QShortcut>
#include "pile.h"
#include "parser.h"
#include "constantefactory.h"
#include "undoredo.h"
#include "contexte.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    private:
        QStringListModel *modele;
        Ui::MainWindow *ui;
        Pile pile;
        UndoRedo savepile;
        unsigned int pileAffiche;
        ConstanteFactory CF;

        static MainWindow* _instance;


    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        static MainWindow * getInstance();
        static void libereInstance();

        void chargerNouveauContexte();

        Pile* getPile() {return (&pile);};

        void setPileAffiche(unsigned int i);
        void setInputLineEdit(const QString &str);

    public slots:

        void button0Pressed();
        void button1Pressed();
        void button2Pressed();
        void button3Pressed();
        void button4Pressed();
        void button5Pressed();
        void button6Pressed();
        void button7Pressed();
        void button8Pressed();
        void button9Pressed();

        void enterPressed();

        void spacePressed();
        void dotPressed();
        void plusPressed();
        void moinsPressed();
        void mulPressed();
        void divPressed();
        void supprPressed();
        void delPressed();
        void quotePressed();

        void invPressed();
        void signPressed();
        void moduloPressed();
        void factPressed();
        void complexePressed();
        void cosPressed();
        void sinPressed();
        void tanPressed();
        void sqrPressed();
        void cubePressed();
        void powPressed();
        void sqrtPressed();
        void lnPressed();
        void logPressed();
        void evalPressed();

        void affichePressed();
        void swapPressed();
        void clearPilePressed();
        void sumPressed();
        void meanPressed();
        void dupPressed();
        void dropPressed();

        void UndoPressed();
        void RedoPressed();

        void actionComplexe();
        void actionType();

        void actionClavierOn();
        void actionClavierOff();
        void cacherClavier(const bool a);
        void actionParametre();

        void update();
};

#endif // MAINWINDOW_H
