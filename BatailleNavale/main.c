//Programme : BatailleNavale
//Auteur : Thomas Grossmann
//Date : 07.03.2019
#include <stdio.h>

int main() {
    int Choix;

    printf("\n---BIENVENUE DANS LA BATAILLE NAVALE---");
    printf("\n\nVeuillez choisir une option :");
    printf("\n1.Jouer\n2.Aide\n9.Quitter");
    scanf("%d", &Choix);

    //POUR LE MOMENT SEUL L'AFFICHAGE DE L'AIDE EST DISPONIBLE !!

    switch (Choix) {
        case 1 :
            printf("Pas encore implementer.");
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