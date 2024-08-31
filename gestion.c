#include<stdio.h>
#include<string.h>
#include"gestion.h"
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int test1(char nom[])
{    
   const char *texteClignotantRouge = "\033[5;91m";
    const char *texteNormal = "\033[0m";
    int i;
    for (i = 0; i < strlen(nom); i++)
    {
        if (!isalpha(nom[i]))
        {   
              for (int i = 0; i <3; i++) { // Faire clignoter 10 fois
        // Afficher le texte clignotant en rouge vif
        printf("%s\t\t\t\t\t\t\t\t\t\t\t veuillez entrez un nom comportant des lettre alphabetiques%s\n", texteClignotantRouge, texteNormal);
        // Attendre 1 seconde
        sleep(1);
        
        // Effacer la ligne précédente
        printf("\033[F\033[J"); // \033[F déplace le curseur vers le haut d'une ligne, \033[J efface le reste de la ligne
    }
          //  printf("\t\t\t\t\t\t\t\t\t\t\tentrez un nom comportant des lettres alphabetique\n");
            return 0;
        }
    }
    const char *texteClignotantVert = "\033[0;92m";
      const char *tExteNormal = "\033[0m";
    printf("%s\t\t\t\t\t\t\t\t\t\t\tgood%s\n",texteClignotantVert,tExteNormal);
    return 1;
}

int test2(char nom[])
{
    int i;
    const char *texteClignotantRouge = "\033[5;91m";
    const char *texteNormal = "\033[0m";
    
    if (strlen(nom) != 7)
    {   
             for (int i = 0; i <3; i++) { // Faire clignoter 10 fois
        // Afficher le texte clignotant en rouge vif
        printf("%s\t\t\t\t\t\t\t\t\t\t\t Veuillez entrez un matricule comportant des lettre alphabetiques%s\n", texteClignotantRouge, texteNormal);
        // Attendre 1 seconde
        sleep(1);
        
        // Effacer la ligne précédente
        printf("\033[F\033[J"); // \033[F déplace le curseur vers le haut d'une ligne, \033[J efface le reste de la ligne
    }
        
        // printf("\t\t\t\t\t\t\t\t\t\t\tEntrez un matricule correct\n");
        return 0;
    }
    else
    {
        for (i = 0; i < strlen(nom); i++)
        {
            if (!isalpha(nom[i]) && !isdigit(nom[i]))
            {
                for (int i = 0; i <3; i++) { // Faire clignoter 10 fois
        // Afficher le texte clignotant en rouge vif
        printf("%s\t\t\t\t\t\t\t\t\t\t\t Veuillez entrez un matricule comportant des lettre alphabetiques et des nombres %s\n", texteClignotantRouge, texteNormal);
        // Attendre 1 seconde
        sleep(1);
        
        // Effacer la ligne précédente
        printf("\033[F\033[J"); // \033[F déplace le curseur vers le haut d'une ligne, \033[J efface le reste de la ligne
    }
               // printf("\t\t\t\t\t\t\t\t\t\t\tentrez un matricule comportant des lettres alphabetique et des nombres \n");
                return 0;
            }
        }
         const char *texteClignotantVert = "\033[0;92m";
      const char *tExteNormal = "\033[0m";
    printf("%s\t\t\t\t\t\t\t\t\t\t\tgood%s\n",texteClignotantVert,tExteNormal);
        return 1;
    }
}

int test3(char num[])
{    int i;
    const char *texteClignotantRouge = "\033[5;91m";
    const char *texteNormal = "\033[0m";
    if (strlen(num) < 7)
    {
       for (int i = 0; i <3; i++) { // Faire clignoter 10 fois
        // Afficher le texte clignotant en rouge vif
        printf("%s\t\t\t\t\t\t\t\t\t\t\t Veuillez entrez un numero comportant des chiffres  %s\n", texteClignotantRouge, texteNormal);
        // Attendre 1 seconde
        sleep(1);
        
        // Effacer la ligne précédente
        printf("\033[F\033[J"); // \033[F déplace le curseur vers le haut d'une ligne, \033[J efface le reste de la ligne
    }
        return 0;
    }
    else
    {
        for (i = 0; i < strlen(num); i++)
        {    
            if (!isalnum(num[i]))
            {
               for (int i = 0; i <3; i++) { // Faire clignoter 10 fois
        // Afficher le texte clignotant en rouge vif
        printf("%s\t\t\t\t\t\t\t\t\t\t\t Veuillez entrez un numero comportant des chiffres  %s\n", texteClignotantRouge, texteNormal);
        // Attendre 1 seconde
        sleep(1);
        
        // Effacer la ligne précédente
        printf("\033[F\033[J"); // \033[F déplace le curseur vers le haut d'une ligne, \033[J efface le reste de la ligne
    }
                return 0;
            }
        }
    }
        const char *texteClignotantVert = "\033[0;92m";
      const char *tExteNormal = "\033[0m";
    printf("%s\t\t\t\t\t\t\t\t\t\t\tgood%s\n",texteClignotantVert,tExteNormal);
    return 1;
}

