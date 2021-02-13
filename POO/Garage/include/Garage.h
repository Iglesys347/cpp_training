#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <vector>


class Vehicule
{
    public:
    Vehicule(int prix);
    virtual void affiche() const;
    virtual int nbRoues() const = 0;
    virtual ~Vehicule();

    protected:
    int m_prix;
};


class Garage
{
    public:
        Garage();
        void ajouter(Vehicule *nouveauVehicule);
        void supprimer(Vehicule *vehicule);
        void afficher() const;
        ~Garage();
    private:
        std::vector<Vehicule*> m_vehicules;
};

class Voiture: public Vehicule
{
    public:
    Voiture(int prix, int portes);
    //Construit une voiture dont on fournit le prix et le nombre de portes
    virtual void affiche() const;
    virtual int nbRoues() const;
    virtual ~Voiture();

    private:
    int m_portes;
};

class Moto : public Vehicule 
{
    public:
    Moto(int prix, double vitesseMax);
    //Construit une moto d'un prix donné et ayant une certaine vitesse maximale
    virtual void affiche() const;
    virtual int nbRoues() const;
    virtual ~Moto();
 
    private:
    double m_vitesse;
};

class Camion : public Vehicule
{
    public:
        Camion(int prix, double poidsMax);
        virtual void affiche() const;
        virtual int nbRoues() const;
        virtual ~Camion();
    private:
        float m_poidsMax;
};

#endif