#include <stdio.h>
#include <stdlib.h>

double horner(double *a, double x, int n)
{
	double y;
	double *p;

	y = *(a + n);

	for (p = n + a - 1; p >= a; p--) {
		y = y*x + *p;
	}
		
	return y;
}

void strassen_2 (float *a, float *b, float *res) {
	float m1 = (*a + *(a + 3)) * (*b + *(b + 3));
	float m2 = (*(a + 2) + *(a + 3)) * (*b);
	float m3 = (*a) * ( *(b + 1) - *(b + 3));
	float m4 = (*(a + 3) * ( *(b + 2) - (*b)));
	float m5 = (*a + *(a+1)) * (*(b + 3));
	float m6 = (*(a + 2) - (*a)) * ((*b) + *(b + 1));
	float m7 = ( *(a + 1) - *(a + 3)) * (*(b + 2) + *(b + 3));

	*res = m1 + m4 - m5 + m7;
	*(res + 1) = m3 + m5;
	*(res + 2) = m2 + m4;
	*(res + 3) = m1 - m2 + m3 + m6;
}

void somme_matrice_2 (float *a, float *b, float *res) {
	for (int i = 0; i<4; i++) {
		*(res + i) = *(a + i) + *(b + i);
	}
}

void produit_matrice_2 (float *a, float *b, float *res) {
	
}


void strassen (float *a, float *b, float *res, int k ) {

}


void print_matrice_2 (char *nom, float *u) {
	printf("matrice: %s \n", nom);

	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			printf ("%f \t", *(u + i*2 + j));
		}
		printf ("\n");
	}
	printf("\n");
}

int main () {
	float u[4] = {
		2, -3,
		-8, 4
	};

	float v[4] = {
		5, 2,
		11, 5
	};

	float res[4] = {
		0, 0,
		0, 0
	};

	print_matrice_2 ("u", u);
	print_matrice_2 ("v", v);

	strassen_2 (u, v, res);

	print_matrice_2 ("result", res);
}