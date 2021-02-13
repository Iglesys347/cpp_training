#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN
 
#include <iostream>
#include <string>
#include "Personnage.h"
 
class Magicien : public Personnage
{
    public:
        Magicien(std::string nom);   //Constructeur par défaut
        void bouleDeFeu() const;
        void bouleDeGlace() const;
};
 
#endif