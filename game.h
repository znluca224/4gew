#ifndef GAME_H
#define GAME_H

#define ROWS 6
#define COLUMNS 7

// 0 = leer, 1 = Spieler 1, 2 = Spieler 2

// Matrix mit Nullen füllen
void setupBoard(int board[ROWS][COLUMNS]); 

// Spielstein setzen
int dropAPiece(int board[ROWS][COLUMNS], int col, int player);

// Gewinnüberprüfung
int checkVictory(int board[ROWS][COLUMNS], int player);

// Board überprüfen: ist das Board voll?
int checkBoard(int board[ROWS][COLUMNS]);

int playOneRound(void);

void clearTerminal();

void printLogo();

// 
void printBoard(int board[ROWS][COLUMNS]);

#endif