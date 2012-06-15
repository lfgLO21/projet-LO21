#include "parser.h"

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

    return tokens;
}

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
