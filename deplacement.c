#include "deplacement.h"

void deplacerPion(Damier *damier, Deplacement deplacement, int prise, int couleur) {

    damier->plateau[deplacement.caseInitiale.ligne][deplacement.caseInitiale.colonne] = CASE_VIDE ;
    damier->plateau[deplacement.caseFinale.ligne][deplacement.caseFinale.colonne] = couleur ;

    if(prise == 1) {
        if(couleur == PION_BLANC) {
            damier->nombreNoir--;
        } else { 
            damier->nombreBlanc--;
        }

        damier->plateau[(deplacement.caseFinale.ligne + deplacement.caseInitiale.ligne)/2][(deplacement.caseFinale.colonne + deplacement.caseInitiale.colonne)/2] = CASE_VIDE;
    }
}

int testerDeplacement(int damier[][], int ligne, int colonne, Deplacement deplacement, int couleur) {
    
    if(damier[deplacement.caseInitiale.ligne][deplacement.caseInitiale.colonne] != couleur) { //Le pion sélectionné n’est pas un pion deplacementu joueur
        return -1;
    }
    
    if(damier[deplacement.caseFinale.ligne][deplacement.caseFinale.colonne] != CASE_VIDE) { //Case occupé
        return -1 ;
    }
    
    if(deplacement.caseFinale.ligne != deplacement.caseInitiale.ligne - couleur) { //Mauvaise Ligne
        return -1 ;
    }
    
    if(deplacement.caseFinale.colonne != (deplacement.caseInitiale.colonne + 1) && deplacement.caseFinale.colonne != (deplacement.caseInitiale.colonne -1) ) { //Mauvaise colonne
        return -1 ;
    }

    return 0 ;
}

int testerDeplacement(int damier[][], int ligne, int colonne, int couleur) {
    Deplacement *deplacement = (deplacement*) malloc (sizeof(deplacement)) ;
    
    if(ligne - couleur >= 0 && ligne - couleur < DIMENSION_PLATEAU && colonne + 1 < DIMENSION_PLATEAU && damier[ligne - couleur][colonne + 1] == CASE_VIDE) {
        deplacement->caseInitiale.ligne = ligne;
        deplacement->caseInitiale.colonne = colonne;
        deplacement->caseFinale.ligne = ligne - couleur;
        deplacement->caseFinale.colonne = colonne +1;

        return deplacement;
    }

    if(ligne - couleur >= 0 && ligne - couleur < DIMENSION_PLATEAU && colonne -1 >= 0 && damier[ligne - couleur][colonne - 1] == CASE_VIDE) {
        deplacement->caseInitiale.ligne = ligne;
        deplacement->caseInitiale.colonne = colonne;
        deplacement->caseFinale.ligne = ligne - couleur;
        deplacement->caseFinale.colonne = colonne - 1;

        return deplacement ;
    }

    return 0;
}

