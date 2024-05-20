#include "fonction_avancee.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction pour trier une colonne de manière générique
// Cette fonction trie les données d'une colonne en ordre croissant ou décroissant
void trierColonne(Colonne *colonne, int ascendant) {
    // Vérifier si le type de données est INT, sinon afficher un message d'erreur
    if (colonne->donnees[0].type != INT) {
        printf("Le tri généralisé n'est pas encore implémenté pour d'autres types que INT.\n");
        return;
    }
    // Tri par insertion pour les données de type entier (INT)
    for (int i = 1; i < colonne->taille; i++) {
        Data temp = colonne->donnees[i];
        int j = i - 1;
        // Comparer et déplacer les éléments en fonction de l'ordre spécifié (ascendant ou descendant)
        while (j >= 0 && (ascendant ? colonne->donnees[j].value.int_val > temp.value.int_val : colonne->donnees[j].value.int_val < temp.value.int_val)) {
            colonne->donnees[j + 1] = colonne->donnees[j];
            j--;
        }
        colonne->donnees[j + 1] = temp;
    }
}

// Fonction pour effectuer une recherche dichotomique sur une colonne triée
// Cette fonction cherche une valeur dans une colonne triée et retourne l'index de la valeur si trouvée
int rechercheDichotomique(Colonne *colonne, DataValue valeur) {
    int bas = 0, haut = colonne->taille - 1, milieu;
    // Utiliser la méthode de recherche dichotomique
    while (bas <= haut) {
        milieu = (bas + haut) / 2;
        // Vérifier si la valeur au milieu correspond à la valeur recherchée
        if (colonne->donnees[milieu].value.int_val == valeur.int_val)
            return milieu;  // Retourner l'index si trouvé
        else if (colonne->donnees[milieu].value.int_val < valeur.int_val)
            bas = milieu + 1;  // Chercher dans la moitié supérieure
        else
            haut = milieu - 1;  // Chercher dans la moitié inférieure
    }
    return -1;  // Retourner -1 si non trouvé
}

// Fonction pour calculer et afficher les statistiques de base d'une colonne
// Cette fonction calcule et affiche le minimum, le maximum et la moyenne des valeurs d'une colonne
void calculerStatistiques(Colonne *colonne) {
    // Vérifier si le type de données est INT, sinon afficher un message d'erreur
    if (colonne->donnees[0].type != INT) {
        printf("Les statistiques ne sont implémentées que pour les entiers.\n");
        return;
    }
    int min = colonne->donnees[0].value.int_val;  // Initialiser min avec la première valeur
    int max = min;  // Initialiser max avec la première valeur
    double sum = 0;  // Initialiser la somme des valeurs à 0
    // Parcourir toutes les valeurs de la colonne
    for (int i = 0; i < colonne->taille; i++) {
        int val = colonne->donnees[i].value.int_val;
        if (val < min) min = val;  // Mettre à jour min si la valeur courante est plus petite
        if (val > max) max = val;  // Mettre à jour max si la valeur courante est plus grande
        sum += val;  // Ajouter la valeur courante à la somme
    }
    double mean = sum / colonne->taille;  // Calculer la moyenne
    // Afficher les statistiques calculées
    printf("Min: %d, Max: %d, Moyenne: %.2f\n", min, max, mean);
}
