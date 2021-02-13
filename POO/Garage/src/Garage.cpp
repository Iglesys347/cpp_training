#include "Garage.h"
#include <vector>
using namespace std;

Vehicule::Vehicule(int prix)
    :m_prix(prix)
{}

void Vehicule::affiche() const
{
    cout << "Ceci est un vehicule coutant " << m_prix << " euros." << endl;
}

Vehicule::~Vehicule()
{}

Garage::Garage()
{
}

void Garage::ajouter(Vehicule *vehicule)
{
    m_vehicules.push_back(vehicule);
}

void Garage::supprimer(Vehicule *vehicule)
{
    for(int i(0); i<m_vehicules.size(); ++i)
    {
        if (m_vehicules[i] == vehicule)
        {
            delete m_vehicules[i];  //On libère la i-ème case mémoire allouée
            m_vehicules[i] = 0;
        }
    }
}

void Garage::afficher() const
{
    for(int i(0); i<m_vehicules.size(); ++i)
    {
        m_vehicules[i]->affiche();
    }
}

Garage::~Garage()
{}


Voiture::Voiture(int prix, int portes)
    :Vehicule(prix), m_portes(portes)   
{}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes et coutant " << m_prix << " euros." << endl;
}

int Voiture::nbRoues() const
{
    return 4;
} 

Voiture::~Voiture()
{}

Moto::Moto(int prix, double vitesseMax)
    :Vehicule(prix), m_vitesse(vitesseMax)
{}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
}

int Moto::nbRoues() const
{
    return 2;
}

Moto::~Moto()
{}

Camion::Camion(int prix, double poidsMax): Vehicule(prix), m_poidsMax(poidsMax){}

void Camion::affiche() const
{
    cout << "Ceci est un camion pouvant transporter " << m_poidsMax << " kg et coutant " << m_prix << " euros." << endl;
}

int Camion::nbRoues() const
{
    return 4;
} 

Camion::~Camion(){}

int main()
{
    Moto maMoto(1000,200);
    Voiture maVoiture(1000,5);
    Camion monCamion(1000, 100);
    Garage monGarage;
    monGarage.ajouter(&maMoto);
    monGarage.ajouter(&maVoiture);
    monGarage.ajouter(&monCamion);

    monGarage.afficher();


    return 0;
}