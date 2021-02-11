#include "Personnage.h"

#include "Arme.h"

using namespace std;

int const NB_MAX_PDV = 100;
int const NB_MAX_MANA = 100;

//Constructeurs
Personnage::Personnage(string nom): m_nom(nom), m_vie(NB_MAX_PDV), m_mana(NB_MAX_MANA), m_arme(0)
{
    m_arme = new Arme();
}
/* Equivalent de :
Personnage::Personnage()
{
    m_vie = NB_MAX_PDV;
    m_mana = NB_MAX_MANA;
}
*/
Personnage::Personnage(string nom, string nomArme, int degatsArme): m_nom(nom),
                                                                    m_vie(NB_MAX_PDV),
                                                                    m_mana(NB_MAX_MANA),
                                                                    m_arme(0)
{
    m_arme = new Arme(nomArme, degatsArme);
}

Personnage::Personnage(string nom, int vie, int mana):  m_nom(nom),
                                                        m_vie(vie),
                                                        m_mana(mana){}

Personnage::~Personnage()
{
    delete m_arme;  //on supprime le pointer vers arme
}

// Méthodes
void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;
    if (m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme->getDegats());
}

void Personnage::sortBouleDeFeu(Personnage &cible)
{
    if (m_mana >= 10)
    {
        m_mana -= 10;
        cible.recevoirDegats(20);
    }
}

void Personnage::boirePotionDeVie(int nbPdvARecuperer)
{
    m_vie += nbPdvARecuperer;
    if (m_vie > NB_MAX_PDV)
    {
        m_vie = NB_MAX_PDV;
    }
}

void Personnage::changerArme(string nomArme, int degatsArme)
{
    m_arme->changer(nomArme, degatsArme);
}

bool Personnage::estVivant() const
{
    return m_vie > 0;
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme->afficher();
}

string Personnage::getName() const
{
    return m_nom;
}

