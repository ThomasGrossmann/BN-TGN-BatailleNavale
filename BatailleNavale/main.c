// Programme : BatailleNavale
// Auteur : Thomas Grossmann
// Date : 07.04.2019

#include <stdio.h>
#include <windows.h>

#define SIZE 8
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
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 3, 0, 0, 0, 0},
        {0, 2, 0, 3, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 4, 4, 4, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
};

int Coule[5];
char tir[5];

void coule(int x, int y) {                  // Fonction pour couler les bateaux
    for (int i = 1; i <= 4; i++) {
        if (Coule[i] == i) {
            for (int s = 0; s < 9; s++) {
                for (int u = 0; u < 9; u++) {
                    if (model[x][y] >= 10 + i) {
                        model[x][y] += 10;
                    }
                }
            }
        }
    }
}

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
    char Case = 'x';
    printf("%2d ", row + 1);    // Numéro de ligne
    for (int colonne = 0; colonne < width; colonne++) {
        Case = ' ';
        coule(row, colonne);
        if (model[row][colonne] < 0) {    // À l'eau
            Case = '~';
        }
        if (model[row][colonne] > 10) {   // Touché
            Case = 'X';
        }
        if (model[row][colonne] > 20) {   // Coulé
            Case = '/';
        }
        printf("%c %c ", SVSB, Case);     // │ + Modèle
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
    printf("\n");
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

void Partie() {
    int liste_bat[3] = {0,0,0};         // Liste des bateaux pour pouvoir les couler
    int gameover = 0;
    do {
        printf("\n");
        grille();
        printf("       Tirez :");
        scanf("%s", tir);
        int col = tir[0] - 65;          // Variable pour définir la colonne de la grille
        int ligne = tir[1] - 49;        // Variable pour définir la ligne de la grille
        printf("\nVous avez tirer en %d %d\n", col, ligne);
        system("cls");
        if (model[ligne][col] == 0) {
            model[ligne][col] = -1;
            printf("\nA l'eau !\n");
        } else if (model[ligne][col] > 0 && model[ligne][col] < 10) {
            Coule[model[ligne][col]] += 1;
            model[ligne][col] += 10;
            printf("Toucher\n");
            if(model[ligne][col] == 12){
                liste_bat[0]++;
                if(liste_bat[0] == 2){                  // Couler le bateau de 2 de long
                    printf("couler !\n");
                    gameover++;
                }
            }
            if(model[ligne][col] == 13){
                liste_bat[1]++;
                if(liste_bat[1] == 3){                  // Couler le bateau de 3 de long
                    printf("couler !\n");
                    gameover++;
                }
            }
            if(model[ligne][col] == 14){
                liste_bat[2]++;
                if(liste_bat[2] == 4){                  // Couler le bateau de 4 de long
                    printf("couler !\n");
                    gameover++;
                }
            }
        } else if (model[ligne][col] > 10 || model[ligne][col] == -1) {         // Si déjà tirer dans la case
            printf("\nVous avez deja tirer dans cette case !\n");
        }
        if (gameover == 3) {        // Victoire
            system("cls");
            printf("\n\nVOUS AVEZ GAGNER BRAVO !\n");
            system("pause");
        }
    } while (gameover != 3);
}

int main(void) {
    int Choix;

    while (1) {
        printf("\n---BIENVENUE DANS LA BATAILLE NAVALE---");
        printf("\n\nVeuillez choisir une option :\n");
        printf("\n1.Jouer\n\n2.Aide\n\n9.Quitter");         // Menu principal
        scanf("\n%d", &Choix);

        switch (Choix) {
            case 1 :
                Partie();
                return 0;
            case 2 :
                printf("\nLes regles du jeu sont simples. Vous et votre adversaire possedez des bateaux de tailles differentes que vous devez couler pour remporter la victoire.");
                printf("\nVous devrez choisir un endroit ou tirer en choisissant une case.");
                printf("\nExemple : vous choississez de tirer sur la case B5, vous entrerez donc : B5");
                printf("\nUne fois que vous aurez tirer 2 a 3 cas s'offrent a vous. Soit votre tir est tomber a l'eau soit il a toucher sa cible.");
                printf("\nSi vous avez rater votre tir le message, 'A l'eau' s'affiche. Dans le cas contraire 'Toucher' ! s'affiche.");
                printf("\nDes que vous aurez toucher toutes les parties d'un bateau, 'Couler !' s'affiche.\n");
                break;
            case 9 :
                return 0;
            default:
                printf("\nChoisissez un chiffre correct !\n");
                break;
        }
    }
}
