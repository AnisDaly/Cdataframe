#include <stdio.h>
#include "cdataframe.h"
#include "fonction_avancee.h"

int main() {
    // Création du dataframe avec une capacité initiale de 3 colonnes
    CDataframe *dataframe = creerCDataframe(3);

    // Création d'une colonne d'entiers
    Colonne *colonneInt = creerColonne("Colonne Entiers", INT, 10);
    for (int i = 10; i > 0; i--) {
        DataValue valeur;
        valeur.int_val = i;
        insererDonnee(colonneInt, valeur);
    }
    ajouterColonne(dataframe, colonneInt);

    // Affichage du dataframe avant le tri
    printf("Dataframe avant le tri:\n");
    afficherCDataframe(dataframe);

    // Tri de la colonne d'entiers en ordre ascendant
    trierColonne(colonneInt, 1);
    printf("Dataframe après le tri ascendant:\n");
    afficherCDataframe(dataframe);

    // Recherche d'une valeur dans la colonne triée
    DataValue valeurRecherchee;
    valeurRecherchee.int_val = 5;
    int index = rechercheDichotomique(colonneInt, valeurRecherchee);
    if (index != -1) {
        printf("Valeur %d trouvée à l'indice %d.\n", valeurRecherchee.int_val, index);
    } else {
        printf("Valeur %d non trouvée.\n", valeurRecherchee.int_val);
    }

    // Calcul et affichage des statistiques pour la colonne d'entiers
    calculerStatistiques(colonneInt);

    // Libération de toutes les ressources
    libererCDataframe(dataframe);

    return 0;
}
