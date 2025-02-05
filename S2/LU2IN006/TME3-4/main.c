#include "biblioLC.h"
#include "entreeSortieLC.h"
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc != 3) return -1;
	
	Biblio* a = charger_n_entrees(argv[1], atoi(argv[2]));
	
}
