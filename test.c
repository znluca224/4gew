// Create a Car class with some attributes
typedef struct // definition of a new type, which is a structure
{              // contains
  int player;
  char *colour;
  int year;
} Piece; // Name of structure

// global variables for player pieces
int playerpiece1 = 81; // Q
int playerpiece2 = 88; // X

void printBoard(Piece[][] Pieces) // prints board onto console
{
  for (int i = 0; i < length(Pieces); i++)
  {
    for (int j = 0; j < length(Pieces[0]); j++)
    {
      prjnt(Pieces[i][j]); // prints the respective piece
    }
    printf("\n------------------------------------------------\n"); // prints new line, filled with dashes
  }
}

void prjnt(Piece Peace)
{
  if (Peace.player == "0")
  {
    return;
  }
  else if (Peace.player == "1")
  {
    printf("%c", playerpiece1);
  }
  else if (Peace.player == "2")
  {
    printf("%c", playerpiece2);
  }
}

void makeBoard(Piece[][] Pieces) // creates the board and fills it with empty objects
{
  for (int i = 0; i < length(Pieces); i++)
  {
    for (int j = 0; j < length(Pieces[0]); j++)
    {
    }
    printf("\n------------------------------------------------\n"); // prints new line, filled with dashes
  }
}

int main()
{ // size of board
  int boredsizey = 6;
  int boredsizex = 7;
  int maxplays = boredsizex * boredsizey; // maximum number of pieces on board

  // Create game board
  Piece Pieces[boredsizex][boredsizey];
  makeBoard(*Pieces); // fills the board with empty game pieces

  while (1) // while true
  {
    printBoard(*Pieces);
    int rowfull = 1;     // variable to check whether the selected row is full
    int usersel;         // the row selected by the user
    while (rowfull != 0) // you cannot add a new piece to a full row!
    {
      usersel = scanf("Where would you like to place your game piece? [1-%i]", length(Pieces[0])); // input up until the last spot in the game board
      rowfull = checkrowfull(usersel);
    }
  }
  return 0;
}