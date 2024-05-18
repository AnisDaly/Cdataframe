#include "column.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Column *creerColonne(const char *nom, int capacite) {
    Column *col = malloc(sizeof(Column));
    col->donnees = malloc(sizeof(void*) * capacite);
    col->taille = 0;
    col->capacite = capacite;
    col->nom = strdup(nom);
    return col;
}

void insererDonnee(Column *col, void *donnee) {
    if (col->taille < col->capacite) {
        col->donnees[col->taille++] = donnee;
    } else {
        printf("La colonne est a pleine capacité.\n");
    }
}

void afficherColonne(const Column *col) {
    printf("Donnees dans %s:\n", col->nom);
    for (int i = 0; i < col->taille; i++) {
        printf("%p ", col->donnees[i]); // Exemple d'affichage des valeurs des pointeurs
    }
    printf("\n");
}

void libererColonne(Column *col) {
    free(col->donnees);
    free(col->nom);
    free(col);
}
