#include <iostream>
#include <string>
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "constante.h"
#include "constantefactory.h"

using namespace std;

int main()
{
    ConstanteFactory tmp;
    Constante* t = tmp.toConstante("5.8");
    t->affiche();
    cout<<endl;
    Constante* a = tmp.toConstante("5");
    Constante* b = tmp.toConstante("2");
    Constante* g = tmp.toConstante("2$9");
    Constante* h = tmp.toConstante("12/4$-15/3");
    g->affiche();
    cout<<endl;
    h->affiche();
    cout<<endl;
    a->affiche();
    cout<<endl;
    b->affiche();
    cout<<endl;
    Constante *c, *d, *e, *f, *i;
    c=(*a)+(*b);
    d=(*a)-(*b);
    e=(*a)*(*b);
    f=(*a)/(*b);
    i=SIN::application(*a);
    c->affiche();
    cout<<endl;
    d->affiche();
    cout<<endl;
    e->affiche();
    cout<<endl;
    f->affiche();
    cout<<endl;
    i->affiche();
    cout<<endl;
    return 0;
}
