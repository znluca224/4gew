#include "header.h"

void clearBoard(int GBoard[ROWS][COLS])
{                                          // array MUST be passed as pointer
  for (int i = 0; i < length(GBoard); i++) // rows
  {
    for (int j = 0; j < length(GBoard[0]); j++) // columns
    {
      GBoard[i][j] = 0;
    }
  }
}

void printBoard(int GBoard[ROWS][COLS]) // prints board onto console
{
  for (int i = 0; i < length(GBoard); i++)
  {
    for (int j = 0; j < length(GBoard[0]); j++)
    {
      if (GBoard[i][j] == 0) // leeres Feld
      {
        continue;
      }
      else if (GBoard[i][j] == 1) // playpiece of Player 2 at this position
      {
        printf("%c", playerpiece1);
      }
      else if (GBoard[i][j] == 2) // playpiece of Player 2 at this position
      {
        printf("%c", playerpiece2);
      }
      printf("|"); // spacer between the individual playpieces
    }
    printf("\n------------------------------------------------\n"); // prints new line, filled with dashes, after the previous line has finished printing
  }
}
