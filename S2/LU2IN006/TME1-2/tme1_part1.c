#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 13
#define P 6

int *alloue_tableau1(int n) {
	int *res = malloc(sizeof(int)*n);
	return res;
}

void alloue_tableau2(int **T, int n){
	*T = malloc(sizeof(int)*n);
}

void desalloue_tableau (int *tab) {
	free(tab);
}

void remplir_tableau(int *tab, int n, int v){
	for (int i=0; i<n; i++) {
		tab[i] = rand() % v;
	}
}

void affichageTableau(int* tab, int n){
	printf("[ ");	
	for (int i=0;i<n;i++){
		printf("%d ",tab[i]);	
	}
	printf("]\n");
}


int diff(int *tab, int n) {
	int res = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			res += pow((tab[i] - tab[j]),2);
		}
	}
	return res;
}

int diff2(int *tab, int n) {
	int res=0;
	int tmp=0;
	for (int i=0; i<n; i++) {
		res += n*pow(tab[i],2);
		tmp += tab[i];
	}
	return 2*(res - pow(tmp, 2));
}





int **alloue_matrice(int n){
	int **res = malloc(sizeof(int)*n);
	for (int i=0; i<n; i++){
		res[i] = malloc(sizeof(int)*n);
	}
	return res;
}

void desalloue_matrice (int **tab, int n) {
	for (int i=0; i<n; i++) {
		free(tab[i]);
	}
	free(tab);
}

void remplir_matrice (int **tab, int n, int v) {
	for (int i = 0; i<n; i++) {
		for (int j=0; j<n; j++) {
			tab[i][j] = rand() % v;
		}
	}
}

void afficher_matrice (int **tab, int n) {
	printf("[\n");
	for (int i = 0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}

int main() {
 	srand(time(NULL));
 	
	int *tab = alloue_tableau1(N);
	alloue_tableau2(&tab, N);
	remplir_tableau(tab,N,10);
	affichageTableau(tab, N);
	
	printf("%d %d \n", diff(tab, N), diff2(tab, N));
	
	desalloue_tableau(tab);	
	
	/*
	int **t = alloue_matrice(P);
	//remplir_matrice(t, P, 5);
	//afficher_matrice(t, P);
	desalloue_matrice(t, P);
	
	return 0;
	*/
	
}
