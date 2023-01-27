//
// Created by Pas un taille crayon on 27/01/2023.
//

#include "Compilation.h"
// FONCTIONS APPEL + BOUCLE
void init_Partie(){
    int exit=1;
    Joueur* JQJ;
    Joueur J1;
    Joueur J2;
    Joueur J3;
    Joueur J4;
    Partie PP;
    Pioche P0;
    Plateau P;
    Menu(&J1,&J2,&J3,&J4,&PP);
    Tab_PointeurJ(&PP,J1,J2,J3,J4);
    Definition_P(&P0,&PP);
    P0= Init_Pioche(P0,PP);
    Affiche_Plateau(P);
    switch (PP.Nb_Joueur) {
        case 2:{
            Pioche_Main(&J1,&P0,PP);
            Pioche_Main(&J2,&P0,PP);
            break;
        }
        case 3:{
            Pioche_Main(&J1,&P0,PP);
            Pioche_Main(&J2,&P0,PP);
            Pioche_Main(&J3,&P0,PP);
            break;
        }
        case 4:{
            Pioche_Main(&J1,&P0,PP);
            Pioche_Main(&J2,&P0,PP);
            Pioche_Main(&J3,&P0,PP);
            Pioche_Main(&J4,&P0,PP);
            break;
        }
    }
    JQJ=&J1;
    PP.Num_J_Actu=1;
    while(exit!=0){
        Boucle_Jeu(PP,JQJ,&P,&P0);
        printf("Fin du jeu ? 0-Oui 1-Non\n");
        scanf("%d",&exit);
        TourJoueur(J1,J2,J3,J4,&PP);
    }
}

void Boucle_Jeu(Partie PP, Joueur* JQJ,Plateau* P, Pioche* P0){
    int X, Y, nbTuilePoz=0;
    Tuile T_Actu;
    printf("Joueur %d Choisissez les coordonnees de votre placement");
    scanf("%d %d",&X,&Y);
    Jouer_nTuile(JQJ,P,X,Y,P0,PP,&nbTuilePoz);
    Pioche_Main(JQJ,P0,PP);
    T_Actu=((*P).Matrice[Y][X]);
    Verif_XY((*P),T_Actu);
    Comptage_Points(T_Actu,nbTuilePoz,(*P),JQJ);
    Afficher_Score(PP);
}

// Fonctions MENU

void Menu(Joueur* J1,Joueur* J2,Joueur* J3,Joueur* J4,Partie* PP) {
    int Nouvelle_Partie = 1;
    int Assigne_Pseudo = 1;
    int Num_J[4];
    int i;
    int pseudo;
    char Psd[25];
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
                    scanf("%s %s %s %s", J1->pseudo, J2->pseudo, J3->pseudo, J4->pseudo);
                    printf("%s\n%s\n%s\n%s\n", (*J1).pseudo, (*J2).pseudo, (*J3).pseudo, (*J4).pseudo);
                    (*J1).Num_J=1;
                    (*J2).Num_J=2;
                    (*J3).Num_J=3;
                    (*J4).Num_J=4;
                    (*PP).Nb_Joueur=4;
                    break;

                }
                case 3: {
                    printf("Entrez vos pseudos:\n");
                    scanf("%s %s %s", J1->pseudo, J2->pseudo, J3->pseudo);
                    printf("%s\n%s\n%s\n", (*J1).pseudo, (*J2).pseudo, (*J3).pseudo);
                    (*J1).Num_J=1;
                    (*J2).Num_J=2;
                    (*J3).Num_J=3;
                    (*PP).Nb_Joueur=3;
                    break;
                }
                case 2: {
                    printf("Entrez vos pseudos:\n");
                    scanf("%s %s %s",J1->pseudo, J2->pseudo);
                    printf("%s\n%s\n", (*J1).pseudo, (*J2).pseudo);
                    (*J1).Num_J=1;
                    (*J2).Num_J=2;
                    (*PP).Nb_Joueur=2;
                    break;
                }
            }
            break;
        }//initialise la partie et les joueurs

        case 2: {
            printf("Credit:\nPierre Wafo\nHenintsoa Ramakavelo\nNathanael\nXavier Ogandaga\n");
            break;
        }// Credits

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
        }// Relges
    }
}// Menu qui va initaliser la partie et les joueurs


