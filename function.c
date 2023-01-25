#include "headers.h"


//Ajouter n employes
void informationEmploye(char nom_fichier[]) {
    int n,i;
    printf("Donner le nombre des employe a ajouter\n");
    scanf("%d",&n);
    employe E;
    FILE* f=fopen(nom_fichier,"a");
    for (i=0;i<n;i++) {
        printf("Donner le nom de l'employer %d\n",i+1);
        scanf("%s",E.nom);
        printf("Donner le prenom de l'employer %d\n",i+1);
        scanf("%s",E.prenom);
        printf("Donner le nombre d'enfants de cet employe\n");
        scanf("%d",&E.nbEnfant);
        fprintf(f,"Nom et prenom d'employe:%s %s Nombre des enfants: %d\n",E.nom,E.prenom,E.nbEnfant);
    }
    fclose(f);
}

//chercher un employe par prenom
void chercherEmploye(char nom_fichier[], char prenom[]) {
    FILE* f=fopen(nom_fichier,"r");
    char nom[50];
    char pre[50];
    int nbenfant;
    int found = 0;
    while (fscanf(f,"Nom et prenom d'employe:%s %s Nombre des enfants: %d\n",nom,pre,&nbenfant)!=EOF) {
        if (strcmp(prenom,pre)==0) {
            found = 1;
        }
    }
    if (found==1) {
        printf("L'employe a ete trouve\n");
    } else {
        printf("Employe inexistant\n");
    }
    fclose(f);
}


//afficher employer avec n enfants
void afficherEmployer(char nom_fichier[], int n) {
    FILE* f=fopen(nom_fichier,"r");
    char nom[50];
    char pre[50];
    int nbenfant;
    while (fscanf(f,"Nom et prenom d'employe:%s %s Nombre des enfants: %d\n",nom,pre,&nbenfant)!=EOF) {
        if (nbenfant == n) {
            printf("L'employe %s %s a %d enfants\n",nom,pre,n);
        }
    }
    fclose(f);
}


//supprimer employe avec 0 enfants
void supprimerEmployer(char nom_fichier[]) {
    FILE* f=fopen(nom_fichier,"r");
    FILE* temp=fopen("temp.txt","w");
    char nom[50];
    char pre[50];
    int nbenfant;
    while (fscanf(f,"Nom et prenom d'employe:%s %s Nombre des enfants: %d\n",nom,pre,&nbenfant)!=EOF) {
        if (nbenfant!=0) {
            fprintf(temp,"Nom et prenom d'employe:%s %s Nombre des enfants: %d\n",nom,pre,nbenfant);
        }
    }
    fclose(f);
    fclose(temp);
    remove(nom_fichier);
    rename("temp.txt",nom_fichier);
}
