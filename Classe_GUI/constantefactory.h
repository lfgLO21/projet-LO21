#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "expression.h"
#include "constante.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "complexe.h"
#include "operation.h"
#include "pile.h"
#include "parser.h"
/*!
 *\class ConstanteFactory
 *\brief fabrique, a partir de chaine de caractere des Constantes et des operations
 */
class ConstanteFactory
{
    public:
        /*!
         *\brief fabrique des constantes a partir de la chainde de caracteres passee en parametre
         */
        static Constante* toConstante1(const string &str);
        /*!
         *\brief fabrique des operations et les effectue sur une pile de constantes
         */
        static void toConstante2(const std::string & str, Pile& P);
};

#endif // CONSTANTEFACTORY_H
