#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int MIN=1;
int MAX=0;
int continuer_partie =1;
int nb_joueur, nb_mystere,difficulte ;

void CHOIX_Niveau(){
    while(MAX==0){
printf(" == Difficulte ==\n 1. 1 a 100\n 2. 1 a 1000\n 3. 1 a 10000\n");
scanf("%d",&difficulte);
switch(difficulte){
case 1:
    MAX=100;
    break;
    case 2:
    MAX=1000;
    break;
    case 3:
    MAX=10000;
    break;
  default:
 MAX=0;
    break;
}
    }
}



int NB_Joueurs(){
printf("combien de joueurs? ");
scanf("%d",&nb_joueur);
return nb_joueur;
}

int CHOIX_Nbr(){
if(nb_joueur==1){
srand(time(NULL));
nb_mystere=(rand()%(MAX-MIN+1))+MIN;
}else{
    do{
    printf("choisir le nombre mystere compris entre %d et %d : ", MIN,MAX);
    scanf("%d",&nb_mystere);
}while((nb_mystere<MIN) || (nb_mystere>MAX));
for (int i=0;i<50;i++)
printf("\n");

}
return nb_mystere;
}


int main()
{
while(continuer_partie == 1){
    int nb_entre,nb_coup=0;
    MAX=0;
CHOIX_Niveau();
NB_Joueurs();
while((nb_joueur!=1) && (nb_joueur!=2)){
printf("Vous ne pouvez jouer que tous seul ou a deux\n");
NB_Joueurs();
}

CHOIX_Nbr();

do{
   nb_coup++;
printf("Quel est le nombre ?  ");
scanf("%d",&nb_entre);
if(nb_entre>nb_mystere)
   printf("C'est moins\n");
    else if(nb_entre<nb_mystere)
    printf("C'est plus\n");
else
   printf("Bravo, vous avez trouve le nombre mystere en %d coups\n",nb_coup);

}while(nb_entre!=nb_mystere);
  printf("voulez vous rejouer ? (1 ou 0)");
  scanf("%d",&continuer_partie);
    }

}



