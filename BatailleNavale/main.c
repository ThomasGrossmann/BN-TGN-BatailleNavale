//Programme : BatailleNavale
//Auteur : Thomas Grossmann
//Date : 07.03.2019
#include <stdio.h>
#include <windows.h>

#define SIZE 6
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
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center
void topborder(int width)
{
    printf("   %c",STLC);      //Coin haut gauche
    for (int row = 1; row < SIZE; row++)
    {
        printf("%c%c%c%c",SHSB,SHSB,SHSB,SHTB);
    }
    printf("%c%c%c%c\n",SHSB,SHSB,SHSB,STRC); //Coin haut droite
}
void verticalbars(int width, int row)
{
    printf(" %d ", row+1);    //Numéro de ligne
    for (int ligne = 1; ligne < SIZE+2; ligne++)
    {
        printf("%c   ",SVSB);
    }
}
void horizonbars(int width)
{
    printf("\n   %c",SVLB);
    for (int row = 1; row < SIZE; row++)
    {
        printf("%c%c%c%c",SHSB,SHSB,SHSB,SC);
    }
    printf("%c%c%c%c\n",SHSB,SHSB,SHSB,SVRB);
}
void bottombars(int width)
{
    printf("\n   %c",SBLC);
    for (int row = 1; row < SIZE; row++)
    {
        printf("%c%c%c%c",SHSB,SHSB,SHSB,SHBB);
    }
    printf("%c%c%c%c",SHSB,SHSB,SHSB,SBRC);
}
int grille(void)
{
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters
    topborder(SIZE);
    for (int row = 0; row < SIZE; row++)
    {
        if (row > 0)
        {
            horizonbars(SIZE);
        }
        verticalbars(SIZE, row);
    }
    bottombars(SIZE);
}


int main(void) {
    int Choix;

    printf("\n---BIENVENUE DANS LA BATAILLE NAVALE---");
    printf("\n\nVeuillez choisir une option :");
    printf("\n1.Jouer\n2.Aide\n9.Quitter");
    scanf("%d", &Choix);

    //POUR LE MOMENT SEUL L'AFFICHAGE DE L'AIDE EST DISPONIBLE !!

    switch (Choix) {
        case 1 :
            for(int i=0; i < SIZE; i++)
            {
                
            }
            grille();
            break;
        case 2 :
            printf("\nLes regles du jeu sont simples. Vous et votre adversaire possedez des bateaux de tailles differentes que vous devez couler pour remporter la victoire.");
            printf("\nVous devez les placer sur une grille de maniere strategique afin que votre adversaire ne puisse pas couler vos bateaux.");
            printf("\nUne fois vos bateaux places, la partie peut commencer.");
            printf("\nVous devrez choisir un endroit ou tirer en choississant une case.");
            printf("\nExemple : vous choississez de tirer sur la case B5, vous entrerez donc : B5");
            printf("\nRien de plus facile n'est-ce pas ?");
            printf("\nUne fois que vous aurez tirer 2 a 3 cas s'offrent a vous. Soit votre tir en tombe a l'eau soit il a touche sa cible.");
            printf("\nSi vous avez rater votre tir le message, A l'eau s'affiche. Dans le cas contraire Toucher ! s'affiche");
            break;
        default :
            break;
    }
    return 0;
}