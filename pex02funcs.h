/** pex02funcs.h
 * =========================================================== 
 * Name: C2C Lisa McCormick
 * Section: T6/7
 * Project: PEX 02
 * Purpose: Write an application that implements the two-player dice game.
 * 
 * =========================================================== */

#define POINTS_TO_WIN 10

char getCharSafe();

int rollDie();

int takeTurn(char* playerName, int playerScore);

void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score);

int winningPlayer(int player1Score, int player2Score);

void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score);
