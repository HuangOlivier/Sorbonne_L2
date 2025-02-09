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
	printf("3 - Supprimer Ouvrage\n");
	printf("4 - Recherche Auteur\n");
}



void TimeTest(char* nomfic, int taille_lc, int taille_H) {
	clock_t start_time;
	clock_t end_time;
	double cpu_time;

	Biblio* LinkedList = charger_n_entrees(nomfic, taille_lc);
	BiblioH* hash = charger_n_entreesH(nomfic, taille_H);

	int randomN = rand() % taille_lc;

	start_time = clock();
	for (int i = 0; i < 150; i++) {
		recherche1(LinkedList->L, randomN);
	}
	end_time = clock();
	cpu_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Liste chainée: recherche 1 - %f \n", cpu_time);

	start_time = clock();
	for (int i = 0; i < 150; i++) {
		recherche1H(hash, randomN);
	}
	end_time = clock();
	cpu_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Table de hachage: recherche 1 - %f \n", cpu_time);


	start_time = clock();
	for (int i = 0; i < 150; i++) {
		recherche2(LinkedList->L, "YPQRXWOAWBMSYX");
	}
	end_time = clock();
	cpu_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Liste chainée: recherche 2 - %f \n", cpu_time);

	start_time = clock();
	for (int i = 0; i < 150; i++) {
		recherche2H(hash, "YPQRXWOAWBMSYX");
	}
	end_time = clock();
	cpu_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Table de hachage: recherche 2 - %f \n", cpu_time);



	start_time = clock();
	for (int i = 0; i < 300; i++) {
		Biblio* res = recherche3(LinkedList, "exqb");
		liberer_biblio(res);
	}
	end_time = clock();
	cpu_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Liste chainée: recherche 3 - %f \n", cpu_time);

	start_time = clock();
	for (int i = 0; i < 300; i++) {
		BiblioH* res = recherche3H(hash, "exqb");
		liberer_biblioH(res);
	}
	end_time = clock();
	cpu_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Table de hachage: recherche 3 - %f \n", cpu_time);


	liberer_biblio(LinkedList);
	liberer_biblioH(hash);
}


int main(int argc, char** argv) {
	if(argc != 3){
		printf("pas assez d'argument\n");
		return -1;
	}

	int choix = -1;
	while (choix != 1 && choix != 2) {
		printf("Partie 1 ou 2: ");
		scanf("%d",&choix);
	}

	if(choix == 1) {
		Biblio *test = charger_n_entrees(argv[1],atoi(argv[2]));
		int action;
		int num;
		char titre[256];
		char auteur[256];
		do{
			menu();
			printf("entrée une action:\n");
			scanf("%d", &action);
			switch (action){
				case 1:
					printf("Affichage:\n");
					afficher_biblio(test);
					printf("\n");
					break;
				case 2:
					printf("Inserer ouvrage \n\n");
					printf("Indiquez le Numéro, Titre et Auteur:\n");
					if(scanf("%d %s %s",&num,titre,auteur)==3){
						printf("%s\n",auteur);
						inserer_en_tete(test, num, titre, auteur);
						printf("Ajout réussi\n\n");
					}
					else{
						printf("Erreur de format\n");
					}
					break;
				case 3:
					printf("Supprimer Ouvrage\n\n");
					printf("Indiquez le Numéro, Titre et Auteur:\n");
					if(scanf("%d %s %s",&num,titre,auteur)==3){
						supprimer(test,num,titre,auteur);
						printf("Suppression réussi\n\n");
					}
					else{
						printf("Erreur de format\n");
					}
					break;
				case 4:
					printf("Recherche Auteur\n\n");
					printf("Indiquez l'auteur recherché:\n");
					if(scanf("%s", auteur)==1){
						Biblio *res = recherche3(test, auteur);

						if(res->L==NULL){
							printf("\nIl n'y a pas d'ouvrage de cette Auteur disponible\n");
						} else{
							printf("\nVoici les ouvrages de cette Auteur disponible:\n\n");
							afficher_biblio(res);
							printf("\n");
						}
						liberer_biblio(res);
					}
					
					break;
			}
		}while(action);
		printf("Sortie du programme \n");
		
		liberer_biblio(test);

	} else {

		clock_t temps_init;
		clock_t temps_final;
		double temps_cpu;
		
		int choix;
		do{
			choix = -1;
			while (choix != 1 && choix != 2 && choix != 3 && choix !=0) {
				printf("\n\nOption:\n");
				printf("0 - Sortie du programme\n");
				printf("1 - Q1 \n");
				printf("2 - Q2 \n");
				printf("3 - Q3 \n");
				scanf("%d",&choix);
			}

			switch (choix) {
				case 1: {
					TimeTest(argv[1], atoi(argv[2]), atoi(argv[2]));
				}
				break;

				case 2: {
					int tailles[] = {100, 500, 1000, 5000, 10000, 50000};
					
					for (int i = 0; i < 6; i++) {
						printf("\nTaille list: %d, taille table de hachage: %d\n\n", atoi(argv[2]), tailles[i]);
						TimeTest(argv[1], atoi(argv[2]), tailles[i]);
					}
				}
				break;

				case 3: {
						FILE *f = fopen("data.csv", "w");
						fprintf(f,"Taille,Temps_Liste,Temps_Hash\n");

						for (int n=10; n<=50000; n=n*2){
							Biblio* LinkedList = charger_n_entrees(argv[1],n);
							BiblioH* hash = charger_n_entreesH(argv[1], n/2);

							double temps_cpuL;
							double temps_cpuH;

							temps_init = clock();
							Biblio* temp1 = recherche4(LinkedList);
							temps_final=clock();
							temps_cpuL = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;


							temps_init = clock();
							BiblioH* temp2 = recherche4H(hash);
							temps_final=clock();
							temps_cpuH = ((double)(temps_final - temps_init)) / CLOCKS_PER_SEC;

							fprintf(f,"%d,%f,%f\n",n, temps_cpuL, temps_cpuH);
							printf("%d, Temps liste chainee: %f, Temps: table de hachage %f\n",n, temps_cpuL, temps_cpuH);
							

							liberer_biblio(temp1);
							liberer_biblioH(temp2);

							liberer_biblio(LinkedList);
							liberer_biblioH(hash);
						}

						fclose(f);
					}
					
				break;
				}
		}while(choix);
	}

	return 0;
	
}


