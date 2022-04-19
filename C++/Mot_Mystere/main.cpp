#include <iostream>
#include <string>
#include <ctime> // Obligatoire
#include <cstdlib> // Obligatoire
#include <vector>
#include <fstream>
using namespace std;

string melangerMot(string);
string dico();
void moyenne(vector<double>& score);


int const nbMaxCoups=5;
vector<double> score;

int main()
{
    srand(time(0));
    char nouvellePartie;
    int nbJoueur;
    do
    {
        string motMystere,motUtilisateur(" "),motMelange;
        int coupsRestant=nbMaxCoups;

        do
        {
            cout << "Combien de joueur (1/2) ";
            cin>>nbJoueur;
        }
        while(nbJoueur!=1 && nbJoueur!=2);

        //1 : On demande de saisir un mot

        if(nbJoueur==2)
        {
            cout << "Saisissez un mot" << endl;
            cin >> motMystere;
            for(int i=0; i<100; i++)
                cout << endl;
        }
        else
        {
            motMystere=dico();
        }
        //2 : On mélange les lettres du mot

        motMelange=melangerMot(motMystere);


        //3 : On demande à l'utilisateur quel est le mot mystère
        while(motUtilisateur!=motMystere && coupsRestant!=0)
        {
            cout << "Quel est le mot mystere ? "<< motMelange << endl;
            cin >> motUtilisateur;
            if(motUtilisateur!=motMystere)
            {
                cout << "Ce n'est pas le mot !" << endl;
                coupsRestant--;
                if(coupsRestant!=0)
                    cout << "Il vous reste " <<coupsRestant<<" coups"<< endl;
            }
            else
                cout << "Bravo, le mot mytere est bien " << motMystere << endl;
            if(coupsRestant==0)
                cout<< "Vous avez perdu ! Le mot mystere etait "<< motMystere;

            cout << endl;
        }
        score.push_back(coupsRestant);
        cout << "Voulez-vous faire une autre partie ? (O/N)";
        cin >> nouvellePartie;
    }
    while(nouvellePartie=='O');
    moyenne(score);
    return(0);
}

string melangerMot(string mot)
{
    int test;
    string motMelange=mot;
    int nombre[mot.size()];

    for(int i(0); i<mot.size(); i++)
    {
        test=1;
        while(test!=0)
        {
            test=0;
            int position = rand() % mot.size();
            for(int j(0); j<i; j++)
            {
                if(nombre[j]==position)
                    test++;

            }
            if (test==0)
            {
                nombre[i]=position;
                motMelange[i]=mot[position];
            }
        }
    }
    return motMelange;
}

void moyenne(vector<double>& score)
{
    double moy;
    for(int i=0; i<score.size(); i++)
        moy +=score[i];

    moy/=score.size();
    cout<<"Votre score est de "<<moy<< " coups en moyenne" <<endl;
}

string dico()
{
    string motMystere;
    ifstream monFlux("dico1.txt");
    if(monFlux)
    {
        long int taille=0;
        string ligne;
        while(getline(monFlux,ligne))
        {
            taille++;
        }
        monFlux.ignore();
        long int position = rand() % taille;
        cout <<taille <<"  "<<position<<endl;
        monFlux.seekg(1, ios::beg);
        for(int i=0; i<position; i++)
            getline(monFlux, motMystere);
        getline(monFlux, motMystere);

    }
    else
        cout<<"erreur d'ouverture du fichier"<< endl;
    return motMystere;
}













