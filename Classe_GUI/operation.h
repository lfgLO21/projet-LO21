#ifndef Operation_H
#define Operation_H

#include "constante.h"
#include "reel.h"
#include "entier.h"
#include "rationnel.h"
#include <cmath>

/*!
 *\class Operation
 *\brief Classe rassemblant l'ensemble des operations sur les Constantes
 * Les Methodes Application de chaque classe fait appel aux methode specifiques appelees dans les Classes Constantes
 */
class Operation
{
public:
    Operation();
};
/*!
 *\brief Fait appel a l'operation +
 */
struct Addition : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

/*!
 *\brief Fait appel a l'operation -
 */
struct Soustraction : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

/*!
 *\brief Fait appel a l'operation *
 */
struct Multiplication : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

/*!
 *\brief Fait appel a l'operation /
 */
struct Division : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

/*!
 *\brief Fait appel a l'operation =
 */
struct Egal : public Operation{
  static bool application(const Constante&, const Constante&);
};

/*!
 *\brief Fait appel a l'operation <
 */
struct Inferieur : public Operation{
    static bool application(const Constante&, const Constante&);
};

/*!
 *\brief Fait appel a l'operation POW()
 */
struct POW : public Operation{
  static Constante* application(const Constante&, const Constante&);
};

/*!
 *\brief Fait appel a l'operation SIGN()
 */
struct SIGN : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation SQR()
 */
struct SQUARE : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation CUBE()
 */
struct CUBE : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation INV()
 */
struct INV : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation SQRT()
 */
struct SQRT : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation COS()
 */
struct COS : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation COSH()
 */
struct COSH : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation SIN()
 */
struct SIN : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation SINH()
 */
struct SINH : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation TAN()
 */
struct TAN : public Operation{
  static Constante* application(const Constante&);
};

/*!
*\brief Fait appel a l'operation TANH()
 */
struct TANH : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation LOG()
 */
struct LOG : public Operation{
  static Constante* application(const Constante&);
};

/*!
 *\brief Fait appel a l'operation LN()
 */
struct LN : public Operation{
  static Constante* application(const Constante&);
};

#endif // Operation_H
