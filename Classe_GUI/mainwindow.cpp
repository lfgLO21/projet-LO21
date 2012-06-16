#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->pileAffiche = 10;
    savepile.addSave(" @ ");

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

    ui->buttonComplexe->setEnabled(false);
    ui->buttonQuote->setEnabled(false);

    connect(ui->buttonDel,SIGNAL(clicked()),ui->inputLine,SLOT(clear()));

    connect(ui->button0,SIGNAL(clicked()),this,SLOT(button0Pressed()));
    QShortcut * clavier0 = new QShortcut(QKeySequence(Qt::Key_0), this->ui->inputLine);
    connect(clavier0, SIGNAL(activated()), this, SLOT(button0Pressed()));
    connect(ui->button1,SIGNAL(clicked()),this,SLOT(button1Pressed()));
    QShortcut * clavier1 = new QShortcut(QKeySequence(Qt::Key_1), this->ui->inputLine);
    connect(clavier1, SIGNAL(activated()), this, SLOT(button1Pressed()));
    connect(ui->button2,SIGNAL(clicked()),this,SLOT(button2Pressed()));
    QShortcut * clavier2 = new QShortcut(QKeySequence(Qt::Key_2), this->ui->inputLine);
    connect(clavier2, SIGNAL(activated()), this, SLOT(button2Pressed()));
    connect(ui->button3,SIGNAL(clicked()),this,SLOT(button3Pressed()));
    QShortcut * clavier3 = new QShortcut(QKeySequence(Qt::Key_3), this->ui->inputLine);
    connect(clavier3, SIGNAL(activated()), this, SLOT(button3Pressed()));
    connect(ui->button4,SIGNAL(clicked()),this,SLOT(button4Pressed()));
    QShortcut * clavier4 = new QShortcut(QKeySequence(Qt::Key_4), this->ui->inputLine);
    connect(clavier4, SIGNAL(activated()), this, SLOT(button4Pressed()));
    connect(ui->button5,SIGNAL(clicked()),this,SLOT(button5Pressed()));
    QShortcut * clavier5 = new QShortcut(QKeySequence(Qt::Key_5), this->ui->inputLine);
    connect(clavier5, SIGNAL(activated()), this, SLOT(button5Pressed()));
    connect(ui->button6,SIGNAL(clicked()),this,SLOT(button6Pressed()));
    QShortcut * clavier6 = new QShortcut(QKeySequence(Qt::Key_6), this->ui->inputLine);
    connect(clavier6, SIGNAL(activated()), this, SLOT(button6Pressed()));
    connect(ui->button7,SIGNAL(clicked()),this,SLOT(button7Pressed()));
    QShortcut * clavier7 = new QShortcut(QKeySequence(Qt::Key_7), this->ui->inputLine);
    connect(clavier7, SIGNAL(activated()), this, SLOT(button7Pressed()));
    connect(ui->button8,SIGNAL(clicked()),this,SLOT(button8Pressed()));
    QShortcut * clavier8 = new QShortcut(QKeySequence(Qt::Key_8), this->ui->inputLine);
    connect(clavier8, SIGNAL(activated()), this, SLOT(button8Pressed()));
    connect(ui->button9,SIGNAL(clicked()),this,SLOT(button9Pressed()));
    QShortcut * clavier9 = new QShortcut(QKeySequence(Qt::Key_9), this->ui->inputLine);
    connect(clavier9, SIGNAL(activated()), this, SLOT(button9Pressed()));

    connect(ui->buttonEnter,SIGNAL(clicked()),this,SLOT(enterPressed()));
    QShortcut * clavierEnter = new QShortcut(QKeySequence(Qt::Key_Execute), this->ui->inputLine);
    connect(clavierEnter, SIGNAL(activated()), this, SLOT(enterPressed()));

    connect(ui->buttonSpace,SIGNAL(clicked()),this,SLOT(spacePressed()));
    QShortcut * clavierSpace = new QShortcut(QKeySequence(Qt::Key_Space), this->ui->inputLine);
    connect(clavierSpace, SIGNAL(activated()), this, SLOT(spacePressed()));
    connect(ui->buttonDot,SIGNAL(clicked()),this,SLOT(dotPressed()));
    QShortcut * clavierDot = new QShortcut(QKeySequence(Qt::Key_Enter), this);
    connect(clavierDot, SIGNAL(activated()), this, SLOT(dotPressed()));
    QShortcut * clavierPlus = new QShortcut(QKeySequence(Qt::Key_Plus), this->ui->inputLine);
    connect(clavierPlus, SIGNAL(activated()), this, SLOT(plusPressed()));
    connect(ui->buttonPlus,SIGNAL(clicked()),this,SLOT(plusPressed()));
    QShortcut * clavierMoins = new QShortcut(QKeySequence(Qt::Key_Minus), this->ui->inputLine);
    connect(clavierMoins, SIGNAL(activated()), this, SLOT(moinsPressed()));
    connect(ui->buttonMoins,SIGNAL(clicked()),this,SLOT(moinsPressed()));
    connect(ui->buttonMul,SIGNAL(clicked()),this,SLOT(mulPressed()));
    QShortcut * clavierMul = new QShortcut(QKeySequence(Qt::Key_Asterisk), this->ui->inputLine);
    connect(clavierMul, SIGNAL(activated()), this, SLOT(mulPressed()));
    connect(ui->buttonDiv,SIGNAL(clicked()),this,SLOT(divPressed()));
    QShortcut * clavierDiv = new QShortcut(QKeySequence(Qt::Key_Slash), this->ui->inputLine);
    connect(clavierDiv, SIGNAL(activated()), this, SLOT(divPressed()));
    connect(ui->buttonSuppr,SIGNAL(clicked()),this,SLOT(supprPressed()));
    QShortcut * clavierSuppr = new QShortcut(QKeySequence(Qt::Key_Delete), this->ui->inputLine);
    connect(clavierSuppr, SIGNAL(activated()), this, SLOT(supprPressed()));
    connect(ui->buttonDel,SIGNAL(clicked()),this,SLOT(delPressed()));
    QShortcut * clavierDel = new QShortcut(QKeySequence(Qt::Key_Backspace), this->ui->inputLine);
    connect(clavierDel, SIGNAL(activated()), this, SLOT(delPressed()));
    connect(ui->buttonQuote,SIGNAL(clicked()),this,SLOT(quotePressed()));
    QShortcut * clavierQuote = new QShortcut(QKeySequence(Qt::Key_Apostrophe), this->ui->inputLine);
    connect(clavierQuote, SIGNAL(activated()), this, SLOT(quotePressed()));

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

    connect(ui->actionYes,SIGNAL(triggered()),this,SLOT(actionComplexe()));
    connect(ui->actionNo,SIGNAL(triggered()),this,SLOT(actionComplexe()));

    connect(ui->actionInteger,SIGNAL(triggered()),this,SLOT(actionType()));
    connect(ui->actionRational,SIGNAL(triggered()),this,SLOT(actionType()));
    connect(ui->actionFloat,SIGNAL(triggered()),this,SLOT(actionType()));

    connect(ui->action_Undo,SIGNAL(triggered()),this,SLOT(UndoPressed()));
    connect(ui->action_Redo,SIGNAL(triggered()),this,SLOT(RedoPressed()));

    connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(close()));

    connect(ui->actionClavierOn, SIGNAL(triggered()), this, SLOT(actionClavierOn()));
    connect(ui->actionClavierOff, SIGNAL(triggered()), this, SLOT(actionClavierOff()));
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
    std::string ustr;
    for(unsigned int j=0;j<pile.getSize();j++)
    {
        ustr+=pile.getConst(j)->toString()+'#';
    }
    ustr[ustr.size()-1]='@';
    ustr+=str.toStdString();
    savepile.addSave(ustr);
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
    if(ui->actionInteger->isChecked())
    {
        ui->inputLine->setText(ui->inputLine->text().append(" / "));
    }
    else
    {
        ui->inputLine->setText(ui->inputLine->text().append("/"));
    }
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
    {
        if(ui->actionRadian->isChecked())
        {
            ui->inputLine->setText(ui->inputLine->text().append("COS"));
        }
        else if(ui->actionDegre->isChecked())
        {
            ui->inputLine->setText(ui->inputLine->text().append("Cos"));
        }
    }

}

