#ifndef ENTREESORTIELC
#define ENTREESORTIELC

#include "biblioLC.h"
#include "biblioH.h"



#include <stdio.h>
#include <stdlib.h>

Biblio* charger_n_entrees(char* nomfic, int n);
void enregistrer_biblio(Biblio *b, char* nomfic);

BiblioH* charger_n_entreesH(char* nomfic, int n);
void enregistrer_biblioH(BiblioH *b, char* nomfic);

#endif

