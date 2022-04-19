#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"

class Personnage
{
    public:

    Personnage();
    Personnage(std::string nom);
    Personnage(std::string nomArme, int degatsArme);
    Personnage(std::string nom, int vie, int mana, std::string nomArme, int degatsArme);
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;
    void afficherEtat() const;

    private:

    int m_vie;
    int m_mana;
    std::string m_nom;
    Arme m_arme;
};

#endif
