/*
#include <stdio.h>
#include "game.h"
//#include "printboard.h"

int main(void) {
    // Deklarieren des Boards mit den Zeilen und Splaten
    int gameBoard[ROWS][COLUMNS];

    // aktueller Spieler wird durch 1 repräsentiert
    int currentPlayer = 1;

    // ausgewählte Spalte
    int chosenColumn;

    // Sieger ist aktuell unbekannt --> 0
    int winner = 0;

    // gameBoard-Matrix wird mit Nullen gefüllt
    setupBoard(gameBoard);

    // Solange das Spiel läuft, wird dieser Ablauf durchgeführt
    while (1) {
        // Ausgabe des Boards im Command Window
        printBoard(gameBoard);

        // schriftliche Ausgabe, welcher Spieler am Zug ist
        printf("Spieler %d ist am Zug.\n", currentPlayer);

        // schrfitliche Aufforderung, wo ein Spielstein gesetzt werden soll
        printf("Bitte Spalte wählen (1-%d): ", COLUMNS);

        // wenn scanf nicht 1 zurückliefert, dann folgendes geprintet
        if (scanf("%d", &chosenColumn) != 1) {
            printf("Ungueltige Eingabe. Programm wird beendet.\n");
            return 0;
        }

        // um die richtige Spalte der Matrix zu wählen, wird die Spaltenzahl dekrementiert
        chosenColumn -= 1;

        // Wenn kein Spielstein gesetzt werden konnte, wird dies schriftlich ausgegeben
        if (!dropAPiece(gameBoard, chosenColumn, currentPlayer)) {
            printf("Ungueltiger Zug! Spalte existiert nicht oder ist voll.\n");
            continue;
        }

        // Wenn vier Steine in einer Reihe sind, ist der aktuelle Spieler der Sieger, das Spiel bricht dann ab
        if (checkVictory(gameBoard, currentPlayer)) {
            winner = currentPlayer;
            break;
        }

        // Wenn das Board voll ist, wird das Spiel abgebrochen
        if (checkBoard(gameBoard)) {
            break;
        }

        // Wechsel zwischen den Spielern: 3-1 --> Spieler 2.  --> 3-2 --> Spieler 1
        currentPlayer = 3 - currentPlayer;
    }

    // Ausgabe des Boards am Ende
    printBoard(gameBoard);

    // Wenn für Winner entweder 1 oder 2 hinterlegt ist, dann hat der jeweilige Spieler gewonnen
    if (winner != 0)
    {
        printf("Spieler %d hat gewonnen! Glückwunsch!\n", winner);
    } else // ansonsten ist das Spiel unentschieden
    {
        printf("Unentschieden! Das Brett ist voll.\n");
    }

    return 0;
}
    */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int player1WinCounter = 0;
int player2WinCounter = 0;

//-----------------------------------------------------------------------------------------------------------------------------
// Method to clear the console of the previous gameboards
// -----------------------------------------------------------------------------------------------------------------------------
void clearAll()
{
#ifdef _WIN32
    system("cls"); // The console on Windows can be cleared with "cls"
#else
    system("clear"); // for other operating Systems the console can be cleared by using "clear"
#endif
}
void clearfrom()
{
    printf("\033[19;1H"); // position: row 5
    printf("\033[J");     // deletes everything below row 5
}

// method to print a "4 in a Row" ASCII-Art
void printLogo()
{
    printf("\n   _____   .__                  __________\n");
    printf("  /  |  |  |__| ____   _____    \\______   \\ ______  _  __\n");
    printf(" /   |  |_ |  |/    \\  \\__  \\    |       _//  _ \\ \\/ \\/ /\n");
    printf("/    ^   / |  |   |  \\  / __ \\_  |    |   (  <_> )     / \n");
    printf("\\____   |  |__|___|  / (____  /  |____|_  /\\____/ \\/\\_/ \n");
    printf("     |__|          \\/       \\/          \\/ \n\n");
}

