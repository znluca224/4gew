#include "header.h"
#include <ncurses.h>

int main(void)
{
    Game game;
    game_init(&game);

    ui_init();

    int cursor_col = 0;

    while (1)
    {
        ui_draw(&game, cursor_col);
        int ch = ui_get_input();

        if (ch == 'q' || ch == 'Q')
        {
            break;
        }
        if (game.game_over)
        {
            if (ch == 'r' || ch == 'R')
            {
                game_init(&game);
                cursor_col = 0;
            }
            continue;
        }

        switch (ch)
        {
        case KEY_LEFT:
        case 'a':
        case 'A':
            if (cursor_col > 0)
                cursor_col--;
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            if (cursor_col < BOARD_COLS - 1)
                cursor_col++;
            break;
        case '\n':
        case KEY_ENTER:
        case ' ':
            if (board_can_drop(&game.board, cursor_col))
            {
                game_make_move(&game, cursor_col);
            }
            break;
        default:
            break;
        }
    }

    ui_shutdown();
    return 0;
}
