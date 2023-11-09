#include "affichage.h"

void afficherLigne(int damier[10][10], int ligne, int colonne) {

    printf(" %2d ", ligne + 1) ;
    
    for(int j = 0; j < colonne; j++) {
        switch(damier[ligne][colonne]) {
            case PION_BLANC:
                printf("| O ");
            break;
            case PION_NOIR:
                printf("| X ");
            break;
            case DAME_NOIR:
                printf("| [X] ");
            break;
            case DAME_BLANC:
                printf("| [O] ");
            break;
            default:
                printf("| ");
            break;
        }
    } 

    printf("| %2d\n", ligne + 1);
    printf(" |-------------------------------------------|\n");
}

void afficherDamier(int damier[10][10], int ligne, int colonne) {

    printf("    a   b   c   d   e   f   g   h   i   j   \n");

    printf("    |----------------------------------------| \n");

    for(int i = 0; i < ligne; i++) {
        afficherLigne(damier, i, colonne);
        printf("    a   b   c   d   e   f   g   h   i   j   \n");
    }
}

void initialiserDamier(Damier *jeu) {

    jeu->nombre_blanc = 20;
    jeu->nombre_noir = 20;

    int i, j;

    for(i = 0; i < 10; i++) { //On initialise le tableau
        for(j = 0; j < 10; j++) {
            jeu->plateau[i][j] = 0;
        }
    }
    
    for(i = 0; i<4; i++) { //On remplie la partie haute du damier par des pions noirs
        if(i%2 == 0) { //Si i est pair, la première case doit être noir (active)
            j = 1;
        }else {
            j = 0;
        }

        for(j; j < 10; j += 2) {
            jeu->plateau[i][j] = PION_NOIR ;
        }
    }

    for(i = 6; i < 10; i++) { //On remplie la partie basse du damier par des pions blancs
        if(i%2 == 0) { //Si i est pair, la premier case doit être noir (active)
            j = 1;
        } else {
            j = 0;
        }

        for(j ;j<10 ;j+=2) {
            jeu->plateau[i][j] = PION_BLANC;
        }
    }
}