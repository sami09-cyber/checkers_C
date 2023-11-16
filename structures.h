#include<stdio.h>
#include<stdlib.h>

/* Constantes representants l'etat d'une case et le type de joueur */ 
#define PION_BLANC 1
#define DAME_BLANC 2
#define PION_NOIR -1
#define DAME_NOIR -2
#define CASE_VIDE 0
#define HUMAIN 0
#define CPU 1
#define DIMENSION_PLATEAU 10
#define NOMBRE_PION_BLANC 20
#define NOMBRE_PION_NOIR 20

/* Representation d'une case */ 
typedef struct case {
    int ligne;
    int colonne ;
} Case;

/* Representation d'un deplacement */ 
typedef struct deplacement {
    Case caseInitiale; 
    Case caseFinale;
} Deplacement;

/* Representation des rafles: Les rafles sont une liste de case*/ 
typedef struct rafle {
    Case case;
    struct rafle *suivante;
} Rafle;

/* Representation d'un joueur: Le type de joueur est soit HUMAIN ou CPU*/ 
typedef struct joueur {
    char *nom ;
    int type ;
    int couleur ;
} Joueur;

/* Representation du damier: Le damier est le plateau contenant les pions */ 
typedef struct damier {
    int plateau[DIMENSION_PLATEAU][DIMENSION_PLATEAU]; // Représente l’état du plateau
    int nombreNoir; // Représente le nombre de pion noir
    int nombreBlanc; // Représente le nombre de pion blanc
} Damier;

/* Representation d'un argument */
typedef struct argument {
    Damier *damier;
    int couleur;
    int nombre;
    Rafle *rafle;
    Rafle *coup;
} Argument;
