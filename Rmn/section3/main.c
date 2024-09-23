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

int main () {
    int n = 10;
    
    double *p = malloc(sizeof(double) * n);
    
    if (p == NULL) {
        printf("Erreur de mémoire");    
    } else {
        printf("OK \n");
    }
    *p = 0;

	double a[4] = {5,4,-3,2};
	printf("%e \n", horner(a, -1, 3));
	
	return 1;
}






/*

int i;
float v[10], w[10], pscla = 0;
for(i=0; i<n; i++)
	pscal += v[i]*w[i];

to 

float v[10], w[10], pscal = 0, *p1, *p2;
for(p1 = v, p2 = w; p1 < v + n; p1++, p2++)
	pscal += *p1 * *p2;

*/