void MainWindow::sinPressed()
{
    if (ui->checkBoxHyperbolique->isChecked())
    {
        ui->inputLine->setText(ui->inputLine->text().append("SINH"));
    }
    else
    {
        if(ui->actionRadian->isChecked())
        {
            ui->inputLine->setText(ui->inputLine->text().append("SIN"));
        }
        else if(ui->actionDegre->isChecked())
        {
            ui->inputLine->setText(ui->inputLine->text().append("Sin"));
        }

    }
}

void MainWindow::tanPressed()
{
    if (ui->checkBoxHyperbolique->isChecked())
        ui->inputLine->setText(ui->inputLine->text().append("TANH"));
    else
        if(ui->actionRadian->isChecked())
        {
            ui->inputLine->setText(ui->inputLine->text().append("TAN"));
        }
        else if(ui->actionDegre->isChecked())
        {
            ui->inputLine->setText(ui->inputLine->text().append("Tan"));
        }
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
        Constante* c = pile.getConst(pile.getSize() -j-1);
        std::string tmp;
        if(c->getType()==Constante::EXPRESSION)
        {
            tmp = static_cast<const Expression*>(c)->getExpression();
        }
        else
        {
            tmp = c->toString();
        }
        list.append(tmp.c_str());
    }
    modele=new QStringListModel(list);
    ui->listPile->setModel(modele);
}

