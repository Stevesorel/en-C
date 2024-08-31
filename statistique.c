#include<stdio.h>
#include<stdlib.h>
#include"gestion.h"
#include"taches.h"
/*------------------------------------------------------------------------------------*/
    float  tranche1(){
    FILE *sorel;
       char matricule[8];
       int montant;
       float size;
       float total;
     sorel =fopen("tranche.txt","r");
     if(sorel==NULL){
        printf("ERREUR D'OUVERTURE DU FICHIER\n");
     }
        else{
               while(!feof(sorel)){
                fscanf(sorel,"\n%s\t\t\t%d",matricule,&montant);
                       size++;             
               }
         total=5000*size;
        } 
        return total;
   }
/*------------------------------------------------------------------------------------*/
   
    float tranche2(){
    FILE *steve=fopen("tranche2.txt","r");
         char coder[23];
         int tranche ,jour,mois,annee;
         float total=0;
       if(steve==NULL){
         printf("erreur d'ouverture du fichier treanche 2\n");
       }else{
            while(!feof(steve)){
               fscanf(steve,"\n%s\t\t\t%d\t\t%d/%d/%d",coder,&tranche,&jour,&mois,&annee);
                total= total+tranche;   
            }
       }
           return total;
    }
/*------------------------------------------------------------------------------------*/
float tranche3(){

   FILE *steven=fopen("3tranche.txt","r");

    char coder[23];
         int tranche ,jour,mois,annee,jours,moiss,anneee;
         float total=0;
       if(steven==NULL){
         printf("erreur d'ouverture du fichier treanche 3\n");
       }else{
            while(!feof(steven)){
               fscanf(steven,"\n%s\t\t\t%d\t%d/%d/%d------%d/%d/%d",coder,&tranche,&jour,&mois,&annee,&jours,&moiss,&anneee);
                total= total+tranche;   
            }
             
       }
           return total;

}
/*------------------------------------------------------------------------------------*/
   float totale(){
      float tote;
      tote=tranche1()+tranche2()+tranche3();
      printf("le totale :%2.f",tote);
      return tote;

   }
/*------------------------------------------------------------------------------------*/
       float sous_tache(float argent){      
            float agt=totale();                 
            float sous = agt-argent;
             return sous;
       }
        
/*------------------------------------------------------------------------------------*/

   
/*------------------------------------------------------------------------------------*/

    


