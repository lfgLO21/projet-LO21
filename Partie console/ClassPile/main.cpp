#include <iostream>
#include "pile.h"

using namespace std;

int main()
{
    std::cout<<"ok"<<endl;
    Pile test = Pile(10);
    int str1 = 1;
    int str2 = 2;
    int str3 = 3;
    int str4 = 4;
    int str5 = 5;
    int str6 = 6;
    int str7 = 7;
    int str8 = 8;

    test.push(str1);
    test.push(str2);
    test.push(str3);
    test.push(str6);

    test.SWAP(2,3);

    test.affiche();
    cout<<endl;
    test.pop();
    test.pop();

    test.affiche();
    cout<<endl;
    test.push(str2);
    test.push(str8);
    test.push(str5);
    test.push(str3);
    test.push(str4);
    test.push(str7);
    test.push(str5);
    test.push(str1);
    test.push(str6);
    test.push(str4);
    test.push(str7);
    test.push(str5);
    test.push(str1);
    test.push(str6);
    test.affiche();

    for(int i = 0;i<17;i++)
    {
        test.pop();
    }
    cout<<endl;
    test.affiche();

    test.push(str4);
    test.push(str7);
    test.push(str5);
    test.push(str1);
    test.push(str6);
    test.DUP();
    test.DROP();
    test.affiche();



    return 0;
}
