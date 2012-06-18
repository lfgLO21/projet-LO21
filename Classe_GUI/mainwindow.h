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
/*!
 *\class MainWindow
 *\brief interface graphiqe de l'application (Qt) et ensemble des signaux et des slots permettant d'interagir avec l'utilisateur
 */
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
        /*!
         *\brief Methode correspondant au clic d'un bouton numerique
         */
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

        /*!
         *\brief Methode correspondant au clic de la touche de validation "entree"
         */
        void enterPressed();

        /*!
         *\brief Methodes correspondant aux operations classiques sur les constantes
         */
        void spacePressed();
        void dotPressed();
        void plusPressed();
        void moinsPressed();
        void mulPressed();
        void divPressed();
        void supprPressed();
        void delPressed();
        void quotePressed();

        /*!
         *\brief Methodes correspondant aux operations "inhabituelles" sur les constantes, c'est a dire les methodes ne touchant pas la totalite des constantes
         */
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

        /*!
         *\brief Methodes sur la pile
         */
        void affichePressed();
        void swapPressed();
        void clearPilePressed();
        void sumPressed();
        void meanPressed();
        void dupPressed();
        void dropPressed();

        /*!
         *\brief Methodes de retour en arriere et de retour en avant
         */
        void UndoPressed();
        void RedoPressed();

        /*!
         *\brief Methodes de gestion des fonctionnalites de la calculatrice
         */
        void actionComplexe();
        void actionType();

        void actionClavierOn();
        void actionClavierOff();
        void cacherClavier(const bool a);
        void actionParametre();

        /*!
         *\brief Methode de mise a jour de l'interface graphique
         */
        void update();
};

#endif // MAINWINDOW_H
