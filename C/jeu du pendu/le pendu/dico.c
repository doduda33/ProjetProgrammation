#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"
#define TAILLE_MAX 20

int nombreMot()
{
    char caractere = 0;
    int nombreMot=1;
    FILE* pointeurMotSecret=NULL;
    pointeurMotSecret = fopen("motSecret.txt", "r");
            if (pointeurMotSecret != NULL){
        do
        {
            caractere = fgetc(pointeurMotSecret);
            if (caractere == '\n')
                nombreMot++;
        } while (caractere != EOF);
            fclose(pointeurMotSecret);
        }else
        printf("Impossible d'ouvrir le fichier");
        return nombreMot;
}

int nombreAlea()
{
srand(time(NULL));
int MIN =1;
int MAX = nombreMot();
return (rand() % (MAX - MIN + 1)) + MIN;
}

void choixMot(char motSecret[])
{
FILE* pointeurMotSecret=NULL;
pointeurMotSecret = fopen("motSecret.txt", "r");
  if (pointeurMotSecret != NULL){
for (int i=0;i<nombreAlea();i++)
        fgets(motSecret,TAILLE_MAX,pointeurMotSecret);

        fclose(pointeurMotSecret);
    }else
        printf("Impossible d'ouvrir le fichier");
}
