#ifndef GAME_HEADER_H
#define GAME_HEADER_H

#include <stdbool.h>

#define BOARD_COLS 7
#define BOARD_ROWS 6

#include <time.h>
#define INNITIME time(NULL);

typedef enum
{
    CELL_EMPTY = 0,
    CELL_P1 = 1,
    CELL_P2 = 2
} Cell;

typedef struct
{
    int rows;
    int cols;
    Cell cells[BOARD_ROWS][BOARD_COLS];
} Board;

// board.c
void board_init(Board *b);
bool board_is_full(const Board *b);
bool board_can_drop(const Board *b, int col);
int board_drop(Board *b, int col, Cell player); // returns row index or -1
Cell board_get(const Board *b, int row, int col);
void board_clear(Board *b);

// game.c
typedef struct
{
    Board board;
    Cell current_player;
    bool game_over;
    Cell winner;
} Game;

void game_init(Game *g);
bool game_make_move(Game *g, int col); // true if move made
bool game_check_win(const Board *b, int last_row, int last_col, Cell player);
bool game_check_draw(const Board *b);

// ui.c (ncurses)
void ui_init(void);
void ui_shutdown(void);
void ui_draw(const Game *g, int cursor_col);
void ui_show_message(const char *msg);
int ui_get_input(void); // returns key code

#endif // GAME_HEADER_H
