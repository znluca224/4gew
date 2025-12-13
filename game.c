// # include <stdio.h>
# include "game.h"

// Setup der Board-Matrix 
void setupBoard(int gameBoard[ROWS][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            gameBoard[i][j] = 0; // Hintergrundmatrix wird zu Spielbeginn mit Nullen gefüllt
        }
    }
}

// Spielstein fallen lassen
int dropAPiece(int gameBoard[ROWS][COLUMNS], int chosenColumn, int player)
{
    // Wenn die ausgewählte Zeile unter 0 liegt oder größer als 6 ist, wird die Eingabe ungültig
    if (0 > chosenColumn || chosenColumn >= COLUMNS)
    {
        return 0;
    }

    for (int rowToBeChecked = ROWS - 1; rowToBeChecked >= 0; --rowToBeChecked)
    {
        // Überprüfen der der Spalten auf eine freie Kachel, Die freie Kachel der ausgewählten Spalte wird mit player belegt
        if (gameBoard[rowToBeChecked][chosenColumn] == 0)
        {
            gameBoard[rowToBeChecked][chosenColumn] = player;
            return 1;
        }
    }
    return 0;
}

int checkVictory(int gameBoard[ROWS][COLUMNS], int player)
{
    // Überprüfung von verschiedenen Fällen 
    // 1. vertikale Überprüfung
    // 2. horizontale Überprüfung
    // 3. Diagonale von NW nach SO
    // 4. Diagonale von SW nach NO

    // 1. Vertikal
    for (int c = 0; c < COLUMNS; c++)
    {
        for (int r = 0; r <= ROWS-4; r++)
        {
            if ((gameBoard[r][c] == player) && (gameBoard[r+1][c] == player) && (gameBoard[r+2][c] == player) && (gameBoard[r+3][c] == player))
            {
                return 1;
            }
        }
    }

    // 2. Horizontal
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c <= COLUMNS-4; c++)
        {
            if ((gameBoard[r][c] == player) && (gameBoard[r][c+1] == player) && (gameBoard[r][c+2] == player) && (gameBoard[r][c+3] == player))
            {
                return 1;
            }
        }
    }

    // 3. diagonal von NW nach SE
    for (int r = 0; r <= ROWS-4; r++)
    {
        for (int c = 0; c <= COLUMNS-4; c++)
        {
            if ((gameBoard[r][c] == player) && (gameBoard[r+1][c+1] == player) && (gameBoard[r+2][c+2] == player) && (gameBoard[r+3][c+3] == player))
            {
                return 1;
            }
        }
    }

    // 4. diagonal von SE nach NO
    for (int r = 3; r < ROWS; r++)
    {
        for (int c = 0; c <= COLUMNS-4; c++)
        {
            if ((gameBoard[r][c] == player) && (gameBoard[r-1][c+1] == player) && (gameBoard[r-2][c+2] == player) && (gameBoard[r-3][c+3] == player))
            {
                return 1;
            }
        }
    }
    return 0;
}

// Überprüfung ob das Board voll ist
int checkBoard(int gameBoard[ROWS][COLUMNS])
{
    for (int c = 0; c < COLUMNS; c++)
    {
        if (gameBoard[0][c] == 0)
        {
            return 0;
        }
    }
    return 1;
}
