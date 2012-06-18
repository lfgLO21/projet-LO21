#ifndef CONTEXTE_H
#define CONTEXTE_H


#include <QFile>
#include <iostream>
#include <fstream>
#include "qsettings.h"
#include "qdebug.h"
#include "QtXml/QDomDocument"

#include "pile.h"
#include "mainwindow.h"
#include "logsystem.h"

using namespace std;

class Etat
{
    public:
        enum CheckComplexe {COMPLEXE = 0, NOCOMPLEXE = 1};
        enum CheckAngle {DEGRES = 0, RADIANS = 1};
        enum CheckType {ENTIER = 0, RATIONNEL = 1, REEL = 2};

    private:
         int _useComplexe;
         int _typeAngle;
         int _typeDonnee;

         unsigned int _nbElementPileAffiche;

         static Etat * _instance;
         Etat();
         Etat(int cc, int ca, int ct, unsigned int nbA, std::string p);
         ~Etat();

    public:
        static Etat* getInstance();
        static void libereInstance();

        int getUseComplexe() const;
        int getTypeAngle() const;
        int getTypeDonnee() const;
        unsigned int getNbElementPileAffiche() const;

        void setUseComplexe(int cc);
        void setTypeAngle (int ca);
        void setTypeDonnee (int ct);
        void setNbElementPileAffiche(unsigned int n);
};

class Contexte
{
    private:
        static Contexte * _instance;

        Contexte();
        Contexte(const Contexte& c);
        //void operator=() const (Contexte & c);

        ~Contexte();

    public:
        static Contexte *getInstance();
        static void libereInstance();

        void saveContexte() const;
        void loadContexte();
    };

#endif // CONTEXTE_H