int test4(char add[])
{
    int i;
    if (strlen(add) > 20)
    {
        printf("\t\t\t\t\t\t\t\t\t\t\tentrez non valide veuillez reessayez\n");
        return 0;
    }
    else
    {
        for (i = 0; i < strlen(add); i++)
        {
            if (!isalpha(add[i]) && !isdigit(add[i]))
            {
                printf("entrez une residance correct \n");
                return 0;
            }
        }
        return 1;
    }
}

  
  void MEMBRE (){
    int somme,jours,moiss,anneee;
    int choix,reste;
    int jour,mois,annee;
    int frais;
    int tranche,trouver=0;
    char coder[10];
    Membre steve;
    
    FILE*fic=NULL;
  FILE*fichier=NULL;
  fichier=fopen("gestion_membre.txt","a+");
  fic=fopen("tranche.txt","a+");
       
     
  if (fichier!=NULL){
	//printf("\t😲️CHAQUE MEMBRE DEUVRA ENTRER UN MATRICULE QUI UN ENSEMBLE DE CHIFFRE NE DEPASSANT PAS 4 CARACTERE☺️\n");
	//printf("\tEXEMPLE (2364) vous devrez le retenir🙂️\n");
	      printf("\t\t\t\t\t\t\t\t<<<AVANT TOUTES CHOSE SACHIEZ QUE LES FRAIS D'INSCRIPTIONS S'ELEVES A 5OOOF>>>\n");
	      printf("\n \t\t\t\t\t\t\t\t\t\t\t<<<PAYABLE EN 3 TRANCHE>>>\n\n"); 
        do{ 
        printf("\t\t\t\t\t\t\t\t\t\t\tentrez votre matricule:");
        scanf("%s",coder);
        }while(test2(coder)!=1);
        
         // strcpy(steve.matricule,coder);
          
        while(!feof(fichier)){
       fscanf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",steve.matricule,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);
          if(strcmp(coder,steve.matricule)==0){
            trouver=1;
            break;
          }
        }
        if(trouver==1){
          system("clear");
          printf("\t\t\t\t\t\t\t\t\t\t\tetudiant existe deja !!!!!\n\n\n");
          return;
        }else{ 
          do{ 
        printf("\t\t\t\t\t\t\t\t\t\t\tentrez le nom du membre:");
        scanf("%s",steve.nom);}while(test1(steve.nom)!=1);
        do{ 
        printf("\t\t\t\t\t\t\t\t\t\t\tentrez le prenom du membre:");
        scanf("%s",steve.prenom);}while(test1(steve.prenom)!=1);
        do{
        printf("\t\t\t\t\t\t\t\t\t\t\tentrez votre numero de telephone:");
        scanf("%s",steve.numero);}while(test3(steve.numero)!=1);
        
        printf("\t\t\t\t\t\t\t\t\t\t\tentrez le nom de votre quartier de residence:");
        scanf("%s",steve.addresse);/*}while(test4(steve.addresse)!=1);*/
        printf("\n");
       
          system("clear");
        printf("\t\t\t\t\t\t\t\t\t\t\tvoulez-vous adeherer le club en tantque :\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t1-president\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t2-vice-president\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t3-tresorier\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t4-manager\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t5-DJ\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t6-vigile\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t7- visiteur\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t🚨️🚨️ENTREZ LE CHIFFRE !!🚨️🚨️\t");
        scanf("%d",& choix);
       
        if(choix==1){
          sprintf(steve.role,"president");
          //fprintf(fichier,"\n============================================================================================\n");
          fprintf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",coder,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);
 }
 else if(choix==2){

 sprintf(steve.role,"vice-president");
          fprintf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",coder,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);
 }
 else if(choix==3){
   sprintf(steve.role,"tresorier");
     fprintf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",coder,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);    
 }
 else if(choix==4){
   sprintf(steve.role,"community-manager");
          fprintf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",coder,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);
 }
 else if(choix==5){
   sprintf(steve.role,"DJ");
         fprintf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",coder,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);
 }
 else if(choix==6){

   sprintf(steve.role,"agent-d'entretient");
        fprintf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",coder,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);
 
 }
 else if(choix==7){
   sprintf(steve.role,"visiteur");
         
     fprintf(fichier,"\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",coder,steve.nom,steve.prenom,steve.numero,steve.role,steve.addresse);
} 
else{ 
   
      printf("votre choix est invalide");
           
}
      fclose(fichier);
    
        }
  }else{

    printf("\t\t\t\t\t\t\t\t\t\t\timpossible d'ouvrire le fichier");

  }
  

     if(fic!=NULL){  

    printf("\t\t\t\t\t\t\t\t\t\t\tvoulez-vous payez vos frais d'inscription en combien de tranche ?:");
       scanf("%d",&frais);
      if(frais==1){
       printf("\t\t\t\t\t\t\t\t\t\t\tentrez vos frais d'inscription:");
       scanf("%d",&tranche);
       if(tranche>=5000)
       fprintf(fic,"\n%s\t\t\t%d",coder,tranche);
       else{
        printf("\t\t\t\t\t\t\t\t\t\t\tentrez une valeur superieur ou egale a 5000\n");
         exit(0);
       }
      }
   else if(frais==2){
     
 FILE *file=fopen("tranche2.txt","a+");
                if(file==NULL){
                  printf("erreur d'ouverture du ficheier");
                  exit(1);
                }else{
    printf("\t\t\t\t\t\t\t\t\t\t\tentrez la premier tranche:");
    scanf("%d",&tranche);
    printf("\t\t\t\t\t\t\t\t\t\t\tQuand allez-vous payer la deuxieme tranche ?\n");
     printf("\t\t\t\t\t\t\t\t\t\t\tentrez le jour:");
    scanf("%d",&jour);
    printf("\t\t\t\t\t\t\t\t\t\t\tentrez le mois:");
    scanf("%d",&mois);
    printf("\t\t\t\t\t\t\t\t\t\t\tentrez l'annee:");
    scanf("%d",&annee);
     if(jour>31||mois>12||annee>2024 ){
      printf("\t\t\t\t\t\t\t\t\t\t\t🤨️entrez une date correcte🤨️\n");
      exit(2);
    }else{
       int somme=5000;
      reste=somme-tranche;
      int age;
      scanf("%d",&age);
      fprintf(file,"\n%s\t\t\t%d\t\t%d/%d/%d",coder,tranche,jour,mois,annee);
      fclose(file);
       printf("\t\t\t\t\t\t\t\tIL NE VOUS RESTE QUE <%d>   PAYER AVANT LE %d/%d/%d \n",reste,jour,mois,annee);
       scanf("%d",&age);
     }
    }

  
   }  else if(frais==3){

   FILE *files=NULL;
    files=fopen("3tranche.txt","a");
       if(files!=NULL){  
    printf("\t\t\t\t\t\t\t\t\t\t\tentrez la premier tranche:");
    scanf("%d",&tranche);
    printf("\t\t\t\t\t\t\t\t\t\t\tQuand allez-vous payer la deuxieme tranche ?\n");
     printf("\t\t\t\t\t\t\t\t\t\t\tentrez le jour:");
    scanf("%d",&jour);
    printf("\t\t\t\t\t\t\t\t\t\t\tentrez le mois:");
    scanf("%d",&mois);
    printf("\t\t\t\t\t\t\t\t\t\t\tentrez l'annee:");
    scanf("%d",&annee);
    if(jour>31||mois>12||annee>2024 ){
      printf("\t\t\t\t\t\t\t\t\t\t\tentrez une date correcte:\n");
      exit(2);}
    printf("\t\t\t\t\t\t\t\t\t\t\tQuand allez-vous payer la troisieme tranche ?\n");
     printf("\t\t\t\t\t\t\t\t\t\t\tentrez le jour:");
    scanf("%d",&jours);
    printf("\t\t\t\t\t\t\t\t\t\t\tentrez le mois:");
    scanf("%d",&moiss);
    printf("\t\t\t\t\t\t\t\t\t\t\tentrez l'annee:");
    scanf("%d",&anneee);
    if(jour>31||mois>12||annee>2024 ){
      printf("\t\t\t\t\t\t\t\t\t\t\t🤨️entrez une date correcte🤨️\n");
      exit(2);
    }else{
      int somme=5000;
      reste=somme-tranche;
      fprintf(files,"\n%s\t\t\t%d\t%d/%d/%d------%d/%d/%d",coder,tranche,jour,mois,annee,jours,moiss,anneee);
      fclose(files);
      printf("\t\t\t\t\t\t\t\t\t\tIL NE VOUS RESTE QUE <%d>   PAYER AVANT LE %d/%d/%d------et-----%d/%d/%d\n",reste,jour,mois,annee,jours,mois,anneee);
    }
    }else{
      printf("erreur d'ouverture de 3tranche");
    }     
   }
        fclose(fic);
        }
        system("clear");
             printf("\e[33 \e[41m");
          printf("\t\t\t\t\t\t\t\t\t\t👍️\e[5mVOUS ETES ENREGISTRER\e[0m👍️");
             printf("\n\n");
  
  }
  

