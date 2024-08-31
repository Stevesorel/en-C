



typedef struct Membre Membre;

struct Membre{
     char nom[30];
     char prenom[50];
     char role[50];
     char addresse[20];
     float cotisation;
     int tranche1;
     int tranche2;
     int tranche3;
     int totalite;
     char numero[19];
     char matricule[12];
     
};
void MEMBRE();
void modifier ();
void afficher_liste_sans_distinction();
void af_l_m_t();
void suppression();

int test1(char nom[]);
int test2(char nom[]);
int test3(char nom[]);
int test4(char nom[]);
 
 /*-------------------------------------------------------------------------------------------------------*/
   

   
   
   
   
   
   
   
   
