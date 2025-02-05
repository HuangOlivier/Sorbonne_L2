#include "biblioH.h"
#include <string.h>

int fonctionClef(char* auteur) {
	int cle = 0;

	for(int i=0; auteur[i] != '\0'; i++) {
		cle += (int) auteur[i];
	}

	return cle;
}

LivreH* creer_livreH(int num, char* titre, char* auteur) {
	LivreH* new = malloc(sizeof(LivreH));

	new->num = num;
	new->titre = strdup(titre);
	new->auteur = strdup(auteur);
	new->suivant = NULL;

	return new;
	
}

void liberer_livreH(LivreH* l) {
	if (l) {
		free(l->titre);
		free(l->auteur);
		liberer_livreH(l->suivant);
		free(l);
	}
}

BiblioH* creer_biblioH (int m) {
	BiblioH* new = malloc(sizeof(BiblioH));
	new->ne=0;
	new->m = m;
	new->T = malloc(sizeof(LivreH*)*m);
	for (int i=0; i<m; i++){
		new->T[i] = NULL;
	}
	
	return new;
}

void liberer_biblioH(BiblioH* b) {
	for (int i=0; i<b->m; i++) {
		liberer_livreH(b->T[i]);
	}
}

int fonctionHachage(int cle, int m) {
	double A = (sqrt(5)-1)/2;
	return (int) (m*(cle*A - (int) (cle*A) ));
}

void insererH(BiblioH* b, int num, char* titre, char* auteur) {
	int cle1 = fonctionClef(auteur);
	int cleHachage = fonctionHachage(cle1, b->m);

	LivreH* new =  creer_livreH(num, titre, auteur);

	new->suivant = b->T[cleHachage];
	b->T[cleHachage] = new;
	b->ne++;
	
}

void afficher_livreH(LivreH* l) {
	if(l) {
		printf("%d %s %s\n", l->num, l->titre, l->auteur);
		afficher_livreH(l->suivant);
	}
}

void afficher_biblioH(BiblioH *b) {
	if (b==NULL) return;
	for (int i=0; i<b->m; i++) {
		printf("indice %d: \n", i);
		afficher_livreH(b->T[i]);
		printf("\n\n");
	}
}

LivreH *recherche1H(BiblioH *b, int num){
	if (b==NULL) return NULL;
	LivreH* tmp;
	for (int i=0; i<b->m; i++) {
		tmp = b->T[i];
		while (tmp) {
			if (tmp->num == num) 
				return tmp;
			tmp = tmp->suivant;
		}

	}
	return NULL;
}

LivreH *recherche2H(BiblioH *b, char *titre){
	if (b==NULL) return NULL;
	LivreH* tmp;
	for (int i=0; i<b->m; i++) {
		tmp = b->T[i];
		while (tmp) {
			if (strcmp(tmp->titre, titre)==0) 
				return tmp;
			tmp = tmp->suivant;
		}

	}
	return NULL;
}

//meme auteur