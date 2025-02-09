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

void liberer_livre(Livre *L){
	if(L==NULL) return;
	free(L->titre);
	free(L->auteur);
	free(L);
}

Biblio* creer_biblio() {
	Biblio* new = malloc(sizeof(Biblio));
	new->L = NULL;
	return new;
}

void liberer_biblio(Biblio* b) {
	if (b) {
		Livre* tmp = b->L;
		Livre* t;
		while (tmp) {
			t = tmp->suiv;
			liberer_livre(tmp);
			tmp = t;
		}
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
	if (b == NULL) return;
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

Biblio* recherche3(Biblio* b, char* auteur){
	Biblio* newb = creer_biblio();
	Livre* l = b->L;
	while(l){
		if(strcmp(auteur, l->auteur) == 0){
			inserer_en_tete(newb, l->num, l->titre, auteur);
		}
		l = l->suiv;
	}
	return newb;
}


void supprimer(Biblio* b, int num, char* titre, char* auteur){
	if (b == NULL || b->L == NULL) {
		printf("La bibliothèque est vide, suppression impossible.\n");
		return;
	}
	
	Livre* l = b->L;
	if(l->num == num && strcmp(titre, l->titre) == 0 && strcmp(auteur, l->auteur) == 0){
		b->L = l->suiv;
		liberer_livre(l);
		return;
	}
	Livre* tmp;
	while(l){
		if(l->num == num && strcmp(titre, l->titre) == 0 && strcmp(auteur, l->auteur) == 0){
			tmp->suiv = l->suiv;
			liberer_livre(l);
			return;
		}
		tmp = l;
		l = l->suiv;
	}
}

Biblio *fusion(Biblio *a, Biblio *b) {
	Livre* tmp = b->L;
	while (tmp) {
		inserer_en_tete(a, tmp->num, tmp->titre, tmp->auteur);
		tmp = tmp->suiv;	
	}

	return a;
}

Biblio *recherche4(Biblio *a) {
	Biblio* res = creer_biblio();

	Livre* now = a->L;
	Livre* tmp;

	while(now) {
		
		tmp= a->L;
		int a=0;

		while (tmp && (a==0)) {
			if ((strcmp(now->titre, tmp->titre)==0) && (strcmp(now->auteur, tmp->auteur)==0)){
				inserer_en_tete (res, tmp->num, tmp->titre, tmp->auteur);
				a=1;
			}

			tmp=tmp->suiv;
		}

		now=now->suiv;
	}
	return res;
}

