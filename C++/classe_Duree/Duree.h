#ifndef DEF_DUREE
#define DEF_DUREE
#include <iostream>

class Duree
{
public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);


    Duree& operator+=(Duree const& a);
    Duree& operator-=(Duree const& a);



private:

    int m_heures;
    int m_minutes;
    int m_secondes;

    void afficher(std::ostream &flux) const;
    bool estEgal(Duree const& b) const;
    bool estPlusPetitQue(Duree const& b) const;
    bool estPlusGrandQue(Duree const& b) const;

    friend bool operator==(Duree const& a, Duree const& b);
    friend bool operator!=(Duree const& a, Duree const& b);
    friend bool operator<(Duree const &a, Duree const& b);
    friend bool operator>(Duree const &a, Duree const& b);
    friend bool operator<=(Duree const &a, Duree const& b);
    friend bool operator>=(Duree const &a, Duree const& b);
    friend std::ostream& operator<< ( std::ostream &flux, Duree const& duree);

};



Duree operator+(Duree const& a, Duree const& b);
Duree operator-(Duree const& a, Duree const& b);



#endif
