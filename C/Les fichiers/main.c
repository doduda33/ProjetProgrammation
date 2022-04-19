#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000 // Tableau de taille 1000


int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    int caracActu=0;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
        int score[3] = {0}; // Tableau des 3 meilleurs scores



    fichier = fopen("test.txt", "r");

        if (fichier != NULL)
    {

        fputs("salut, je suis un fichier test\n",fichier);
        for(int i=65;i<=90;i++){
            fputc(i,fichier);
            fputc('\n',fichier);
    }
        fputs("FIN\n",fichier);

       /* while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }*/
        fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
        printf("Les meilleurs scores sont : %d, %d et %d", score[0], score[1], score[2]);



       /* do{
               caracActu = fgetc(fichier);
               printf("%c",caracActu);
        }while(caracActu!=EOF);*/
            fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }


    return 0;

}
