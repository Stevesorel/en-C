  #include"ressource.h"
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>

  Liste ajouter_ressource(Liste li,char *nom,char *type,char *status,char *nom_d,float *quantite,int *id){

                      Liste l=NULL;
                      l=(Liste*)malloc(sizeof(Liste));
                      if(l==NULL){
                          fprintf(stderr,"Erreur d'allocation memoire");
                           exit(EXIT_FAILURE);
                      }else{    
                               l->id=*id;
                               strcpy(l->nom,nom);
                               strcpy(l->type,type);
                               l->quantite=*quantite;
                               sprintf(l->status,"disponible");
                               strcpy(l->nom_d,nom_d);
                               l->suivant=li;
                               return l;
                      }               
  }
            void afficher(Liste l){
                  
                     if(l==NULL){
                         printf("LISTE VIDE");
                         exit(0);
                     }else{
                             Liste p=l;
                             while(p!=NULL){
                                 printf("%d",l->id);
                                 printf("%s",l->nom);
                                 printf("%s",l->type);
                                 printf("%f",l->quantite);
                                 printf("%s",l->status);
                                 printf("%s",l->nom_d);
                                 l=l->suivant;
                             }
                     }
            }
             
            Liste saisir_element(){
                     char ka[20];
                   char n[40];
                   int k;
                  char choix;
                  char nom[20], type[20],status[20],nom_d[20];float quantite;int id;
                  Liste *li=NULL;
                   puts("voulez-vous enregistrez une ressources ?: ");
                   choix=getchar();
                   getchar();
                   while(choix=='o'||choix=='O'){
                         puts("Entrez le nom de la ressource:");
                         scanf("%s",nom);
                         getchar();
                         puts("Entrez la quatite ou la somme :");
                         scanf("%f",&quantite);
                         getchar();
                         puts("Entrez le type de la ressources:");
                         printf("Selectionnez la lettre correspondant au type de la ressource");
                        //   do{ 
                         printf("Entrez:\n");
                         printf("1-Don\n2-gagner_apres competition\n3-acheter par le club\n");     
                         scanf("%d",&k);
                         getchar();
                         switch (k)
                         {
                         case 1:
                                   strcpy(type,"DON");
                         break;
                         case 2:
                                   strcpy(type,"COMPETITION");
                             break;
                         case 3:
                                   strcpy(type,"ACHETER");
                         break;      
                         default:
                                    printf("Option invalide veuillez reessayer");
                           break;
                         }
                         //}while(k!=1||k!=2||k!=3);
                           if(strcmp(type,"DON")==0){
                              printf("Entrez le nom /association qui a fait le don:");
                                    
                                    scanf("%s",n);
                                    getchar();
                                    strcpy(nom_d,n);
                           }else if(strcmp(type,"COMPETITION")==0){
                                    printf("Entrez le nom de la competition:");                                
                                     scanf("%s",ka);
                                     getchar();
                                    strcpy(nom_d,ka);
                                
                           }else if(strcmp(type,"ACHETER")==0){
                                  sprintf(nom_d,"CLUB");
                             
                           }
                           sprintf(status,"DISPONIBLE");

                            id=1;
                            id++;
                      li=ajouter_ressource(li,nom,type,status,nom_d,&quantite,&id);
                      puts("voulez-vous continuez ??");
                      choix=getchar();
                      getchar();
                   }
                      return li;
            }
            
                int main(){
  
                 Liste li;
                 li=saisir_element();
                 afficher(li);
                  return 0;
                }