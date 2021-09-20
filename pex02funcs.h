/** pex02funcs.h
 * =========================================================== 
 * Name: your name
 * Section: your section
 * Project: assignment information 
 * Purpose: high level description of purpose of the program
 *          could be multiple lines
 * =========================================================== */

char getCharSafe();

int rollDie();

int takeTurn(char* playerName, int playerScore);

void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score);

int winningPlayer(int player1Score, int player2Score);

void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score);
