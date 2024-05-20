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
        colonne->donnees[i].type = type;
    }
    return colonne;
}

void insererDonnee(Colonne* colonne, DataValue valeur) {
    if (colonne->taille == colonne->capacite) {
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

void afficherColonne(const Colonne* colonne) {
    printf("| %s ", colonne->nom);
    int nomLen = strlen(colonne->nom);
    for (int i = nomLen; i < 10; i++) {
        printf(" ");
    }
}
void afficherColonneAvecNom(const char* nom) {
    printf("| %s ", nom);
    int nomLen = strlen(nom);
    for (int i = nomLen; i < 10; i++) {
        printf(" ");
    }
}

void afficherDonneesColonne(const Colonne* colonne, int index) {
    if (index < colonne->taille) {
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
        printf("| %-10s ", " ");
    }
}

void afficherLigneSeparateur(int nombreColonnes) {
    for (int i = 0; i < nombreColonnes; i++) {
        printf("|____________");
    }
    printf("|\n");
}

void libererColonne(Colonne* colonne) {
    if (colonne->donnees[0].type == STRING) {
        for (int i = 0; i < colonne->taille; i++) {
            free(colonne->donnees[i].value.string_val);
        }
    }
    free(colonne->donnees);
    free(colonne->nom);
    free(colonne);
}
