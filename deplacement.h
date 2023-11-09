#include "structures.h"



void deplacerPion(int couleur, Deplacement d, int prise, Damier *jeu);

int testerDeplacement(int couleur, Deplacement d, int damier[10][10], int ligne, int colonne);

int max_pion_prises(Case case_i, int couleur, damier* jeu, listeCases* rafle_max,int* n);

// deplacement* testdeplacement(int plateau[10][10],int i,int j,int couleur);

listeCases trouvercoup(damier* jeu, int couleur);

int jouer_cpu(damier* jeu,int couleur,int nb_coup,listeCases* rafle);

int jeu_fini(damier* jeu, int couleur);

int selec_pion(int couleur,damier* jeu);

void affiche_choixcoup(listeCases* rafle, int n, int couleur, damier* jeu);

void *tour(void* a);

void* temps();


// similerCoup
// calculerCoupObligatoire
// calculerCoupObligatoireCPU
// calculerPrise
// deplacerDame
// deplacerPion
// rafler
// promouvoirPion
// lectureDeplacement
// calculerPrise
// verifierDeplacement
// selectionnerPion
// trouverCoup
// gererTour
// testerCase
// testerDeplacement
// testerDeplacementDame
// maximumDamePrises
// maximumPionPrises

// jeuFini
// jouerCPU