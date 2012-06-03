#include <iostream>
#include "entier.h"

using namespace std;

int main()
{
    entier a(16),b(3);
    entier c,d,e,f,g,h,i,l;
    c=a+b;
    d=a-b;
    e=a*b;
    f=a/b;
    g=MOD(a,b);
    h=SQR(b);
    i=CUBE(b);
    l=fact(b);
    float j,k;
    j=LOG(b);
    k=SQRT(a);
    a.affiche();
    b.affiche();
    c.affiche();
    d.affiche();
    e.affiche();
    f.affiche();
    g.affiche();
    h.affiche();
    i.affiche();
    cout<<j<<endl;
    cout<<k<<endl<<endl;
    l.affiche();
    a.SIGN();
    a.affiche();
    return 0;
}

