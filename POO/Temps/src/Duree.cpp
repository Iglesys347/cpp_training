#include "Duree.h"
#include <iostream>

Duree::Duree(int heures, int minutes, int secondes):    m_heures(heures),
                                                        m_minutes(minutes),
                                                        m_secondes(secondes){}

bool Duree::estEgal(Duree const& b) const
{
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);     //Teste si a.m_heure == b.m_heure etc.  
}

bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)   // Si les heures sont différentes
        return true; 
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else              //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;
}

Duree& Duree::operator+=(const Duree& a)
{
    m_secondes += a.m_secondes;

    m_minutes += m_secondes / 60;
    m_secondes = m_secondes % 60;

    m_minutes += a.m_minutes;
    m_heures += m_minutes / 60;
    m_minutes = m_minutes % 60;

    m_heures += a.m_heures;

    return *this;
}
Duree& Duree::operator+=(int a)
{
    m_secondes += a;

    m_minutes += m_secondes / 60;
    m_secondes = m_secondes % 60;

    m_heures += m_minutes / 60;
    m_minutes = m_minutes % 60;

    return *this;
}

Duree& Duree::operator-=(const Duree& a)
{
    m_heures -= a.m_heures;
    if (a.m_minutes > m_minutes and m_heures >= 1)
    {
        m_minutes+=60;
        m_heures-=1;
    }
    m_minutes -= a.m_minutes;
    if (a.m_secondes > m_secondes and m_minutes >= 1)
    {
        m_secondes+=60;
        m_minutes-=1;
    }
    m_secondes -= a.m_secondes;

    return *this;
}

void Duree::afficher()
{
    std::cout << m_heures << "h" << m_minutes << "m" << m_secondes << "s" << std::endl;
}

void Duree::afficher(std::ostream &flux) const
{
    flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}

