#include "header.h"
// #include <ncurses.h>

int drop_piece(int GBoard[ROWS][COLS], int col, char piece) // col: 0-based, return is row or -1, if row is full
{
  if (GBoard[ROWS][col] != 0)
  {
    return -1; // row is full, no piece can be put here
  }
  else
  {
    int curry = 0;                    // current spot is the very top one in the row
    while (GBoard[curry++][col] == 0) // is the spot in the row below empty?????????
    {
      curry += curry; // current row goes one lower
    }
    GBoard[curry][col] = piece;
    return curry;
  }
}

int board_is_full(const Board *b)
{
  if (moves == ROWS * COLS)
  {
    return 1;
  }
  else
    return 0;
}

<<<<<<< HEAD
/*int board_check_win(int GBoard[ROWS][COLS], int n, char piece)                                   passes on board and position of playpiece on it, 1 = win
{                                                                                                important note: The playpiece MUST be at the end of a connect four in order to fulfill the criterion!
  int directions[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; {x,y}; directions: right, left, down, up, right top, left top, right down, left down
  n = 4;                                                                                         number of values to check; could be changed by function call in the future
=======
int board_check_win(int GBoard[ROWS][COLS], int n, int piece) // passes on board and position of playpiece on it, 1 = win
{                                                             // important note: The playpiece MUST be at the end of a connect four in order to fulfill the criterion!
  int directions[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  //{x,y}; directions: right, left, down, up, right top, left top, right down, left down
  n = 4; // number of values to check; could be changed by function call in the future
>>>>>>> 97b9625f3aab98e0fe4a0c53a4ceefded0cca5de
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (GBoard[i][j] != piece)
        continue; // skip cells that are not the playpiece

      for (int k = 0; k < 8; k++)
      {
        int count = 1;
        int initval = piece;
        int x2 = i + directions[k][0];
        int y2 = j + directions[k][1];

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
      }
    }
  }
<<<<<<< HEAD
}
*/
=======
  return 0; // no four in a row were found anywhere
}
>>>>>>> 97b9625f3aab98e0fe4a0c53a4ceefded0cca5de
