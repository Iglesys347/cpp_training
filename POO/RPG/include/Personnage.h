#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"

class Personnage
{
    private:    //tout ce qui suit sera privé (ça l'est déjà par défaut)
    std::string m_nom;
    int m_vie;
    int m_mana;
    Arme *m_arme;

    public: //tout ce qui va suivre sera public

    Personnage(std::string nom);   //Constructeur par défaut
    Personnage(std::string nom, std::string nomArme, int degatsArme);    //surcharge de constructeur
    Personnage(std::string nom, int vie, int mana);

    Personnage(Personnage &const personnageACopier);    //constructeur de copie

    ~Personnage();  //destructeur de la classe (ici inutile mais à titre d'exemple)

    void recevoirDegats(int nbDegats);

    void attaquer(Personnage &cible);

    void sortBouleDeFeu(Personnage &cible);

    void boirePotionDeVie(int nbPdvARecuperer);

    void changerArme(std::string nomArme, int degatsArme);

    bool estVivant() const; //ajout mot clé const en fin de méthode signifie que la méthode est constante (ie elle ne modifie pas l'objet)

    void afficherEtat() const;

    std::string getName() const;

};
#endif