#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

CDataframe* creerCDataframe(int capacite) {
    CDataframe* dataframe = (CDataframe*)malloc(sizeof(CDataframe));
    if (!dataframe) {
        perror("Allocation mémoire échouée pour CDataframe");
        exit(EXIT_FAILURE);
    }
    dataframe->colonnes = (Colonne**)malloc(sizeof(Colonne*) * capacite);
    if (!dataframe->colonnes) {
        perror("Allocation mémoire échouée pour les colonnes de CDataframe");
        free(dataframe);
        exit(EXIT_FAILURE);
    }
    dataframe->nombreColonnes = 0;
    dataframe->capacite = capacite;
    return dataframe;
}

void ajouterColonne(CDataframe* dataframe, Colonne* colonne) {
    if (dataframe->nombreColonnes >= dataframe->capacite) {
        printf("Capacité maximale atteinte. Impossible d'ajouter une nouvelle colonne.\n");
        return;
    }
    dataframe->colonnes[dataframe->nombreColonnes++] = colonne;
}

void afficherCDataframe(const CDataframe* dataframe, const char* nomsColonnes[]) {
    printf("CDataframe contient %d colonnes:\n", dataframe->nombreColonnes);
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        afficherColonneAvecNom(nomsColonnes[i]);
    }
    printf("|\n");
    afficherLigneSeparateur(dataframe->nombreColonnes);

    int maxTaille = 0;
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        if (dataframe->colonnes[i]->taille > maxTaille) {
            maxTaille = dataframe->colonnes[i]->taille;
        }
    }

    for (int i = 0; i < maxTaille; i++) {
        for (int j = 0; j < dataframe->nombreColonnes; j++) {
            afficherDonneesColonne(dataframe->colonnes[j], i);
        }
        printf("|\n");
        afficherLigneSeparateur(dataframe->nombreColonnes);
    }
}

void libererCDataframe(CDataframe* dataframe) {
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        libererColonne(dataframe->colonnes[i]);
    }
    free(dataframe->colonnes);
    free(dataframe);
}
