#include "Duree.h"
#include <iostream>
using namespace std;


bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}
bool operator!=(Duree const& a, Duree const& b)
{
    return !(a==b); //On utilise l'opérateur == qu'on a défini précédemment !
}
bool operator<(Duree const &a, Duree const& b)
{
    return a.estPlusPetitQue(b);
}
bool operator>(Duree const &a, Duree const& b)
{
    return !(a<b);
}
bool operator<=(Duree const &a, Duree const& b)
{
    return ((a<b) or (a==b));
}
bool operator>=(Duree const &a, Duree const& b)
{
    return ((a>b) or (a==b));
}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie += b;
    return copie;
}
Duree operator+(Duree const& a, int secondes)
{
    Duree copie(a);
    copie += secondes;
    return copie;
}

ostream& operator<<(ostream& flux, Duree const& duree)
{
    duree.afficher(flux);
    return flux;
}


int main()
{
    Duree duree1(2, 25, 28), duree2(0, 16, 33);
    
    cout << duree1 + duree2 << endl;

    return 0;
}

