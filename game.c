// # include <stdio.h>
#include "game.h"

// Setup of GBoard
void setupBoard(int gameBoard[ROWS][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            gameBoard[i][j] = 0; // fills every spot with zeros
        }
    }
}

int dropAPiece(int gameBoard[ROWS][COLUMNS], int chosenColumn, int player)
{
    // if the selected row is <0 or >Columns, the function stops
    if (0 > chosenColumn || chosenColumn >= COLUMNS)
    {
        return 0;
    }

    for (int rowToBeChecked = ROWS - 1; rowToBeChecked >= 0; --rowToBeChecked)
    {
        // putting the piece onto the lowest possible row
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
    // directions
    // 1. vertical
    // 2. horizontal
    // 3. diagonal from top right to bottom left
    // 4. diagonal from bottom right to top left

    // 1. vertical
    for (int c = 0; c < COLUMNS; c++)
    {
        for (int r = 0; r <= ROWS - 4; r++)
        {
            if ((gameBoard[r][c] == player) && (gameBoard[r + 1][c] == player) && (gameBoard[r + 2][c] == player) && (gameBoard[r + 3][c] == player))
            {
                return 1;
            }
        }
    }

    // 2. horizontal
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c <= COLUMNS - 4; c++)
        {
            if ((gameBoard[r][c] == player) && (gameBoard[r][c + 1] == player) && (gameBoard[r][c + 2] == player) && (gameBoard[r][c + 3] == player))
            {
                return 1;
            }
        }
    }

    // 3. diagonal from top right to bottom left
    for (int r = 0; r <= ROWS - 4; r++)
    {
        for (int c = 0; c <= COLUMNS - 4; c++)
        {
            if ((gameBoard[r][c] == player) && (gameBoard[r + 1][c + 1] == player) && (gameBoard[r + 2][c + 2] == player) && (gameBoard[r + 3][c + 3] == player))
            {
                return 1;
            }
        }
    }

    // 4. diagonal from bottom right to top left
    for (int r = 3; r < ROWS; r++)
    {
        for (int c = 0; c <= COLUMNS - 4; c++)
        {
            if ((gameBoard[r][c] == player) && (gameBoard[r - 1][c + 1] == player) && (gameBoard[r - 2][c + 2] == player) && (gameBoard[r - 3][c + 3] == player))
            {
                return 1;
            }
        }
    }
    return 0;
}

// is the board full?
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
