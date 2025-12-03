#ifndef BOARD_H
#define BOARD_H

#define ROWS 6
#define COLS 7

typedef struct {
    char cells[ROWS][COLS];  // ' ', 'X' oder 'O'
} Board;

void board_init(Board *b);
void board_print(const Board *b);
int  board_drop_piece(Board *b, int col, char piece); // col: 0-basiert, Rückgabe: Zeile oder -1
int  board_is_full(const Board *b);
int  board_check_win(const Board *b, char piece);     // 1 = gewonnen, 0 = noch nicht

#endif
