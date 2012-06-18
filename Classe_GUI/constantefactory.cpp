#include "constantefactory.h"
/*!
 *\fn void ConstanteFactory::toConstante2(string, Pile)
 *\brief Methode construisant un objet de la classe Operation a partir d'un string
 *\param prend un string en entree et une pile destinee a recevoir le resultat des calculs
 *\return void
 */
void ConstanteFactory::toConstante2(const std::string & str, Pile& P)
{
    ConstanteFactory TMP;
    Constante *C1, *C2;
    if(str == "+")
    {
        C1=P.pop();
        C2=P.pop();
        if(C1==0||C2==0)
        {
                throw std::invalid_argument("deux arguments sont necessaire");
        }
        P.push(Addition::application(*C1,*C2));
    }
    else if(str == "-")
    {
        C1=P.pop();
        C2=P.pop();
        if(C1==0||C2==0)
        {
                throw std::invalid_argument("deux arguments sont necessaire");
        }
        P.push(Soustraction::application(*C1,*C2));
    }
    else if(str == "*")
    {
        C1=P.pop();
        C2=P.pop();
        if(C1==0||C2==0)
        {
                throw std::invalid_argument("deux arguments sont necessaire");
        }
        P.push(Multiplication::application(*C1,*C2));
    }
    else if(str == "/")
    {
        C1=P.pop();
        C2=P.pop();
        if(C1==0||C2==0)
        {
                throw std::invalid_argument("deux arguments sont necessaire");
        }
        P.push(Division::application(*C1,*C2));
    }
    else if(str == "POW")
    {
        C1=P.pop();
        C2=P.pop();
        if(C1==0||C2==0)
        {
                throw std::invalid_argument("deux arguments sont necessaire");
        }
        P.push(POW::application(*C1,*C2));
    }
    else if(str == "MOD")
    {
        C1=P.pop();
        C2=P.pop();
        if(C1==0||C2==0)
        {
                throw std::invalid_argument("deux arguments sont necessaire");
        }
        P.push(static_cast<Entier*>(C2)->operator %(*static_cast<Entier*>(C1)));
    }
    else if(str == "!"){
            C1=P.pop();
            P.push(static_cast<Entier*>(C1)->operator !());
    }
    else if(str == "SIGN"){
            C1 = P.pop();
            P.push(-(*C1));
    }
    else if(str == "SQR"){
            C1 = P.pop();
            P.push(SQUARE::application(*C1));
    }
    else if(str == "CUBE"){
        C1 = P.pop();
        P.push(CUBE::application(*C1));
    }
    else if(str == "INV"){
        C1 = P.pop();
        P.push(INV::application(*C1));
    }
    else if(str == "SQRT"){
        C1 = P.pop();
        P.push(SQRT::application(*C1));
    }
    else if(str == "SIN"){
        C1 = P.pop();
        P.push(SIN::application(*C1));
    }
    else if(str == "Sin"){
        C1 = P.pop();
        float c = (M_PI/180);
        Reel tmp(c);
        Constante* tmp2(&tmp);
        P.push(SIN::application(*(Multiplication::application(*C1,*tmp2))));
    }
    else if(str == "COS"){
        C1 = P.pop();
        P.push(COS::application(*C1));
    }
    else if(str == "Cos"){
        C1 = P.pop();
        float c = (M_PI/180);
        Reel tmp(c);
        Constante* tmp2(&tmp);
        P.push(COS::application(*(Multiplication::application(*C1,*tmp2))));
    }
    else if(str == "TAN"){
        C1 = P.pop();
        P.push(TAN::application(*C1));
    }
    else if(str == "Tan"){
        C1 = P.pop();
        float c = (M_PI/180);
        Reel tmp(c);
        Constante* tmp2(&tmp);
        P.push(TAN::application(*(Multiplication::application(*C1,*tmp2))));
    }
    else if(str == "SINH"){
        C1 = P.pop();
        P.push(SINH::application(*C1));
    }
    else if(str == "COSH"){
        C1 = P.pop();
        P.push(COSH::application(*C1));
    }
    else if(str == "TANH"){
        C1 = P.pop();
        P.push(TANH::application(*C1));
    }
    else if(str == "LOG"){
        C1 = P.pop();
        P.push(LOG::application(*C1));
    }
    else if(str == "LN"){
        C1 = P.pop();
        P.push(LN::application(*C1));
    }
    else if(str == "EVAL")
    {
        C1 = P.pop();
        std::string str = C1->toString();
        std::vector<std::string> entree = Parser::traitementString(str);
        for(unsigned int i = 0;i<entree.size();i++)
        {
            TMP.toConstante2(entree[i],P);
        }
    }
    else
    {
        P.push(TMP.toConstante1(str));
    }
    LogSystem::printLog(LogMessage("Fabrication des Operations",5));
}
/*!
 *\fn Constante * ConstanteFactory::toConstante1(string)
 *\brief Methode construisant des objets de la classe constante a partir de string
 *\param une chaine de caractere et une pile ou l'empiler
 *\return void
 */
Constante * ConstanteFactory::toConstante1(const std::string & str)
{
    std::vector <std::string> temp;

    if (str.find('\'') != std::string::npos)
    {
        return new Expression(str);
    }
    else
    {
        if (str.find('$') != std::string::npos)
        {
            temp = Parser::parse(str,'$');
            if(temp.size() > 2)
            {
                throw std::invalid_argument("Trop de '$' separant le Complexe");
            }
            else
            {
                ConstanteFactory TMP;
                Constante* tmp1 = TMP.toConstante1(temp.at(0));
                Constante* tmp2 = TMP.toConstante1(temp.at(1));
                return new Complexe(tmp1,tmp2);
            }
        }
        else
        {
            if (str.find('.') != std::string::npos)
            {
                temp = Parser::parse(str,'.');
                if(temp.size() > 2)
                {
                    throw std::invalid_argument("Trop de '.' separant le Reel");
                }
                else
                {
                    return new Reel(atof(str.c_str()));
                }
            }
            else
            {
                if ((str != "/")&&(str.find('/') != std::string::npos))
                {
                    temp = Parser::parse(str,'/');
                    if(temp.size() > 2)
                    {
                        throw std::invalid_argument("Trop de '/' separant la Fraction");
                    }
                    else
                    {
                        return new Rationnel(atoi((temp.at(0)).c_str()),atoi((temp.at(1)).c_str()));
                    }
                }
                else
                {
                    return new Entier(atof(str.c_str()));
                }
           }
        }
    }
    LogSystem::printLog(LogMessage("Fabrication des Constantes",5));
}
