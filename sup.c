#include<stdio.h>
#include"stdlib.h"
#include<string.h>
#include"gestion.h"

void suppression() {
    Membre steve;
    FILE *temp;
    char coder[10];
    int trouver = 0;
    FILE *fichier = fopen("gestion_membre.txt", "r");

    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier gestion\n");
        exit(1);
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erreur d'ouverture du fichier temp\n");
        fclose(fichier); // Fermer le fichier ouvert avant de quitter
        exit(1);
    }

    printf("Donner le code de l'étudiant à supprimer: ");
    scanf("%s", coder);

    while (fscanf(fichier, "\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", steve.matricule, steve.nom, steve.prenom, steve.numero, steve.role, steve.addresse) == 6) {
        if (strcmp(steve.matricule, coder) != 0) {
            fprintf(temp, "\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", steve.matricule, steve.nom, steve.prenom, steve.numero, steve.role, steve.addresse);
        } else {
            trouver = 1;
        }
    }

    fclose(fichier);
    fclose(temp);
    remove("gestion_membre.txt");
    rename("temp.txt", "gestion_membre.txt");

    if (trouver == 0) {
        printf("L'étudiant n'existe pas\n");
    } else {
        printf("Le membre a été supprimé\n");
    }
}
