//
// Created by PC on 25/01/2023.
//

#include"struct.h"
#include <stdio.h>
int menu;
int x;
int y;
int Vc;
int Vf;
int Valid;
Tuile T[];
int nb_J;

void Jouer() {
    int Nouvelle_Partie=1;
    int Assigne_Pseudo=1;
    int Num_J;
    int i;
    Joueur J1;
    Joueur J2;
    Joueur J3;
    Joueur J4;
    int nb_J;
    int choix;




    Joueur* TourJoueur(Joueur J1,Joueur J2,Joueur J3,Joueur J4);{
        Joueur *JQJ;
        int Num_J, Nb_J, exit;
        while (exit != 0) {
            Num_J=(Num_J%Nb_J)+1;
            switch (Num_J) {
                case 1:
                    JQJ=&J1;
                    break;
                case 2:
                    JQJ=&J2;
                    break;
                case 3:
                    JQJ=&J3;
                    break;
                case 4:
                    JQJ=&J4;
                    break;
            }  }
        }
    }

int Verif_XY(Plateau Case,Tuile coord,Tuile T_Actu[x][y])
{
    int Verif_X(int i);
    {
        for (int i = x - 6; i < x + 6; ++i) {
            Vc += (T[i].Couleurs == T_Actu) ? 1 : 0;
            Vf += (T[i].Forme == T_Actu) ? 1 : 0;
            Valid = ((Vc <= 6) && (Vf <= 6)) ? 1 : 0;

        }
        int Verif_Y(int j);{
            for (int j = y - 6; j < x + 6; ++j) {
                Vc += (T[j].Couleurs == T_Actu) ? 1 : 0;
                Vf += (T[j].Forme == T_Actu) ? 1 : 0;
                Valid = ((Vc <= 6) && (Vf <= 6)) ? 1 : 0;
            }
        }
    }
     return 0;
}

int Comptage_Points(Tuile tuile_Actu,int NbTuilePoz,Plateau Case,Joueur* pjoueur)
{
    for (int i = 0; i <=Case.Matrice[LONGUEUR];i++) {
        if(Case.Matrice[i]==T[i].Couleurs)
        {
            pjoueur->score +=NbTuilePoz;
        }
        else if (Case.Matrice[i]==T[i].Forme)
        {
            pjoueur->score+=NbTuilePoz;
        }
        else if (Case.Matrice[LONGUEUR]==6){
            pjoueur->score+=6;
        }
        
    }
    for (int j = 0; j <=Case.Matrice[HAUTEUR]; j++) {
        if(Case.Matrice[j]==T[j].Couleurs)
        {
            pjoueur->score +=NbTuilePoz;
        }
        else if (Case.Matrice[j]==T[j].Forme)
        {
            pjoueur->score+=NbTuilePoz;
        }
        else if (Case.Matrice[HAUTEUR]==6){
            pjoueur->score +=6;
        }

    }
    return pjoueur->score;
}

void Afficher_Score(int nb_J,Joueur* joueur[]){
    for(int i=0;i<nb_J;i++){
        printf("Le score du joueur %d est: %d\n",i+1,joueur[i]->score);
    }

}

void Sauv(Joueur* joueur,int nb_J )
{
    FILE* fichier= fopen("Partie.txt","w");
    for (int i = 0; i < nb_J; i++) {

        fprintf(fichier,"Joueur %d : %s\nscore:%d\n",i+1,joueur[i].pseudo,joueur[i].pseudo);
    }
    fclose(fichier);
    printf("Scores et pseudos sauvegardés avec succès.\n");
}
