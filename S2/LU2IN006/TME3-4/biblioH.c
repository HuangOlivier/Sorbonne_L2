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
	if (b == NULL) return;

	for (int i=0; i<b->m; i++) {
		liberer_livreH(b->T[i]);
	}
	free(b->T);
	free(b);
	
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
		if(b->T[i] != NULL) {
			printf("indice %d: \n", i);
			afficher_livreH(b->T[i]);
			printf("\n\n");
		}
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

BiblioH *recherche3H(BiblioH *b, char* auteur) {
	BiblioH* res = creer_biblioH (b->m);
	int cleHachage = fonctionHachage(fonctionClef(auteur), b->m);

	LivreH* tmp = b->T[cleHachage];

	while(tmp) {
		if (strcmp(auteur, tmp->auteur)==0) {
			insererH(res, tmp->num, tmp->titre, tmp->auteur);
		}

		tmp = tmp->suivant;
	}
	return res;
}

BiblioH *supprimerH(BiblioH *b, int num, char *titre, char* auteur) {
	if (b==NULL) return NULL;

	int cleHachage = fonctionHachage(fonctionClef(auteur), b->m);
	LivreH* tmp = b->T[cleHachage];
	LivreH* prec = NULL;

	while(tmp) {
		if ((tmp->num==num) && (strcmp(tmp->titre,titre)==0) && (strcmp(tmp->auteur,auteur)==0)) {
			
			if (prec == NULL) {
				b->T[cleHachage] = tmp->suivant;
			} else {
				prec->suivant=tmp->suivant;
			}

			free(tmp->titre);
			free(tmp->auteur);
			free(tmp);

			b->ne--;
			return b;
		}
		prec = tmp;
		tmp=tmp->suivant;
	}
	return b;
} 

BiblioH *fusionH(BiblioH *a, BiblioH *b) {
	if (a==NULL) return NULL;
	if (b==NULL) return a;

	LivreH *tmp;

	for (int i=0; i<b->m; i++) {
		if(b->T[i] != NULL) {
			tmp = b->T[i];
			while(tmp) {
				insererH(a, tmp->num, tmp->titre, tmp->auteur);
				tmp = tmp->suivant;
			}
		}
	}
	liberer_biblioH(b);

	return a;
}

BiblioH *recherche4H(BiblioH *a) {
	BiblioH* res = creer_biblioH (a->m);
	LivreH* cour;
	LivreH* tmp;
	int count = 0;
	for (int i=0; i<a->m; i++) {
		cour = a->T[i];
		while(cour) {
			tmp=a->T[i];

			while(tmp) {
				if ((strcmp(cour->titre, tmp->titre)==0) && (strcmp(cour->auteur, tmp->auteur)==0) && (tmp != cour)) {
					count++;
				}
				tmp = tmp->suivant;
			}
			if(count > 2){
				insererH(res, cour->num, cour->titre, cour->auteur);
				count = 0;
			}
			cour = cour->suivant;
		}
	}
	return res;
}