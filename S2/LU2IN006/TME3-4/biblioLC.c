#include "biblioLC.h"
#include <string.h>

//fonction qui crée un livre
Livre* creer_livre(int num, char* titre, char* auteur){
	Livre* new = malloc(sizeof(Livre));
	new-> num = num;
	new->titre = strdup(titre); //allouer et initialiser en mémoire d'un char*
	new->auteur = strdup(auteur); //allouer et initialiser en mémoire d'un char*
	new->suiv = NULL;
	
	return new;
}

//Fonction pour libérer UN seul livre
void liberer_livre(Livre *L){
	if(L==NULL) return;
	free(L->titre);
	free(L->auteur);
	free(L);
}

//Fonction pour crée une bibliothèque vide
Biblio* creer_biblio() {
	Biblio* new = malloc(sizeof(Biblio));
	new->L = NULL;
	return new;
}

//Fonction pour libérer tous les livres d'une liste chainée (Biblio->L) qui utilise la fonction liberer_livre
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

//Fonction qui insère en tête un livre dans la liste chainée (Biblio->L) 
void inserer_en_tete (Biblio* b, int num, char* titre, char* auteur) {
	if(b==NULL) return;
	Livre* new = creer_livre(num, titre, auteur);
	new->suiv = b->L;
	b->L = new;
}

//Fonction qui affiche UN livre
void afficher_livre(Livre* l){
	if (l){
		printf("%d %s %s\n", l->num, l->titre, l->auteur);
	}
}

//Fonction qui affiche tous les livres de la liste chainée de b->L
void afficher_biblio(Biblio* b){
	if (b == NULL) return;
	
	Livre* tmp = b->L;
	while (tmp) {
		afficher_livre(tmp);
		tmp = tmp->suiv;
	}
}

//Fonction pour rechercher un livre dont le numéro est num
Livre* recherche_num(Livre *l, int num) {
	if (l == NULL) return NULL;
	if (l->num == num) return l;
	
	recherche_num(l->suiv, num);
}

//Fonction pour rechercher un livre dont le titre est titre
Livre* recherche_titre(Livre *l, char *titre) {
	if (l == NULL) return NULL;
	if (strcmp(titre, l->titre)==0) return l;
	
	recherche_titre(l->suiv, titre);
}

//Fonction pour rechercher un livre dont l'auteur est auteur
Biblio* recherche_auteur(Biblio* b, char* auteur){
	if (b == NULL) return NULL;
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

//Fonction qui supprime le livre dont les valeurs sont passées en argument
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

//Fonction qui fusionne deux bibliothèque
Biblio *fusion(Biblio *a, Biblio *b) {
	if (a==NULL) return NULL;
	if (b==NULL) return a;
	
	Livre* tmp = b->L;
	while (tmp) {
		inserer_en_tete(a, tmp->num, tmp->titre, tmp->auteur);
		tmp = tmp->suiv;	
	}
	return a;
}

//Fonction qui recherche les livre qui sont en plusieurs exemplaires
Biblio *recherche_meme_ouvrage(Biblio *a) {
	if(a == NULL) return NULL;
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

