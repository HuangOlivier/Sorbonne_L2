#include "biblioLC.h"
#include "entreeSortieLC.h"

#include "biblioH.h"

#include <stdlib.h>


void menu() {
	printf("Option:\n");
	printf("0 - Sortie du programme\n");
	printf("1 - Affichage \n");
	printf("2 - Inserer ouvrage \n");
}


int main(int argc, char** argv) {
	if (argc != 3) {
		printf("args error \n"); 
		return -1;
	};

	Biblio* LinkedList = charger_n_entrees(argv[1], atoi(argv[2]));
	BiblioH* hash = charger_n_entreesH(argv[1], atoi(argv[2]));

	//afficher_biblioH(hash);
	BiblioH* t = recherche3H(hash, "xyrivhpp");
	BiblioH* c = recherche3H(hash, "bbqcwi");
	
	BiblioH* fusion = fusionH(t,c);
	afficher_biblioH(fusion);
	
	liberer_biblio(LinkedList);
	
	liberer_biblioH(hash);
	liberer_biblioH(fusion);
	
	
	/*
	int rep;
	do {
		menu();
		scanf("%d", &rep);
		switch (rep) {
			case 0: 
				rep = 0;
				break;
			
			case 1:
				printf("Affichage: \n");
				afficher_biblio(a);
				break;
		}


	} while (rep != 0);
	printf("Bye Bye \n");
	*/
	return 0;
	
}
