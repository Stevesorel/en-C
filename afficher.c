#include"gestion.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void afficher_liste_sans_distinction(){
	
	 FILE *fichier = fopen("gestion_membre.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier gestion_membre.txt\n");
        return;
    }

    Membre steve;
    printf("\n\033[1;34mListe des MEMBRES:\033[0m\n");
    printf("+---------------+----------------------+----------------------+---------------------+----------------+-----------------------------+\n");
    printf("| \033[1;36mMatricule\033[0m     | \033[1;36mNom\033[0m                  | \033[1;36mPrénom\033[0m               | \033[1;36mTéléphone\033[0m           | \033[1;36mrole\033[0m           | \033[1;36mquartier\033[0m                    | \n");
    printf("+---------------+----------------------+----------------------+---------------------+----------------+-----------------------------+\n");

    while (fscanf(fichier, "\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", steve.matricule, steve.nom, steve.prenom, steve.numero, steve.role, steve.addresse) == 6) {
        printf("| \033[1;35m%-13s\033[0m | \033[1;32m%-20s\033[0m | \033[1;32m%-20s\033[0m | \033[1;32m%-19s\033[0m | \033[1;32m%-14s\033[0m | \033[1;34m%-27s\033[0m |\n",
               steve.matricule, steve.nom, steve.prenom, steve.numero, steve.role, steve.addresse);
        printf("+---------------+----------------------+----------------------+---------------------+----------------+-----------------------------+\n");
    }

    fclose(fichier);
}



//totalite
void af_l_m_t(){
 
	 FILE *fic;
	 char aff;
	 fic =fopen("tranche.txt","rt");
	 if(fic==NULL){
	 	printf("impossible d'ouvrir fic");
	 }
	 else{

	 	while(1){
             aff=fgetc(fic);
             if(feof(fic))
             	break;
             printf("%c",aff);
	 	}
	 }
	 fclose(fic);
}


void modifier(){
       Membre steve;
	    FILE *temp;
		int choix;
    char coder[10];int trouver=0;
    FILE *fichier=NULL;
	fichier=fopen("gestion_membre.txt","r");
    if(fichier==NULL){
		printf("erreur d'ouverture du fichier du fichier geestion\n");
		exit(1);
	}
	 temp=fopen("temp.txt","w");
	 if(temp==NULL){
		printf("erreur d'ouverture du fichier temp\n");
		exit(1);
	}
	printf("donner le code de l'etudiant a modifier:");
	scanf("%s",coder);

     while(fscanf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",steve.matricule,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse)==6){
		      if(strcmp(coder,steve.matricule)==0){
                  trouver=1;
				  printf("que voulez vous modifier sur cette etudiant ?\n");
				  printf("TAPEZ:\n 1-NOM\n2-PRENOM\n3-NUMERO\n4-ROLE");
                   scanf("%d",&choix);
				   if(choix==1){ 
				  printf("donner le nouveau nom:\t");
				  scanf("%s",steve.nom);
				 // fprintf(temp,"\n%d\t\t%s\t\t\t%s\t\t\t%d\t\t\t%s\t\t\t%s",steve.code,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);	
				   }else if(choix==2){
                      printf("entrez le nouveau prenom :");
					  scanf("%s",steve.prenom);
				 // fprintf(temp,"\n%d\t\t%s\t\t\t%s\t\t\t%d\t\t\t%s\t\t\t%s",steve.code,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);	
				   }else if(choix==3){
					printf("entrez le nouveau numero :");
					scanf("%s",steve.numero);
					 // fprintf(temp,"\n%d\t\t%s\t\t\t%s\t\t\t%d\t\t\t%s\t\t\t%s",steve.code,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);	
				   }else if(choix==4){
                              printf("entrez le nouveau role");
							  scanf("%s",steve.role);
							   // fprintf(temp,"\n%d\t\t%s\t\t\t%s\t\t\t%d\t\t\t%s\t\t\t%s",steve.code,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);	
				   }else if(choix==5){
					printf("entrez votre nouvelle addresse : ");
					scanf("%s",steve.addresse);
					// fprintf(temp,"\n%d\t\t%s\t\t\t%s\t\t\t%d\t\t\t%s\t\t\t%s",steve.code,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);	
				   }
			  }
			fprintf(temp,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",steve.matricule,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);	  
	 }
        fclose(fichier);
		fclose(temp);
		remove("gestion_membre.txt");	 
		rename("temp.txt","gestion_membre.txt");
		if(trouver==0){
			printf("\033[1;31ml'etudiant n'existe pas.\033[0m\n");
		
		}
		else{
			printf("le membre a ete modifier");
		}
}







