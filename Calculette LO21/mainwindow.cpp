#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->clearButton,SIGNAL(clicked()),ui->inputLine,SLOT(clear()));

    connect(ui->num0Button,SIGNAL(clicked()),this,SLOT(num0Pressed()));
    connect(ui->num1Button,SIGNAL(clicked()),this,SLOT(num1Pressed()));
    connect(ui->num2Button,SIGNAL(clicked()),this,SLOT(num2Pressed()));
    connect(ui->num3Button,SIGNAL(clicked()),this,SLOT(num3Pressed()));
    connect(ui->num4Button,SIGNAL(clicked()),this,SLOT(num4Pressed()));
    connect(ui->num5Button,SIGNAL(clicked()),this,SLOT(num5Pressed()));
    connect(ui->num6Button,SIGNAL(clicked()),this,SLOT(num6Pressed()));
    connect(ui->num7Button,SIGNAL(clicked()),this,SLOT(num7Pressed()));
    connect(ui->num8Button,SIGNAL(clicked()),this,SLOT(num8Pressed()));
    connect(ui->num9Button,SIGNAL(clicked()),this,SLOT(num9Pressed()));

    connect(ui->spaceButton,SIGNAL(clicked()),this,SLOT(spacePressed()));
    connect(ui->pointButton,SIGNAL(clicked()),this,SLOT(pointPressed()));
    connect(ui->plusButton,SIGNAL(clicked()),this,SLOT(plusPressed()));
    connect(ui->lessButton,SIGNAL(clicked()),this,SLOT(lessPressed()));
    connect(ui->mulButton,SIGNAL(clicked()),this,SLOT(mulPressed()));
    connect(ui->divButton,SIGNAL(clicked()),this,SLOT(divPressed()));
    connect(ui->supprButton,SIGNAL(clicked()),this,SLOT(supprPressed()));

    connect(ui->enterButton,SIGNAL(clicked()),this,SLOT(enterPressed()));

    connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(close()));
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

void MainWindow::enterPressed()
{
    QStringList list;
    QString st = ui->inputLine->text();
    list = st.split(" ");
    modele=new QStringListModel(list);
    ui->listPile->setModel(modele);
    ui->inputLine->clear();
}
