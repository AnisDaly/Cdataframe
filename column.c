#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Créer une nouvelle colonne avec une capacité initiale
Colonne* creerColonne(const char* nom, DataType type, int capacite) {
    Colonne* colonne = (Colonne*)malloc(sizeof(Colonne));
    colonne->nom = strdup(nom);
    colonne->donnees = (Data*)malloc(sizeof(Data) * capacite);
    colonne->taille = 0;
    colonne->capacite = capacite;
    for (int i = 0; i < capacite; i++) {
        colonne->donnees[i].type = type; // Initialise le type de chaque élément
    }
    return colonne;
}

// Insérer une nouvelle donnée dans la colonne
void insererDonnee(Colonne* colonne, DataValue valeur) {
    if (colonne->taille == colonne->capacite) {
        // Augmentation de la capacité de la colonne
        colonne->capacite *= 2;
        colonne->donnees = (Data*)realloc(colonne->donnees, sizeof(Data) * colonne->capacite);
        if (colonne->donnees == NULL) {
            perror("Échec de la réallocation de mémoire");
            exit(EXIT_FAILURE);
        }
    }
    colonne->donnees[colonne->taille].value = valeur;
    colonne->taille++;
}

// Afficher le contenu de la colonne
void afficherColonne(const Colonne* colonne) {
    printf("Colonne: %s\n", colonne->nom);
    for (int i = 0; i < colonne->taille; i++) {
        switch (colonne->donnees[i].type) {
            case INT:
                printf("%d ", colonne->donnees[i].value.int_val);
                break;
            case FLOAT:
                printf("%f ", colonne->donnees[i].value.float_val);
                break;
            case DOUBLE:
                printf("%lf ", colonne->donnees[i].value.double_val);
                break;
            case CHAR:
                printf("%c ", colonne->donnees[i].value.char_val);
                break;
            case STRING:
                printf("%s ", colonne->donnees[i].value.string_val);
                break;
            default:
                printf("Type inconnu ");
        }
    }
    printf("\n");
}

// Libérer la mémoire allouée pour la colonne
void libererColonne(Colonne* colonne) {
    if (colonne->donnees[0].type == STRING) { // Supposer que tous les éléments sont du même type
        for (int i = 0; i < colonne->taille; i++) {
            free(colonne->donnees[i].value.string_val); // Libérer les chaînes de caractères
        }
    }
    free(colonne->donnees);
    free(colonne->nom);
    free(colonne);
}