#include "header.h"
#include <stdbool.h>

int drop_piece(Board *b, int col, char piece) // col: 0-basiert, Rückgabe: Zeile oder -1
{
}
int board_is_full(const Board *b)
{
}
int board_check_win(int GBoard[ROWS][COLS], int x, int y) // 1 = win
{                                                         // passes on board and position of playpiece on it
  int player = GBoard[x][y];
  bool r = true; // right
  bool l = true; // left
  bool t = true; // top
  bool b = true; // bottom
  bool tr = true;
  bool br = true;
  bool bl = true;
  bool tl = true;
  for (int i = x; i < 4; i++)
  {
    // delta-x only
    if (!r || GBoard[x + i][y] != player) // checks board going to right
    {
      r = false; // breaks for loop
    }
    if (!l || GBoard[x - i][y] != player) // checks board going to right
    {
      l = false; // breaks for loop
    }
    for (int j = y; j < 4; j++)
    {
      // delta-y only
      if (!t || GBoard[x][y + j] != player)
      {
        t = false;
      }
      if (!b || GBoard[x][y - j] != player)
      {
        b = false;
      }

      // delta y AND x
      if (!tr || GBoard[x + i][y + j] != player)
      {
        tr = false;
      }
      if (!br || GBoard[x + i][y - j] != player)
      {
        br = false;
      }
      if (!tl || GBoard[x - i][y + j] != player)
      {
        tl = false;
      }
      if (!bl || GBoard[x - i][y - j] != player)
      {
        bl = false;
      }
    }
  }
  if (r || l || b || t || br || bl || tr || tl)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}