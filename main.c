#include "headers.h"

int main() {
    int x;
    char prenom[50];
    int nbr;
    do {
        printf("*******************\n");
        printf("1-Ajouter un nombre des employes\n");
        printf("2-Chercher un employes par prenom\n");
        printf("3-Afficher les employes avec n enfants\n");
        printf("4-Supprimer les employes avec 0 enfants\n");
        printf("0-Quitter\n");
        printf("*******************\n");
        scanf("%d",&x);
        switch (x) {
            case 1:
                informationEmploye("nombre_enfants.txt");
                break;
            case 2:
                printf("Donner le prenom de lemploye a rechercher\n");
                scanf("%s",prenom);
                chercherEmploye("nombre_enfants.txt",prenom);
                break;
            case 3:
                printf("Donner le nombre d'enfant a chercher\n");
                scanf("%d",&nbr);
                afficherEmployer("nombre_enfants.txt",nbr);
                break;
            case 4:
                supprimerEmployer("nombre_enfants.txt");
                printf("Suppression faite avec success!\n");
                break;
        }
    } while ( (x!=0) && (x>=1) && (x<=7) );
    printf("vous avez quitter :)\n");
    printf("********Merci********\n");
    return 0;
}
