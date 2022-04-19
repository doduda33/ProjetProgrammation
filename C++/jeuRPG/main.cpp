#include <iostream>
#include <string>
#include <vector>

#include "Personnage.h"

using namespace std;

int main()
{
    int nbJoueurs=2;
string nomJoueur[4];
    cout<<"Bienvenue dans le meilleure MMORPG du monde"<< endl;
    cout << "Conbien de joueurs y a t'il ? ";
    cin >> nbJoueurs;

    cin.ignore();
    cout<<endl;

    for(int i(0); i<nbJoueurs; i++)
    {
        string nomJoueurs;

        cout<<"Joueur numero "<<i+1<<", veuillez entrer votre pseudo : ";
        getline(cin, nomJoueurs);
        nomJoueur[i]=nomJoueurs;
    }

    for(int i(0); i<nbJoueurs; i++)
        cout<<"Joueur numero "<<i+1<<" est "<<nomJoueur[i]<<endl;

    cout<<endl<<endl;

    Personnage joueur1(nomJoueur[0]),joueur2(nomJoueur[1]),joueur3(nomJoueur[2]);

    if(nbJoueurs>0)
    {
        joueur1.afficherEtat();
        cout << endl;
    }
    if(nbJoueurs>1)
    {
        joueur2.afficherEtat();
        cout << endl;
    }
    if(nbJoueurs>2)
    {
        joueur3.afficherEtat();
        cout << endl;
    }

    /*Personnage david, goliath("Épée aiguisée", 20);

    //Au combat !
    goliath.attaquer(david);
    david.boirePotionDeVie(20);
    goliath.attaquer(david);
    david.attaquer(goliath);
    goliath.changerArme("Double hache tranchante vénéneuse de la mort", 40);
    goliath.attaquer(david);

    //Temps mort ! Voyons voir la vie de chacun…
    cout << "David" << endl;
    david.afficherEtat();
    cout << endl << "Goliath" << endl;
    goliath.afficherEtat();
    */
    return 0;
}
