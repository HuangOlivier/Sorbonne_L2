#include "biblioLC.h"
#include "entreeSortieLC.h"


Biblio* charger_n_entrees(char* nomfic, int n) {
	FILE *f = fopen(nomfic, "r");
	if (f == NULL) return NULL;
	char buffer[555];
	int num;
	char titre[255];
	char auteur[255];
	Biblio* new = creer_biblio();
	
	for(int i=0; i<n; i++){
	 	fgets(buffer, 555, f);
 		sscanf(buffer, "%d %s %s",&num, titre, auteur);
	 	inserer_en_tete(new, num, titre, auteur);
	}
	return new;
} 


void enregistrer_biblio(Biblio *b, char* nomfic) {
	FILE *f = fopen(nomfic, "w");
	
	Livre* t = b->L;
	while(t) {
		fprintf(f,"%d %s %s\n",t->num, t->titre, t->auteur);
		t=t->suiv;
	}
	
	fclose(f);
}
