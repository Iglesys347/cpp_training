#include <iostream>
#include <vector>

using namespace std;

void affichageTableau(vector<string> const& tableau, int tailleTab)
{
    for(int i(0); i<tailleTab; i++)
    {
        cout << tableau[i] << endl;
    }
}
int main()
{
    int const tailleTab(10);
    vector<string> tab(tailleTab, "Je suis vide !"); //tabelau dynamique de taille 'tailleTab' avec comme valuer par defaut 0 pour les 10 champs
    tab.push_back("J'ai été ajouté en fin de tableau !");  //ajout à la fin du tab
    affichageTableau(tab, 11);
    for (int i(0); i<10; i++)
    {
        tab.pop_back();
    }
    cout << endl;
    affichageTableau(tab, 1);
    cout << tab.size() << endl;
}