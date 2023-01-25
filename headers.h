#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];
    char prenom[50];
    int nbEnfant;
}employe;

void informationEmploye(char nom_fichier[]);
void chercherEmploye(char nom_fichier[], char prenom[]);
void afficherEmployer(char nom_fichier[], int n);
void supprimerEmployer(char nom_fichier[]);
