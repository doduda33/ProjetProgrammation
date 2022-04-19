#ifndef ZFRACTION_H
#define ZFRACTION_H
#include <iostream>
#include <cmath>

class ZFraction
{
public:
    ZFraction(int a=0, int b=1);
    void afficher(std::ostream &flux) const;
    bool estEgal(ZFraction const& b)const;
    bool estInferieur(ZFraction const& b)const;
    bool estSuperieur(ZFraction const& b)const;

    ZFraction& operator+=(ZFraction const& a);
    ZFraction& operator-=(ZFraction const& a);
    ZFraction& operator*=(ZFraction const& a);
    ZFraction& operator/=(ZFraction const& a);
    ZFraction& operator%=(ZFraction const& a);

    void numerateur() const;
    void denominateur() const;
    void nombreReel();


private:
    void simplifier();

    int m_numerateur;
    int m_denominateur;
    double m_fraction;
};

std::ostream &operator<<( std::ostream &flux, ZFraction const& fraction);

bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);
ZFraction operator+(ZFraction const& a,ZFraction const& b);
ZFraction operator-(ZFraction const& a,ZFraction const& b);
ZFraction operator*(ZFraction const& a,ZFraction const& b);
ZFraction operator/(ZFraction const& a,ZFraction const& b);
//ZFraction operator-(ZFraction const& a);

int pgcd(int a, int b);



#endif // ZFRACTION_H
