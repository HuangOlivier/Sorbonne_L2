#include "entreeSortieH.h"
#include "biblioH.h"

//Fonction qui permet de lire les n premières lignes du fichier "nomfic" (Table de hachage)
BiblioH* charger_n_entreesH(char* nomfic, int n) {
	FILE *f = fopen(nomfic, "r");
	if (f == NULL) return NULL;
	char buffer[555];
	int num;
	char titre[255];
	char auteur[255];
	BiblioH* new = creer_biblioH(n);
	
	for(int i=0; i<n; i++){
	 	fgets(buffer, 555, f);
 		sscanf(buffer, "%d %s %s",&num, titre, auteur);
	 	insererH(new, num, titre, auteur);
	}
	
	fclose(f);
	return new;
}

//Fonction qui stock dans un fichier "nomfic" la bibliothèque b (Table de hachage)
void enregistrer_biblioH(BiblioH *b, char* nomfic) {
	FILE *f = fopen(nomfic, "w");
	if(f==NULL) return;
	for (int i=0; i<b->m; i++) {
		LivreH* tmp = b->T[i];
		while(tmp) {
			fprintf(f,"%d %s %s\n",tmp->num, tmp->titre, tmp->auteur);
			tmp=tmp->suivant;
		}
	}
	
	fclose(f);
}
