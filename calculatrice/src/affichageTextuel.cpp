#include <iostream>
#include <tuple>

#include "affichageTextuel.h"

using namespace std;


void affichageEntete()
{
    cout << "Ce programme peut effectuer différent calculs :" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Soustraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Entrez le numéro de votre choix (1 pour l'addition par exemple): ";
}

tuple<double, double> demandeNombres()
{
    double a, b;
    cout << "Entrez le premier nombre : ";
    cin >> a;
    cout << "Entrez le second nombre : ";
    cin >> b;
    return make_tuple(a, b);
}