#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->pileAffiche = 10;

    QActionGroup* complexGroup = new QActionGroup(this);
    QActionGroup* typeGroup = new QActionGroup(this);
    QActionGroup* degreGroup = new QActionGroup(this);
    QActionGroup* clavierGroup = new QActionGroup(this);

    ui->actionYes->setActionGroup(complexGroup);
    ui->actionNo->setActionGroup(complexGroup);

    ui->actionInteger->setActionGroup(typeGroup);
    ui->actionFloat->setActionGroup(typeGroup);
    ui->actionRational->setActionGroup(typeGroup);

    ui->actionDegre->setActionGroup(degreGroup);
    ui->actionRadian->setActionGroup(degreGroup);

    ui->actionClavierOn->setActionGroup(clavierGroup);
    ui->actionClavierOff->setActionGroup(clavierGroup);

    connect(ui->buttonDel,SIGNAL(clicked()),ui->inputLine,SLOT(clear()));

    connect(ui->button0,SIGNAL(clicked()),this,SLOT(button0Pressed()));
    connect(ui->button1,SIGNAL(clicked()),this,SLOT(button1Pressed()));
    connect(ui->button2,SIGNAL(clicked()),this,SLOT(button2Pressed()));
    connect(ui->button3,SIGNAL(clicked()),this,SLOT(button3Pressed()));
    connect(ui->button4,SIGNAL(clicked()),this,SLOT(button4Pressed()));
    connect(ui->button5,SIGNAL(clicked()),this,SLOT(button5Pressed()));
    connect(ui->button6,SIGNAL(clicked()),this,SLOT(button6Pressed()));
    connect(ui->button7,SIGNAL(clicked()),this,SLOT(button7Pressed()));
    connect(ui->button8,SIGNAL(clicked()),this,SLOT(button8Pressed()));
    connect(ui->button9,SIGNAL(clicked()),this,SLOT(button9Pressed()));

    connect(ui->buttonEnter,SIGNAL(clicked()),this,SLOT(enterPressed()));

    connect(ui->buttonSpace,SIGNAL(clicked()),this,SLOT(spacePressed()));
    connect(ui->buttonDot,SIGNAL(clicked()),this,SLOT(dotPressed()));
    connect(ui->buttonPlus,SIGNAL(clicked()),this,SLOT(plusPressed()));
    connect(ui->buttonMoins,SIGNAL(clicked()),this,SLOT(moinsPressed()));
    connect(ui->buttonMul,SIGNAL(clicked()),this,SLOT(mulPressed()));
    connect(ui->buttonDiv,SIGNAL(clicked()),this,SLOT(divPressed()));
    connect(ui->buttonSuppr,SIGNAL(clicked()),this,SLOT(supprPressed()));
    connect(ui->buttonDel,SIGNAL(clicked()),this,SLOT(delPressed()));
    connect(ui->buttonQuote,SIGNAL(clicked()),this,SLOT(quotePressed()));

    connect(ui->buttonInv,SIGNAL(clicked()),this,SLOT(invPressed()));
    connect(ui->buttonSign,SIGNAL(clicked()),this,SLOT(signPressed()));
    connect(ui->buttonModulo,SIGNAL(clicked()),this,SLOT(moduloPressed()));
    connect(ui->buttonComplexe,SIGNAL(clicked()),this,SLOT(complexePressed()));
    connect(ui->buttonCos,SIGNAL(clicked()),this,SLOT(cosPressed()));
    connect(ui->buttonSin,SIGNAL(clicked()),this,SLOT(sinPressed()));
    connect(ui->buttonTan,SIGNAL(clicked()),this,SLOT(tanPressed()));
    connect(ui->buttonSqr,SIGNAL(clicked()),this,SLOT(sqrPressed()));
    connect(ui->buttonCube,SIGNAL(clicked()),this,SLOT(cubePressed()));
    connect(ui->buttonPow,SIGNAL(clicked()),this,SLOT(powPressed()));
    connect(ui->buttonSqrt,SIGNAL(clicked()),this,SLOT(sqrtPressed()));
    connect(ui->buttonLn,SIGNAL(clicked()),this,SLOT(lnPressed()));
    connect(ui->buttonLog,SIGNAL(clicked()),this,SLOT(logPressed()));
    connect(ui->buttonEval,SIGNAL(clicked()),this,SLOT(evalPressed()));

    connect(ui->buttonAffiche,SIGNAL(clicked()),this,SLOT(affichePressed()));
    connect(ui->buttonSwap,SIGNAL(clicked()),this,SLOT(swapPressed()));
    connect(ui->buttonClearPile,SIGNAL(clicked()),this,SLOT(clearPilePressed()));
    connect(ui->buttonSum,SIGNAL(clicked()),this,SLOT(sumPressed()));
    connect(ui->buttonMean,SIGNAL(clicked()),this,SLOT(meanPressed()));
    connect(ui->buttonDup,SIGNAL(clicked()),this,SLOT(dupPressed()));
    connect(ui->buttonDrop,SIGNAL(clicked()),this,SLOT(dropPressed()));

    connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::setPileAffiche(unsigned int i)
{
    this->pileAffiche = i;
}