// FONCTIONS JEU

void Jouer_Tuile(Joueur* J, Plateau* P, int X, int Y,  Pioche* P1,  Partie PP) {
    int choix;
    afficher_Main((*J));
    printf("Choisissez une case à jouer (0-5):\n");
    scanf("%d", &choix);
    if((choix>=0)&&(choix<=5)){
        (*P).Matrice[Y][X]=(*J).Main[choix];
        (*P).Matrice[Y][X].X=X;
        (*P).Matrice[Y][X].Y=Y;
        (*J).Main[choix]=Init_Tuile_Vide();
        Pioche_Main(J,P1,PP);
    }
    else{
        printf("Choix impossible choisissez a nouveau:\n");
        scanf("%d", &choix);
    }
} // permet le placement des tuiles
void Jouer_nTuile(Joueur* J, Plateau* P, int X, int Y,  Pioche* P1,  Partie PP, int* nbTuilePoz){
    int choix, i=0, nb_Choix, dir;
    Tuile Selection[6];
    Jouer_Tuile(J,P,X,Y,P1,PP);
    printf("Choisissez une autre case (si possible) 6- Sortie");
    scanf("%d",&choix);
    while((choix!=6)&&(nb_Choix<=6)){
     Selection[i]=(*J).Main[choix];
     i++;
     nb_Choix++;
    }
    printf("Choissez une direction : 1- Gauche; 2- Haut; 3- Bas; 4-Droite");
    scanf("%d",&dir);
    for(int j=0;j<nb_Choix;j++){
        (*P).Matrice[Y][X]=Selection[j];
        (*P).Matrice[Y][X].X=X;
        (*P).Matrice[Y][X].Y=Y;
        (*J).Main[choix]=Init_Tuile_Vide();
        Pioche_Main(J,P1,PP);
        switch (dir) {
            case 1:{X--;}
            case 2:{Y--;}
            case 3:{Y++;}
            case 4:{X++;}
        }
    }
    (*nbTuilePoz)=nb_Choix;
    printf("Dans quelle direction ? 1- Droite, 2- Gauche, 3- Haut, 4- Bas");
} // Placmeent de nCases alignés

// FONCTIONS VERIF + PTS

int Verif_XY(Plateau P,Tuile T_Actu)
{
    int Valid, Vc, Vf;
    int Verif_X(int i);
    int x = T_Actu.X;
    int y = T_Actu.Y;
    {
        for (int i = x - 6; i < x + 6; ++i) {
            Vc += (P.Matrice[y][i].Couleurs == T_Actu.Couleurs) ? 1 : 0;
            Vf += (P.Matrice[y][i].Forme == T_Actu.Forme) ? 1 : 0;
            Valid = ((Vc <= 6) && (Vf <= 6)) ? 1 : 0;

        }
        int Verif_Y(int j);{
            for (int j = y - 6; j < x + 6; ++j) {
                Vc += (P.Matrice[j][x].Couleurs == T_Actu.Couleurs) ? 1 : 0;
                Vf += (P.Matrice[j][x].Forme == T_Actu.Forme) ? 1 : 0;
                Valid = ((Vc <= 6) && (Vf <= 6)) ? 1 : 0;
            }
        }
    }
    return Valid;
} // Vérifie en ligne et en colonne les cases du plateau
void Comptage_Points(Tuile T_Actu,int NbTuilePoz,Plateau P,Joueur* pjoueur)
{
    int x = T_Actu.X;
    int y = T_Actu.Y;
    int cont_X = 0, cont_Y=0;
    for (int i = x-6; i <= x+6;i++) {
        if((P.Matrice[i][x].Couleurs==T_Actu.Couleurs)||(P.Matrice[i][x].Forme==T_Actu.Forme))
        {
            (*pjoueur).score +=NbTuilePoz;
            cont_X++;
        }
        else if (cont_X==6){
            (*pjoueur).score +=6;
        }

    }

    for (int j = y-6; j <= y+6; j++) {
        if((P.Matrice[y][j].Couleurs==T_Actu.Couleurs)||(P.Matrice[y][j].Forme==T_Actu.Forme))
        {
            (*pjoueur).score +=NbTuilePoz;
            cont_Y++;
        }
        else if (cont_Y==6){
            (*pjoueur).score  +=6;
        }

    }
} // De la meme manière que la verification compte les points totaux d'une action du joueur
void Afficher_Score(Partie P){
    for(int i=0;i<P.Nb_Joueur;i++){
        printf("Le score du joueur %d est: %d\n",(*P.pTab[i]).Num_J,(*P.pTab[i]).score);
    }
} // Affichage du score

