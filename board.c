#include "header.h"
#include <string.h>

void board_init(Board *b)
{
    b->rows = BOARD_ROWS;
    b->cols = BOARD_COLS;
    for (int r = 0; r < BOARD_ROWS; ++r)
    {
        for (int c = 0; c < BOARD_COLS; ++c)
        {
            b->cells[r][c] = CELL_EMPTY;
        }
    }
}

void board_clear(Board *b)
{
    for (int r = 0; r < b->rows; ++r)
    {
        for (int c = 0; c < b->cols; ++c)
        {
            b->cells[r][c] = CELL_EMPTY;
        }
    }
}

bool board_is_full(const Board *b)
{
    for (int c = 0; c < b->cols; ++c)
    {
        if (b->cells[0][c] == CELL_EMPTY)
            return false;
    }
    return true;
}

bool board_can_drop(const Board *b, int col)
{
    if (col < 0 || col >= b->cols)
        return false;
    return b->cells[0][col] == CELL_EMPTY;
}

int board_drop(Board *b, int col, Cell player)
{
    if (!board_can_drop(b, col))
        return -1;
    for (int r = b->rows - 1; r >= 0; --r)
    {
        if (b->cells[r][col] == CELL_EMPTY)
        {
            b->cells[r][col] = player;
            return r;
        }
    }
    return -1;
}

Cell board_get(const Board *b, int row, int col)
{
    if (row < 0 || row >= b->rows || col < 0 || col >= b->cols)
        return CELL_EMPTY;
    return b->cells[row][col];
}
