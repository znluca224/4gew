#include "header.h"

int main()
{
    // size of board
    int boredsizey = 6;                     // y-dimension of board
    int boredsizex = 7;                     // x-dimension of board
    int maxplays = boredsizex * boredsizey; // maximum number of pieces on board

    // Create game board
    int GBoard[boredsizex][boredsizey];
    clearBoard(*GBoard); // fills the board with empty game pieces
    int running = 1;

    while (running == 1)
    {
        printBoard(*GBoard); // updating the board before the 1st plyer takes their turn

        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        //  Player one
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        int rowfull = -1;    // variable to check whether the selected row is full
        while (rowfull != 0) // you cannot add a new piece to a full row!
        {
            int usersel1;                                                                              // the row selected by the first user
            usersel1 = scanf("Where would you like to place your game piece? [1-%i]", length(GBoard)); // input up until the last spot in the game board
            rowfull = game_board_drop_piece(*GBoard, usersel1, playerpiece1);
            if (rowfull == -1)
            {
                printf("row %i is full, please try another!");
            }
            else if (moves >= maxplays && game_board_check_win(*GBoard, 0, playerpiece1) != 1) // maximum plays were reached and the wincon was not met
            {
                int rowfull = game_board_check_win(*GBoard, 0, 'X');
                printf("Board is full, sowwy!\n press any key to start a new game");
            }
        }
        moves++; // increments the moves counter by one after every move

        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        //  P L A Y E R  T H E  S E C O N D
        //---------------------------------------------------------------------------------------------------------------------------------------------------------
        printBoard(*GBoard); // updating the board before the 2nd plyer takes their turn
        rowfull = 0;         // resetting variable to check whether the selected row is full before the 2nd players turn
        while (rowfull < 1)  // you cannot add a new piece to a full row!
        {
            int usersel2;                                                                                  // the row selected by the second user
            usersel2 = scanf("Where would you like to place your game piece? [1-%i]", length(GBoard)) - 1; // offer inputs including the last column in the game board; -1 to account for the difference between computer and human counting
            rowfull = drop_piece(*GBoard, usersel2, playerpiece1);                                         // if rowfull is returned as "1", the loop exits.

            if (rowfull == -1)
            {
                printf("row %i is full, please try another!");
                usersel2 = scanf("Where would you like to place your game piece? Row %i is full, please select another from [1-%i]", rowfull, length(GBoard));
            }
            if (moves >= maxplays && game_board_check_win(*GBoard, 0, playerpiece2) != 1) // maximum plays were reached and the wincon was not met
            {
                printf("Board is full, sowwy!\n press any key to start a new game");
            }
        }
        moves++; // increments the moves counter by one after every move
    }
    return 0;
}