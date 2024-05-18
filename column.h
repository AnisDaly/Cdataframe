#ifndef COLUMN_H
#define COLUMN_H

typedef struct {
    void **donnees;
    int taille;
    int capacite;
    char *nom;
} Column;

Column *creerColonne(const char *nom, int capacite);
void insererDonnee(Column *col, void *donnee);
void afficherColonne(const Column *col);
void libererColonne(Column *col);

#endif
