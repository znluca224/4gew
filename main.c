
// global variables for player pieces
int playerpiece1 = 81; // Q
int playerpiece2 = 88; // X

int main()
{ // size of board
  int boredsizey = 6;
  int boredsizex = 7;
  int maxplays = boredsizex * boredsizey; // maximum number of pieces on board

  // Create game board
  Piece GBoard[boredsizex][boredsizey];
  clearBoard(*GBoard); // fills the board with empty game pieces

  while (1) // while true
  {
    printBoard(*GBoard);
    int rowfull = 1;     // variable to check whether the selected row is full
    int usersel;         // the row selected by the user
    while (rowfull != 0) // you cannot add a new piece to a full row!
    {
      usersel = scanf("Where would you like to place your game piece? [1-%i]", length(GBoard[0])); // input up until the last spot in the game board
      rowfull = checkrowfull(usersel);
    }
  }
  return 0;
}