void MainWindow::UndoPressed()
{
    std::vector<std::string> CalculUndo=Parser::parse(savepile.Undo(),'@');
    std::vector<std::string> PileUndo=Parser::parse(CalculUndo[0],'#');
    pile.clear();
    for(int i=0;i<PileUndo.size();i++)
    {
        CF.toConstante2(PileUndo[i],pile);
    }
    ui->inputLine->setText(CalculUndo[1].c_str());
    update();

}

void MainWindow::RedoPressed()
{
    std::vector<std::string> CalculUndo=Parser::parse(savepile.Redo(),'@');
    std::vector<std::string> PileUndo=Parser::parse(CalculUndo[0],'#');
    pile.clear();
    for(int i=0;i<PileUndo.size();i++)
    {
        CF.toConstante2(PileUndo[i],pile);
    }
    ui->inputLine->setText(CalculUndo[1].c_str());
    update();
}

void MainWindow::actionComplexe()
{
    if(ui->actionYes->isChecked())
    {
        ui->buttonComplexe->setEnabled(true);
    }
    else if(ui->actionNo->isChecked())
    {
        ui->buttonComplexe->setEnabled(false);
    }
}

void MainWindow::actionType()
{
    if(ui->actionInteger->isChecked()||ui->actionRational->isChecked())
    {
        ui->buttonQuote->setEnabled(false);
    }
    else if(ui->actionFloat->isChecked())
    {
        ui->buttonQuote->setEnabled(true);
    }
}

void MainWindow::actionClavierOn()
{
    if (ui->actionClavierOn->isChecked())
    {
        cacherClavier(false);
    }
}

void MainWindow::actionClavierOff()
{
    if (ui->actionClavierOff->isChecked())
    {
        cacherClavier(true);
    }
}

void MainWindow::cacherClavier(const bool a)
{
    this->ui->button0->setHidden(a);
    this->ui->button1->setHidden(a);
    this->ui->button2->setHidden(a);
    this->ui->button3->setHidden(a);
    this->ui->button4->setHidden(a);
    this->ui->button5->setHidden(a);
    this->ui->button6->setHidden(a);
    this->ui->button7->setHidden(a);
    this->ui->button8->setHidden(a);
    this->ui->button9->setHidden(a);

    this->ui->buttonEnter->setHidden(a);

    this->ui->buttonSpace->setHidden(a);
    this->ui->buttonDot->setHidden(a);
    this->ui->buttonPlus->setHidden(a);
    this->ui->buttonMoins->setHidden(a);
    this->ui->buttonMul->setHidden(a);
    this->ui->buttonDiv->setHidden(a);
    this->ui->buttonSuppr->setHidden(a);
    this->ui->buttonDel->setHidden(a);
    this->ui->buttonQuote->setHidden(a);

    this->ui->buttonInv->setDisabled(a);
    this->ui->buttonInv->setHidden(a);
    this->ui->buttonSign->setDisabled(a);
    this->ui->buttonSign->setHidden(a);
    this->ui->buttonModulo->setDisabled(a);
    this->ui->buttonModulo->setHidden(a);
    this->ui->buttonComplexe->setHidden(a);
    this->ui->buttonCos->setDisabled(a);
    this->ui->buttonCos->setHidden(a);
    this->ui->buttonSin->setDisabled(a);
    this->ui->buttonSin->setHidden(a);
    this->ui->buttonTan->setDisabled(a);
    this->ui->buttonTan->setHidden(a);
    this->ui->buttonSqr->setDisabled(a);
    this->ui->buttonSqr->setHidden(a);
    this->ui->buttonCube->setDisabled(a);
    this->ui->buttonCube->setHidden(a);
    this->ui->buttonPow->setDisabled(a);
    this->ui->buttonPow->setHidden(a);
    this->ui->buttonSqrt->setDisabled(a);
    this->ui->buttonSqrt->setHidden(a);
    this->ui->buttonLn->setDisabled(a);
    this->ui->buttonLn->setHidden(a);
    this->ui->buttonLog->setDisabled(a);
    this->ui->buttonLog->setHidden(a);
    this->ui->buttonEval->setDisabled(a);
    this->ui->buttonEval->setHidden(a);

    this->ui->checkBoxHyperbolique->setDisabled(a);;
    this->ui->checkBoxHyperbolique->setHidden(a);
}
