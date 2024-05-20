#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Créer une nouvelle colonne avec une capacité initiale
// Cette fonction initialise une structure Colonne avec un nom, un type de données, et une capacité initiale
Colonne* creerColonne(const char* nom, DataType type, int capacite) {
    // Allouer de la mémoire pour la structure Colonne
    Colonne* colonne = (Colonne*)malloc(sizeof(Colonne));
    // Dupliquer le nom de la colonne
    colonne->nom = strdup(nom);
    // Allouer de la mémoire pour le tableau de données de la colonne
    colonne->donnees = (Data*)malloc(sizeof(Data) * capacite);
    // Initialiser les attributs de la colonne
    colonne->taille = 0;  // Initialiser le nombre d'éléments à 0
    colonne->capacite = capacite;  // Définir la capacité initiale
    // Initialiser le type de chaque élément du tableau de données
    for (int i = 0; i < capacite; i++) {
        colonne->donnees[i].type = type;
    }
    return colonne;  // Retourner le pointeur vers la nouvelle colonne
}

// Insérer une nouvelle donnée dans la colonne
// Cette fonction ajoute une nouvelle donnée à une colonne donnée
void insererDonnee(Colonne* colonne, DataValue valeur) {
    // Vérifier si la capacité maximale de la colonne est atteinte
    if (colonne->taille == colonne->capacite) {
        // Augmenter la capacité de la colonne en doublant sa taille
        colonne->capacite *= 2;
        // Réallouer de la mémoire pour le tableau de données avec la nouvelle capacité
        colonne->donnees = (Data*)realloc(colonne->donnees, sizeof(Data) * colonne->capacite);
        // Vérifier si la réallocation a échoué
        if (colonne->donnees == NULL) {
            perror("Échec de la réallocation de mémoire");
            exit(EXIT_FAILURE);  // Terminer le programme si la réallocation échoue
        }
    }
    // Ajouter la nouvelle donnée dans le tableau de données
    colonne->donnees[colonne->taille].value = valeur;
    // Incrémenter la taille de la colonne
    colonne->taille++;
}

// Afficher le contenu de la colonne
// Cette fonction affiche les informations et les données de la colonne
void afficherColonne(const Colonne* colonne) {
    // Afficher le nom de la colonne
    printf("Colonne: %s\n", colonne->nom);
    // Parcourir et afficher chaque donnée de la colonne
    for (int i = 0; i < colonne->taille; i++) {
        // Afficher la valeur de la donnée en fonction de son type
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
    printf("\n");  // Nouvelle ligne après l'affichage de toutes les données
}

// Libérer la mémoire allouée pour la colonne
// Cette fonction libère toute la mémoire allouée pour une colonne donnée
void libererColonne(Colonne* colonne) {
    // Si le type des données est STRING, libérer chaque chaîne de caractères
    if (colonne->donnees[0].type == STRING) {  // Supposer que tous les éléments sont du même type
        for (int i = 0; i < colonne->taille; i++) {
            free(colonne->donnees[i].value.string_val);  // Libérer la mémoire de la chaîne de caractères
        }
    }
    // Libérer la mémoire allouée pour le tableau de données
    free(colonne->donnees);
    // Libérer la mémoire allouée pour le nom de la colonne
    free(colonne->nom);
    // Libérer la mémoire allouée pour la structure Colonne elle-même
    free(colonne);
}
