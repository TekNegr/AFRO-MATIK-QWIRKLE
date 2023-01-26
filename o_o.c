//
// Created by Pas un taille crayon on 24/01/2023.
//

#include "o_o.h"


// Initie tuile une tuile vide pour les effacer
Tuile Init_Tuile_Vide(){
    Tuile T;
    T.Forme='\0';
    T.Couleurs='\0';
    T.X='\0';
    T.Y='\0';
    return T;
}


//Initialise la pioche selon sa taille
void Init_Pioche(Pioche* P, int type_Partie){
    int Taille, Coul_I=0;
    char Forme[6]={'C','E','L','X','R','F'};
    char Couleur[6]={'R','Y','G','B','P','W'};

    // Alloue dynamiquement la pioche pour adapter la taille à sa partie
    switch (type_Partie) {
        case 1:{
            printf("Partie Normale\n");
            P->Stock= (Tuile*) malloc(Taille_N* sizeof(Tuile));
            Taille=Taille_N;
            break;
        }
        case 2:{
            printf("Partie Dégradé\n");
            P->Stock= (Tuile*) malloc(Taille_D* sizeof(Tuile));
            Taille=Taille_D;
            break;
        }
        default:{
            printf("Type de Partie Impossible");
            scanf("%d", &type_Partie);
            break;
        }
    }//Rempli la pioche de sa taille et toutes les 6 formes change de couleurs
    printf("Initialisation de la pioche...");
    for(int i=0;i<Taille;i++){
        printf(".");
        P->Stock[i].Forme=Forme[i%6];
        if ((i%6==0)&&(i!=0)){
            Coul_I++;
            Coul_I=Coul_I%6;
        }
        P->Stock[i].Couleurs=Couleur[Coul_I];
        P->Stock[i].X='\0';
        P->Stock[i].Y='\0';
    }
    printf("Pioche initialisee\n");
}


//Parcours la main du joueur, si il y a une case vide il va en prendre une de la pioche et ensuite la supprimer de cette dernière pour remplir la main
void Pioche_Main_Auto(Joueur* J, Pioche P1, int Type_Partie){
    srand(time(NULL));
    int Rand_Tuile, Taille, nbTuile;
    printf("Initialisation de la main...");
    Taille=(Type_Partie==1)? Taille_N:Taille_D;
    for (int i=0; i<6; i++){
        printf("Tuile %d\t",i);
        if((J->Main[i].Couleurs=='\0')||(J->Main[i].Forme=='\0')){//Prend les Tuiles vide de la main
            do {
                Rand_Tuile = rand();
                Rand_Tuile = Rand_Tuile % Taille;
                J->Main[i] = P1.Stock[Rand_Tuile];
                P1.Stock[Rand_Tuile] = Init_Tuile_Vide();
                if((J->Main[i].Couleurs!='\0')&&(J->Main[i].Forme!='\0')){
                    nbTuile+=1; // Compte le nombre de tuiles dans la main pour permettre au joueur d'avoir une main complete
                }
            }while(((P1.Stock[Rand_Tuile].Forme=='\0')||(P1.Stock[Rand_Tuile].Couleurs=='\0'))&&(nbTuile<=6));//verifie que la case choisi aléatoirement soit existante et non vide

        }

    }
    printf("Main initialisee");
    Update_Pioche(&P1,Taille);
}


//Prend le joueur, le laisse joueur une tuile de sa main puis la remplace par une tuile de la pioche
void Jouer_Tuile(Joueur* J, Plateau* P, int X, int Y,  Pioche P1,  int Type_Partie) {
    int choix;
    ;
    printf("Choisissez une case à jouer (0-5):\n");
    scanf("%d", &choix);
    if((choix>=0)&&(choix<=5)){
        P->Matrice[Y][X]=J->Main[choix];
        P->Matrice[Y][X].X=X;
        P->Matrice[Y][X].Y=Y;
        J->Main[choix]=Init_Tuile_Vide();
        Pioche_Main_Auto(J,P1,Type_Partie);
    }
    else{
        printf("Choix impossible choisissez a nouveau:\n");
        scanf("%d", &choix);
    }
}

void afficher_Main(Joueur J){
    printf("Pupitre de tuiles:\t");
    for (int i=0;i<6;i++){
        Affiche_Tuile(J.Main[i]);
    }
}

Plateau init_Plateau(){
    Plateau P;
    for (int i=0;i<HAUTEUR; i++){
        for (int j=0; j<LONGUEUR; j++){
            P.Matrice[i][j]=Init_Tuile_Vide();
            P.Matrice[i][j].Y=i;
            P.Matrice[i][j].X=j;
        }
    }
    printf("Initialisation du plateau...");
    return P;
}

void Init_Partie(){
    int X, Y, type_Partie, Taille=0;
    Joueur J;
    Pioche P1;
    Plateau P=init_Plateau();
    Get_TypePartie(&Taille,&type_Partie);
    Init_Pioche(&P1,type_Partie);
    Pioche_Main_Auto(&J,P1,type_Partie);
    Affiche_Plateau(P);
    printf("Entrez les coordonnées de la case à inserer:\n");
    scanf("%d %d",&X, &Y);
    afficher_Main(J);
    Jouer_Tuile(&J,&P,X,Y, P1, type_Partie);
    Update_Pioche(&P1, Taille);

}

void Get_TypePartie(int* Taille, int* TypePartie){
    printf("Choisissez votre type de partie : \n 1-Normal \n 2-Degrade");
    if((*TypePartie)==0) {
        scanf("%d", TypePartie);
    }
    (*Taille)=(TypePartie==1)?Taille_N:Taille_D;
}


void Update_Pioche(Pioche* P, int Taille){
    for(int i=0;i<Taille;i++){
        if((P->Stock[i].Couleurs=='\0')||(P->Stock[i].Forme=='\0')){
            for (int j=i;((P->Stock[j].Couleurs!='\0')||(P->Stock[j].Forme!='\0'));j++){
            P->Stock[j]=P->Stock[j+1];}
        }
    }
    printf("Pioche mise a jour");
}


void Affiche_Tuile(Tuile T){
    /*if((T.X!='\0')&&(T.Y!='\0')){
        printf("[%d;%d]",T.X,T.Y);
    }*/
    switch(T.Couleurs){
        case 'R':{
            printf('\033[0;31m');
            printf('%c',T.Forme);
            break;
        }
        case 'Y':{printf('\033[0;33m');
            printf('%c',T.Forme);
        break;}
        case 'G':{printf('\033[0;32m');
            printf('%c',T.Forme);
        break;}
        case 'B':{printf('\033[0;34m');
            printf('%c',T.Forme);
        break;}
        case 'P':{printf('\033[0;35m');
            printf('%c',T.Forme);
        break;}
        case 'W':{printf('\033[0;37m');
            printf('%c',T.Forme);
            break;}
        default:{
            printf("_");
            break;
        }
    }

}
/* bb*/
void Affiche_Plateau(Plateau P){
    int i,j;
    printf("Affichage plateau\n");
    printf("  \t A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z\n");

    for(i=0;i<=HAUTEUR;i++){
        for(j=0;j<=LONGUEUR;j++){
            if(j==0){
                printf("%d\t",i);
            }
            else {
                printf("|");
                Affiche_Tuile(P.Matrice[i][j-1]);
                printf("|");
            }
        }
        if (j==0){
            printf("%d\t", i);
        }
        printf("\n");
    }
}