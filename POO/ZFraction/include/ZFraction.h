#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION

#include <iostream>

class ZFraction
{
    private:
    int m_numerateur;
    int m_denominateur;

    public:
    ZFraction();
    ZFraction(int numerateur);
    ZFraction(int numerateur, int denominateur);

    void afficher(std::ostream &flux) const;

    ZFraction& simplifier();

    ZFraction& operator+=(ZFraction autre);
    ZFraction operator+(ZFraction autre);
    ZFraction& operator-=(ZFraction autre);
    ZFraction operator-(ZFraction autre);
    ZFraction& operator*=(ZFraction autre);
    ZFraction operator*(ZFraction autre);
    ZFraction& operator/=(ZFraction autre);
    ZFraction operator/(ZFraction autre);

    bool operator>(ZFraction autre);
    bool operator<(ZFraction autre);
    bool operator>=(ZFraction autre);
    bool operator<=(ZFraction autre);
    bool operator==(ZFraction autre);

    bool estEgal(ZFraction autre);
    bool estPlusPetit(ZFraction autre);

    int numerateur();
    int denominateur();

    double nombreReel();

    ZFraction& signe();

};

int pgcd(int a, int b);

#endif