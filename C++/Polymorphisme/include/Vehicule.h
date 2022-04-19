#ifndef VEHICULE_H
#define VEHICULE_H

#include <iostream>
#include <vector>

class Vehicule
{
    public:
    Vehicule(int prix, int annee, int nbRoues=4);           //Construit un véhicule d'un certain prix
    virtual void affiche() const;
    virtual int nbrRoues() const;
    virtual ~Vehicule();          //Remarquez le 'virtual' ici

    protected:
    int m_prix;
    int m_annee;
};

class Voiture: public Vehicule
{
    public:
    Voiture(int prix, int annee, int portes);
    //Construit une voiture dont on fournit le prix et le nombre de portes
    virtual void affiche() const;
    virtual ~Voiture();

    private:
    int m_portes;
};

class Moto : public Vehicule
{
    public:
    Moto(int prix, int annee, double vitesseMax);
    //Construit une moto d'un prix donné et ayant une certaine vitesse maximale
    virtual void affiche() const;
    virtual ~Moto();

    private:
    double m_vitesse;
};

class Camion : public Vehicule
{
    public:
    Camion(int prix, int annee, double poidMax);

    virtual void affiche() const;
    virtual ~Camion();

    private:
        double m_poids;
};


class Garage
{
    public:
    Garage(std::vector<Vehicule*> liste);

    void affiche() const;
    void ajouterVehicule(Vehicule* const& a);
    void retirerVehicule(int a);

    virtual ~Garage();
    private:
    std::vector<Vehicule*> m_vehicules;
} ;

#endif // VEHICULE_H
