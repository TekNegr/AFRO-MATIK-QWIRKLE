#include <stdio.h>
#include "stdlib.h"
#include "struct.h"

int main() {
    int Nouvelle_Partie = 1;
    int Assigne_Pseudo = 1;
    int Num_J[4];
    int i;
    int pseudo;
    char Psd[25];
    Joueur J1;
    Joueur J2;
    Joueur J3;
    Joueur J4;
    int nb_J;
    int choix;
    char choix1;
    printf("Bienvenue selectioner votre choix\n");
    printf("1.NouvellePartie\n2.Credit\n3.Regle\n4.sauvegarde\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1: {
            printf("Entrez le nombre de joueur\n");
            scanf("%d", &nb_J);
            printf("%d", nb_J);
            switch (nb_J) {
                case 4: {
                    printf("Entrez vos pseudos:\n");
                    scanf("%s %s %s %s", &J1.pseudo, &J2.pseudo, &J3.pseudo, &J4.pseudo);
                    printf("%s\n%s\n%s\n%s\n", J1.pseudo, J2.pseudo, J3.pseudo, J4.pseudo);
                    break;

                }
                case 3: {
                    printf("Entrez vos pseudos:\n");
                    scanf("%s %s %s", &J1.pseudo, &J2.pseudo, &J3.pseudo);
                    printf("%s\n%s\n%s\n", J1.pseudo, J2.pseudo, J3.pseudo);
                    break;
                }
                case 2: {
                    printf("Entrez vos pseudos:\n");
                    scanf("%s %s %s", &J1.pseudo, &J2.pseudo);
                    printf("%s\n%s\n", J1.pseudo, J2.pseudo);
                    break;
                }
            }
        }
            break;

        case 2: {
            printf("Credit:\nPierre Wafo\nHenintsoa Ramakavelo\nNathanael\nXavier Ogandaga\n");
            break;
        }

        case 3: {
            printf("Regles:\n");
            printf("Dans Qwirkle, vous devez aligner des tuiles ayant des simboles\n"
                   "De formes ou de couleurs identiques de facon a realiser\n"
                   " des combinaisons qui vous rapporteront des points\n"

                   " Au debut de la partie,chaque joueur pioche 6 tuiles de facon aleatoire\n"
                   "Les autres tuiles formeront la reserve\n"

                   " A son tour , chaque joueur a le choix entre 3 actions :\n"
                   "- Completer une ligne en y ajoutant une tuile puis piocher une tuile afin de toujours en avoir 6\n"
                   "- Completer une ligne en y ajoutant 2 tuiles puis piocher 2 tuiles dans la reserve\n"
                   "- Echanger une partie ou l’ensemble de ses tuiles contre celles de la reserve.\n");
            break;

        }
        case 4:{
            
        }

    }
}







