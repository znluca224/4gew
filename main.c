#include <stdio.h>
#include "game.h"
// #include "printboard.h"

int main(void)
{
    // this is the game board
    int gameBoard[ROWS][COLUMNS];

    int currentPlayer = 1;

    int chosenColumn;

    int winner = 0; // neither player is number 0 -> no winner

    setupBoard(gameBoard);

    while (1)
    { // while true
        printBoard(gameBoard);

        // Current player
        printf("Spieler %d ist am Zug.\n", currentPlayer);

        // where does the player want their playpiece
        printf("Bitte Spalte wählen (1-%d): ", COLUMNS);

        // If the chosen column is not empty, a value of one will be returned

        //---------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------
        if (scanf("%d", &chosenColumn) != 1)
        {
            // kann man das vereinfachen?
            //---------------------------------------------------------------------------------------
            //---------------------------------------------------------------------------------------
            printf("Ungueltige Eingabe. Programm wird beendet.\n");
            return 0;
        }

        // decrementing row number to account for difference in human and computer counting
        chosenColumn -= 1;

        // no piece placed
        if (!dropAPiece(gameBoard, chosenColumn, currentPlayer))
        {
            printf("Ungueltiger Zug! Spalte existiert nicht oder ist voll.\n");
            continue;
        }

        // Four pieces in a row -> current player has won and game is stopped
        if (checkVictory(gameBoard, currentPlayer))
        {
            winner = currentPlayer;
            break;
        }

        // full board stops game
        if (checkBoard(gameBoard))
        {
            break;
        }

        // Switch between players: 3-1 --> player 2.  --> 3-2 --> player 1
        currentPlayer = 3 - currentPlayer;
    }

    printBoard(gameBoard);

    // if there is a winner, they will be pronounced so
    if (winner != 0)
    {
        printf("Spieler %d hat gewonnen! Herzlichen Glühstrumpf!\n", winner);
    }
    else // draw
    {
        printf("Unentschieden! Das Brett ist voll.\n");
    }

    return 0;
}
