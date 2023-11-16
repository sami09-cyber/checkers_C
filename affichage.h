#include "structures.h"

void afficherLigne(int damier[][], int ligne, int colonne);

void afficherDamier(int damier[][], int ligne, int colonne);

void initialiserDamier(Damier *damier, int ligne, int colonne);

void affiche_choixcoup(Damier *damier, Rafle *rafle, int ncouleur, int n);

void afficherAide();
void afficherCoup();
void chargerPartie();
void afficherPlateau();
void quitterJeu();
void afficherRafle();
void sauvegarderPartie();
