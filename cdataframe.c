#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

// Créer un nouveau CDataframe avec une capacité initiale
// Cette fonction initialise une structure CDataframe avec une capacité spécifiée
CDataframe* creerCDataframe(int capacite) {
    // Allouer de la mémoire pour la structure CDataframe
    CDataframe* dataframe = (CDataframe*)malloc(sizeof(CDataframe));
    // Vérifier si l'allocation a échoué
    if (!dataframe) {
        perror("Allocation mémoire échouée pour CDataframe");
        exit(EXIT_FAILURE);  // Terminer le programme si l'allocation échoue
    }
    // Allouer de la mémoire pour les pointeurs vers les colonnes
    dataframe->colonnes = (Colonne**)malloc(sizeof(Colonne*) * capacite);
    // Vérifier si l'allocation a échoué
    if (!dataframe->colonnes) {
        perror("Allocation mémoire échouée pour les colonnes de CDataframe");
        free(dataframe);  // Libérer la mémoire allouée pour le dataframe avant de quitter
        exit(EXIT_FAILURE);  // Terminer le programme si l'allocation échoue
    }
    // Initialiser les attributs de la structure
    dataframe->nombreColonnes = 0;  // Initialiser le nombre de colonnes à 0
    dataframe->capacite = capacite;  // Définir la capacité initiale
    return dataframe;  // Retourner le pointeur vers la nouvelle structure
}

// Ajouter une colonne au CDataframe
// Cette fonction ajoute une colonne à un dataframe donné
void ajouterColonne(CDataframe* dataframe, Colonne* colonne) {
    // Vérifier si la capacité maximale du dataframe est atteinte
    if (dataframe->nombreColonnes >= dataframe->capacite) {
        printf("Capacité maximale atteinte. Impossible d'ajouter une nouvelle colonne.\n");
        return;  // Ne pas ajouter la colonne si la capacité est atteinte
    }
    // Ajouter la colonne au tableau de colonnes
    dataframe->colonnes[dataframe->nombreColonnes++] = colonne;
}

// Afficher le contenu du CDataframe
// Cette fonction affiche les informations du dataframe et de ses colonnes
void afficherCDataframe(const CDataframe* dataframe) {
    // Afficher le nombre de colonnes dans le dataframe
    printf("CDataframe contient %d colonnes:\n", dataframe->nombreColonnes);
    // Parcourir et afficher chaque colonne
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        afficherColonne(dataframe->colonnes[i]);  // Appeler une fonction pour afficher une colonne
    }
}

// Libérer la mémoire allouée pour le CDataframe et ses colonnes
// Cette fonction libère toute la mémoire allouée pour le dataframe et ses colonnes
void libererCDataframe(CDataframe* dataframe) {
    // Parcourir et libérer chaque colonne
    for (int i = 0; i < dataframe->nombreColonnes; i++) {
        libererColonne(dataframe->colonnes[i]);  // Appeler une fonction pour libérer la mémoire d'une colonne
    }
    // Libérer la mémoire allouée pour le tableau de colonnes
    free(dataframe->colonnes);
    // Libérer la mémoire allouée pour la structure CDataframe
    free(dataframe);
}