// FONCTIONS TUILES

void Definition_P(Pioche* P, Partie* P1) {
    //Défini la taille de la pioche dans une structure Partie et son type de partie egalement
    printf("Choisissez un type de Partie : \n 1- Partie Normale (108 Tuiles) \n 2- Partie Degrade (36 Tuiles)");
    scanf("%d",P1->Type_Partie);
    // Alloue dynamiquement la pioche pour adapter la taille à sa partie
    while(((*P1).Type_Partie!=2)||((*P1).Type_Partie!=1)){
    switch ((*P1).Type_Partie) {
        case 1: {
            printf("Partie Normale\n");
            (*P).Stock = (Tuile *) malloc(Taille_N * sizeof(Tuile));
            (*P1).Taille = Taille_N;
            break;
        }
        case 2: {
            printf("Partie Dégradé\n");
            (*P).Stock = (Tuile *) malloc(Taille_D * sizeof(Tuile));
            (*P1).Taille = Taille_D;
            break;
        }
        default: {
            printf("Type de Partie Impossible : Non defini");
            scanf("%d",(*P1).Type_Partie);
            break;
        }
    }}
}   // Allocation dynamique de la pioche adapate au type de partie
Pioche Init_Pioche(Pioche P,Partie P1){
    int Taille, Coul_I=0;
    char Forme[6]={'C','E','L','X','R','F'};// defini les differentes formes possible
    char Couleur[6]={'R','Y','G','B','P','W'};//defini les differentes couleurs possible
    //Rempli la pioche de sa taille et toutes les 6 formes change de couleurs
    printf("Initialisation de la pioche...");
    for(int i=0;i<P1.Taille;i++){
        printf(".");
        P.Stock[i].Forme=Forme[i%6];
        if ((i%6==0)&&(i!=0)){
            Coul_I++;
            Coul_I=Coul_I%6;
        }
        P.Stock[i].Couleurs=Couleur[Coul_I];
        P.Stock[i].X='\0';
        P.Stock[i].Y='\0';
    }
    printf("Pioche initialisee\n");
    return P;
}      // Generation de Pioche
void Update_Pioche(Pioche* P, Partie P1){
    for(int i=0;i<P1.Taille;i++){
        if(((*P).Stock[i].Couleurs=='\0')||((*P).Stock[i].Forme=='\0')){
            for (int j=i;(((*P).Stock[j].Couleurs!='\0')||((*P).Stock[j].Forme!='\0'));j++){
                (*P).Stock[j]=(*P).Stock[j+1];}
        }
    }
    printf("Pioche mise a jour\n");
}    // Permet la mise à jour de la Pioche
Tuile Init_Tuile_Vide(){
    Tuile T;
    T.Forme='\0';
    T.Couleurs='\0';
    T.X='\0';
    T.Y='\0';
    return T;
}                     // Génère une case Vide

