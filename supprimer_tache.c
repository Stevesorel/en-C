#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taches.h"

Tache* supprimer_tache(Tache *tete, int numero) {
    system("clear");
    if (numero <= 0 || tete == NULL) {
        return tete;
    }

    Tache *courant = tete;
    if (numero == 1) { // Suppression de la première tâche
        tete = tete->suiv;
        free(courant);
        return tete;
    }

    for (int i = 1; i < numero - 1; i++) {
        if (courant->suiv == NULL) {
            return tete;
        }
        courant = courant->suiv;
    }

    Tache *a_supprimer = courant->suiv;
    if (a_supprimer == NULL) {
        return tete;
    }

    courant->suiv = a_supprimer->suiv;
    free(a_supprimer);
    return tete;
}