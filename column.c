#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Créer une nouvelle colonne avec une capacité initiale
Colonne* creerColonne(const char* nom, DataType type, int capacite) {
    // Allocation de mémoire pour une nouvelle colonne
    Colonne* colonne = (Colonne*)malloc(sizeof(Colonne));
    // Allocation et copie du nom de la colonne
    colonne->nom = strdup(nom);
    // Allocation de mémoire pour les données de la colonne
    colonne->donnees = (Data*)malloc(sizeof(Data) * capacite);
    colonne->taille = 0; // Initialisation de la taille à 0
    colonne->capacite = capacite; // Initialisation de la capacité
    // Initialisation du type de chaque élément de données
    for (int i = 0; i < capacite; i++) {
        colonne->donnees[i].type = type;
    }
    return colonne; // Retourne la colonne créée
}

// Insérer une donnée dans la colonne
void insererDonnee(Colonne* colonne, DataValue valeur) {
    // Si la colonne est pleine, doubler la capacité
    if (colonne->taille == colonne->capacite) {
        colonne->capacite *= 2;
        colonne->donnees = (Data*)realloc(colonne->donnees, sizeof(Data) * colonne->capacite);
        // Vérifier si la réallocation a échoué
        if (colonne->donnees == NULL) {
            perror("Échec de la réallocation de mémoire");
            exit(EXIT_FAILURE);
        }
    }
    // Insérer la nouvelle valeur dans la colonne
    colonne->donnees[colonne->taille].value = valeur;
    colonne->taille++; // Incrémenter la taille de la colonne
}

// Afficher le nom de la colonne
void afficherColonne(const Colonne* colonne) {
    printf("| %s ", colonne->nom);
    // Ajouter des espaces pour l'alignement
    int nomLen = strlen(colonne->nom);
    for (int i = nomLen; i < 10; i++) {
        printf(" ");
    }
}

// Afficher un nom de colonne spécifique
void afficherColonneAvecNom(const char* nom) {
    printf("| %s ", nom);
    // Ajouter des espaces pour l'alignement
    int nomLen = strlen(nom);
    for (int i = nomLen; i < 10; i++) {
        printf(" ");
    }
}

// Afficher les données d'une colonne à un index donné
void afficherDonneesColonne(const Colonne* colonne, int index) {
    if (index < colonne->taille) {
        // Afficher la donnée en fonction de son type
        switch (colonne->donnees[index].type) {
            case INT:
                printf("| %10d ", colonne->donnees[index].value.int_val);
                break;
            case FLOAT:
                printf("| %10.2f ", colonne->donnees[index].value.float_val);
                break;
            case DOUBLE:
                printf("| %10.2lf ", colonne->donnees[index].value.double_val);
                break;
            case CHAR:
                printf("| %10c ", colonne->donnees[index].value.char_val);
                break;
            case STRING:
                printf("| %-10s ", colonne->donnees[index].value.string_val);
                break;
            default:
                printf("| %-10s ", "Type inconnu");
        }
    } else {
        // Afficher des espaces si l'index est hors de portée
        printf("| %-10s ", " ");
    }
}

// Afficher une ligne de séparation pour le tableau
void afficherLigneSeparateur(int nombreColonnes) {
    for (int i = 0; i < nombreColonnes; i++) {
        printf("|____________");
    }
    printf("|\n");
}

// Libérer la mémoire allouée pour une colonne
void libererColonne(Colonne* colonne) {
    // Si les données sont de type STRING, libérer la mémoire allouée pour chaque chaîne
    if (colonne->donnees[0].type == STRING) {
        for (int i = 0; i < colonne->taille; i++) {
            free(colonne->donnees[i].value.string_val);
        }
    }
    // Libérer la mémoire allouée pour les données, le nom et la colonne elle-même
    free(colonne->donnees);
    free(colonne->nom);
    free(colonne);
}
