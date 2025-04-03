// Florian Lavigne Chappaz

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction d'affichage de la grille
int displayGrid(char grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("%c|%c|%c\n", grid[i][0], grid[i][1], grid[i][2]);
    }
    return 0;
}

int main()
{
    // Grille du morpion
    char grid[3][3] =
        {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

    // Booléens pour gérer le tour actuel et la victoire
    bool turnO = true;
    bool win = false;

    printf("<---------- Jeu du Morpion ----------> \n");
    while (1)
    {
        int horizontal;
        int vertical;

        displayGrid(grid);

        // Choix de la ligne verticale + vérification de la valeur entrée
        printf("\nligne vertical : ");
        scanf("%d", &vertical);
        while (vertical > 2 || vertical < 0)
        {
            printf("\nligne invalide, entrez une autre ligne : ");
            scanf("%d", &vertical);
        }
        
        // Choix de la ligne horizontale + vérification de la valeur entrée
        printf("\nligne horizontal : ");
        scanf("%d", &horizontal);
        while (horizontal > 2 || horizontal < 0)
        {
            printf("\nligne invalide, entrez une autre ligne : ");
            scanf("%d", &horizontal);
        }

        // Ternaire pour définir le tour actuel
        grid[vertical][horizontal] = turnO ? 'O' : 'X';
        turnO = !turnO;
        
        for (int i = 0; i < 3; i++)
        {
            // Vérification de victoire (ligne verticale)
            if (grid[i][0] == 'O' && grid[i][1] == 'O' && grid[i][2] == 'O' || grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X')
            {
                displayGrid(grid);
                printf("\nPartie terminée !");
                win = true;
            }

            // Vérification de victoire (ligne horizontale)
            if (grid[0][i] == 'O' && grid[1][i] == 'O' && grid[2][i] == 'O' || grid[0][i] == 'X' && grid[1][i] == 'X' && grid[2][i] == 'X')
            {
                displayGrid(grid);
                printf("\nPartie terminée !");
                win = true;
            }

            // Vérification de victoire (Diagonales - symbole 'O')
            if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O' || grid[0][2] == 'O' && grid[1][1] == '0' && grid[2][0] == '0')
            {
                displayGrid(grid);
                printf("\nPartie terminée !");
                win = true;
            }

            // Vérification de victoire (Diagonales - symbole 'X')
            if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X' || grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')
            {
                displayGrid(grid);
                printf("\nPartie terminée !");
                win = true;
            }
        }

        // Condition d'arrêt de la partie si quelqu'un a gagné
        if (win == true)
        {
            break;
        };
    }

    return 0;
}