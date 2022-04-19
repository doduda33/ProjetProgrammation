#include "Personnage.h"
#include <string>
using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100)
{

}
Personnage::Personnage(string nom) : m_nom(nom),m_vie(100), m_mana(100),m_arme("epee rouillee", 10)
{

}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100),m_arme(nomArme, degatsArme)
{

}

Personnage::Personnage(string nom, int vie, int mana, string nomArme, int degatsArme) : m_nom(nom),m_vie(vie), m_mana(mana),m_arme(nomArme, degatsArme)
{

}


void Personnage::recevoirDegats(int nbDegats)
{
    m_vie-=nbDegats;

    if(m_vie<0)
        m_vie=0;
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie+=quantitePotion;
    if(m_vie>100)
        m_vie = 100;
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    return m_vie > 0;
}

void Personnage::afficherEtat()const
{
    cout<< "" << m_nom << endl;
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();

}




