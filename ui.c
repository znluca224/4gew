#include "header.h"
#include <ncurses.h>

static int board_origin_row = 2;
static int board_origin_col = 4;

void ui_init(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);    // Player 1
    init_pair(2, COLOR_YELLOW, COLOR_BLACK); // Player 2
    init_pair(3, COLOR_CYAN, COLOR_BLACK);   // Frame
    init_pair(4, COLOR_WHITE, COLOR_BLACK);  // Text
}

void ui_shutdown(void)
{
    endwin();
}

static void draw_frame(const Board *b)
{
    attron(COLOR_PAIR(3));
    for (int r = 0; r <= b->rows; ++r)
    {
        for (int c = 0; c <= b->cols; ++c)
        {
            int y = board_origin_row + r * 2;
            int x = board_origin_col + c * 4;
            mvaddch(y, x, '+');
            if (c < b->cols)
            {
                mvhline(y, x + 1, '-', 3);
            }
            if (r < b->rows)
            {
                mvvline(y + 1, x, '|', 1);
            }
        }
    }
    attroff(COLOR_PAIR(3));
}

static void draw_cells(const Board *b)
{
    for (int r = 0; r < b->rows; ++r)
    {
        for (int c = 0; c < b->cols; ++c)
        {
            Cell cell = board_get(b, r, c);
            int y = board_origin_row + r * 2 + 1;
            int x = board_origin_col + c * 4 + 2;
            if (cell == CELL_P1)
            {
                attron(COLOR_PAIR(1));
                mvaddch(y, x, 'O');
                attroff(COLOR_PAIR(1));
            }
            else if (cell == CELL_P2)
            {
                attron(COLOR_PAIR(2));
                mvaddch(y, x, 'O');
                attroff(COLOR_PAIR(2));
            }
            else
            {
                attron(COLOR_PAIR(4));
                mvaddch(y, x, '.');
                attroff(COLOR_PAIR(4));
            }
        }
    }
}

void ui_draw(const Game *g, int cursor_col)
{
    clear();
    attron(COLOR_PAIR(4));
    mvprintw(0, 2, "Vier Gewinnt (ncurses) - Pfeile links/rechts, Enter zum Fallenlassen, q zum Beenden");
    attroff(COLOR_PAIR(4));

    // Draw current player indicator
    if (g->current_player == CELL_P1)
    {
        attron(COLOR_PAIR(1));
        mvprintw(1, 2, "Am Zug: Spieler 1 (Rot)");
        attroff(COLOR_PAIR(1));
    }
    else
    {
        attron(COLOR_PAIR(2));
        mvprintw(1, 2, "Am Zug: Spieler 2 (Gelb)");
        attroff(COLOR_PAIR(2));
    }

    // Drop indicator above selected column
    int x_cursor = board_origin_col + cursor_col * 4 + 2;
    mvaddch(board_origin_row - 1, x_cursor, 'v');

    draw_frame(&g->board);
    draw_cells(&g->board);

    // Game over message
    if (g->game_over)
    {
        if (g->winner == CELL_EMPTY)
        {
            ui_show_message("Unentschieden! Druecke r fuer Neustart oder q um zu beenden.");
        }
        else
        {
            const char *wmsg = (g->winner == CELL_P1) ? "Spieler 1 (Rot) gewinnt!" : "Spieler 2 (Gelb) gewinnt!";
            ui_show_message(wmsg);
            mvprintw(board_origin_row + g->board.rows * 2 + 2, 2, "Druecke r fuer Neustart oder q um zu beenden.");
        }
    }

    refresh();
}

void ui_show_message(const char *msg)
{
    attron(COLOR_PAIR(4));
    mvprintw(board_origin_row + BOARD_ROWS * 2 + 1, 2, "%s", msg);
    attroff(COLOR_PAIR(4));
}

int ui_get_input(void)
{
    return getch();
}
