#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    Fraction a(12,-16),b(2,3);
    Fraction c,d,e,f,g,h,i;
    c = a+b;
    d=a-b;
    e=a*b;
    f=a/b;
    g=INV(a);
    h=SQR(b);
    i=CUBE(b);
    float j;
    j=LOG(b);
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
    a.SIGN();
    a.affiche();


    return 0;
}

