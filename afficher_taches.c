#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include "taches.h"

int calculer_heures_restantes(const char *date_fin)
{
   struct tm tm_fin ={0};
   int jour,mois,annee;
   if (sscanf(date_fin,"%2d/%2d/%2d",&jour,&mois,&annee) !=3)
   {
        return -1;
   }
   
   tm_fin.tm_mday=jour;
   tm_fin.tm_mon = mois-1;
   tm_fin.tm_year=annee+100;//Pour ajuster a l'annee 2000

   time_t temps_fin = mktime(&tm_fin);
   time_t temps_actuel= time(NULL);

   double difference = difftime(temps_fin,temps_actuel);
   return (int)(difference/3600);
}

void afficher_taches(Tache *tete)
{
    if (!tete)
    {
        printf("\033[1;31mAucune tâche enregistrée.\033[0m\n");
        return;
    }

    printf("\n\033[1;34mListe des Tâches:\033[0m\n");
    printf("+-----+------------------------------------------+-------------+---------------+------------+--------------------------------+------------------------+----------------+\n");
    printf("| \033[1;33mNo🔢\033[0m| \033[1;33mLibellé📋                                \033[0m| \033[1;33mBudget💰    \033[0m| \033[1;33mStatut📊      \033[0m| \033[1;33mDate Line📅\033[0m| \033[1;33mID du Responsable👤            \033[0m| \033[1;33mDate D'Enregistrement🕒\033[0m|\033[1;33mRappel(heures)⏳\033[0m|\n");
    printf("+-----+------------------------------------------+-------------+---------------+------------+--------------------------------+------------------------+----------------+\n");

    Tache *courant = tete;
    while (courant != NULL)
    {
            int heures_restantes = calculer_heures_restantes(courant->date_fin);
        printf("|\033[1;32m%-5d\033[0m| \033[1;32m%-40.40s\033[0m | \033[1;32m%12.2f\033[0m| \033[1;32m%-13.13s\033[0m |\033[1;32m%-12.12s\033[0m| \033[1;32m%-30.30s\033[0m | \033[1;32m%-20.20s\033[0m   | \033[1;32m%-14d\033[0m |\n",
               courant->numero, courant->libelle, courant->budget, courant->statut, courant->date_fin, courant->responsable_Id, courant->tempsFormater, heures_restantes);
        printf("+-----+------------------------------------------+-------------+---------------+------------+--------------------------------+------------------------+----------------+\n");
        courant = courant->suiv;
    }
    printf("\n");
}

