#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"
#include "fonction_avancee.h"
#include "column.h"

// Fonction pour saisir une donnée selon le type spécifié
void saisirDonnee(DataType type, DataValue *valeur) {
    switch (type) {
        case INT:
            scanf("%d", &valeur->int_val);
            break;
        case FLOAT:
            scanf("%f", &valeur->float_val);
            break;
        case DOUBLE:
            scanf("%lf", &valeur->double_val);
            break;
        case CHAR:
            scanf(" %c", &valeur->char_val);
            break;
        case STRING:
            valeur->string_val = malloc(100);  // Allocation d'espace pour une chaîne
            scanf("%99s", valeur->string_val);
            break;
    }
}

int main() {
    int capacite, choix, continuer = 1, type;
    printf("Entrez la capacite initiale du CDataframe (nombre maximum de colonnes) :\n");
    scanf("%d", &capacite);

    // Création du dataframe
    CDataframe *dataframe = creerCDataframe(capacite);

    // Allocation de mémoire pour les noms des colonnes
    char** nomsColonnes = (char**)malloc(sizeof(char*) * capacite);

    while (continuer) {
        printf("\nMenu:\n");
        printf("1. Ajouter une colonne\n");
        printf("2. Afficher le DataFrame\n");
        printf("3. Trier une colonne\n");
        printf("4. Rechercher une valeur\n");
        printf("5. Calculer les statistiques d'une colonne\n");
        printf("6. Recherche dichotomique\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix :\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                // Ajout d'une colonne
                int nombreElements;
                char nomColonne[100];
                printf("Entrez le nom de la colonne :\n");
                scanf("%s", nomColonne);
                printf("Entrez le type de donnees pour la colonne (0: INT, 1: FLOAT, 2: DOUBLE, 3: CHAR, 4: STRING) :\n");
                scanf("%d", &type);
                printf("Combien d'elements souhaitez-vous ajouter dans la colonne ?\n");
                scanf("%d", &nombreElements);
                Colonne *colonne = creerColonne(nomColonne, type, nombreElements);
                printf("Entrez les elements de la colonne :\n");
                for (int i = 0; i < nombreElements; i++) {
                    DataValue valeur;
                    printf("Entrez l'element %d: ", i + 1);
                    saisirDonnee(type, &valeur);
                    insererDonnee(colonne, valeur);
                }
                ajouterColonne(dataframe, colonne);
                nomsColonnes[dataframe->nombreColonnes - 1] = strdup(nomColonne); // Stocker le nom de la colonne
                break;
            }
            case 2:
                // Affichage du DataFrame
                afficherCDataframe(dataframe, (const char**)nomsColonnes);
                break;
            case 3:
                // Tri d'une colonne
                printf("Quel est l'index de la colonne à trier ?\n");
                int indexColonne, ordreTri;
                scanf("%d", &indexColonne);
                printf("Voulez-vous trier la colonne en ordre ascendant (1) ou descendant (0) ?\n");
                scanf("%d", &ordreTri);
                trierColonne(dataframe->colonnes[indexColonne], ordreTri);
                break;
            case 4:
                // Recherche d'une valeur
                printf("Quel est l'index de la colonne pour la recherche ?\n");
                scanf("%d", &indexColonne);
                DataValue valeurRecherchee;
                printf("Entrez la valeur a rechercher :\n");
                saisirDonnee(dataframe->colonnes[indexColonne]->donnees[0].type, &valeurRecherchee);
                int trouve = rechercheDichotomique(dataframe->colonnes[indexColonne], valeurRecherchee);
                if (trouve != -1) {
                    printf("Valeur trouvee à l'indice %d.\n", trouve);
                } else {
                    printf("Valeur non trouvee.\n");
                }
                break;
            case 5:
                // Calcul des statistiques
                printf("Quel est l'index de la colonne pour calculer les statistiques ?\n");
                scanf("%d", &indexColonne);
                calculerStatistiques(dataframe->colonnes[indexColonne]);
                break;
            case 6:
                // Recherche dichotomique
                printf("Quel est l'index de la colonne pour la recherche dichotomique ?\n");
                int indexDicho;
                scanf("%d", &indexDicho);
                DataValue valeurDicho;
                printf("Entrez la valeur à rechercher :\n");
                saisirDonnee(dataframe->colonnes[indexDicho]->donnees[0].type, &valeurDicho);
                int result = rechercheDichotomique(dataframe->colonnes[indexDicho], valeurDicho);
                if (result != -1) {
                    printf("Valeur trouvée à l'indice %d.\n", result);
                } else {
                    printf("Valeur non trouvée.\n");
                }
                break;
            case 7:
                continuer = 0;
                break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    }

    // Libération des ressources
    libererCDataframe(dataframe);
    for (int i = 0; i < capacite; i++) {
        free(nomsColonnes[i]);
    }
    free(nomsColonnes);
    printf("Programme termine.\n");
    return 0;
}
