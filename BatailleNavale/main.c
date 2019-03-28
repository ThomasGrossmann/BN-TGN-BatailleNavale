// Programme : BatailleNavale
// Auteur : Thomas Grossmann
// Date : 07.03.2019

#include <stdio.h>
#include <windows.h>

#define SIZE 4
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center

int model[SIZE][SIZE] = {
        {0, 0, 0, 0},
        {0, 2, 0, 3},
        {0, 2, 0, 3},
        {0, 0, 0, 3},

};

void topborder(int width) {
    printf("     ");
    for (int i = 0; i < width; i++) {
        printf("%c   ", 'A' + i);       // Lettres incrémentées
    }
    printf("\n");
    printf("   %c", STLC);       // ┌
    for (int row = 1; row < width; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);     // ┬
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, STRC);       // ┐
}

void verticalbars(int width, int row) {
    char TabCase = 'x';
    printf("%2d ", row + 1);    // Numéro de ligne
    for (int colonne = 0; colonne < width; colonne++) {
        TabCase = ' ';
        if(model[row][colonne] < 0){    // À l'eau
            TabCase = '.';
        }
        if(model[row][colonne] > 10){   // Touché
            TabCase = 'X';
        }
        if(model[row][colonne] > 20){   // Coulé
            TabCase = '/';
        }
        printf("%c %c ", SVSB, TabCase);     // │ + Modèle
    }
    printf("%c", SVSB);
}

void horizonbars(int width) {
    printf("\n   %c", SVLB);     // ├
    for (int row = 1; row < width; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SC);   // ┼
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, SVRB);   // ┤
}

void bottombars(int width) {
    printf("\n   %c", SBLC);     // └
    for (int row = 1; row < width; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);     // ┴
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SBRC);     // ┘
}

int grille(void) {
    SetConsoleOutputCP(65001);      // Pour les caractères accentués
    SetConsoleOutputCP(437);       // Pour les caractères semi-graphiques
    topborder(SIZE);        // Ligne du haut
    for (int row = 0; row < SIZE; row++) {
        if (row > 0) {
            horizonbars(SIZE);      // Ligne du milieu
        }
        verticalbars(SIZE, row);    // Ligne de barres verticales
    }
    bottombars(SIZE);       // Ligne du bas
}


int main(void) {
    int Choix;
    printf("\n---BIENVENUE DANS LA BATAILLE NAVALE---");
    printf("\n\nVeuillez choisir une option :");
    printf("\n1.Jouer\n\n2.Aide\n\n9.Quitter");
    scanf("%d", &Choix);


    switch (Choix) {
        case 1 :
            printf("\n\nLa seule grille disponible est la grille predefinie par le code.\n\n\n");
            char tir[5];
            grille();
            printf("       Tirez :");
            scanf("%s", &tir);
            int col = tir[0] - 49;
            int ligne = tir[1] - 65;
            break;
        case 2 :
            printf("\nLes regles du jeu sont simples. Vous et votre adversaire possedez des bateaux de tailles differentes que vous devez couler pour remporter la victoire.");
            printf("\nVous devez les placer sur une grille de maniere strategique afin que votre adversaire ne puisse pas couler vos bateaux.");
            printf("\nUne fois vos bateaux places, la partie peut commencer.");
            printf("\nVous devrez choisir un endroit ou tirer en choisissant une case.");
            printf("\nExemple : vous choississez de tirer sur la case B5, vous entrerez donc : B5");
            printf("\nUne fois que vous aurez tirer 2 a 3 cas s'offrent a vous. Soit votre tir en tombe a l'eau soit il a touche sa cible.");
            printf("\nSi vous avez rater votre tir le message, A l'eau s'affiche. Dans le cas contraire Toucher ! s'affiche");
        default :
            break;
    }
    return 0;
}