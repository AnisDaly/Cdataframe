#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour créer un CDataframe avec une capacité donnée
CDataframe* creerCDataframe(int capacite) {
    // Allocation de mémoire pour le CDataframe
    CDataframe* dataframe = (CDataframe*)malloc(sizeof(CDataframe));
    if (!dataframe) {
        // Si l'allocation échoue, afficher un message d'erreur et quitter
        perror("Allocation mémoire échouée pour CDataframe");
        exit(EXIT_FAILURE);
    }
    // Allocation de mémoire pour les pointeurs de colonnes
    dataframe->colonnes = (Colonne**)malloc(sizeof(Colonne*) * capacite);
    if (!dataframe->colonnes) {
        // Si l'allocation échoue, afficher un message d'erreur, libérer la mémoire allouée et quitter
        perror("Allocation mémoire échouée pour les colonnes de CDataframe");
        free(dataframe);
        exit(EXIT_FAILURE);
    }
    // Initialisation du nombre de colonnes à 0 et de la capacité à la valeur donnée
    dataframe->nombreColonnes = 0;
    dataframe->capacite = capacite;
    return dataframe; // Retourne le dataframe créé
}

// Fonction pour ajouter une colonne au CDataframe
void ajouterColonne(CDataframe* dataframe, Colonne* colonne) {
    // Vérifie si la capacité maximale est atteinte
    if (dataframe->nombreColonnes >= dataframe->capacite) {
        printf("Capacité maximale atteinte. Impossible d'ajouter une nouvelle colonne.\n");
        return;
    }
    // Ajoute la nouvelle colonne au dataframe
    dataframe->colonnes[dataframe->nombreColonnes++] = colonne;
}

// Fonction pour afficher le contenu du CDataframe
void afficherCDataframe(const CDataframe* dataframe, const char* nomsColonnes[]) {
    printf("CDataframe contient %d colonnes:\n", dataframe->nombreColonnes);
    // Affiche le nom de chaque colonne
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        afficherColonneAvecNom(nomsColonnes[i]);
    }
    printf("|\n");
    // Affiche une ligne de séparation
    afficherLigneSeparateur(dataframe->nombreColonnes);

    // Détermine la taille maximale parmi toutes les colonnes
    int maxTaille = 0;
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        if (dataframe->colonnes[i]->taille > maxTaille) {
            maxTaille = dataframe->colonnes[i]->taille;
        }
    }

    // Affiche les données des colonnes ligne par ligne
    for (int i = 0; i < maxTaille; i++) {
        for (int j = 0; j < dataframe->nombreColonnes; j++) {
            afficherDonneesColonne(dataframe->colonnes[j], i);
        }
        printf("|\n");
        // Affiche une ligne de séparation après chaque ligne de données
        afficherLigneSeparateur(dataframe->nombreColonnes);
    }
}

// Fonction pour libérer la mémoire allouée pour le CDataframe
void libererCDataframe(CDataframe* dataframe) {
    // Libère la mémoire allouée pour chaque colonne
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        libererColonne(dataframe->colonnes[i]);
    }
    // Libère la mémoire allouée pour les pointeurs de colonnes
    free(dataframe->colonnes);
    // Libère la mémoire allouée pour le dataframe lui-même
    free(dataframe);
}
