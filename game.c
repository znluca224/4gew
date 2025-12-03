#include "header.h"

int drop_piece(Board *b, int col, char piece); // col: 0-basiert, Rückgabe: Zeile oder -1
int board_is_full(const Board *b);
int board_check_win(const Board *b, char piece); // 1 = gewonnen, 0 = noch nicht