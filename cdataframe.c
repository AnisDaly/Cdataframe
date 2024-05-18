#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>

void initialiserCDataframe(CDataframe *cdf, int capacite) {
    cdf->colonnes = malloc(sizeof(Column*) * capacite);
    cdf->nombre_colonnes = 0;
    cdf->capacite = capacite;
}

void ajouterColonne(CDataframe *cdf, Column *colonne) {
    if (cdf->nombre_colonnes < cdf->capacite) {
        cdf->colonnes[cdf->nombre_colonnes++] = colonne;
    } else {
        printf("Le CDataframe a atteint sa capacite maximale.\n");
    }
}

void afficherCDataframe(const CDataframe *cdf) {
    for (int i = 0; i < cdf->nombre_colonnes; i++) {
        printf("Colonne %d: %s\n", i, cdf->colonnes[i]->nom);
        afficherColonne(cdf->colonnes[i]);
    }
}

void libererCDataframe(CDataframe *cdf) {
    for (int i = 0; i < cdf->nombre_colonnes; i++) {
        libererColonne(cdf->colonnes[i]);
    }
    free(cdf->colonnes);
}
