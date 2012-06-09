#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parser
{
    private:

    public:
        Parser(){};
        ~Parser(){};

        static std::vector <std::string> traitementString(std::string str);
        static std::vector <std::string> parse(std::string,char c = ' ');
        static std::vector <std::string> parse2(std::string, char c = ' ');
        static void printVector(const std::vector<std::string> v);
};
#endif // PARSER_H
