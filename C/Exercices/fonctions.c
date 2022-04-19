
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
int taille_tableau=10;
int tableauOriginal[2]={1,5};
int tableauCopie[2]={0};
int tableau[10]={15,81,22,13,15,1,45,65,34,12};

printf("la somme des valeur du tableau est de %d\n",sommeTableau(tableau,taille_tableau));
printf("la moyenne du tableau est de %f\n",moyenneTableau(tableau,taille_tableau));
copie(tableauOriginal,tableauCopie,2);
//maximumTableau(tableau,taille_tableau,8);
ordonnerTableau(tableau,taille_tableau);
return 0;
}

int sommeTableau(int *tableau, int taille_tableau){

int sommeTableau=0;
for (int i=0;i<taille_tableau;i++){
   sommeTableau+= tableau[i];
}
return sommeTableau;
}

double moyenneTableau(int tableau[], int taille_tableau){

return sommeTableau(tableau,2)/taille_tableau;
}

void copie(int tableauOriginal[],int tableauCopie[],int taille_tableau){
tableauCopie[0]=tableauOriginal[0];
}

void maximumTableau(int tableau[],int taille_tableau, int valeurMax){
for (int i=0;i<taille_tableau;i++){
    if(tableau[i]>valeurMax)
    tableau[i]=0;
printf("tableau[%d]=%d\n",i,tableau[i]);
}
}

void ordonnerTableau(int tableau[], int taille_tableau){
int tableauOrdonner[10]={0};
tableauOrdonner[0]=tableau[0];
for (int i=1;i<taille_tableau;i++){
if(tableau[i]>tableauOrdonner[i-1])
tableauOrdonner[i]=tableau[i];
else{
      int  j=i;
while((tableau[i]<tableauOrdonner[j-1])&&(j!=0)){

tableauOrdonner[j]= tableauOrdonner[j-1];
j--;
}

tableauOrdonner[j]=tableau[i];
}

}
for(int r=0;r<taille_tableau;r++)
printf("tab[%d]=%d\n",r,tableauOrdonner[r]);
}















