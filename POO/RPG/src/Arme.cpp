#include "Arme.h"

using namespace std;

Arme::Arme(): m_nom("Épée nulle"), m_degats(10){}

Arme::Arme(string nom, int degats): m_nom(nom), m_degats(degats){}

int Arme::getDegats() const
{
    return m_degats;
}

string Arme::getNom() const
{
    return m_nom;
}

void Arme::changer(string nouveauNom, int nouveauDegats)
{
    m_nom = nouveauNom;
    m_degats = nouveauDegats;
}

void Arme::afficher() const
{
    cout << "Arme : " << m_nom << " (dégats : " << m_degats << ")" << endl;
}