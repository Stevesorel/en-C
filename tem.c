            #include<stdio.h>
            #include<stdlib.h>
            #include<string.h>
                            void reserver_acheter(){
                                   
                                   FILE *temp=fopen("acheter.txt","r");
                                   if(temp==NULL){
                                       fprintf(stderr,"Erreur d'ouverture du fichier");
                                       exit (1);
                                   }
                                    char f[20],k[20],l[9],nom[20];
                                    int stquantite;
                                    printf("entrez la nom du truc :");
                                    scanf("%s",nom);
                                   while(fscanf(temp,"%s\t\t%d\t\t%s\t\t%s\n",f,&stquantite,l,k)==4){
                                          if(strcmp(nom,f)==0){
                                            strcpy(k,"occuper");
                                          }
                                   }
                            }
                      
                       int main(){
                            
                                  reserver_acheter();

                        return 0;
                       }
                         
