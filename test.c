// THIS FILE IS PROPERTY OF ME, DO NOT!!!!! TOUCH
#include <stdio.h>
#include <stdbool.h>

#include <ncurses.h>
#include <stdlib.h>

/*/--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void printing()
{
  addstr("This was printed using addstr\n\n");
  refresh();

  addstr("The following letter was printed using addch:- ");
  addch('a');
  refresh();

  printw("\n\nThese numbers were printed using printw\n%d\n%f\n", 123, 456.789);
  refresh();
}

void moving_and_sleeping()
{
  int row = 5;
  int col = 0;

  curs_set(0);

  for (char c = 65; c <= 90; c++)
  {
    move(row++, col++);
    addch(c);
    refresh();
    napms(100);
  }

  row = 5;
  col = 3;

  for (char c = 97; c <= 122; c++)
  {
    mvaddch(row++, col++, c);
    refresh();
    napms(100);
  }

  curs_set(1);

  addch('\n');
}

void colouring()
{
  if (has_colors())
  {
    if (start_color() == OK)
    {
      init_pair(1, COLOR_YELLOW, COLOR_RED);
      init_pair(2, COLOR_GREEN, COLOR_GREEN);
      init_pair(3, COLOR_MAGENTA, COLOR_CYAN);

      attrset(COLOR_PAIR(1));
      addstr("Yellow and red\n\n");
      refresh();
      attroff(COLOR_PAIR(1));

      attrset(COLOR_PAIR(2) | A_BOLD);
      addstr("Green and green A_BOLD\n\n");
      refresh();
      attroff(COLOR_PAIR(2));
      attroff(A_BOLD);

      attrset(COLOR_PAIR(3));
      addstr("Magenta and cyan\n");
      refresh();
      attroff(COLOR_PAIR(3));
    }
    else
    {
      addstr("Cannot start colours\n");
      refresh();
    }
  }
  else
  {
    addstr("Not colour capable\n");
    refresh();
  }
}

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(void)
{
  initscr(); // sets up library and enters into ncurses environment
  cbreak();
  noecho();             // no buffering of keypresses, recommended to leave on
  keypad(stdscr, TRUE); // enables arrow keys, F-Keys and such within the program
  // getmaxxy();           // returns maximum screen dimensions

  addstr("-----------------\n| codedrome.com |\n| ncurses Demo  |\n-----------------\n\n");
  refresh(); // refreshes stdscr, the main window

  printing();

  void moving_and_sleeping();

  colouring();
  char in = 'l';
  while (in != 'e')
  {
    printw("press a key!");
    in = getch(); // catches user inputs
    printw("\n you pressed: ");
    addch(in); // returns user input
  }

  addstr("\npress any key to exit...");
  refresh();

  getch(); // catches user inputs

  endwin(); // shuts down ncurses

  return EXIT_SUCCESS;
}*/

#define ROWS 6
#define COLS 7
#define N 4

int check_concurrent_cells(int GBoard[ROWS][COLS], int n, int piece) // passes on board and position of playpiece on it, 1 = win
{                                                                    // important note: The playpiece MUST be at the end of a connect four in order to fulfill the criterion!
  int directions[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  //{x,y}; directions: right, left, down, up, right top, left top, right down, left down
  n = 4; // number of values to check; could be changed by function call in the future
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
  return 0; // no four in a row were found anywhere
}

/*
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
      r = false; // breaks for loopprintf("\n%i\n", ret);
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
*/
int main()
{
  int GBoard[ROWS][COLS] = {
      {1, 1, 1, 0, 1, 0, 0},
      {1, 0, 1, 1, 1, 0, 1},
      {1, 1, 0, 0, 1, 1, 0},
      {1, 0, 1, 0, 1, 1, 1},
      {0, 0, 1, 0, 0, 0, 1},
      {1, 0, 1, 1, 0, 1, 0}};

  int ret1 = check_concurrent_cells(*GBoard, 3, 1);
  printf("\n%i\n", ret1);

  // int ret = board_check_win(GBoard, 3, 2);
  // printf("\n%i\n", ret);

  return 0;
}
