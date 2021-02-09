#include <iostream>

using namespace std;

// Prototype avec des valeurs par défaut
int nbSecondes(int heures=0, int min=0, int sec=0);

int main()
{
    cout << nbSecondes(1, 10, 25) << endl;
    return 0;
}


int nbSecondes(int heures, int min, int sec)
{
    int res = 0;

    res += heures*60*60;
    res += min*60;
    res += sec;

    return res;
}