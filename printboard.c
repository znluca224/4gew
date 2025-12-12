#include <stdio.h>
#include "game.h"
//#include "printboard.h"

// Ausgabe des Boards 
void printBoard(int board[ROWS][COLUMNS]) 
{
    // Beginn mit Absatz
    printf("\n");

    for (int r = 0; r < ROWS; r++) {
        printf("|");
        for (int c = 0; c < COLUMNS; c++) 
        {
            // Deklaration des jeweiligen Symbols als Space 
            char symbol = ' ';

            if (board[r][c] == 1) // Spieler 1 setzt ein X
            {
                symbol = 'X';
            } else if (board[r][c] == 2) // Spieler 2 setzt ein O
            {
                symbol = 'O';
            }

            // Ausgabe des Symbols
            printf(" %c |", symbol);
        }

        // Absatz
        printf("\n");
    }

    // Drucken von Linien zum Trennen der Zeilen 
    for (int c = 0; c < COLUMNS; c++) 
    {
        printf("----");
    }
    printf("-\n");

    printf(" ");
    // Ausgeben der Spalten
    for (int c = 0; c < COLUMNS; c++) 
    {
        printf(" %d  ", c + 1);
    }
    printf("\n\n");
}
