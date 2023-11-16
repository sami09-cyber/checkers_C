

int main(int argc, char *argv[]) {

    int endGame = 0;
    int playerType;

    do{
        homeInit();

        afficherDamier();

        savePlayer();
        printf("Choississez le type de joueur:");
        
        printf("1: Pour jouer avec l'ordinateur");
        printf("2: Pour jouer a deux");

        scanf("%d", &playerType);


        if(playerColor == PION_NOIR){
            printf("\n C’est à %s de jouer avec les noirs ( %d pions) \n",joueur_c->nom,jeu.nb_noir);

            printf("Nombre de prises maximum : %d \n", coup_obligatoire(joueur_c->couleur,jeu,rafle,tmp,&n));
        } else {
            printf("\nC’est à %s de jouer avec les blancs ( %d pions) \n",joueur_c->nom,jeu.nb_blanc);
                
            printf("Nombre de prises maximum : %d \n", coup_obligatoire(joueur_c->couleur,jeu,rafle,tmp,&n));
        }


        if(playerType == 2) {
            // Human

            if(playerColor == PION_NOIR){
                coup = coup_obligatoire(joueur_c->couleur,jeu,rafle,tmp,&n);

                printf("\n C’est à %s de jouer avec les noirs ( %d pions) \n",joueur_c->nom,jeu.nb_noir);
                printf("Nombre de prises maximum : %d \n", coup);

                if(coup > 0 ){
                    affiche_choixcoup(rafle,n,joueur_c->couleur,&jeu);
                } else{
                    if(selec_pion(joueur_c->couleur,&jeu)==-1){
                        endGame = 1;
                    }
                }

            } else {
                printf("\nC’est à %s de jouer avec les blancs ( %d pions) \n",joueur_c->nom,jeu.nb_blanc);    
                printf("Nombre de prises maximum : %d \n", coup);

                if(coup > 0 ){
                    affiche_choixcoup(rafle,n,joueur_c->couleur,&jeu);
                } else{
                    if(selec_pion(joueur_c->couleur,&jeu)==-1){
                        endGame = 1;
                    }
                }
                
            }
        } else {
            // CPU
            coup = coup_obligatoire(joueur_c->couleur,jeu,rafle,tmp,&n);

            if(playerColor == PION_NOIR){
                printf("\n C’est à %s de jouer avec les noirs ( %d pions) \n",joueur_c->nom,jeu.nb_noir);
                printf("Nombre de prises maximum : %d \n", coup);

                if(coup > 0 ){
                    affiche_choixcoup(rafle,n,joueur_c->couleur,&jeu);
                } else{
                    if(selec_pion(joueur_c->couleur,&jeu)==-1){
                        endGame = 1;
                    }
                }

            } else {
                printf("\nC’est à %s de jouer avec les blancs ( %d pions) \n",joueur_c->nom,jeu.nb_blanc);    
                printf("Nombre de prises maximum : %d \n", coup);

                if(coup > 0 ){
                    affiche_choixcoup(rafle,n,joueur_c->couleur,&jeu);
                } else{
                    if(selec_pion(joueur_c->couleur,&jeu)==-1){
                        endGame = 1;
                    }
                }

            }   

        }

    }while(endGame);

    return 0;
}