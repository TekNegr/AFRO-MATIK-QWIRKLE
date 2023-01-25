//
// Created by Pas un taille crayon on 24/01/2023.
//

#ifndef QUIRKY_W_LE_O_O_H
#define QUIRKY_W_LE_O_O_H

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

#endif //QUIRKY_W_LE_O_O_H
