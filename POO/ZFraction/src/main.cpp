#include <iostream>
#include "ZFraction.h"
using namespace std;

ostream& operator<<(ostream& flux, ZFraction const& fraction)
{
    fraction.afficher(flux);
    return flux;
}

int main()
{
    ZFraction a(4,10);      //Déclare une fraction valant 4/5
    ZFraction b(3,-10);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    ZFraction g;
    ZFraction c,d;         //Déclare deux fractions valant 0
    double e;
    c = a-b;               //Calcule 4/5 + 2/1 = 14/5

    d = a/b;               //Calcule 4/5 * 2/1 = 8/5

    e = a.nombreReel();

    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    cout << g << endl;

    cout << a << "="  <<  e << endl;

    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;

    return 0;
}