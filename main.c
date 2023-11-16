#include "structures.h"


int main(int argc, char* argv[]) {
    

    do {
        coup = coup_obligatoire(joueur_c->couleur,jeu,rafle,tmp,&n);

        if(joueur_c->type == HUMAIN){
            affiche_damier(jeu.plateau);

            if(joueur_c->couleur == PION_NOIR){
                printf("\n C’est à %s de jouer avec les noirs ( %d pions) \n",joueur_c->nom,jeu.nb_noir);
            } else {
                printf("\nC’est à %s de jouer avec les blancs ( %d pions) \n",joueur_c->nom,jeu.nb_blanc);
            }

            printf("Nombre de prises maximum : %d \n",coup);

            if(coup > 0 ){
                affiche_choixcoup(rafle,n,joueur_c->couleur,&jeu);
            } else{
                if(selec_pion(joueur_c->couleur,&jeu)==-1){
                    quitter = 1;
                }
            }

        } else {
            if(jouer_cpu(&jeu,joueur_c->couleur,coup,rafle)==-1) {
                printf("L’ordinateur abandonne, vous avez gagner ! ! ! \n");
                quitter=1 ;
            }
        }
        
        //On change de joueur
        if(joueur_c == joueur1) {
            joueur_c = joueur2;
        } else {
            joueur_c = joueur1;
        } 
        
        }while(quitter==0 && (statut = jeu_fini(&jeu,joueur_c->couleur))==0);

    return 0;
}