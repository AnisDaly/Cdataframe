#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

// Créer un nouveau CDataframe avec une capacité initiale
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

// Ajouter une colonne au CDataframe
void ajouterColonne(CDataframe* dataframe, Colonne* colonne) {
    if (dataframe->nombreColonnes >= dataframe->capacite) {
        printf("Capacité maximale atteinte. Impossible d'ajouter une nouvelle colonne.\n");
        return;
    }
    dataframe->colonnes[dataframe->nombreColonnes++] = colonne;
}

// Afficher le contenu du CDataframe
void afficherCDataframe(const CDataframe* dataframe) {
    printf("CDataframe contient %d colonnes:\n", dataframe->nombreColonnes);
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        afficherColonne(dataframe->colonnes[i]);
    }
}

// Libérer la mémoire allouée pour le CDataframe et ses colonnes
void libererCDataframe(CDataframe* dataframe) {
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        libererColonne(dataframe->colonnes[i]);
    }
    free(dataframe->colonnes);
    free(dataframe);
}
