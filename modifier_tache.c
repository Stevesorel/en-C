#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taches.h"

void modifier_tache(Tache *tete, int numero_tache, const char *nv_statut)
{
    system("clear");
    if (numero_tache <= 0 || tete == NULL)
    {
        printf("Il n'y a aucune tâche dans la liste.\n");
        return;
    }

    Tache *courant = tete;
    for (int i = 1; i < numero_tache; i++)
    {
        if (courant->suiv == NULL)
        {
            return;
        }
        courant = courant->suiv;
    }
    strcpy(courant->statut, nv_statut);
}