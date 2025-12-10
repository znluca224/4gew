#include "header.h"

static bool in_bounds(const Board *b, int r, int c)
{
    return r >= 0 && r < b->rows && c >= 0 && c < b->cols;
}

void game_init(Game *g)
{
    board_init(&g->board);
    g->current_player = CELL_P1;
    g->game_over = false;
    g->winner = CELL_EMPTY;
}

bool game_check_line(const Board *b, int r0, int c0, int dr, int dc, Cell player)
{
    int count = 0;
    int r = r0, c = c0;

    // Walk backward
    while (in_bounds(b, r - dr, c - dc) && board_get(b, r - dr, c - dc) == player)
    {
        r -= dr;
        c -= dc;
    }
    // Walk forward and count
    while (in_bounds(b, r, c) && board_get(b, r, c) == player)
    {
        count++;
        r += dr;
        c += dc;
    }
    return count >= 4;
}

bool game_check_win(const Board *b, int last_row, int last_col, Cell player)
{
    if (player == CELL_EMPTY || last_row < 0 || last_col < 0)
        return false;
    return game_check_line(b, last_row, last_col, 0, 1, player) || // horizontal
           game_check_line(b, last_row, last_col, 1, 0, player) || // vertical
           game_check_line(b, last_row, last_col, 1, 1, player) || // diag down-right
           game_check_line(b, last_row, last_col, 1, -1, player);  // diag down-left
}

bool game_check_draw(const Board *b)
{
    return board_is_full(b);
}

bool game_make_move(Game *g, int col)
{
    if (g->game_over)
        return false;
    int row = board_drop(&g->board, col, g->current_player);
    if (row < 0)
        return false;

    if (game_check_win(&g->board, row, col, g->current_player))
    {
        g->game_over = true;
        g->winner = g->current_player;
    }
    else if (game_check_draw(&g->board))
    {
        g->game_over = true;
        g->winner = CELL_EMPTY;
    }
    else
    {
        g->current_player = (g->current_player == CELL_P1) ? CELL_P2 : CELL_P1;
    }
    return true;
}
