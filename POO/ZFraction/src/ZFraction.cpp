#include "ZFraction.h"

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

ZFraction::ZFraction(): m_numerateur(0), m_denominateur(1){}

ZFraction::ZFraction(int numerateur): m_numerateur(numerateur), m_denominateur(1){}

ZFraction::ZFraction(int numerateur, int denominateur)
{
    int PGCD = pgcd(numerateur, denominateur);
    m_numerateur = numerateur / PGCD;
    m_denominateur = denominateur / PGCD;
}

void ZFraction::afficher(std::ostream &flux) const
{
    if (m_denominateur != 1)
    {
        flux << m_numerateur << "/" << m_denominateur;
    }
    else
    {
        flux << m_numerateur;
    }
}

ZFraction& ZFraction::simplifier()
{
    int PGCD = pgcd(m_numerateur, m_denominateur);
    m_numerateur = m_numerateur / PGCD;
    m_denominateur = m_denominateur / PGCD;
    return *this;
}

ZFraction& ZFraction::signe()
{
    //Si le signe est au dénominateur seulement
    if(m_numerateur >= 0 && m_denominateur <0)
    {
        m_numerateur = -m_numerateur;
        m_denominateur = -m_denominateur;
    }

    //Si le signe est au numérateur et au dénominateur
    else if(m_numerateur < 0 && m_denominateur <0)
    {
        m_numerateur = -m_numerateur;
        m_denominateur = -m_denominateur;
    }

    //Dans tous les autres cas, il n'y a rien à faire
    return *this;
}

ZFraction& ZFraction::operator+=(ZFraction autre)
{
    // a/b + c/d = (ad+cb)/bd
    m_numerateur = m_numerateur*autre.m_denominateur + autre.m_numerateur*m_denominateur;
    m_denominateur = m_denominateur * autre.m_denominateur;

    this->simplifier();

    return *this;
}

ZFraction& ZFraction::operator-=(ZFraction autre)
{
    // a/b + c/d = (ad+cb)/bd
    m_numerateur = m_numerateur*autre.m_denominateur - autre.m_numerateur*m_denominateur;
    m_denominateur = m_denominateur * autre.m_denominateur;

    this->simplifier();

    return *this;
}

ZFraction ZFraction::operator+(ZFraction autre)
{
    ZFraction copie(*this);
    copie += autre;
    return copie;
}

ZFraction ZFraction::operator-(ZFraction autre)
{
    ZFraction copie(*this);
    copie -= autre;
    return copie;
}

ZFraction& ZFraction::operator*=(ZFraction autre)
{
    m_numerateur *= autre.m_numerateur;
    m_denominateur *= autre.m_denominateur;

    this->simplifier();

    return *this;
}

ZFraction& ZFraction::operator/=(ZFraction autre)
{
    m_numerateur *= autre.m_denominateur;
    m_denominateur *= autre.m_numerateur;

    this->simplifier();
    this->signe();
    return *this;
}

ZFraction ZFraction::operator*(ZFraction autre)
{
    ZFraction copie(*this);
    copie *= autre;
    return copie;
}

ZFraction ZFraction::operator/(ZFraction autre)
{
    ZFraction copie(*this);
    copie /= autre;
    return copie;
}

bool ZFraction::estEgal(ZFraction autre)
{
    return (m_numerateur==autre.m_numerateur and m_denominateur==autre.m_denominateur);
}

bool ZFraction::estPlusPetit(ZFraction autre)
{
    /* Pour comparer deux fractions on les met sous le même dénominateur
     * a/b > c/d devient ad/bd > cb/bd <=> ad > cb */
    return m_numerateur*autre.m_denominateur < autre.m_numerateur*m_denominateur;
}

bool ZFraction::operator>(ZFraction autre)
{
    return autre.estPlusPetit(*this);
}

bool ZFraction::operator<(ZFraction autre)
{
    return !(this->estPlusPetit(autre));
}

bool ZFraction::operator>=(ZFraction autre)
{
    return !(*this < autre);
}

bool ZFraction::operator<=(ZFraction autre)
{
    return !(*this > autre);
}


bool ZFraction::operator==(ZFraction autre)
{
    return estEgal(autre);
}

int ZFraction::numerateur()
{
    return m_numerateur;
}

int ZFraction::denominateur()
{
    return m_denominateur;
}

double ZFraction::nombreReel()
{
    double num(m_numerateur);
    double den(m_denominateur);
    return num/den;
}



