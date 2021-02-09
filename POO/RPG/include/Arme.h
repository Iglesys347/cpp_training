#ifndef DEF_ARME
#define DEF_ARME

#include <string>
#include <iostream>

class Arme
{
    private:
    std::string m_nom;
    int m_degats;

    public:
    Arme();
    Arme(std::string nom, int degats);
    int getDegats() const;
    std::string getNom() const;
    void changer(std::string nom, int degats);
    void afficher() const;
};

#endif