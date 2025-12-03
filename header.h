#ifndef BOARD_H
#define BOARD_H

#define ROWS 6
#define COLS 7

typedef struct
{
    char cells[ROWS][COLS]; // ' 'leeres Feld, 'X' Spieler 1 oder 'O' Spieler 2
} Board;

void clearBoard(int[][] GBoard);
void printBoard(int[][] GBoard, char piece1, char piece2);
int board_drop_piece(Board *b, int col, char piece); // col: 0-basiert, Rückgabe: Zeile oder -1
int board_is_full(const Board *b);
int board_check_win(const Board *b, char piece); // 1 = gewonnen, 0 = noch nicht

#endif
