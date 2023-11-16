#include "structures.h"


void deplacerPion(Damier *damier, Deplacement deplacement, int prise, int couleur);

int testerDeplacement(int damier[][], int ligne, int colonne, Deplacement deplacement, int couleur);
int testerDeplacement(int damier[][], int ligne, int colonne, int couleur);

int maximumPionPrises(Damier *damier, Case case, int couleur, Rafle *maximumRafle, int* n);


Rafle trouvercoup(Damier *damier, int couleur);

// int jouer_cpu(damier* jeu,int couleur,int nb_coup,listeCases* rafle);
int jouer_cpu(Damier *damier,int couleur,int nombreCoup,Rafle *rafle);

int jeu_fini(damier* jeu, int couleur);

int selec_pion(int couleur, Damier *damier);

void affiche_choixcoup(listeCases* rafle, int n, int couleur, damier* jeu);

void faire_dames(Damier *damier,int couleur);

void *tour(void* a);

void* temps();


void similerCoup();
void calculerCoupObligatoire();
void calculerCoupObligatoireCPU();
void calculerPrise();
void deplacerDame();
void deplacerPion();
void rafler();
void promouvoirPion();
void lectureDeplacement();
void calculerPrise();
void verifierDeplacement();
void selectionnerPion();
void trouverCoup();
void gererTour();
void testerCase();
void testerDeplacement();
void testerDeplacementDame();
void maximumDamePrises();
void maximumPionPrises();

void jeuFini();
void jouerCPU();