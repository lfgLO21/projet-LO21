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

class ConstanteFactory
{
    public:
        static Constante* toConstante1(const string &str);
        static void toConstante2(const std::string & str, Pile& P);
};

#endif // CONSTANTEFACTORY_H
