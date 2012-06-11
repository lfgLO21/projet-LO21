#ifndef Operation_H
#define Operation_H

#include "constante.h"
#include "reel.h"
#include "entier.h"
#include "rationnel.h"
#include <cmath>

class Operation
{
public:
    Operation();
};

struct Addition : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

struct Soustraction : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

struct Multiplication : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

struct Division : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

struct Egal : public Operation{
  static bool application(const Constante&, const Constante&);
};

struct Inferieur : public Operation{
    static bool application(const Constante&, const Constante&);
};

struct POW : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

struct SIGN : public Operation{
  static Constante* application(const Constante&);
};

struct SQUARE : public Operation{
  static Constante* application(const Constante&);
};

struct CUBE : public Operation{
  static Constante* application(const Constante&);
};

struct INV : public Operation{
  static Constante* application(const Constante&);
};

struct SQRT : public Operation{
  static Constante* application(const Constante&);
};

struct COS : public Operation{
  static Constante* application(const Constante&);
};

struct COSH : public Operation{
  static Constante* application(const Constante&);
};

struct SIN : public Operation{
  static Constante* application(const Constante&);
};

struct SINH : public Operation{
  static Constante* application(const Constante&);
};

struct TAN : public Operation{
  static Constante* application(const Constante&);
};

struct TANH : public Operation{
  static Constante* application(const Constante&);
};

struct LOG : public Operation{
  static Constante* application(const Constante&);
};

struct LN : public Operation{
  static Constante* application(const Constante&);
};

#endif // Operation_H
