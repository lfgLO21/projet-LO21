#include "constantefactory.h"

Constante * ConstanteFactory::toConstante(const std::string & str)
{
    std::vector <std::string> temp;

    if (str[0] == '\'')
    {
        // new Expression(str);
    }
    else
    {
        if (str.find('$') != std::string::npos)
        {
            temp = Parser::parse(str,'$');
            if(temp.size() > 2)
            {
                throw std::invalid_argument("Trop de '$' séparant le Complexe");
            }
            else
            {
                ConstanteFactory TMP;
                Constante* tmp1 = TMP.toConstante(temp.at(0));
                Constante* tmp2 = TMP.toConstante(temp.at(1));
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
                    throw std::invalid_argument("Trop de '.' séparant le Reel");
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
                        throw std::invalid_argument("Trop de '/' séparant la Fraction");
                    }
                    else
                    {
                        return new Rationnel(atoi((temp.at(0)).c_str()),atoi(temp.at(1).c_str()));
                    }
                }
                else
                {
                    return new Entier(atof(str.c_str()));
                }
           }
        }
    }
}