int maximumPionPrises(Damier *damier, Case caseInitiale, int couleur, Rafle *maximumRafle, int* nombre) {
    int prises = 0; //0 si on peut pas prendre en case, 1 sinon
    int nombrePriseMaximumCase; //Nombre de prises max en case[i]
    int maximumPriseTrouve = 0; //Nombre max de prises possibles trouvé
    int possibiliteMaximumPionCase; //Nombre de possibilité de prendre le max de pions en case[i]
    int possibilitePriseCase; //Contient le nombre de possibilité de prises en caseInitiale
    int i, t, indice = 0; //Variable d’indice, de boucle
    //Variable servant au calcul
    Case case[4];
    Deplacement deplacement;
    Damier copieDamier;
    Rafle *rafle;


    if ((possibilitePriseCase = pion_prise(caseInitiale.col,caseInitiale.lig,couleur, damier->plateau,case)) != 0) { //Le pions situé en caseInitiale peut prendre possibilitePriseCase pions. On créé un copie du damier qui va nous permettre de simuler les coups sans affecter le damier originel
        copieDamier = copie_damier(damier);
        prises++; //On peut prendre un pion -> prises = 1

        for(i = 0; i < possibilitePriseCase; i++) { //Pour chaque possibilité de prises, on calcul le nombre de prises maximales que l’on peut faire
            possibiliteMaximumPionCase = 1; //On initialise le nombre de façon de faire
            rafle = (listeCases*) malloc(sizeof(listeCases)); // On alloue de la place
            rafle[0] = (listeCases) malloc(sizeof(struct element));
            deplacement.caseFinale = case[i]; //On crée une variable déplacement et on effectue le deplacement
            deplacement.caseInitiale = caseInitiale;
            deplace_pion(couleur,deplacement,1,&copieDamier);
            nombrePriseMaximumCase = max_pion_prises(case[i],couleur,&copieDamier,rafle,&possibiliteMaximumPionCase ); //Calcul du nombre de prises max a partir de cette position
            
            if(nombrePriseMaximumCase == maximumPriseTrouve && nombrePriseMaximumCase>0) { // Il y a d’autre possibilité de prendre maximumPriseTrouve pion, mais en passant par un autre endroit
            
                for(t = 0; t < possibiliteMaximumPionCase; t++) { // Pour chaque nouvelle possibilité on crée une nouvelle cases dans maximumRafle
                    maximumRafle[indice] = (Rafle *) malloc(sizeof(Rafle));
                    maximumRafle[indice]->suivante = rafle[t]; //On lui affecte les valeurs
                    maximumRafle[indice]->case = caseInitiale;

                    indice++;
                }

                indice--; // Correction de l’indice
                *nombre = *nombre + possibiliteMaximumPionCase; // On ajoute au nombre de possibilité les possibiliteMaximumPionCase que l’on vient de trouver
            }

            if(nombrePriseMaximumCase == 0 && maximumPriseTrouve == 0) { // On ne peut plus prendre de pion. On crée le dernier element de la liste
                rafle[0]->case = case[i];
                rafle[0]->suivante = 0;
                maximumRafle[indice] = (listeCases) malloc(sizeof(struct element)); // On créé une nouvelle case dans le tableau
                maximumRafle[indice]->suivante = rafle[0]; // On lui affecte les valeurs correspondante
                maximumRafle[indice]->case = caseInitiale;

                indice++; // L’indice augmente de 1 car on a trouvé un moyen de faire maximumPriseTrouve
                *nombre = indice;
            }

            if(nombrePriseMaximumCase > maximumPriseTrouve) { // On a trouvé possibiliteMaximumPionCase moyen de faire plus de prises. Il y a possibiliteMaximumPionCase moyen
                *nombre = possibiliteMaximumPionCase;
                maximumPriseTrouve = nombrePriseMaximumCase;

                for(indice = 0; indice < possibiliteMaximumPionCase; indice++) { //On met dans le tableau toutes les possibilités qu’on a trouvées
                    maximumRafle[indice] = (Rafle *) malloc(sizeof(Rafle));
                    maximumRafle[indice]->suivante = r[indice];
                    maximumRafle[indice]->case = caseInitiale;
                }
            }
        }
    } else {
        for(t = 0; t < indice; t++) { //Si on ne peut pas prendre, on est en fin de liste, d’où suivante pointe vers nulle
            maximumRafle[t]->suivante = 0;
        }
    }
    
    return prises + maximumPriseTrouve; //On retourne le nombre de prises maximales
}

Rafle * trouvercoup(Damier *damier, int couleur) {

    int i = 0, j, nombrePion = 0, maximum;
    Deplacement *deplacement;
    Rafle coup = (Rafle *) malloc(sizeof(Rafle));

    if(couleur == PION_BLANC) {
        maximum = damier->nombreBlanc;
    } else {
        maximum = damier->nombreNoir;
    }

    while(nombrePion < maximum) {
        for(j = 0; j < DIMENSION_PLATEAU; j++) {
            if(damier->plateau[i][j] == couleur) {
                nombrePion++; //On a trouvé un pion

                if((deplacement = testdeplacement(damier->plateau,i,j,couleur)) !=0) { //On crée notre liste
                    coup->case = deplacement->caseInitiale; 
                    coup->suivante = (Rafle *) malloc(sizeof(Rafle));
                    coup->suivante->case = deplacement->caseFinale;
                    coup->suivante->suivante = 0;

                    return coup ;
                }
            } else {

                if(damier->plateau[i][j] == 2*couleur) { //On a trouvé une dame
                    nombrePion++;

                    if((deplacement = testdeplacement_dame(damier->plateau,i,j,couleur)) !=0) { //On crée notre liste
                        coup->case = deplacement->caseInitiale;
                        coup->suivante = (Rafle *) malloc(sizeof(Rafle));
                        coup->suivante->case = deplacement->caseFinale;
                        coup->suivante->suivante = 0;

                        return coup;
                    }
                }
            }
        }

        i++;
    }

    return 0 ;
}


int jouer_cpu(Damier *damier,int couleur,int nombreCoup,Rafle *rafle) {
    Rafle coup;
    Deplacement deplacement;

    if(nombreCoup > 0){ //Si il y a plusieurs coups possibles, on prend le premier
        faire_coup(rafle[0],couleur,damier);
    } else { //Pas de coup possible
        if((coup = trouvercoup(damier,couleur)) == 0) {
            return -1;
        } else {
            deplacement.caseInitiale = coup->case;
            deplacement.caseFinale = coup->suivante->case;
            deplace_pion(couleur,d,0,damier);
        }
    }

    return 1;
}


