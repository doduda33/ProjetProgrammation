#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
personne joueur[2]={0};
int ajoutJoueur=0;
int i=0;
do{
demandeInfos(joueur,i);
printf("voulez vous ajouter un joueur ? ");
scanf("%d",&ajoutJoueur);
i++;
}while(ajoutJoueur==1);

for(int j=0;j<i;j++){
if(joueur[j].genre==1)
printf("Le joueur n°%d s'apelle %s %s, habite au %s. Il a %d ans et est un garcon\n",j+1,joueur[j].nom,joueur[j].prenom,joueur[j].adresse, joueur[j].age);
else
printf("Le joueur n°%d s'apelle %s %s, habite au %s. Il a %d ans et est une fille\n",j+1,joueur[j].nom,joueur[j].prenom,joueur[j].adresse, joueur[j].age);
}
}


void demandeInfos(personne joueur[],int i){
printf("joueur n°%d\n",i+1);
printf("Quel est votre nom ? ");
scanf("%s",joueur[i].nom);
printf("Quel est votre prenom ? ");
scanf("%s",joueur[i].prenom);
printf("Quel est votre adresse ? ");
scanf("%s",joueur[i].adresse);
printf("Quel est votre age ? ");
scanf("%d",&joueur[i].age);
printf("Quel est votre genre ? (0:fille, 1:garcon ");
scanf("%d",&joueur[i].genre);
}