void MainWindow::button0Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("0"));
}

void MainWindow::button1Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("1"));
}

void MainWindow::button2Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("2"));
}

void MainWindow::button3Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("3"));
}

void MainWindow::button4Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("4"));
}

void MainWindow::button5Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("5"));
}

void MainWindow::button6Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("6"));
}

void MainWindow::button7Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("7"));
}

void MainWindow::button8Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("8"));
}

void MainWindow::button9Pressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("9"));
}

void MainWindow::enterPressed()
{
    QString str = ui->inputLine->text();
    std::vector <std::string> entree = Parser::traitementString(str.toStdString());

    for (unsigned int i = 0; i < entree.size(); i++)
    {
        //list.append(entree.at(i).c_str());
        CF.toConstante2(entree[i],pile);
    }

    update();
    ui->inputLine->clear();
}

void MainWindow::spacePressed()
{
    ui->inputLine->setText(ui->inputLine->text().append(" "));
}

void MainWindow::dotPressed()
{
    if(ui->actionFloat->isChecked())
    {
        ui->inputLine->setText(ui->inputLine->text().append("."));
    }
}

void MainWindow::plusPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("+"));
}

void MainWindow::moinsPressed()
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
    QRegExp RWL("^(.* )?(?:[\\S]+[ ]?)$");
    RWL.exactMatch(ui->inputLine->text());
    ui->inputLine->setText(RWL.cap(1));
    //ui->inputLine->setText(ui->inputLine->text().remove(ui->inputLine->text().size()-1,1));
}

void MainWindow::delPressed()
{
    ui->inputLine->del();
}

void MainWindow::quotePressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("'"));
}

void MainWindow::invPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("INV"));
}

void MainWindow::signPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("SIGN"));
}

void MainWindow::moduloPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("%"));
}

void MainWindow::complexePressed()
{
    if(ui->actionYes->isChecked())
    {
        ui->inputLine->setText(ui->inputLine->text().append("$"));
    }
}

void MainWindow::cosPressed()
{
    if (ui->checkBoxHyperbolique->isChecked())
        ui->inputLine->setText(ui->inputLine->text().append("COSH"));
    else
        ui->inputLine->setText(ui->inputLine->text().append("COS"));

}

void MainWindow::sinPressed()
{    
    if (ui->checkBoxHyperbolique->isChecked())
    {
        ui->inputLine->setText(ui->inputLine->text().append("SINH"));
    }
    else
    {
        ui->inputLine->setText(ui->inputLine->text().append("SIN"));
    }
}

void MainWindow::tanPressed()
{
    if (ui->checkBoxHyperbolique->isChecked())
        ui->inputLine->setText(ui->inputLine->text().append("TANH"));
    else
        ui->inputLine->setText(ui->inputLine->text().append("TAN"));
}

void MainWindow::sqrPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("SQR"));
}

void MainWindow::cubePressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("CUBE"));
}

void MainWindow::powPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("^"));
}

void MainWindow::sqrtPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("SQRT"));
}

void MainWindow::lnPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("LN"));
}

void MainWindow::logPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("LOG"));
}

void MainWindow::evalPressed()
{
    ui->inputLine->setText(ui->inputLine->text().append("EVAL"));
}

void MainWindow::affichePressed()
{
    Constante *n;
    n = pile.pop();
    this->setPileAffiche(std::floor(static_cast<Entier*>(n)->getEntier()));
    std::cout << this->pileAffiche <<endl;
    update();
}

void MainWindow::swapPressed()
{
    Constante *x, *y;
    x=pile.pop();
    y=pile.pop();
    pile.swap(static_cast<Entier*>(x)->getEntier()-1,static_cast<Entier*>(y)->getEntier()-1);
    update();
}

void MainWindow::clearPilePressed()
{
    while(pile.getSize()!=0)
    {
        pile.pop();
    }
    update();
}

void MainWindow::sumPressed()
{
    Constante *x;
    x=pile.pop();
    pile.sum(static_cast<Entier*>(x));
    update();
}

void MainWindow::meanPressed()
{
    Constante *x;
    x=pile.pop();
    pile.mean(static_cast<Entier*>(x));
    update();
}

void MainWindow::dupPressed()
{
    Constante *x;
    x=pile.pop();
    pile.push(x);
    pile.push(x);
    update();
}

void MainWindow::dropPressed()
{
    pile.pop();
    update();
}

void MainWindow::update()
{
    QStringList list;
    for (unsigned int j = 0; ((j < pile.getSize()) && (j < this->pileAffiche)); j++)
    {
        //list.append(entree.at(i).c_str());
        Constante* c = pile.getConst(j);
        const std::string tmp = c->toString();
        list.append(tmp.c_str());
    }
    modele=new QStringListModel(list);
    ui->listPile->setModel(modele);
}
