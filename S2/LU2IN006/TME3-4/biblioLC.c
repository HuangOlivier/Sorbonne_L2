#include "biblioLC.h"
#include <string.h>

Livre* creer_livre(int num, char* titre, char* auteur){
	Livre* new = malloc(sizeof(Livre));
	new-> num = num;
	new->titre = strdup(titre);
	new->auteur = strdup(auteur);
	new->suiv = NULL;
	
	return new;
}

void liberer_livre(Livre* l) {
	if (l) {
		free(l->titre);
		free(l->auteur);
		liberer_livre(l->suiv);
		free(l);
	}
}

Biblio* creer_biblio() {
	Biblio* new = malloc(sizeof(Biblio));
	new->L = NULL;
	return new;
}

void liberer_biblio(Biblio* b) {
	if (b) {
		liberer_livre(b->L);
		free(b);
	}
}

void inserer_en_tete (Biblio* b, int num, char* titre, char* auteur) {
	Livre* new = creer_livre(num, titre, auteur);
	new->suiv = b->L;
	b->L = new;
}

void afficher_livre(Livre* l){
	if (l){
		printf("%d %s %s\n", l->num, l->titre, l->auteur);
		afficher_livre(l->suiv);
	}
}

void afficher_biblio(Biblio* b){
	afficher_livre(b->L);
}

Livre* recherche1(Livre *l, int num) {
	if (l == NULL) return NULL;
	if (l->num == num) return l;
	
	recherche1(l->suiv, num);
}

Livre* recherche2(Livre *l, char *titre) {
	if (l == NULL) return NULL;
	if (strcmp(titre, l->titre)==0) return l;
	
	recherche2(l->suiv, titre);
}

Biblio* recherche3(Livre *l, char* auteur) {
	Biblio* new = creer_biblio();
	
	while (l) {
		if (strcmp(auteur, l->auteur)==0) {
			inserer_en_tete(new, l->num, l->titre, l->auteur);
		}
		l=l->suiv;
	}
	
}

Livre *suprimer(Livre *l, int num, char* titre, char* auteur) {
	if (l == NULL) return NULL;
	Livre *prec = NULL;
	
	while (l) { 
		if ((l->num==num) && (strcmp(l->titre,titre)) && (strcmp(l->auteur,auteur))) {
			Livre *tmp = l;
			
			if(prec == NULL) {
				l=tmp->suiv;
				free(tmp);
			} else {
				prec = l->suiv;
				free(l);
				l=prec;
			}
			return l;
		}
		prec = l;
		l=l->suiv;
	}
	return l;
}

Biblio *fusion(Biblio *a, Biblio *b) {
	Livre* tmp = b->L;
	while (tmp) {
		inserer_en_tete(a, tmp->num, tmp->titre, tmp->auteur);
		tmp = tmp->suiv;	
	}
	liberer_biblio(b);
}

Biblio *recherche4(Biblio *a) {
	
}

