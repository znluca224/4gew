#include "header.h"

void clearBoard(int[][] GBoard) // creates the board and fills it with empty objects
{
  for (int i = 0; i < length(GBoard); i++)
  {
    for (int j = 0; j < length(GBoard[0]); j++)
    {
      GBoard[i][j] = 0;
    }
  }
}

void printBoard(int[][] GBoard) // prints board onto console
{
  for (int i = 0; i < length(GBoard); i++)
  {
    for (int j = 0; j < length(GBoard[0]); j++)
    {
      if (GBoard[i][j] == 0)
      {
        continue;
      }
      else if (GBoard[i][j] == 1)
      {
        printf("%c", playerpiece1);
      }
      else if (GBoard[i][j] == 2)
      {
        printf("%c", playerpiece2);
      }
      printf("|");
    }
    printf("\n------------------------------------------------\n"); // prints new line, filled with dashes
  }
}
