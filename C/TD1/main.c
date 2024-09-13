#include <stdio.h>

void min_max_moy (int* listEntier, int longeur, int* moy, int* min, int* max) {
    if (longeur == 0) return;

    *min = listEntier[0];
    *max = listEntier[0];
    *moy = 0;
    int sum = 0;
    for (int i = 0; i<longeur; i++) {
        if (listEntier[i] < *min) *min = listEntier[i];
        if (listEntier[i] > *max) *max = listEntier[i];
        sum += listEntier[i];
    }

    *moy = sum/longeur;
}

void min_max_moy_intermediaire (int* listEntier, int longeur, int* moy, int* min, int* max) {
    if (longeur == 1) {
		*moy += listEntier[0];
        if (listEntier[0] < *min) *min = listEntier[0];
        if (listEntier[0] > *max) *max = listEntier[0];
        return;
	}

	int i = listEntier[longeur-1];
	*moy += i;
	if (i > *max) *max = i;
	if (i < *min) *min = i;

    min_max_moy_intermediaire ((listEntier), longeur-1, moy, min, max);
}

void min_max_moy_recursive (int* listEntier, int longeur, int* moy, int* min, int* max) {
	*min = listEntier[0];
    *max = listEntier[0];
    *moy = 0;

	min_max_moy_intermediaire (listEntier, longeur, moy, min, max); 

	*moy = *moy / longeur;
}



int main () {
    int list[10] = {1,2,3,4,5,6,7,8,9};
    int moy, min, max;

    min_max_moy_recursive (list, 10, &moy, &min, &max);
    printf ("min: %d, max: %d, moy: %d \n", min, max, moy);
}