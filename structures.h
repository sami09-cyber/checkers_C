#include<stdio.h>
#include<stdlib.h>

/* Constantes representants l'etat d'une case*/ 
#define PION_BLANC 1
#define DAME_BLANC 2
#define PION_NOIR -1
#define DAME_NOIR -2
#define CASE_VIDE 0
#define HUMAIN 0
#define CPU 1


typedef struct case {
    int ligne;
    int colonne ;
} Case ;

typedef struct deplacement {
    Case case_initiale; 
    Case case_finale;
} Deplacement ;

/* Representation des rafles*/ 
typedef struct rafle {
    Case c ;
    struct rafle *suivante ;
} Rafle;

/* Le type de joueur est soit HUMAIN ou CPU*/ 
typedef struct joueur {
    char *nom ;
    int type ;
    int couleur ;
} Joueur;


typedef struct damier {
    int plateau[10][10]; // Représente l’état du plateau
    int nombre_noir; // Représente le nombre de pion noir
    int nombre_blanc; // Représente le nombre de pion blanc
} Damier;

