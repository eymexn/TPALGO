#include <stdio.h>
#include <stdlib.h>


typedef struct{
char Nom[10];
float Note;
int Coef;
}TModule;

typedef struct{
char Nom[20];
char Prenom[20];
char Matricule[12];
TModule M1,M2,M3;
float Moyenne;
}TEtudiant;


int main()
{
    int nbrEtu, nbreAdmis, i;
    TEtudiant T[100];
    TModule modules[3];
    TEtudiant ADMIS[100];
    TEtudiant *pt;


    printf("---------------------------------------- SOLUTION TP EXO 6  ----------------------------------------");


    for(i=0; i<3; i++){
        char str[10];
        printf("\nEntrez le nom du module n%i: ", i+1);
        scanf("%s", str);
        strcpy(modules[i].Nom, &str);

        printf("\nEntrez le coef du module \"%s\": ", str);
        scanf("%i", &modules[i].Coef);


    }


    do{
        printf("\nEntrez le nombre d'etudiants: ");
        scanf("%i", &nbrEtu);

    }while(nbrEtu<=0);



    for(i = 0; i < nbrEtu; i++){
            printf("\n-------------------------------------------------------------");
            printf("\nEntrez le nom d'etudiant n%i: ", i+1);
            scanf("%s", &T[i].Nom);
            printf("\nEntrez le prenom d'etudiant n%i: ", i+1);
            scanf("%s", &T[i].Prenom);
            printf("\nEntrez le matricule d'etudiant n%i: ", i+1);
            scanf("%s", &T[i].Matricule);

            strcpy(T[i].M1.Nom, modules[0].Nom);
            strcpy(T[i].M2.Nom, modules[2].Nom);
            strcpy(T[i].M3.Nom, modules[3].Nom);
            T[i].M1.Coef=modules[0].Coef;
            T[i].M2.Coef=modules[1].Coef;
            T[i].M3.Coef=modules[2].Coef;

            printf("\nEntrez la note du module %s: ", modules[0].Nom);
            scanf("%f", &T[i].M1.Note);
            printf("\nEntrez la note du module %s: ", modules[1].Nom);
            scanf("%f", &T[i].M2.Note);
            printf("\nEntrez la note du module %s: ", modules[2].Nom);
            scanf("%f", &T[i].M3.Note);

            T[i].Moyenne = ((T[i].M1.Note* T[i].M1.Coef)+(T[i].M2.Note* T[i].M2.Coef)+(T[i].M3.Note* T[i].M3.Coef))/(T[i].M1.Coef + T[i].M2.Coef + T[i].M3.Coef);





    }
    printf("\n-------------------------------------------------------------\nLISTE D'ADMIS:");
    printf("\n\nNom & Prenom                       Matricule                 Moyenne");
    nbreAdmis=0;
    for(i=0;i<nbrEtu;i++){
        if(T[i].Moyenne >= 10){
            pt = &T[i];
            ADMIS[nbreAdmis]= *pt;
            nbreAdmis++;
            printf("\n%s %s",T[i].Nom, T[i].Prenom);
            for(int j = 0; j<= 22+(12-(strlen(T[i].Nom)+ strlen(T[i].Prenom)+1)); j++){
                printf(" ");
            }
            printf("%.12s              %f", T[i].Matricule, T[i].Moyenne);
        }


    }

}
