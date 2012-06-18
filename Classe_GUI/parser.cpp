#include "parser.h"
/*!
 *\fn vector <string> Parser::traitementString(string)
 *\brief Methode de decoupe d'une chaine de caractere en vue d'un traitement par le constante factory
 *\param une chaine de caractere contenant ussi bien des constanes que des operations
 *\return un vector de chaines de caracteres dont chaque case est potentiellement soit une constante soit une ooperation
 */
std::vector <std::string> Parser::traitementString(std::string str)
{
    std::vector <std::string> tokens;
    tokens = Parser::parse2(str,'\'');

    std::vector<std::string>::iterator it = tokens.begin();
    std::vector<std::string>temp;
    for(std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        if ((*it)[0] != '\'')
        {
            std::vector<std::string>temp2 = Parser::parse(*it);
            for (unsigned int i = 0; i < temp2.size(); i++)
            {
                temp.push_back(temp2.at(i));
            }
        }
        else
        {
            temp.push_back(*it);
        }
    }
    tokens = temp;

    //Parser::printVector(tokens);
    return tokens;
}

/*!
 *\fn vector <string> Parser::parse(string ,char)
 *\brief Methode de decoupe de chaine de caractere supprimant le separateur
 *\param une chaine a decouper str et un separateur c
 *\return un vector de chaine de caractere correspondant a la chaine entre separee a l'emplacement des separateurs
 */
std::vector <std::string> Parser::parse(std::string str,char c)
{
    std::vector <std::string> tokens;
    std::string accumulator;
    int i = str.size();

    while(i >= 0)
    {
        if ((str.size() == 0))
        {
            if(!accumulator.empty())
            {
                tokens.push_back(accumulator);
            }
            i--;
        }
        else
        {
            if (str[0] == c)
            {
                if (!accumulator.empty())
                {
                    tokens.push_back(accumulator);
                    accumulator.clear();
                }
                str.erase(0,1);
                i--;
            }
            else
            {
                accumulator += str.substr(0,1);
                str.erase(0,1);
                i--;
            }
        }
    }
    return tokens;
}

/*!
 *\fn vector <string> Parser::parse2(str, c)
 *\brief Methode de decoupe de chaine de caractere concervant le separateur
 *\param une chaine a decouper str et un separateur c
 *\return un vector de chaine de caractere correspondant a la chaine entre separee a l'emplacement des separateurs
 */
std::vector <std::string> Parser::parse2(std::string str, char c)
{
    std::vector <std::string> tokens;
    std::string accumulator;
    int i = str.size();

    while (i >= 0)
    {
        if (str.size() == 0)
        {
            if(!accumulator.empty())
            {
                tokens.push_back(accumulator);
            }
            i--;
        }
        else
        {
            if (str[0] == c)
            {
                if(!accumulator.empty())
                {
                    tokens.push_back(accumulator);
                    accumulator.clear();
                }
                else
                {
                    accumulator += str.substr(0,1);
                    str.erase(0,1);
                    i--;
                    while (str[0] != c && i >= 0)
                    {
                        accumulator += str.substr(0,1);
                        str.erase(0,1);
                        i--;
                    }
                    
                    accumulator += str.substr(0,1);
                    str.erase(0,1);
                    i--;
                    tokens.push_back(accumulator);
                    accumulator.clear();
                }
            }
            else
            {
                accumulator += str.substr(0,1);
                str.erase(0,1);
                i--;
            }
        }
    }
    return tokens;
}

void Parser::printVector(const std::vector<std::string> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        std::cout <<"["<< v.at(i) <<"]";
    }
    std::cout << std::endl;
}
