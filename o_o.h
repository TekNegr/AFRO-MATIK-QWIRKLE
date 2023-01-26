//
// Created by Pas un taille crayon on 24/01/2023.
//

#ifndef QUIRKY_W_LE_O_O_H
#define QUIRKY_W_LE_O_O_H
#define HAUTEUR 12
#define LONGUEUR 26
#define Taille_N 108
#define Taille_D 36
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//STRUCTURE NECESSAIRE
//

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

void Pioche_Main(Joueur* J, int Partie);
Tuile Init_Tuile_Vide();
void Pioche_Main_Auto(Joueur* J, Pioche P1, int Type_Partie);
void Jouer_Tuile(Joueur* J, Plateau* P, int X, int Y, Pioche P1,  int Type_Partie);
Plateau init_Plateau();
void Init_Partie();
void Init_Pioche(Pioche* P, int type_Partie);
void Get_TypePartie(int* Taille, int* TypePartie);
void Update_Pioche(Pioche* P, int Taille);
void Affiche_Tuile(Tuile T);
void Affiche_Plateau(Plateau P);
#endif //QUIRKY_W_LE_O_O_H
