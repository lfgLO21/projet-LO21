#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include <iostream>
#include <cstdlib>

#include "constante.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "complexe.h"

#include "parser.h"

class ConstanteFactory
{
    public:
        static Constante * toConstante(const std::string & str);
};

#endif // CONSTANTEFACTORY_H
