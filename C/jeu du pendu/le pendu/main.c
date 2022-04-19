#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAILLE_MAX 20
#include "dico.h"

char lireCaractere();

void ecrireFichierIni(char motJoueur[]);
void ecrireFichier(char motJoueur[]);
void afficherFichier(char motJoueur[]);
//int continuerPartie = 1;


int main(int argc, char *argv[])
{
while(continuerPartie==1){
if choixJoueur()==1
    {
char motSecret[TAILLE_MAX] = "";
char motJoueur[TAILLE_MAX] = "";
int coupRestant=10;
int i=0,j=0;

choixMot(motSecret);
while((motSecret[i]!=NULL)&&(motSecret[i]!='\n')){
motJoueur[i]='*';
i++;
}
motJoueur[i]='\n';
ecrireFichierIni(motJoueur);
printf("bienvenu dans le pendu!\n\n");


while((strcmp(motJoueur,motSecret)!=0)&&(coupRestant!=0)){

afficherFichier(motJoueur);
printf("Il vous reste %d coups a jouer\nQuel est le mot secret ? %s\nProposez une lettre :",coupRestant,motJoueur);
char caractereEntre = lireCaractere();
for(j=0;j<i;j++){
   if(motSecret[j]==caractereEntre)
   {
        motJoueur[j]=caractereEntre;
        coupRestant++;
}
}
ecrireFichier(motJoueur);
coupRestant--;
}

if (strcmp(motJoueur,motSecret)==0)
    printf("Gagne ! Le mot secret etait bien : %s",motSecret);
else
printf("Perdu ! Le mot secret etait : %s",motSecret);

printf("voulez vous rejouer ?");
scanf("%d",continuerPartie);
}
}else
{

}
return 0;
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}



void ecrireFichierIni(char motJoueur[])
{
FILE* pointeurMotJoueur=NULL;
pointeurMotJoueur = fopen("motJoueur.txt","w+");
if(pointeurMotJoueur!=NULL){
 fputs(motJoueur,pointeurMotJoueur);
 fclose(pointeurMotJoueur);
}else
  printf("Impossible d'ouvrir le fichier");
}

void afficherFichier(char motJoueur[])
{
FILE* pointeurMotJoueur=NULL;
pointeurMotJoueur = fopen("motJoueur.txt","r");
if(pointeurMotJoueur!=NULL){
 fgets(motJoueur,TAILLE_MAX,pointeurMotJoueur);
 fclose(pointeurMotJoueur);
}else
  printf("Impossible d'ouvrir le fichier");
}

void ecrireFichier(char motJoueur[])
{
FILE* pointeurMotJoueur=NULL;
pointeurMotJoueur = fopen("motJoueur.txt","r+");
if(pointeurMotJoueur!=NULL){
 fputs(motJoueur,pointeurMotJoueur);
 fclose(pointeurMotJoueur);
}else
printf("Impossible d'ouvrir le fichier");
}

int choixJoueur()
{
        int nb_joueur = 0;
    while((nb_joueur!=1)||(nb_joueur!=2))
          {
              printf("Combien de joueurs");
              scanf("%d",&nb_joueur);
          }
    return nb_joueur;
}
















