#include <iostream>
#include "reel.h"

using namespace std;

int main()
{
    reel a(16.5),b(3.1);
    reel c,d,e,f,g,h,i,j,k;
    c=a+b;
    d=a-b;
    e=a*b;
    f=a/b;
    h=SQR(b);
    i=CUBE(b);
    j=LOG(b);
    k=SQRT(a);
    a.affiche();
    b.affiche();
    c.affiche();
    d.affiche();
    e.affiche();
    f.affiche();
    h.affiche();
    i.affiche();
    j.affiche();
    k.affiche();
    a.SIGN();
    a.affiche();
    return 0;
}

