#include "affichage.h"
/*
Affichage du damier ligne par ligne
    X => Pion Noir
    0 => Pion Blanc
*/
void afficherLigne(int damier[][], int ligne, int colonne) {

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

/* Affichage du damier en totalite */ 
void afficherDamier(int damier[][], int ligne, int colonne) {

    printf("    a   b   c   d   e   f   g   h   i   j   \n");

    printf("    |----------------------------------------| \n");

    for(int i = 0; i < ligne; i++) {
        afficherLigne(damier, i, colonne);
        printf("    a   b   c   d   e   f   g   h   i   j   \n");
    }
}

void initialiserDamier(Damier *damier, int ligne, int colonne) {

    damier->nombre_blanc = NOMBRE_PION_BLANC;
    damier->nombre_noir = NOMBRE_PION_NOIR;

    int i, j;

    for(i = 0; i < ligne; i++) { //On initialise le tableau
        for(j = 0; j < colonne; j++) {
            damier->plateau[i][j] = 0;
        }
    }
    
    for(i = 0; i < ligne/2 - 1; i++) { //On remplie la partie haute du damier par des pions noirs
        if(i%2 == 0) { //Si i est pair, la première case doit être noir (active)
            j = 1;
        }else {
            j = 0;
        }

        for(j; j < colonne; j += 2) {
            damier->plateau[i][j] = PION_NOIR;
        }
    }

    for(i = 6; i < ligne; i++) { //On remplie la partie basse du damier par des pions blancs
        if(i%2 == 0) { //Si i est pair, la premier case doit être noir (active)
            j = 1;
        } else {
            j = 0;
        }

        for(j; j < colonne; j += 2) {
            damier->plateau[i][j] = PION_BLANC;
        }
    }
}


void affiche_choixcoup(Damier *damier, Rafle *rafle, int ncouleur, int n) {
    int ok = 0, i;
    char buffer[50];

    do {
        printf( "Plusieurs coups sont possibles %d : \n",n);

        for(i=0 ;i<n ;i++) {
            printf(" %d : ",i+1) ;
            affiche_rafle(rafle[i]) ;
        }

        if(scanf( " %d ",&i) ==1 && i>0 && i<=n) {
            faire_coup(rafle[i-1],couleur,damier) ;
            ok = 1 ;
        } else { //Vide le tampon
            fflush(stdin);
        }
    } while(ok == 0) ;
}