#include "fonction_avancee.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction pour trier une colonne de manière générique
void trierColonne(Colonne *colonne, int ascendant) {
    if (colonne->donnees[0].type != INT) {
        printf("Le tri généralisé n'est pas encore implémenté pour d'autres types que INT.\n");
        return;
    }
    // Tri par insertion pour les entiers
    for (int i = 1; i < colonne->taille; i++) {
        Data temp = colonne->donnees[i];
        int j = i - 1;
        while (j >= 0 && (ascendant ? colonne->donnees[j].value.int_val > temp.value.int_val : colonne->donnees[j].value.int_val < temp.value.int_val)) {
            colonne->donnees[j + 1] = colonne->donnees[j];
            j--;
        }
        colonne->donnees[j + 1] = temp;
    }
}

// Fonction pour effectuer une recherche dichotomique sur une colonne triée
int rechercheDichotomique(Colonne *colonne, DataValue valeur) {
    int bas = 0, haut = colonne->taille - 1, milieu;
    while (bas <= haut) {
        milieu = (bas + haut) / 2;
        if (colonne->donnees[milieu].value.int_val == valeur.int_val)
            return milieu;
        else if (colonne->donnees[milieu].value.int_val < valeur.int_val)
            bas = milieu + 1;
        else
            haut = milieu - 1;
    }
    return -1;  // Non trouvé
}

// Fonction pour calculer et afficher les statistiques de base d'une colonne
void calculerStatistiques(Colonne *colonne) {
    if (colonne->donnees[0].type != INT) {
        printf("Les statistiques ne sont implémentées que pour les entiers.\n");
        return;
    }
    int min = colonne->donnees[0].value.int_val;
    int max = min;
    double sum = 0;
    for (int i = 0; i < colonne->taille; i++) {
        int val = colonne->donnees[i].value.int_val;
        if (val < min) min = val;
        if (val > max) max = val;
        sum += val;
    }
    double mean = sum / colonne->taille;
    printf("Min: %d, Max: %d, Moyenne: %.2f\n", min, max, mean);
}