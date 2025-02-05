#ifndef BIBLIOLC
#define BIBLIOLC

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct livre {
	int num;
	char *titre;
	char *auteur;
	struct livre *suiv;
} Livre;

typedef struct {
	Livre *L;
} Biblio;

Livre* creer_livre(int num, char* titre, char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete (Biblio* b, int num, char* titre, char* auteur);
void afficher_livre(Livre* l);
void afficher_biblio(Biblio* b);
Livre* recherche1(Livre *l, int num);
Livre* recherche2(Livre *l, char *titre);
Biblio* recherche3(Livre *l, char* auteur);

#endif
