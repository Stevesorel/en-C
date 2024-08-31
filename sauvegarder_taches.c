#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taches.h"

void sauvegarder_taches(Tache *tete, const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur: impossible d'ouvrir le fichier %s\n", nom_fichier);
        return;
    }

    Tache *courant = tete;
    while (courant != NULL) {
        fprintf(fichier, "%d\n%s\n%.2f\n%s\n%s\n%s\n%s\n", courant->numero, courant->libelle,
                courant->budget, courant->statut, courant->date_fin, courant->responsable_Id, courant->tempsFormater);
        courant = courant->suiv;
    }
    fclose(fichier);
}
