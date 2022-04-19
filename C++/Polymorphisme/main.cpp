#include <iostream>
#include <vector>

#include "Vehicule.h"

using namespace std;

int main()
{

    vector<Vehicule*> listeVehicules;

    listeVehicules.push_back(new Voiture(15000,1908, 5));
    listeVehicules.push_back(new Voiture(12000,2032, 3));
    listeVehicules.push_back(new Moto(2000,1978, 212.5));
    listeVehicules.push_back(new Camion(2000,2201, 20000));

    listeVehicules[2]->nbrRoues();

    Garage monGarage(listeVehicules);
    monGarage.affiche();
    cout << endl;

    monGarage.ajouterVehicule(new Camion(35000,1999, 400));

    monGarage.affiche();
    cout << endl;

    monGarage.retirerVehicule(1);
    monGarage.affiche();
    cout << endl;




    for(int i(0); i<listeVehicules.size(); ++i)
    {
        delete listeVehicules[i];  //On libère la i-ème case mémoire allouée
        listeVehicules[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }

    return 0;
}
