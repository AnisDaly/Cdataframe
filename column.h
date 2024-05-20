#ifndef COLUMN_H
#define COLUMN_H

#include "data_types.h"

// Structure de colonne pouvant contenir divers types de données
typedef struct {
    char* nom;
    Data* donnees; // Tableau de Data
    int taille;
    int capacite;
} Colonne;

Colonne* creerColonne(const char* nom, DataType type, int capacite);
void insererDonnee(Colonne* colonne, DataValue valeur);
void afficherColonne(const Colonne* colonne);
void afficherDonneesColonne(const Colonne* colonne, int index);
void afficherLigneSeparateur(int nombreColonnes);
void afficherColonneAvecNom(const char* nom);
void libererColonne(Colonne* colonne);

#endif // COLUMN_H
