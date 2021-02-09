#include <iostream>
#include <tuple>

#include "operations.h"
#include "affichageTextuel.h"

using namespace std;

int main()
{
    int num;
    double a, b;
    affichageEntete();
    cin >> num;
    tuple<double, double> lesNombres(demandeNombres());
    switch (num)
    {
    case 1:
        a = addition(get<0>(lesNombres), get<1>(lesNombres));
        break;
    case 2:
        a = soustraction(get<0>(lesNombres), get<1>(lesNombres));
        break;
    case 3:
        a = multiplication(get<0>(lesNombres), get<1>(lesNombres));
        break;
    case 4:
        a = division(get<0>(lesNombres), get<1>(lesNombres));
        break;
    }
    cout << "Résultat : " << a << endl;
    return 0;
}
