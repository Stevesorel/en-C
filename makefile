 sorel:gestion.o main.o sup.o afficher.o ajouter_taches.o afficher_taches.o supprimer_tache.o modifier_tache.o charger_taches.o sauvegarder_taches.o res.o
	gcc gestion.o main.o sup.o afficher.o ajouter_taches.o afficher_taches.o supprimer_tache.o modifier_tache.o charger_taches.o sauvegarder_taches.o res.o -o sorel
	./sorel
main.o:main.c gestion.h taches.h ressource.h
	gcc -c main.c
gestion.o:gestion.h gestion.c
	gcc -c gestion.c
sup.o:gestion.h sup.c
	gcc -c sup.c
res.o:res.c ressource.h gestion.h
	gcc -c res.c	
afficher.o:afficher.c gestion.h	
	gcc -c afficher.c
ajouter_taches.o: ajouter_taches.c taches.h
	gcc -c ajouter_taches.c
afficher_taches.o: afficher_taches.c taches.h
	gcc -c afficher_taches.c
supprimer_tache.o: supprimer_tache.c taches.h
	gcc -c supprimer_tache.c
modifier_tache.o: modifier_tache.c taches.h
	gcc -c modifier_tache.c
charger_taches.o: charger_taches.c taches.h
	gcc -c charger_taches.c
sauvegarder_taches.o: sauvegarder_taches.c taches.h
	gcc -c sauvegarder_taches.c	

clean:
	rm -f *o
	rm sorel
