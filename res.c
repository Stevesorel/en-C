#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"ressource.h"
#include"gestion.h"
#include<ctype.h>
#include<time.h>
 const char *sorel = "\033[0m";
        const char *soreli = "\033[5;36m";
        void ressource(){
          int stquantite;
               Donne st;
              FILE *temp=NULL;
              temp=fopen("don.txt","a");
              if(temp==NULL){
                fprintf(stderr,"Erreur d'ouverture du fichier");
                exit(EXIT_FAILURE);
              }else{
                int choix;
                char quantite[50];
                      do{ 
                      printf("Entrez le nom de la ressource\n");
                      scanf("%s",st.nom);  
                      }while(test1(st.nom)!=1);   
                       do{ 
                      printf("Entrez la quantite de la ressource\n");
                      scanf("%s",quantite);}while(estMontantValide(quantite)!=1);
                       stquantite=atoi(quantite);
                      printf("QU'ELLE EST LE TYPE DE LA RESSOURCE\n");
                            printf("1-DON\n");
                            printf("2-Acheter par le club\n");
                            printf("3-gagner apres une competition\n");
                            scanf("%d",&  choix);
                            if(choix==1){
                               strcpy(st.type,"DON");
                            }else if(choix==2){
                              strcpy(st.type,"ACHETER");
                            }else if(choix==3){
                               strcpy(st.type,"competition");
                            }
                            strcpy(st.status,"disponible");           
              }
                 if(strcmp(st.type,"DON")==0){
                    
                     fprintf(temp,"%s\t\t%d\t\t%s\t\t%s\n",st.nom,stquantite,st.type,st.status);
                     fclose(temp);
                 }else if(strcmp(st.type,"ACHETER")==0){
                     FILE *temp1=NULL;
                     temp1=fopen("acheter.txt","a");
                      if(temp1==NULL){
                        fprintf(stderr,"EReur d'ouverture du fichier temp1");
                        exit(EXIT_FAILURE);
                      }else{
                          fprintf(temp1,"%s\t\t%d\t\t%s\t\t%s\n",st.nom,stquantite,st.type,st.status);
                          fclose(temp1);
                      }
                 }else if(strcmp(st.type,"competition")==0){
                     FILE *temp2=NULL;
                     temp2=fopen("competition.txt","a");
                      if(temp2==NULL){
                        fprintf(stderr,"EReur d'ouverture du fichier temp2");
                        exit(EXIT_FAILURE);
                      }else{
                          fprintf(temp2,"%s\t\t%d\t\t%s\t\t%s\n",st.nom,stquantite,st.type,st.status);
                          fclose(temp2);
                      }
                 }
        }
             void ressource_monaitaire(){
                   int choix;
                    FILE *temp3=NULL;
                    temp3=fopen("don_m.txt","a");
                    if(temp3==NULL){
                      fprintf(stderr,"Erreur d'ouverture du fichier temp3");
                      exit(EXIT_FAILURE);
                    }else{ 
                    Donne st;
                    printf("BIEN VOUS ETES CHEZ LES DONS MONAITAIRE\n");
                        
                          printf("entrez :\n");
                          printf("1-pour Don\n");
                          printf("2-pour argent recu apres une competion:\t\n");
                          scanf("%d",&choix);
                          if(choix==1){ 
                     printf("Entrez le montant du don recue \n");
                     scanf("%f",&st.quantite);
                     printf("Entrez le nom du donateur");
                     scanf("%s",st.nom_d);
                      fprintf(temp3,"%.1ffcfa\t\t%s\n",st.quantite,st.nom_d);
                      fclose(temp3);
                          }else{
                     printf("Entrez le montant recue apres la competition \n");
                     scanf("%f",&st.quantite);
                     printf("Entrez le nom de la competition\n");
                     scanf("%s",st.nom_d);
                      fprintf(temp3,"%.1ffcfa\t\t%s\n",st.quantite,st.nom_d);
                      fclose(temp3);
                          }
                        
                    }
             }
           
              void afficher_t(){
                 int choix=3;
                do{  
                    
                    printf("Voulez -vous voire :\n");
                    printf("1-Liste des ressources  acheter par le club\n");
                    printf("2-Liste des dons fait au club\n");
                    printf("0-pour retourner aux menu\n");
                    scanf("%d",&choix);
                    if(choix==1){
                      system("clear");
                      system("cat acheter.txt");
                      for (int i = 0; i <3; i++) { 
            printf("%s\t\t\t\t\t\t\t\t\t\t\t veuillez patientez ...%s\n",soreli,sorel);
            sleep(1);
            printf("\033[F\033[J"); 
                 }
                  printf("\033[1;32maucune ressource n'est absente \033[0m\n");
                        printf("\n\n\n");
                    }else if (choix==2){
                      system("clear");
                       system("cat competition.txt");
                       for (int i = 0; i <3; i++) { 
            printf("%s\t\t\t\t\t\t\t\t\t\t\t veuillez patientez ...%s\n",soreli,sorel);
            sleep(1);
            printf("\033[F\033[J"); 
                 }
                  printf("\033[1;32maucune ressource n'est absente \033[0m\n");
                       printf("\n\n\n");
                    }
                }while(choix!=0);
              }

              int estMontantValide(char *entree) {
                     for (int i = 0; i < strlen(entree); i++) {
                           if (!isdigit(entree[i])) {
                                    return 0; // Non valide si un caractère n'est pas un chiffre
                            }
                               }
                                return 1; // Valide si tous les caractères sont des chiffres
                                    }
                              
                         void date(char* buffer, size_t bufferSize) {
                               time_t current_time;
                               struct tm *time_info;

                              // Obtenir l'heure actuelle
                                  time(&current_time);
                                    time_info = localtime(&current_time);

                                    // Formater l'heure en HH:MM:SS
                                  strftime(buffer, bufferSize, "%H:%M:%S", time_info);
                          }              
                     void modifier_acheter(){
                           char timeString[9]; 
                           date(timeString, sizeof(timeString));
                           printf("L'heure actuelle est : %s\n", timeString);  
                              
                            char nom[23];
                            char nome[20];
                            int quantite;
                            char type[20];
                            char status[20];
                            int tr;
                                FILE *temp;
                                FILE *fp;
                                fp=fopen("acheter.txt","r");
                                if(fp==NULL){
                                      fprintf(stderr,"Erreur impossible d'ouvrir le fichier<acheter.txt>");
                                      exit(EXIT_FAILURE);
                                }
                                temp=fopen("temp9.txt","w");
                                if(temp==NULL){
                                   fprintf(stderr,"impossible d'ouvrire le fichier temp9.txt");
                                   exit(EXIT_FAILURE);
                                }
                                printf("voicie la liste des ressources disponibles:\n\n");
                                system("cat acheter.txt");
                                do{ 
                                printf("Donner le nom de la ressource dont vous souhaitez reserver :");
                                scanf("%s",nom);
                                }while(test1(nom)!=1);
                                while(fscanf(fp,"%s\t\t%d\t\t%s\t\t%s\n",nome,&quantite,type,status)==4){

                                        if(strcmp(nom,nome)==0)
                                        {
                                              tr=1;
                                              if(strcmp(status,"OCCUPER")==0){ 
                                              printf("LA RESSOURCE EST DEJA OCCUPER\n");
                                              return;
                                              }
                                              strcpy(status,"OCCUPER");
                                        }
                                             fprintf(temp,"%s\t\t%d\t\t%s\t\t%s\n",nome,quantite,type,status);
                                }
                                      fclose(temp);
                                      fclose(fp);
                                      remove("acheter.txt");
                                      rename("temp9.txt","acheter.txt");
                                      if(tr==0){
                                          printf("la ressource n'existe pas\n !!");
                                      }else if(tr==1){
                                           
                                           printf("la ressource a ete occuper le %s\n\n",timeString);
                                           FILE *steve;
                                           steve=fopen("date.txt","a");
                                           if(steve==NULL){
                                             fprintf(stderr,"Erreur impossible d'ouvire date.txt\n");
                                             exit(EXIT_FAILURE);
                                           }else{
                                                   printf("Quand aller vous liberer les %s ??\n",nom);
                                                   char date_fin[20];
                                                   printf("entrez la date de libairation:\n");
                                                   scanf("%s",date_fin);
                                                   fprintf(steve,"%s---%s---%s\n",nom,timeString,date_fin);
                                                   printf("passer ce delais vous serez penaliser !!!!\n");
                                                   printf("%s",date_fin);
                                           }
                                      }
                     }
                      


                       void modifier_competition(){
                           char timeString[9]; 
                           date(timeString, sizeof(timeString));
                           printf("L'heure actuelle est : %s\n", timeString);  
                              
                            char nom[23];
                            char nome[20];
                            int quantite;
                            char type[20];
                            char status[20];
                            int tr;
                                FILE *temp;
                                FILE *fp;
                                fp=fopen("competition.txt","r");
                                if(fp==NULL){
                                      fprintf(stderr,"Erreur impossible d'ouvrir le fichier<acheter.txt>");
                                      exit(EXIT_FAILURE);
                                }
                                temp=fopen("temp9.txt","w");
                                if(temp==NULL){
                                   fprintf(stderr,"impossible d'ouvrire le fichier temp9.txt");
                                   exit(EXIT_FAILURE);
                                }
                                printf("voicie la liste des ressources disponibles:\n\n");
                                system("cat competition.txt");
                                do{ 
                                printf("Donner le nom de la ressource dont vous souhaitez reserver :");
                                scanf("%s",nom);
                                }while(test1(nom)!=1);
                                while(fscanf(fp,"%s\t\t%d\t\t%s\t\t%s\n",nome,&quantite,type,status)==4){
                                          
                                        if(strcmp(nom,nome)==0)
                                        {
                                              tr=1;
                                              if(strcmp(status,"OCCUPER")==0){ 
                                              printf("LA RESSOURCE EST DEJA OCCUPER\n");
                                              return;
                                              }
                                              strcpy(status,"OCCUPER");
                                        }
                                             fprintf(temp,"%s\t\t%d\t\t%s\t\t%s\n",nome,quantite,type,status);
                                }
                                      fclose(temp);
                                      fclose(fp);
                                      remove("competition.txt");
                                      rename("temp9.txt","competition.txt");
                                      if(tr==0){
                                          printf("la ressource n'existe pas\n !!");
                                      }else if(tr==1){
                                           
                                           printf("la ressource a ete occuper le %s\n\n",timeString);
                                           FILE *steve;
                                           steve=fopen("date.txt","a");
                                           if(steve==NULL){
                                             fprintf(stderr,"Erreur impossible d'ouvire date.txt\n");
                                             exit(EXIT_FAILURE);
                                           }else{
                                                   printf("Quand aller vous liberer les %s ??\n",nom);
                                                   char date_fin[20];
                                                   printf("entrez la date de libairation:\n");
                                                   scanf("%s",date_fin);
                                                   fprintf(steve,"%s---%s---%s\n",nom,timeString,date_fin);
                                                   printf("passer ce delais vous serez penaliser !!!!\n");
                                                   printf("%s",date_fin);
                                           }
                                      }
                     }
                         void modifier_don(){

                           char timeString[9]; 
                           date(timeString, sizeof(timeString));
                           printf("L'heure actuelle est : %s\n", timeString);  
                              
                            char nom[23];
                            char nome[20];
                            int quantite;
                            char type[20];
                            char status[20];
                            int tr;
                                FILE *temp;
                                FILE *fp;
                                fp=fopen("don.txt","r");
                                if(fp==NULL){
                                      fprintf(stderr,"Erreur impossible d'ouvrir le fichier<acheter.txt>");
                                      exit(EXIT_FAILURE);
                                }
                                temp=fopen("temp9.txt","w");
                                if(temp==NULL){
                                   fprintf(stderr,"impossible d'ouvrire le fichier temp9.txt");
                                   exit(EXIT_FAILURE);
                                }
                                printf("voicie la liste des ressources disponibles:\n\n");
                                system("cat don.txt");
                                do{ 
                                printf("Donner le nom de la ressource dont vous souhaitez reserver :");
                                scanf("%s",nom);
                                }while(test1(nom)!=1);
                                while(fscanf(fp,"%s\t\t%d\t\t%s\t\t%s\n",nome,&quantite,type,status)==4){
                                          
                                        if(strcmp(nom,nome)==0)
                                        {
                                              tr=1;
                                              if(strcmp(status,"OCCUPER")==0){  
                                              printf("LA RESSOURCE EST DEJA OCCUPER\n");
                                              return;
                                              }
                                              strcpy(status,"OCCUPER");
                                        }
                                             fprintf(temp,"%s\t\t%d\t\t%s\t\t%s\n",nome,quantite,type,status);
                                }
                                      fclose(temp);
                                      fclose(fp);
                                      remove("don.txt");
                                      rename("temp9.txt","don.txt");
                                      if(tr==0){
                                          printf("la ressource n'existe pas\n !!");
                                      }else if(tr==1){
                                           
                                           printf("la ressource a ete occuper le %s\n\n",timeString);
                                           FILE *steve;
                                           steve=fopen("date.txt","a");
                                           if(steve==NULL){
                                             fprintf(stderr,"Erreur impossible d'ouvire date.txt\n");
                                             exit(EXIT_FAILURE);
                                           }else{
                                                   printf("Quand aller vous liberer les %s ??\n",nom);
                                                   char date_fin[20];
                                                   printf("entrez la date de libairation:\n");
                                                   scanf("%s",date_fin);
                                                   fprintf(steve,"%s---%s---%s\n",nom,timeString,date_fin);
                                                   printf("passer ce delais vous serez penaliser !!!!\n");
                                                   printf("%s",date_fin);
                                           }
                                      }
                     }






























































































