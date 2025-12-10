#ifndef BOARD_H
#define BOARD_H

#define ROWS 6
#define COLS 7

//---------------------------------------------------------------------------------
// global variables
//---------------------------------------------------------------------------------
// player pieces
int playerpiece1 = 79; // O
int playerpiece2 = 88; // X
// other
int moves = 0; // moves made (pices put onto board)

typedef struct
{
    char cells[ROWS][COLS]; // ' 'leeres Feld, 'X' Spieler 1 oder 'O' Spieler 2
} Board;

void clearBoard(int GBoard[ROWS][COLS]);
void printBoard(int GBoard[ROWS][COLS]); // prints board onto console
int drop_piece(int GBoard[ROWS][COLS], int col, char piece);

#endif
