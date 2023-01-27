//
// Created by Pas un taille crayon on 27/01/2023.
//

#ifndef QWIRKLE_COMPILATION_COMPILATION_H
#define QWIRKLE_COMPILATION_COMPILATION_H
// MACROS + BIBLI

#define HAUTEUR 12
#define LONGUEUR 26
#define Taille_N 108
#define Taille_D 36
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//STRUCTURE

typedef struct{
    char Forme; char Couleurs; int X; int Y;
}Tuile;

typedef struct{
    Tuile Main[6];
    int score;
    char pseudo[25];
    int Num_J;
}Joueur;

typedef struct{
    Tuile* Stock;
}Pioche;


typedef struct{
    Tuile Matrice[HAUTEUR][LONGUEUR];
}Plateau;

typedef struct{
    int Taille;
    int Type_Partie;
    int Nb_Joueur;
    int Num_J_Actu;
    Joueur* pTab[4]
}Partie;

// DEFINITION FONCTIONS
Pioche Init_Pioche(Pioche P,Partie P1);
void Definition_P(Pioche* P, Partie* P1);
Tuile Init_Tuile_Vide();
void Update_Pioche(Pioche* P, Partie P1);
void Color(int couleurDuTexte,int couleurDeFond);
void Affiche_Tuile(Tuile T);
void Affiche_Plateau(Plateau P);
void Pioche_Main(Joueur* J, Pioche* P1, Partie PP);
void afficher_Main(Joueur J);
Joueur* TourJoueur(Joueur J1,Joueur J2,Joueur J3,Joueur J4,Partie* PP);
void Tab_PointeurJ(Partie* P, Joueur J1,Joueur J2,Joueur J3,Joueur J4 );
int Verif_XY(Plateau P,Tuile T_Actu);
void Comptage_Points(Tuile T_Actu,int NbTuilePoz,Plateau P,Joueur* pjoueur);
void Afficher_Score(Partie P);
void Menu(Joueur* J1,Joueur* J2,Joueur* J3,Joueur* J4, Partie* PP);
void Jouer_Tuile(Joueur* J, Plateau* P, int X, int Y,  Pioche* P1,  Partie PP);
void Jouer_nTuile(Joueur* J, Plateau* P, int X, int Y,  Pioche* P1,  Partie PP, int* nbTuilePoz);
void Boucle_Jeu(Partie PP, Joueur* JQJ,Plateau* P, Pioche* P0);
void init_Partie();
#endif //QWIRKLE_COMPILATION_COMPILATION_H
