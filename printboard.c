#include <stdio.h>
#include "game.h"
//#include "printboard.h"

// Ausgabe des Boards 
void printBoard(int board[ROWS][COLUMNS]) 
{
    // Beginn mit Absatz
    printf("\n");

    /*
    for (int r = 0; r < ROWS; r++) {
        printf("|");
        for (int c = 0; c < COLUMNS; c++) 
        {
            // Deklaration des jeweiligen Symbols als Space 
            // char symbol = ' ';

            if (board[r][c] == 1) // Spieler 1 setzt ein X
            {
                //symbol = 'X';
                printf("\x1b[31m X\x1b[0m");
            } else if (board[r][c] == 2) // Spieler 2 setzt ein O
            {
                //symbol = 'O';
                printf("\x1b[33m O\x1b[0m");
            }

            // Ausgabe des Symbols
            //printf(" %c |", symbol);
            printf("   |");
        }

        // Absatz
        printf("\n");
    }
        */

    for (int r = 0; r < ROWS; r++) 
    {
        printf("|");
        
        for (int c = 0; c < COLUMNS; c++) 
        {
            char symbol = ' ';
            const char* color = "\x1b[0m";   // Standardfarbe (weiß)

            if (board[r][c] == 1) {
                symbol = 'X';
                color = "\x1b[31m"; // Rot
            }
            else if (board[r][c] == 2) {
                symbol = 'O';
                color = "\x1b[33m"; // Gelb
            }

            // Immer exakt gleich breiter Ausdruck:
            printf(" %s%c\x1b[0m |", color, symbol);
        }
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
