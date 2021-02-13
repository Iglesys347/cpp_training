#ifndef DEF_GUERRIER
#define DEF_GUERRIER

#include <iostream>
#include <string>
#include "Personnage.h"

class Guerrier : public Personnage
{
    public:
        Guerrier(std::string nom);
        void frappeEnragee() const;
        void sePresenter() const;
};

#endif