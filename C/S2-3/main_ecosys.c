#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include "ecosys.h"



#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000


/* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.01;
float p_reproduce_proie=0.4;
float p_reproduce_predateur=0.5;
int temps_repousse_herbe=-15;



int main(void) {
	int monde[SIZE_X][SIZE_Y];

	FILE *res = fopen("Evol_Pop.txt", "w");

	for (int i=0; i < SIZE_X; i++) {
		for (int j=0; j < SIZE_Y; j++) {
			monde[i][j] = 0;
		}
	}
	Animal *tete_proies = NULL;
	Animal *tete_predateur = NULL;


	for (int i=0; i<20;i++) {
		ajouter_animal ( rand() % (SIZE_X-1), rand() % (SIZE_Y-1), 10, &tete_proies);
		ajouter_animal ( rand() % (SIZE_X-1), rand() % (SIZE_Y-1), 10, &tete_predateur);
	}

	int i =0;
	

	//afficher_ecosys (tete_proies, tete_predateur);
	//sleep(2);

	while ( (tete_proies != NULL || tete_predateur != NULL) && i < 600) {
		printf("%d \n", i);

		rafraichir_monde(monde);
		rafraichir_proies (&tete_proies, monde);
		rafraichir_predateurs (&tete_predateur, &tete_proies);
		//afficher_ecosys (tete_proies, tete_predateur);
		
		fprintf(stdout, "%d %d %d \n",i, compte_animal_it(tete_proies), compte_animal_it(tete_predateur));
		fprintf(res, "%d %d %d \n",i, compte_animal_it(tete_proies), compte_animal_it(tete_predateur));



		i++;
	}
	
	fclose(res);

	/* A completer. Part 2:
	* exercice 4, questions 2 et 4 
	* exercice 6, question 2
	* exercice 7, question 3
	* exercice 8, question 1
	*/

	return 0;
}

