//
// Created by PC on 25/01/2023.
//

#ifndef PROJET_AFROMATIK_STRUCT_H
#define PROJET_AFROMATIK_STRUCT_H
//
// Created by Pas un taille crayon on 24/01/2023.
//

#ifndef QUIRKY_W_LE_O_O_H
#define QUIRKY_W_LE_O_O_H
#define HAUTEUR 12
#define LONGUEUR 108

//STRUCTURE NECESSAIRE
//
typedef struct{
    int Forme; int Couleurs; int X; int Y;
}Tuile;

typedef struct{
    Tuile Main[6];
    int score;
    char pseudo[25];
    int Num_J;
}Joueur;

typedef struct{
    Tuile Stock[108];
}Pioche_Normal;

typedef struct{
    Tuile Stock[36];
}Pioche_Degrade;



Joueur* TourJoueur(Joueur J1,Joueur J2,Joueur J3,Joueur J4);
Tuile Init_Tuile_Vide();
typedef struct{
    Tuile Matrice[HAUTEUR][LONGUEUR];
}Plateau;

int Comptage_Points(Tuile tuile_Actu,int NbTuilePoz,Plateau Case,Joueur* pjoueur);

void Afficher_Score(int Nb_J,Joueur* joueur[]);

void Sauv(Joueur* joueur,int nb_J );

#endif //QUIRKY_W_LE_O_O_H
#endif //PROJET_AFROMATIK_STRUCT_H
