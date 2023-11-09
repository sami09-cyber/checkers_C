#include "deplacement.h"

void deplacerPion(int couleur, Deplacement d, int prise, Damier *jeu) {

    jeu->plateau[d.case_i.lig][d.case_i.col] = CASE_VIDE ;
    jeu->plateau[d.case_f.lig][d.case_f.col] = couleur ;

    if(prise == 1) {
        if(couleur == PION_BLANC) {
            jeu->nombre_noir--;
        } else { 
            jeu->nombre_blanc--;
        }

        jeu->plateau[(d.case_finale.ligne + d.case_initiale.ligne)/2]

        [(d.case_f.col + d.case_i.col)/2] = CASE_VIDE;
    }
}

int test_deplacement(int couleur,deplacement d,int damier[10][10]) {
    
    if(damier[d.case_i.lig][d.case_i.col] != couleur) { //Le pion sélectionné n’est pas un pion du joueur
        return -1 ;
    }
    
    if(damier[d.case_f.lig][d.case_f.col] != CASE_VIDE) { //Case occupé
        return -1 ;
    }
    
    if(d.case_f.lig != d.case_i.lig - couleur) { //Mauvaise Ligne
        return -1 ;
    }
    
    if(d.case_f.col != (d.case_i.col+1) && d.case_f.col != (d.case_i.col-1) ) { //Mauvaise colonne
        return -1 ;
    }

    return 0 ;
}