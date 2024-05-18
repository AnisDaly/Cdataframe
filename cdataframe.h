#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

typedef struct {
    Column **colonnes;
    int nombre_colonnes;
    int capacite;
} CDataframe;

void initialiserCDataframe(CDataframe *cdf, int capacite);
void ajouterColonne(CDataframe *cdf, Column *colonne);
void afficherCDataframe(const CDataframe *cdf);
void libererCDataframe(CDataframe *cdf);

#endif
