#include<stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include<time.h>
#include <stdbool.h>
//Les couleurs d'echappement ANSI
//syntaxe  generale: \033[<code_couleur>m
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"


#define F() do {\
int choix1 =1;\
    while(choix1){\
                        int rep;\
                    printf(BLUE"7. Retourner au Menu 💫️\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"RESET);\
                    printf(RED"9. Enregistrer et quitter ❌\n" RESET);\
                    scanf("%d", &rep);\
                        if(rep==9){\
                            sauvegarder_taches(liste, "taches.txt");\
                            printf("\033[1;32mAu revoir!\033[0m\n");\
                            return 0;\
                        }else if(rep==7){\
                            choix1=0;\
                        }\
                        else{\
                                printf("\033[1;31mOption invalide!\033[0m\n");\
                        }\
                 }\
} while (0);

typedef struct Tache {
    int numero;
    char libelle[100];
    float budget;
    char statut[14];
    char date_fin[11];
    char responsable_Id[50];
    char tempsFormater[11];
    float jourRestant;
    struct Tache *suiv;
} Tache;
Tache* ajouter_taches(Tache *liste, int nb_taches);
void afficher_taches(Tache *tete);
Tache* supprimer_tache(Tache *tete, int numero);
void modifier_tache(Tache *tete, int numero_tache, const char *nv_statut);
Tache* charger_taches(const char *nom_fichier);
void sauvegarder_taches(Tache *tete, const char *nom_fichier);
