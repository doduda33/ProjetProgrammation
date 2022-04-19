#include "Vehicule.h"

using namespace std;

Vehicule::Vehicule(int prix, int annee,int nbRoues)
    :m_prix(prix), m_annee(annee),m_roues(nbRoues)
{}

void Vehicule::affiche() const
//J'en profite pour modifier un peu les fonctions d'affichage
{
    cout << "Ceci est un vehicule de " << m_annee << " coutant " << m_prix << " euros." << endl;
}

void Vehicule::nbrRoues() const
{
    cout << "Ceci est un vehicule de " << m_roues << " roues " << endl;
}

Vehicule::~Vehicule() //Même si le destructeur ne fait rien, on doit le mettre !
{}

Voiture::Voiture(int prix, int annee, int portes)
    :Vehicule(prix, annee), m_portes(portes)
{}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture de " << m_annee << " avec " << m_portes << " portes et coutant " << m_prix << " euros." << endl;
}

Voiture::~Voiture()
{}

Moto::Moto(int prix, int annee, double vitesseMax)
    :Vehicule(prix, annee,2), m_vitesse(vitesseMax)
{}

void Moto::affiche() const
{
    cout << "Ceci est une moto de " << m_annee << " allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
}

Moto::~Moto()
{}

Camion::Camion(int prix, int annee, double poidMax) : Vehicule(prix, annee, 6), m_poids(poidMax)
{}

void Camion::affiche() const
{
    cout << "Ceci est un camion de " << m_annee << " pouvant porter " << m_poids << " kilos et coutant " << m_prix << " euros." << endl;
}

Camion::~Camion()
{}

Garage::Garage(vector<Vehicule*> liste) : m_vehicules(liste)
{}

void Garage::affiche() const
{
    cout << "Laissez moi faire la presentation de mon garage :" << endl;
    for(int i(0); i<m_vehicules.size(); i++){
            cout << "Vehicule n " << i+1 << ": ";
        m_vehicules[i]->affiche();
    }
}

void Garage::ajouterVehicule(Vehicule* const& a)
{
    m_vehicules.push_back(a);
}

void Garage::retirerVehicule(int a)
{
    a-=1;
    if(a >= m_vehicules.size())
        cout << "Erreur dans la saisie du nombre !" << endl;
    else{
    for(int i(a);i < m_vehicules.size()-1 ;i++)
        m_vehicules[i]=m_vehicules[i+1];
    m_vehicules.pop_back();
    }
}

Garage::~Garage()
{}



