#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

string melangeLettres(string mot)
{
    srand(time(0));
    string res("");
    while (mot.size() != 0)
    {
        int nbAleatoire = rand() % mot.size();
        res += mot[nbAleatoire];
        mot.erase(nbAleatoire, 1);  //on retire la lettre du mot (le deuxième paramètre correspond au nombre de lettre à aretirer ici 1)
    }
    return res;
}

double calculScore(vector<int> scores)
{
    double res(0);
    for (int i(0); i<scores.size(); i++) 
    {
        res += scores[i];
    }
    return res/scores.size();
}

int nbLignesFichier(string nomFichier)
{
    int nbLignes = 0;
    ifstream in(nomFichier , ios::in);
    std::string ligne;
    while(std::getline(in, ligne))
    {
        nbLignes++;
    }
    in.close(); // serait automatiquement fermé à la sortie du bloc
    return nbLignes;
}

string piocherDansFichier()
{
    string res;
    srand(time(0));
    ifstream fichier("dico.txt");
    int nbAleatoire = rand() % nbLignesFichier("dico.txt");
    for (int i(0); i<nbAleatoire; i++)
    {
        getline(fichier, res);
    }
    res.pop_back();
    return res;
}

int main()
{
    string motAFaireDeviner, motMelange, motUtilisateur, solo, reponse;
    vector<int> scoreTab;
    int score;
    std::cout << "Jouer en solo ou à deux ? (s,d)" << endl;
    std::cin >> solo;
    do
    {
        score = 0;
        bool trouve(false);
        if (solo == "s")
        {
            motAFaireDeviner = piocherDansFichier();
            std::cout << motAFaireDeviner << endl;
        }
        else
        {
            std::cout << "Saisissez un mot à faire deviner : ";
            std::cin >> motAFaireDeviner;
        }
        for (int i(0); i<=10; i++)
        {
            std::cout << endl;
        }
        motMelange = melangeLettres(motAFaireDeviner);
        while (!trouve)
        {
            score++;
            cout << "Quel est ce mot ? " << endl;
            cout << motMelange << endl;
            std::cin >> motUtilisateur;
            if (motUtilisateur == motAFaireDeviner)
            {
                trouve = true;
            }
            else
            {
                std::cout << "Ce n'est pas le bon mot !" << endl << endl;
                cout << motUtilisateur.size() << "!=" << motAFaireDeviner.size() << endl;
            }
        }
        std::cout << "Bravo !" << endl;
        std::cout << "Voulez vous rejouer ? (o,n) ";
        std::cin >> reponse;
        scoreTab.push_back(score);
    } while (reponse == "o");
    std::cout << "Votre score final est : " << calculScore(scoreTab) << endl;
}