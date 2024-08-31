#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taches.h"

Tache *charger_taches(const char *nom_fichier)
{
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL)
    {
        printf("Erreur: impossible d'ouvrir le fichier %s\n", nom_fichier);
        return NULL;
    }

    Tache *tete = NULL;
    Tache *courant = NULL;
    while (!feof(fichier))
    {
        Tache *nouvel_tache = (Tache *)malloc(sizeof(Tache));
        if (fscanf(fichier, "%d\n", &nouvel_tache->numero) != 1)
        {
            free(nouvel_tache);
            break;
        }
        fgets(nouvel_tache->libelle, 100, fichier);
        nouvel_tache->libelle[strcspn(nouvel_tache->libelle, "\n")] = 0; // Remove newline character

        fscanf(fichier, "%f\n", &nouvel_tache->budget);

        fgets(nouvel_tache->statut, 14, fichier);
        nouvel_tache->statut[strcspn(nouvel_tache->statut, "\n")] = 0;

        fgets(nouvel_tache->date_fin, 11, fichier);
        nouvel_tache->date_fin[strcspn(nouvel_tache->date_fin, "\n")] = 0;

        fgets(nouvel_tache->responsable_Id, 50, fichier);
        nouvel_tache->responsable_Id[strcspn(nouvel_tache->responsable_Id, "\n")] = 0;

        fgets(nouvel_tache->tempsFormater,11,fichier);
        nouvel_tache->tempsFormater[strcspn(nouvel_tache->tempsFormater, "\n")] =0;

        nouvel_tache->suiv = NULL;

        if (tete == NULL)
        {
            tete = nouvel_tache;
        }
        else
        {
            courant->suiv = nouvel_tache;
        }
        courant = nouvel_tache;
    }
    fclose(fichier);
    return tete;
}
