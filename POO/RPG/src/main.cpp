#include <string>
#include "Personnage.h"
using namespace std;

int main()
    {
        Personnage david("David"), goliath("Goliath", "Planche de bois", 20);
        Personnage frereDeGoliath(goliath); //créé un objet copie exacte de goliath  

        goliath.attaquer(david);
        david.boirePotionDeVie(20);
        goliath.attaquer(david);
        david.attaquer(goliath);

        goliath.changerArme("Gros caillou pointu", 50);
        goliath.attaquer(david);
        david.sortBouleDeFeu(goliath);

        //Temps mort ! Voyons voir la vie de chacun…
        cout << david.getName() << endl;
        david.afficherEtat();
        cout << endl << goliath.getName() << endl;
        goliath.afficherEtat();

        return 0;
    }