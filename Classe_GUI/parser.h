#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*!
 *\class Parser
 *\brief Classe de methodes statics splittant des String en vue de les traiter plus tard dans un ConstanteFactory
 * Chaque String en découper en element selon un séparateur définit et ajouter dans un vector<String> en attente du traitement
 */
class Parser
{
    private:

    public:
        /*!
         *\brief Constructeur (relativement inutile puisque la classe est un rassemblement de methode et fonctionne sans attribut)
         */
        Parser(){}
        /*!
         *\brief Destructeur (relativement inutile aussi puisque la classe est un rassemblement de methode et fonctionne sans attribut)
         */
        ~Parser(){}

        /*!
         *\brief Methode de traitement spécifique à la calculatrice qui prend un string en entree et le traite
         */
        static std::vector <std::string> traitementString(std::string str);
        /*!
         *\brief Methode statique qui prend un string et le decoupe en un vector<String> dont les separator passes en parametres sont supprimes de la chaine resultante
         */
        static std::vector <std::string> parse(std::string,char c = ' ');
        /*!
         *\brief Methode statique qui prend un string et le decoupe en un vector<String> dont les separator passes en parametres sont conserves dans la chaine resultante
         */
        static std::vector <std::string> parse2(std::string, char c = ' ');
        /*!
         *\brief Methode statique qui affiche le vector<String> apres le traitement, chaque string entouré des caracteres '[' et ']'
         */
        static void printVector(const std::vector<std::string> v);
};
#endif // PARSER_H
