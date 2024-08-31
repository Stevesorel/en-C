#include<stdio.h>
#include<stdlib.h>
#include"gestion.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include "taches.h"
#include"ressource.h"
#include<string.h>
/*-----------------------------------------------------------------------------------*/
 const char *sorelo = "\033[0m";
        const char *sorelio = "\033[5;36m";
        const char *sor = "\033[0m";
        const char *sore = "\033[5;36m";
// Fonction pour obtenir la largeur du terminal
int obtenir_largeur_terminal()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int compte_taches(Tache *tete)
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

// Fonction pour centrer le texte
void afficher_centre(const char *texte)
{
    int largeur = obtenir_largeur_terminal();
    int longueur = strlen(texte);
    int espaces = (largeur - longueur) / 2;
    for (int i = 0; i < espaces; i++)
    {
        printf(" ");
    }
    printf("%s\n", texte);
}

// Menu principal avec couleurs et emojis
void afficher_menu()
{
    printf("\033[1;34m"); // Bleu clair
    afficher_centre("🌟 Bienvenue dans le Gestionnaire de Tâches 🌟");
    printf("\033[0m");      // Réinitialiser la couleur
    printf("\n\033[1;33m"); // Jaune
    afficher_centre("Menu des Tâches:");
    printf("\033[0m"); // Réinitialiser la couleur
    printf("1. \033[1;32mEnregistrer des Tâches 📋\033[0m\n");
    printf("2. \033[1;32mAfficher la liste des Tâches 📋\033[0m\n");
    printf("3. \033[1;32mMettre à jour le statut d'une Tâche 📝\033[0m\n");
    printf("4. \033[1;32mSupprimer une Tâche ❌\033[0m\n");
    printf("5. \033[1;31mEnregistrer et Quitter 🚪\033[0m\n");
    printf("0. \033[1;31m pour retourner au menu principale🚪\033[0m\n");

    printf(BOLD YELLOW"Choisissez une option: "RESET);
}
/*-----------------------------------------------------------------------------------------------*/
 int main(){
   int choix;
   int chouoz;
   
                            //  system("cp acheter.txt dispo.txt");
                            //  system("cp don.txt dispo.txt");
                            //  system("cp competition.txt dispo.txt");
   system("clear");
   do{     
          system("clear");
         system("figlet bienvenue dans le projet d inf 132 |lolcat");
   printf("\t\t\t\t\t\t\t\t\t\t||FAIT COMME CHEZ VOUS A TOUT !!||\n");
   printf("\t\t\t\t\t\t\t\t\t\t==================================");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t1-GESTION DES MEMBRES\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t2-GESTION DES TACHES\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t3-GESTION DES RESSOURCES\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t0-POUR QUITER\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\tOPTION :");
    scanf("%d",&chouoz);
    system("clear");
     if(chouoz==1){
      system("figlet bienvenue dans la gestion des membres|lolcat");
      do{         
                    printf("\033[1;1m"); 
    printf( BOLD YELLOW"\t\t\t\t\t\t\t\t\t\t BIENVENUE DANS LA GESTION DES MEMBRES\n\n"RESET);
    printf("\t\t\t\t\t\t\t\t\t\tQU'ELLE OPERATION VOULEZ-VOUS EFFECTUER❓️\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\tTAPEZ\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t1-POUR VOUS ENREGISTRER📖️\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t2-POUR MODIFIER UN MEMBRE❎️\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t3-POUR SUPRIMER UN MEMBRE❌️\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t4-POUR VOIR LA LISTE DES MEMBRES🤓️\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t9-POUR RETOURNER AU MENU PRINCIPALE\t");
       scanf("%d",&choix);
       if(choix==1){
        system("clear");
        MEMBRE();
       }
       else if(choix==2){
         system("clear");
         modifier();
       }
       else if(choix==3){
         system("clear");
       suppression();
       }
       else if(choix==4){
         system("clear");
        afficher_liste_sans_distinction();
               for (int i = 0; i <3; i++) { 
            printf("%s\t\t\t\t\t\t\t\t\t\t\t veuillez patientez ...%s\n",sore,sor);
            sleep(1);
            printf("\033[F\033[J"); 
                 }
                  printf("\033[1;32maucun membre  n'est absente \033[0m\n");
        printf("\n\n\n\n\n\n\n\n");
       }else if(choix==9){
             system("clear");
             break ;
       }
       else{   
        system("clear");
           printf("VOUS AVEZ FAITES UNE ENTREZ IVALIDE MERCIE DE RELANCER L'APPLICATION");
           system("./sorel");
       }
      }while(choix!=0);
     }else if(chouoz==2){

     do{
         system("clear");
     system("figlet  Bienvenue dans le Gestionnaire de Taches |lolcat");
     Tache *liste = charger_taches("taches.txt"); // Charger les tâches au début

    int choix=1;
    while (choix!=0)
    {
        afficher_menu();
        scanf("%d", &choix);
        getchar(); // Capture le caractère de nouvelle ligne

        switch (choix)
        {
        case 1:
            system("clear");
            int nb_taches;
            printf(BLUE"Entrer le nombre de taches a enregistrer: "RESET);
            scanf("%d", &nb_taches);
            getchar(); // Capture le caractère de nouvelle ligne
            liste = ajouter_taches(liste, nb_taches);
            printf(GREEN"Les/La Tache(s) a(on) été enregistrer avec succes ! ✅️\n"RESET);
            printf("\n");
            F();
            system("clear");
            break;
        case 2:
            system("clear");
            afficher_taches(liste);
            F();
            system("clear");
            break;
        case 3:
            system("clear");
            int numero;
            char statut[50];
            int count=compte_taches(liste);
            if (count==0)
            {
                printf("Il n'y a aucune tâche dans la liste.\n");
                continue;
            }
            
            do
            {
                printf(ITALIC CYAN"Entrer le numéro de la tache a modifier(entre 1 et %d): " RESET ,count);
                scanf("%d", &numero);
                if (numero<=0 || numero>count)
                {
                    printf("Numéro de tâche invalide. Veuillez réessayer.\n");
                }
                
            } while (numero<=0 || numero>count);
            
            int choix3;
            do
            {
                printf(BLUE"Choisissez Le Nouveau Statut de la Tache:\n"RESET);
                printf(DIM"1. En attente🥱️,\t 2. En Cours🫡️,\t 3. Terminé🤝️\n"RESET);
                scanf("%d", &choix3);
                getchar();
                switch (choix3)
                {
                case 1:
                    strcpy(statut, "En attente");
                    break;
                case 2:
                    strcpy(statut, "En Cours");
                    break;
                case 3:
                    strcpy(statut, "Terminé");
                    break;
                default:
                    printf("Erreur! Entrée invalide!🧐️\n");
                    continue;
                }
            } while (choix3 < 1 || choix3 > 3);
            modifier_tache(liste, numero, statut);
            printf("Le statut de la tache a été modifié avec Succès");
            F();
            system("clear");
            break;
        case 4:
            system("clear");

            int count1=compte_taches(liste);
            if (count1==0)
            {
                printf("Il n'y a aucune tâche dans la liste.\n");
                continue;
            }
            
            do
            {
                printf(ITALIC CYAN"Entrer le numéro de la tache a supprimer(entre 1 et %d): " RESET ,count1);
                scanf("%d", &numero);
                if (numero<=0 || numero>count1)
                {
                    printf("Numéro de tâche invalide. Veuillez réessayer.\n");
                }
                
            } while (numero<=0 || numero>count1);
            liste = supprimer_tache(liste, numero);
            printf(BLUE"la Tache a été supprimé avec succès 😀️\n"RESET);
            printf("\n");
            F();
            system("clear");
            break;
        case 5:
            sauvegarder_taches(liste, "taches.txt"); // Sauvegarder les tâches avant de quitter
            printf("\033[1;32mAu revoir!👋️\033[0m\n");
            return 0;
        case 0: 
                 choix=0;
                 break;    
        default:
            printf("\033[1;31mOption invalide!🧐️\033[0m\n");
        }
    }
    }while(choix !=0);


}else if(chouoz==3){
     system("clear");
        do {
               
    printf("\t\t\t\t\t\t\t\t\t\tBIENVENUE DANS LA GESTION DES RESSOURCES\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tQU'ELLE OPERATION VOULEZ-VOUS EFFECTUER❓️\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\tTAPEZ\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t1-POUR ENREGISTRER UNE RESSOURCE📖️\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t2-POUR ENREGISTRER UNE RESSOURCE MONAITAIRE❎️\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t3-POUR VOIR LA LISTE DES RESSOURECES \n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t4-POUR VOIR LA LISTE DES DON FAIT AU CLUB\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t5-POUR VOIR LA LISTE DES RESSOURCES DISPONIBLES\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t6-POUR RESERVER UNE RESSOURCE MATERIELLE\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t0-POUR RETOURNER AU MENU PRINCIPALE : \t");
          scanf("%d",&choix);
          if(choix==1){
             ressource();
             system("clear");
             printf("\033[5;32m RESSOURCE ENREGISTRER\033[0m\n\n");
          }else if(choix==2){
              system("clear");
             ressource_monaitaire();
          }else if(choix==3){
              system("clear");
             afficher_t();
          }else if(choix==4){
            system("clear");
            int a ;
            printf("Entrez:\n");
            printf("1-pour DON_monaitaire\n");
            printf("2-pour DON_ materielle");
            scanf("%d",&a);
            if(a==2){ 
                   printf("\033[1;32m Liste des Dons materielles... \033[0m\n");
            system("cat don.txt");
            for (int i = 0; i <3; i++) { 
            printf("%s\t\t\t\t\t\t\t\t\t\t\t veuillez patientez ...%s\n",sorelio,sorelo);
            sleep(1);
            printf("\033[F\033[J"); 
                 }
                  printf("\033[1;32maucune ressource n'est absente \033[0m\n");
            }else if(a==1){ 
           printf("\033[1;32mvoicie la liste des don monataire... \033[0m\n");
            system("cat don_m.txt");
            for (int i = 0; i <3; i++) { 
            printf("%s\t\t\t\t\t\t\t\t\t\t\t veuillez patientez ...%s\n",sorelio,sorelo);
            sleep(1);
            printf("\033[F\033[J"); 
                 }
                  printf("\033[1;32maucune ressource n'est absente \033[0m\n");
            }
          }else if(choix==5){
              printf("\033[1;32mvoicie la liste des ressources du club disponible... \033[0m\n");
                 system("cp acheter.txt dispo.txt");
                 system("cp don.txt dispo.txt");
                 system("cp competition.txt dispo.txt");
          system("cat don.txt");
          system("cat acheter.txt");
          system("cat competition.txt");
          for (int i = 0; i <3; i++) { 
            printf("%s\t\t\t\t\t\t\t\t\t\t\t veuillez patientez ...%s\n",sorelio,sorelo);
            sleep(1);
            printf("\033[F\033[J"); 
                 }
                  printf("\033[1;32maucune ressource n'est absente \033[0m\n");
        break;
          }else if (choix==6){
                          int choi;   
                             do{
                                   
                     printf("Entrez :\n1-pour ressource acheter par le club\n2-Pour ressource recue apres une competition \n3-pour resource acheter par le club");
                                 scanf("%d",&choi);
                            switch (choi)
                            {
                            case 1:
                                modifier_acheter();
                                break;
                            case 2:
                                 modifier_competition();
                                break; 
                            case 3:
                                 modifier_don();       
                            default:
                                printf("OPtion invalide veuillez reesayez");
                                break;
                            }
                             }while(choi!=1||choi!=2||choi!=3);
          }
         } while(choix!=0);
     } else if(chouoz==0){
         system("clear"); 
         return 0;
         }
         else{        
         printf("FAUTE DE FRAPPE \n");
         system("./sorel");
         system("make");
     }

    } while(chouoz!=0);
   return 0;
 }
