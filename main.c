#include "cdataframe.h"

int main() {
    CDataframe cdf;
    initialiserCDataframe(&cdf, 5); // Initialiser un CDataframe avec une capacité de 5 colonnes

    Column *nouvelleColonne = creerColonne("Colonne d'exemple", 10);
    insererDonnee(nouvelleColonne, (void*)0x123456); // Donnée exemple (adresse)
    ajouterColonne(&cdf, nouvelleColonne);

    afficherCDataframe(&cdf);
    libererCDataframe(&cdf);

    return 0;
}
