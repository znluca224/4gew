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

void printBoard(int[][] GBoard, char piece1, char piece2) // prints board onto console
{
  for (int i = 0; i < length(GBoard); i++)
  {
    for (int j = 0; j < length(GBoard[0]); j++)
    {
      if (GBoard[i][j] == 0) // empty cell
      {
        continue;
      }
      else if (GBoard[i][j] == 1) // piece of player one is there
      {
        printf("%c", piece1);
      }
      else if (GBoard[i][j] == 2) // piece of player two is there
      {
        printf("%c", piece2);
      }
      printf("|"); // divider between pieces for the full table
    }
    printf("\n------------------------------------------------\n"); // prints new line, filled with dashes
  }
}
