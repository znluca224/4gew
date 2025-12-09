#include "header.h"
#include <stdbool.h>
#include <ncurses.h>

int drop_piece(Board *b, int col, char piece) // col: 0-basiert, Rückgabe: Zeile oder -1
{
}
int board_is_full(const Board *b)
{
}
int board_check_win(int GBoard[ROWS][COLS], int x, int y) // 1 = win
{                                                         // passes on board and position of playpiece on it
  int directions[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  // right, left, down, up, right top, left top, right down, left down
  int n = 4; // number of values to check
  if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
  {
    return 0; // invalid coordinates, should never trigger
  }

  for (int k = 0; k < 8; k++)
  {
    int count = 1;
    int initval = GBoard[x][y];
    int x2 = x + directions[k][0];
    int y2 = y + directions[k][1];

    while (x2 >= 0 && x2 < ROWS && y2 >= 0 && y2 < COLS && GBoard[x2][y2] == initval)
    {
      count++;
      x2 += directions[k][0];
      y2 += directions[k][1];
    }

    if (count == n)
    {
      return 1;
    }
    else
      return 0;
  }
}