int jeu_fini(Damier *damier, int couleur) {

    if(damier->nombreBlanc == 0) {
        return PION_BLANC;
    }

    if(damier->nombreNoir == 0) {
        return PION_NOIR;
    }
    
    if(trouvercoup(damier,couleur) == 0) {
        printf( “Fin du match \n “);
        affiche_damier(damier->plateau);

        if(couleur == PION_NOIR) {
            printf("Les noirs ne peuvent plus bouger ! \n");
        } else {
            printf("Les blancs ne peuvent plus bouger ! \n");
        }

        return couleur ;
    }

    return 0;
}


int selec_pion(int couleur, Damier *damier) {
    int ok = 0;
    int i,prise ;
    Deplacement deplacement; 

    do {
        switch(lecture_deplacement(&d,jeu,couleur)) {
            case -1 :
                printf("Erreur de deplacement\n");
            break ;
            case 0 :
                if(jeu->plateau[d.case_i.lig][d.case_i.col] == couleur) {
                    if((prise = test_deplacement(couleur,d,jeu->plateau)) == -1) {
                        printf("Impossible de déplacer le pion %c,%d en %c,%d\n", deplacement.caseInitiale.colonne + 'a', deplacement.caseInitiale.ligbe + 1, deplacement.caseFinale.colonne + 'a', deplacement.caseFinale.ligne + 1);
                    }
                    else {
                        ok = 1 ;
                    }
                }
            break;
            case 3 :
                return -1 ;
            break ;
            case 4 :
                return 2 ;
            break ;
            default :
            break ;
        }
    } while(ok == 0) ;

    deplace_pion(couleur,d,prise,jeu) ;

    return 1 ;
}


void faire_dames(Damier *damier,int couleur) {
    int i,j;

    if(couleur == PION_NOIR) {
        i=9 ;
        j=0 ;
    } else {
        i=0 ;
        j=1 ;
    }

    for(j ;j<10 ;j+=2) {
        if(jeu->plateau[i][j] == couleur) {
            jeu->plateau[i][j] = 2*couleur ;
        }
    }
}

int test_deplace_dame(Damier *damier, int couleur,Deplacement deplacement) {
    int i = deplacement.caseInitiale.ligne, j = deplacement.caseInitiale.colonne;

    if(damier->plateau[i][j] != couleur*2) {
        printf("%c%d n’est pas une dame\n",j+’a’,i+1);

        return -1 ;
    }

    while(i != deplacement.caseFinale.ligne || j != deplacement.caseFinale.colonne) {
        if(deplacement.caseFinale.ligne > deplacement.caseInitiale.ligne){
            i++;
        } else {
            i--;
        }

        if(deplacement.caseFinale.colonne > deplacement.caseInitiale.colonne) {
            j++;
        } else {
            j--;
        }

        if(damier->plateau[i][j] != CASE_VIDE) {
            printf("%c%d n’est pas vide\n",j + 'a', i+1);

            return -1;
        }
    }

    return 1;
}

void deplace_dame(damier* jeu, int couleur,deplacement d, int p, Case prise) {
jeu->plateau[d.case_i.lig][d.case_i.col] = CASE_VIDE ;
jeu->plateau[d.case_f.lig][d.case_f.col] = 2*couleur ;
if(p==1 && (jeu->plateau[prise.lig][prise.col]==-couleur ||
jeu->plateau[prise.lig][prise.col]==-couleur*2)) {
jeu->plateau[prise.lig][prise.col] = CASE_VIDE ;
if(couleur == PION_BLANC)
jeu->nb_noir = jeu->nb_noir -1 ;
else
jeu->nb_blanc = jeu->nb_blanc - 1 ;
}
}

void *tour(void* a) {
    Argument *argument = (Argument *) a;
    int retour = 0;

    if(tour_joueur(argument->damier, argument->couleur, argument->nombre, argument->rafle, argument->coup) == -1) {
        retour = -1;
    }
    pthread_mutex_lock(&mutex);

    if(tour_fini == 0) {
        tour_fini = 1;
    } 
    pthread_mutex_unlock(&mutex) ;
    pthread_exit((void *) retour) ;
}

void* temps() {
    int i = 0;

    while(i<=time_limit) {
        pthread_mutex_lock(&mutex);

        if(tour_fini == 1){
            pthread_exit((void *) 1) ;
        }

        pthread_mutex_unlock(&mutex) ;
        sleep(1) ;
        i++ ;
    }
    pthread_exit((void *) -1) ;
}