// FONCTIONS PLATEAU

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
}                      // Génération d'un Plateau à Case Vides
void Color(int couleurDuTexte,int couleurDeFond) {
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}// fonction d'affichage de couleurs
void Affiche_Tuile(Tuile T){
    switch(T.Couleurs){
        case 'R':{
            Color(4,0);
            printf('%c',T.Forme);
            break;
        }
        case 'Y':{Color(14,0);
            printf('%c',T.Forme);
            break;}
        case 'G':{Color(10,0);
            printf('%c',T.Forme);
            break;}
        case 'B':{Color(1,0);
            printf('%c',T.Forme);
            break;}
        case 'P':{Color(13,0);
            printf('%c',T.Forme);
            break;}
        case 'W':{Color(15,0);
            printf('%c',T.Forme);
            break;}
        default:{
            printf("_");
            break;
        }
    }

}                 // Affichage des tuiles dans leurs couleurs
void Affiche_Plateau(Plateau P){
    int i,j;
    printf("Affichage plateau\n");
    printf("  \t A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z\n");

    for(i=0;i<HAUTEUR;i++){
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
}             // Affichage du plateau

// FONCTIONS JOUEUR

void Pioche_Main(Joueur* J, Pioche* P1, Partie PP){
    srand(time(NULL));
    int Rand_Tuile, nbTuile_J, nbTuile_P, tentative=0;
    printf("Initialisation de la main...");
    for (int i=0; i<PP.Taille; i++){
        if((*P1).Stock!='\0'){
            nbTuile_P++;
        }
    }
    while(nbTuile_P!=0){
        for (int i=0; i<6; i++){
            printf("Tuile %d\t",i);
            if(((*J).Main[i].Couleurs=='\0')||((*J).Main[i].Forme=='\0')){//Prend les Tuiles vide de la main
                do{
                    do {
                        Rand_Tuile = rand();
                        Rand_Tuile = Rand_Tuile % PP.Taille;
                        tentative++;
                    }while((((*P1).Stock[Rand_Tuile].Forme=='\0')||((*P1).Stock[Rand_Tuile].Couleurs=='\0'))&&(nbTuile_J<=6)&&(tentative<PP.Taille));//verifie que la case choisi aléatoirement soit existante et non vide
                    (*J).Main[i] = P1->Stock[Rand_Tuile];
                    (*P1).Stock[Rand_Tuile] = Init_Tuile_Vide();
                    nbTuile_J+=1; // Compte le nombre de tuiles dans la main pour permettre au joueur d'avoir une main complete
                }while(nbTuile_J<6);}
        }
    }
    Update_Pioche(P1,PP);
} // Initialise la main en choisissant de manière aleatoire une tuile dans la pioche
void afficher_Main(Joueur J){
    printf("Pupitre de tuiles:\t");
    for (int i=0;i<6;i++){
        printf("Case %d",i);
        Affiche_Tuile(J.Main[i]);
        printf("\t");
    }
}                   // Affiche le pupitre du joueur
Joueur* TourJoueur(Joueur J1,Joueur J2,Joueur J3,Joueur J4,Partie* PP){
    Joueur* JQJ;
    int exit;
    int Num_J, Nb_J;
    Num_J=(*PP).Num_J_Actu;
    Nb_J=(*PP).Nb_Joueur;
    while (exit != 0) {
        (*PP).Num_J_Actu=(Num_J%Nb_J)+1;
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
    return JQJ;
} // Pointeur de joueur qui indique le tour de chacuns
void Tab_PointeurJ(Partie* P, Joueur J1,Joueur J2,Joueur J3,Joueur J4 ){
     int* poinTab={&J1, &J2, &J3, &J3};
     for (int i=0; i<4;i++){
         (*P).pTab[i]=poinTab[i];
     }
} // affecte l'adresse de chaque joueur dans la partie