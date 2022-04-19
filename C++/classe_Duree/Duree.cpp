#include "Duree.h"
#include <iostream>

using namespace std;

Duree::Duree(int heures, int minutes, int secondes)
{
    minutes+=secondes/60;
    secondes%=60;
    heures+=minutes/60;
    minutes%=60;
    heures%=24;

    m_heures=heures;
    m_minutes=minutes;
    m_secondes=secondes;
}

void Duree::afficher(ostream &flux) const
{
    flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}

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

bool Duree::estPlusGrandQue(Duree const& b) const
{
    if (m_heures > b.m_heures)   // Si les heures sont différentes
        return true;
    else if (m_heures == b.m_heures && m_minutes > b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes > b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else              //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;
}

Duree& Duree::operator+=(Duree const& a)
{
    m_secondes+=a.m_secondes;
    m_minutes+= m_secondes/60;
    m_secondes%=60;
    m_minutes+=a.m_minutes;
    m_heures+=m_minutes/60;
    m_minutes%=60;

    m_heures+=a.m_heures;
    //m_heures%=24;
    return *this;
}

Duree& Duree::operator-=(Duree const& a){
m_secondes-=a.m_secondes;
while(m_secondes<0){
    m_minutes--;
    m_secondes+=60;
}

m_minutes-=a.m_minutes;
while(m_minutes<0){
    m_heures--;
    m_minutes+=60;
}

m_heures-=a.m_heures;
}


bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const&a,Duree const& b)
{
    return !(a==b);
}
bool operator<(Duree const &a, Duree const& b)
{
    return a.estPlusPetitQue(b);
}

bool operator>(Duree const &a, Duree const& b)
{
    return a.estPlusGrandQue(b);
}
bool operator<=(Duree const &a, Duree const& b)
{
    return !(a>b);
}
bool operator>=(Duree const &a, Duree const& b)
{
    return !(a<b);
}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie += b;
    return copie;
}

Duree operator-(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie -= b;
    return copie;
}

ostream &operator<<( ostream &flux, Duree const& duree)
{
    duree.afficher(flux) ;
    return flux;
}









