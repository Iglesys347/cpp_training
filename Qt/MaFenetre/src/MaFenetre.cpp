#include "MaFenetre.h"
 
MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(300, 150);
 
    // Construction du bouton
    m_bouton = new QPushButton("Pimp mon bouton !", this);
 
    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->setIcon(QIcon("img/risi.png"));
    m_bouton->move(60, 50);
}

MaFenetre::MaFenetre(int longueur, int largeur) : QWidget()
{
    setFixedSize(longueur, largeur);
 
    // Construction du bouton
    m_bouton = new QPushButton("Pimp mon bouton !", this);
 
    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->setIcon(QIcon("img/risi.png"));
    m_bouton->move(60, 50);
}