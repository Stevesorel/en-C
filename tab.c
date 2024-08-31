#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  typedef struct Etudiant *Liste;
  struct Etudiant{
   
       int val;
       struct Etudiant *suivant;
  };
     
     int estvide(Liste li){
        if(li==NULL)
          return 1;
          return 0;
     }
         
         Liste insert_tete(Liste li,int new){

              Liste e;
             e=(Liste)malloc(sizeof(e));
             if(e==NULL){
                printf("erreur d'allocation memoire\n");
             }
             e->val=new;
             if(estvide(li)){
              e->suivant=NULL;
              return e;
             }              
             else{
                e->suivant=li;
                return e;
             }
         }
 
             Liste insert_queue(Liste li,int new){

        
                   Liste e;
                  e=(Liste)malloc(sizeof(e));
                  if(e==NULL){
                    printf("erreur d'allocation");
                  }
                  else{
                    e->val=new;
                    if(estvide(li)){
                        e->suivant=NULL;
                        return e;
                    }
                    else{
                           Liste temp;
                            temp=li;
                           while(temp->suivant!=NULL){
                            temp=temp->suivant;
                           }
                           e->suivant=NULL;
                           temp->suivant=e;
                           return li;
                             }         }
        }
        void affiche(Liste li){

            if(estvide(li)){
                  printf("rien a afficher\n");
            }else{
                  while(li!=NULL){
                        printf("%d-->",li->val);
                        li=li->suivant;
                  }
                  printf("NULL");
            }
        }
              int nombre(Liste li){
                  int size=0;
                  while(li!=NULL){
                        ++size;
                        li=li->suivant;
                  } return size;}

      Liste supprimer( Liste li){
            Liste l,p;    
            p=li;
            
            if(estvide(li)){
                  printf("rien a supprimer");
            }else{
                  l=li->suivant;
                  free(p);
            }
            
      return l;
      }
      Liste supprimer_queue(Liste li){

            Liste l,p;
            p=li;
            if(estvide(li)){
                  printf("rien a supprimer");
            }else{
                  
            }
      }
int main(){

Liste li=NULL;
li=insert_queue(li,9);
li=insert_tete(li,65);
li=insert_tete(li,6);
li=insert_queue(li,9);
li=insert_tete(li,5);
li=insert_queue(li,9);
li=insert_tete(li,15);
li=insert_queue(li,9);
li=insert_tete(li,55);
affiche(li);
printf("\n");
printf("le nombre d'element est :%d\n",nombre(li));
li=supprimer(li);
li=supprimer(li);
li=supprimer(li);
li=supprimer(li);
li=supprimer(li);
affiche(li);
printf("\n");
printf("le nombre d'element est :%d\n",nombre(li));
  return 0;
}




