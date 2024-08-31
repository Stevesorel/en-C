

      typedef struct Liste *Liste,Donne;   

      struct Liste{ 
           char nom[20];
           char type[23];
           char status[32];
           float quantite;
           char nom_d[20];
           int id;
           struct Liste *suivant;
          };
  Liste ajouter_ressource(Liste li,char *nom,char *type,char *status,char *nom_d,float *quantite,int *id);
    Liste saisir_element();
     void date(char* buffer, size_t bufferSize);
       void modifier_acheter();
        void modifier_don();
         void modifier_competition();