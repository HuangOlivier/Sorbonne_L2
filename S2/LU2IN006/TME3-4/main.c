#include "biblioLC.h"
#include "entreeSortieLC.h"

#include "biblioH.h"

#include <stdlib.h>
#include <time.h>

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

	//Biblio* LinkedList = charger_n_entrees(argv[1], atoi(argv[2]));
	//BiblioH* hash = charger_n_entreesH(argv[1], atoi(argv[2]));


	clock_t temps_init;
	clock_t temps_final;
	double temps_cpu;



	/*
	int randomN = rand() % atoi(argv[2]);
	temps_init = clock();
	for(int i=0; i<150;i++) {
		recherche1(LinkedList->L, randomN);
	}
	temps_final=clock();
	temps_cpu = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;
	printf("Liste chainée: recherche 1 - %f \n", temps_cpu);


	temps_init = clock();
	for(int i=0; i<150;i++) {
		recherche1H(hash, randomN);
	}
	temps_final=clock();
	temps_cpu = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;
	printf("Table de hachage: recherche 1 - %f \n", temps_cpu);

	printf("\n\n\n");

	temps_init = clock();
	for(int i=0; i<150;i++) {
		recherche2(LinkedList->L, "YPQRXWOAWBMSYX");
	}
	temps_final=clock();
	temps_cpu = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;
	printf("Liste chainée: recherche 2 - %f \n", temps_cpu);

	temps_init = clock();
	for(int i=0; i<150;i++) {
		recherche2H(hash, "YPQRXWOAWBMSYX");
	}
	temps_final=clock();
	temps_cpu = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;
	printf("Table de hachage: recherche 2 - %f \n", temps_cpu);


	printf("\n\n\n");


	temps_init = clock();
	for(int i=0; i<300;i++) {
		recherche3(LinkedList->L, "exqb");
	}
	temps_final=clock();
	temps_cpu = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;
	printf("Liste chainée: recherche 3 - %f \n", temps_cpu);

	temps_init = clock();
	for(int i=0; i<300;i++) {
		recherche3H(hash, "exqb");
	}
	temps_final=clock();
	temps_cpu = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;
	printf("Table de hachage: recherche 3 - %f \n", temps_cpu);


	printf("\n\n\n");


	
	*/
	FILE *f = fopen("data.csv", "w");
	fprintf(f,"Taille,Temps_Liste,Temps_Hash\n");

	for (int n=10; n<=100000; n=n*1.1){
		Biblio* LinkedList = charger_n_entrees(argv[1],n);
		BiblioH* hash = charger_n_entreesH(argv[1], n);
		double temps_cpuL;
		double temps_cpuH;

		temps_init = clock();
		recherche4(LinkedList);
		temps_final=clock();
		temps_cpuL = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;
		//printf("Liste chainée: recherche 4 - %f \n", temps_cpuL);


		temps_init = clock();
		recherche4H(hash);
		temps_final=clock();
		temps_cpuH = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;
		//printf("Table de hachage: recherche 4 - %f \n", temps_cpuH);
		printf("%d \n", n);
		fprintf(f,"%d,%f,%f\n",n, temps_cpuL, temps_cpuH);


		liberer_biblio(LinkedList);
		liberer_biblioH(hash);
	}

	fclose(f);

	
	/*
	//afficher_biblioH(hash);
	BiblioH* t = recherche3H(hash, "xyrivhpp");
	BiblioH* c = recherche3H(hash, "bbqcwi");
	
	BiblioH* fusion = fusionH(t,c);

	BiblioH* dup = recherche4H(hash);

	afficher_biblioH(dup);
	
	
	liberer_biblioH(fusion);
	*/
	
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
