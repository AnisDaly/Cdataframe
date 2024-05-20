#ifndef FONCTION_AVANCEE_H
#define FONCTION_AVANCEE_H

#include "column.h"

// Fonctions avancÃ©es pour le tri, la recherche et les statistiques
void trierColonne(Colonne *colonne, int ascendant);
int rechercheDichotomique(Colonne *colonne, DataValue valeur);
void calculerStatistiques(Colonne *colonne);

#endif