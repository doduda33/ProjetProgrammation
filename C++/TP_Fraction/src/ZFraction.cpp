#include "ZFraction.h"
using namespace std;


ZFraction::ZFraction(int a, int b): m_numerateur(a), m_denominateur(b)
{
    simplifier();
}

void ZFraction::afficher(ostream &flux) const
{
    if(m_denominateur!=1)
        flux << m_numerateur <<"/" << m_denominateur;
    else
        flux << m_numerateur;
}

void ZFraction::simplifier()
{
    if(m_denominateur<0)
    {
        m_numerateur = -m_numerateur;
        m_denominateur = - m_denominateur;
    }

    int calculPgcd = pgcd(m_numerateur,m_denominateur);
    m_denominateur/=calculPgcd;
    m_numerateur/=calculPgcd;
}

bool ZFraction::estEgal(ZFraction const& b)const
{
    return m_numerateur*b.m_denominateur==m_denominateur * b.m_numerateur;
}

bool ZFraction::estInferieur(ZFraction const& b)const
{
    return m_numerateur*b.m_denominateur < m_denominateur * b.m_numerateur;
}

bool ZFraction::estSuperieur(ZFraction const& b)const
{
    return m_numerateur*b.m_denominateur > m_denominateur * b.m_numerateur;
}

ZFraction& ZFraction::operator+=(ZFraction const& a)
{
    m_numerateur = m_numerateur*a.m_denominateur+a.m_numerateur*m_denominateur;
    m_denominateur*=a.m_denominateur;

    simplifier();
    return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const& a)
{
    m_numerateur = m_numerateur*a.m_denominateur-a.m_numerateur*m_denominateur;
    m_denominateur*=a.m_denominateur;

    simplifier();
    return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& a)
{
    m_numerateur *= a.m_numerateur;
    m_denominateur*=a.m_denominateur;

    simplifier();
    return *this;
}

ZFraction& ZFraction::operator/=(ZFraction const& a)
{
    m_numerateur *= a.m_denominateur;
    m_denominateur*=a.m_numerateur;

    simplifier();
    return *this;
}


/*ZFraction& ZFraction::operator%=(ZFraction const& a)
{
    m_numerateur = m_numerateur*a.m_denominateur-a.m_numerateur*m_denominateur;
    m_denominateur*=a.m_denominateur;
}*/

void ZFraction::numerateur() const
{
    cout << m_numerateur;
}

void ZFraction::denominateur() const
{
    cout << m_denominateur;
}

void ZFraction::nombreReel()
{
    m_fraction=(double)m_numerateur / (double)m_denominateur;
    cout << m_fraction;
}








ostream &operator<<( ostream &flux, ZFraction const& fraction)
{
    fraction.afficher(flux) ;
    return flux;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
    return a.estEgal(b);
}

bool operator!=(ZFraction const& a, ZFraction const& b)
{
    return !(a==b);
}

bool operator<(ZFraction const& a, ZFraction const& b)
{
    return a.estInferieur(b);
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
    return a.estSuperieur(b);
}

bool operator<=(ZFraction const& a, ZFraction const& b)
{
    return !(a>b);
}

bool operator>=(ZFraction const& a, ZFraction const& b)
{
    return !(a<b);
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);   //On utilise le constructeur de copie de la classe ZFraction !
    copie += b;       //On appelle la méthode d'addition qui modifie l'objet 'copie'
    return copie;     //Et on renvoie le résultat. Ni a ni b n'ont changé.
}

ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie -= b;
    return copie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie *= b;
    return copie;
}

ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie /= b;
    return copie;
}


int pgcd(int a, int b)
{

    if(a<0)
        a = -a;
    if(b<0)
        b= -b;
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}




