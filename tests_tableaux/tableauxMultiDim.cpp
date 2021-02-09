#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int const nbLignes(5);
    int const nbColonnes(4);

    int tab[nbLignes][nbColonnes];

    for (int i(0); i<nbLignes; i++)
    {
        for (int j(0); j<nbColonnes; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}