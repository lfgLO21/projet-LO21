#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //création des radio button du menu
    QActionGroup* complexGroup = new QActionGroup(this);
    QActionGroup* typeGroup = new QActionGroup(this);
    QActionGroup* degreGroup = new QActionGroup(this);
    QActionGroup* clavierGroup = new QActionGroup(this);

    ui->actionYes->setActionGroup(complexGroup);
    ui->actionNo->setActionGroup(complexGroup);

    ui->actionInteger->setActionGroup(typeGroup);
    ui->actionFloat->setActionGroup(typeGroup);
    ui->actionRational->setActionGroup(typeGroup);

    ui->actionDegr->setActionGroup(degreGroup);
    ui->actionRadian->setActionGroup(degreGroup);

    ui->actionOui->setActionGroup(clavierGroup);
    ui->actionNon->setActionGroup(clavierGroup);


    //paramétrage des boutons du clavier
    connect(ui->clearButton,SIGNAL(clicked()),ui->inputLine,SLOT(clear())); //le bouton clear supprime toute la ligne que l'on a saisi

    connect(ui->num0Button,SIGNAL(clicked()),this,SLOT(num0Pressed())); //0
    connect(ui->num1Button,SIGNAL(clicked()),this,SLOT(num1Pressed())); //1
    connect(ui->num2Button,SIGNAL(clicked()),this,SLOT(num2Pressed())); //2
    connect(ui->num3Button,SIGNAL(clicked()),this,SLOT(num3Pressed())); //3
    connect(ui->num4Button,SIGNAL(clicked()),this,SLOT(num4Pressed())); //4
    connect(ui->num5Button,SIGNAL(clicked()),this,SLOT(num5Pressed())); //5
    connect(ui->num6Button,SIGNAL(clicked()),this,SLOT(num6Pressed())); //6
    connect(ui->num7Button,SIGNAL(clicked()),this,SLOT(num7Pressed())); //7
    connect(ui->num8Button,SIGNAL(clicked()),this,SLOT(num8Pressed())); //8
    connect(ui->num9Button,SIGNAL(clicked()),this,SLOT(num9Pressed())); //9

    connect(ui->spaceButton,SIGNAL(clicked()),this,SLOT(spacePressed()));   //bouton espace
    connect(ui->pointButton,SIGNAL(clicked()),this,SLOT(pointPressed()));   //.
    connect(ui->plusButton,SIGNAL(clicked()),this,SLOT(plusPressed()));     //+
    connect(ui->lessButton,SIGNAL(clicked()),this,SLOT(lessPressed()));     //-
    connect(ui->mulButton,SIGNAL(clicked()),this,SLOT(mulPressed()));       //*
    connect(ui->divButton,SIGNAL(clicked()),this,SLOT(divPressed()));       //bouton division
    connect(ui->supprButton,SIGNAL(clicked()),this,SLOT(supprPressed()));   //le bouton del supprime le dernier caractère entré
    connect(ui->quoteButton,SIGNAL(clicked()),this,SLOT(quotePressed()));   // '

    connect(ui->enterButton,SIGNAL(clicked()),this,SLOT(enterPressed()));   // le bouton enter exécute ce que l'on vient d'entrer et nettoie la ligne

    connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(close()));     //le choix Quit du menu permet de quitter le programme
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::num0Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("0"));
}

void MainWindow::num1Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("1"));
}

void MainWindow::num2Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("2"));
}

void MainWindow::num3Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("3"));
}

void MainWindow::num4Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("4"));
}

void MainWindow::num5Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("5"));
}

void MainWindow::num6Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("6"));
}

void MainWindow::num7Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("7"));
}

void MainWindow::num8Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("8"));
}

void MainWindow::num9Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("9"));
}

void MainWindow::spacePressed()
{
    ui->inputLine->setText(ui->inputLine->text().append(" "));
}

void MainWindow::pointPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("."));
}

void MainWindow::plusPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("+"));
}

void MainWindow::lessPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("-"));
}

void MainWindow::mulPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("*"));
}

void MainWindow::divPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("/"));
}

void MainWindow::supprPressed()
{

    ui->inputLine->setText(ui->inputLine->text().remove(ui->inputLine->text().size()-1,1));
}

void MainWindow::quotePressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("'"));
}

void MainWindow::enterPressed()
{
    QStringList list;
    QString st = ui->inputLine->text();
    list = st.split(" ");
    modele=new QStringListModel(list);
    ui->listPile->setModel(modele);
    ui->inputLine->clear();
}