// Start of the main method
int main(void)
{

    int round = 1;

    // print ASCII-Art
    printLogo();

    // welcome message
    printf("Willkommen in dem Konsolenspiel 4 Gewinnt (Best of 3)!\n\n");

    // game explanation
    printf("In diesem Spiel treten zwei Spieler abwechselnd in drei Runden an. \n Die Person mit den meisten Siegen, gewinnt das Spiel.\n");
    printf("Ziel ist es, vier Spielsteine in einer Zeile, einer Spalte oder in einer Diagonalen zu legen.\n Falls Sie das Spiel beenden möchten, können Sie Q in das Terminal eingeben.\n\n");

    // Mode: Best of three
    // maximum rounds: 3
    // win condition: a player needs to have at least two wins
    while (player1WinCounter < 2 && player2WinCounter < 2 && round <= 3)
    {

        // prints the current round
        printf("--> Sie befinden sich in Spielrunde %d <--\n\n", round);

        // play one round and return the winner
        int winner = playOneRound();

        // if the game returns "-1" one player probably wants to exit
        if (winner == -1)
        {
            // determine whether the players really want to quit
            printf("Wollen Sie das Spiel wirklich beenden?\n\n");
            printf("B zum beenden oder W zum weiterspielen:\n\n");

            // read the input
            char input2[10];
            scanf("%9s", input2);

            // if the input equals B the game will end
            if (input2[0] == 'B' || input2[0] == 'b')
            {
                printf("Das Spiel ist jetzt beendet!\n\n");
                return 0;
            }

            // if the input equals B the game will restart
            if (input2[0] == 'W' || input2[0] == 'w')
            {
                continue;
                ;
            }
        }
        else if (winner == 1) // the return of number 1 indicates that player 1 has won
        {
            player1WinCounter++;
            printf("Runde %d: Spieler 1 gewinnt diese Runde. Herzlichen Glückwunsch! \n\n\n\n", round);
        }
        else if (winner == 2) // the return of number 2 indicates that player 2 has won
        {
            player2WinCounter++;
            printf("Runde %d: Spieler 2 gewinnt diese Runde. Herzlichen Glückwunsch! \n\n\n\n", round);
        }
        else // a draw occured if the value of winner does not equal 1, 2 or -1
        {
            printf("Runde %d endet unentschieden.\n\n\n", round);
        }

        // increment the round
        round++;
    }

    printf("Das Endergebnis des Best of 3 lautet wie folgt: \n\n");

    if (player1WinCounter > player2WinCounter)
    {
        printf("Spieler 1 ist der endgültige Gewinner von 4 Gewinnt mit einem Spielstand von %d : %d \n\n", player1WinCounter, player2WinCounter);
    }
    else if (player2WinCounter > player1WinCounter)
    {
        printf("Spieler 2 ist der endgültige Gewinner von 4 Gewinnt mit einem Spielstand von %d : %d \n\n", player2WinCounter, player1WinCounter);
    }
    else
    {
        printf("Das Spiel endet unentschieden (%d : %d).\n\n", player1WinCounter, player2WinCounter);
    }
    return 0;
}

// Eine einzelne Runde 4 Gewinnt
// Rückgabewert: 1 = Spieler 1, 2 = Spieler 2, 0 = Unentschieden
int playOneRound(void)
{
    int gameBoard[ROWS][COLUMNS];

    int currentPlayer = 1;
    int chosenColumn;
    int winner = 0;

    // Board initialisieren
    setupBoard(gameBoard);

    // Solange die Runde läuft
    while (1)
    {
        // Verlauf löschen
        clearTerminal();

        printf("Zwischenstand: Spieler 1 = %d Siege   |   Spieler 2 = %d Siege\n\n", player1WinCounter, player2WinCounter);

        // Board ausgeben
        printBoard(gameBoard);

        printf("Spieler %d ist am Zug.\n", currentPlayer);

        char input[10];

        printf("Bitte wählen Sie eine Spalte (1-%d) oder drücken Sie Q zum Beenden des Spiels: ", COLUMNS);

        // Eingabe als String lesen
        if (scanf("%9s", input) != 1)
        {
            printf("Fehler bei der Eingabe.\n\n");
            return 0;
        }

        // Prüfen ob der Spieler abbrechen will
        if (input[0] == 'Q' || input[0] == 'q')
        {
            printf("Spieler %d möchte das gesamte Spiel beenden.\n\n", currentPlayer);
            return -1;
        }

        // Falls keine Zahl → Fehler
        if (sscanf(input, "%d", &chosenColumn) != 1)
        {
            printf("Ungueltige Eingabe. Bitte Zahl oder Q.\n\n");
            continue; // Spieler soll nochmal eingeben
        }

        printf("\n");

        // Spalte anpassen (Benutzer gibt 1-7 ein, Matrix nutzt 0-6)
        chosenColumn -= 1;

        // Stein setzen
        if (!dropAPiece(gameBoard, chosenColumn, currentPlayer))
        {
            printf("Ungueltiger Zug! Spalte existiert nicht oder ist voll.\n\n");
            continue;
        }

        // Siegprüfung
        if (checkVictory(gameBoard, currentPlayer))
        {
            winner = currentPlayer;
            break;
        }

        // Board voll?
        if (checkBoard(gameBoard))
        {
            break;
        }

        // Spieler wechseln (1 -> 2, 2 -> 1)
        currentPlayer = 3 - currentPlayer;
    }

    // Endzustand des Boards ausgeben
    printBoard(gameBoard);

    if (winner != 0)
    {
        // printf("Spieler %d hat diese Runde gewonnen! Glueckwunsch!\n", winner);
    }
    else
    {
        printf("Unentschieden! Das Brett ist voll.\n\n");
    }

    return winner;
}
