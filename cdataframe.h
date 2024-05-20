#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

// Structure du CDataframe qui contient un tableau de pointeurs vers des colonnes
typedef struct {
    Colonne** colonnes;  // Tableau de pointeurs vers les colonnes
    int nombreColonnes;  // Nombre actuel de colonnes dans le dataframe
    int capacite;        // Capacité maximale du dataframe
} CDataframe;

CDataframe* creerCDataframe(int capacite);
void ajouterColonne(CDataframe* dataframe, Colonne* colonne);
void afficherCDataframe(const CDataframe* dataframe, const char* nomsColonnes[]);
void libererCDataframe(CDataframe* dataframe);

#endif // CDATAFRAME_H
