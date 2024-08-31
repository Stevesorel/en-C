#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "taches.h"

int compter_taches(Tache *tete)
{
    int count = 0;
    Tache *courant = tete;
    while (courant != NULL)
    {
        count++;
        courant = courant->suiv;
    }
    return count;
}

bool estBissextile(int annee)
{
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

bool ver_tache(const char *date)
{
    int jour, mois, annee; // jj/mm/aa
    if (sscanf(date, "%2d/%2d/%2d", &jour, &mois, &annee) == 3)
    {
        if (annee < 0 || annee > 99)
        {
            printf("\033[1;31mFormat de Date Incorrecte\n\033[0m");
            return false;
        }
        if (mois < 1 || mois > 12)
        {
            printf("\033[1;31mUn An a 12 mois\n\033[0m");
            return false;
        }
        if (jour < 1 || jour > 31)
        {
            printf("\033[1;31mUn mois a 31 jours\n\033[0m");
            return false;
        }
        // Gérons le cas de février et les années bissextiles
        if (mois == 2)
        {
            if (estBissextile(annee + 2000))
            {
                return jour <= 29;
            }
            else
            {
                return jour <= 28;
            }
        }
        // Gérez les mois avec 30 jours
        if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
        {
            return jour <= 30;
        }
        return true;
    }
    printf("\033[1;31mFormat de Date Incorrecte\n\033[0m");
    return false;
}

Tache *ajouter_taches(Tache *tete, int nb_taches)
{
    Tache *courant = tete;
    Tache *nouvelle_tete = tete;

    // Aller jusqu'à la fin de la liste existante
    while (courant != NULL && courant->suiv != NULL)
    {
        courant = courant->suiv;
    }

    int numero_initial = compter_taches(tete) + 1;

    for (int i = 0; i < nb_taches; i++)
    {
        Tache *nouvel_tache = (Tache *)malloc(sizeof(Tache));
        if (!nouvel_tache)
        {
            printf("Erreur d'allocation de mémoire\n");
            exit(EXIT_FAILURE);
        }

        nouvel_tache->numero = numero_initial + i;
        printf("\nTache %d: \n", nouvel_tache->numero);

        printf(MAGENTA"Libelle: "RESET);
        fgets(nouvel_tache->libelle, 100, stdin);
        nouvel_tache->libelle[strcspn(nouvel_tache->libelle, "\n")] = 0; // Supprime le caractère de nouvelle ligne

        while (1)
        {
            char buffer[50];
            printf(MAGENTA"Budget: "RESET);
            fgets(buffer, 50, stdin);

            if (sscanf(buffer, "%f", &nouvel_tache->budget) != 1)
            {
                printf("\033[1;31mErreur: veuillez entrer un nombre valide pour le budget.\n\033[0m");
            }
            else
            {
                break;
            }
        }

        int choix1;
        do
        {
            printf(MAGENTA"Choisissez Le Statut de la Tache:\n"RESET);
            printf("1. En attente,\t 2. En Cours,\t 3. Terminé\t\t\t");
            scanf("%d", &choix1);
            getchar();
            switch (choix1)
            {
            case 1:
                strcpy(nouvel_tache->statut, "En attente");
                break;
            case 2:
                strcpy(nouvel_tache->statut, "En Cours");
                break;
            case 3:
                strcpy(nouvel_tache->statut, "Terminé   ");
                break;
            default:
                printf("Erreur! Entrée invalide!\n");
                continue;
            }
        } while (choix1 < 1 || choix1 > 3);
        do
        {
            printf(MAGENTA"Date de Fin/Limite (jj/mm/aa): "RESET);
            fgets(nouvel_tache->date_fin, 11, stdin);
            nouvel_tache->date_fin[strcspn(nouvel_tache->date_fin, "\n")] = 0;
        } while (!ver_tache(nouvel_tache->date_fin));

        printf(MAGENTA"Matricule du Responsable de la Tache: "RESET);
        fgets(nouvel_tache->responsable_Id, 50, stdin);
        nouvel_tache->responsable_Id[strcspn(nouvel_tache->responsable_Id, "\n")] = 0;
        printf("\n");
            // Récupération du temps actuel
        time_t now = time(NULL);
        // Conversion en struct tm pour obtenir une représentation locale du temps

        struct tm *t = localtime(&now);
        // Formatage de l'heure en jj/mm/aa

        strftime(nouvel_tache->tempsFormater, sizeof(nouvel_tache->tempsFormater), "%d/%m/%y", t);
        nouvel_tache->suiv = NULL;

        if (courant == NULL)
        {
            nouvelle_tete = nouvel_tache;
            
        }
        else
        {
            courant->suiv = nouvel_tache;
        }
        courant = nouvel_tache;
    }
    return nouvelle_tete;
}
