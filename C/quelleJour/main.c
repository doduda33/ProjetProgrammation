#include <stdio.h>
#include <stdlib.h>

int main(){
    int jour,mois,annee,nJour=0;

    printf("Entrez une date (jj/mm/aaaa) : ");
    scanf("%u/%u/%u",&jour, &mois, &annee);
    nJour = (annee-1)*365;
    nJour+=(annee-1)/4;
    if(annee>1582){
       nJour-= (annee-1)/100;
       nJour+= (annee-1)/400;
       nJour+= 2;

    }else;

    switch(mois-1){
    case 11:
        nJour+=30;

    case 10:
        nJour+=31;

    case 9:
        nJour+=30;

    case 8:
        nJour+=31;

    case 7:
        nJour+=31;

    case 6:
        nJour+=30;

    case 5:
        nJour+=31;

    case 4:
        nJour+=30;

    case 3:
        nJour+=31;

    case 2:
        if(annee>1582){
            if(annee%4==0&&(annee%100!=0||annee%400==0))
                nJour+=29;
            else
                nJour+=28;
        }else{
            if(annee%4==0)
                nJour+=29;
            else
                nJour+=28;
        }

    case 1:
        nJour+=31;

    case 0:
        break;
    }
nJour+=jour;
    switch(nJour%7){
        case 0:
        printf("C'est un vendredi");
        break;

        case 1:
        printf("C'est un samedi");
        break;

        case 2:
        printf("C'est un dimanche");
        break;

        case 3:
        printf("C'est un lundi");
        break;

        case 4:
        printf("C'est un mardi");
        break;

        case 5:
        printf("C'est un mercredi");
        break;

        case 6:
        printf("C'est un jeudi");
        break;
}
return 0;
}
