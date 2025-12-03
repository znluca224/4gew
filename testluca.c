#define ROWS 6
#define COLUMNS 7


void initialiaze_Board(Board *b) // Übergeben des Board-Zeigers zur Initialisierung 
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
        {
            b->cells[r][c] = " "; // für jedes Element des Boards werden leere Felder gesetzt
        }
    }
}

void print_Board(const Board *b) // Board wird konstant übergeben (nicht veränderlich)
{
    printf("\n"); // leerer Absatz

    printf("  ");

    // Spaltennummerierung 1 bis 7
    for (int c = 0; c < COLUMNS; c++) 
    {
        printf(" %d ", c + 1); 
    }
    printf("\n"); // Absatz 

    
    for (int r = 0; r < ROWS; r++) 
    {
        // Setzen eines | am Anfang jeder Zeile 
        printf(" |");

        // Füllen des Arrays mit Nullen 
        for (int c = 0; c < COLUMNS; c++) 
        {
            char ch = b->cells[r][c];
            if (ch == ' ') ch = '0';
            printf(" %c", ch);
        }

        printf(" |\n");
    }

    printf("\n");
}