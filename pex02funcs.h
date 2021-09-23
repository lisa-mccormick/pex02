/** pex02funcs.h
 * ===========================================================
 * Name: C2C Lisa McCormick
 * Section: T6/7
 * Project: PEX 02
 * Purpose: Write an application that implements the two-player dice game Pig.
 *
 * =========================================================== */

#ifndef PEX02FUNCS_H
#define PEX02FUNCS_H
#define POINTS_TO_WIN 100

/*
 * @brief gets a character from the keyboard
 * @param N/A
 * @return whether or not the character is valid
 * @pre doesn't check for character
 * @post reports if character is Y or y
 */
char getCharSafe();

/*
 * @brief will use a random number from 1 -6
 * @param N/A
 * @return the value from 1 to 6
 * @pre no value reported
 * @post reports value between 1 and 6
 */
int rollDie();

/*
 * @brief values stored in a char string and and int
 * @param playerName the string
 * @param playerScore the int
 * @return the playerScore associated with the playerName
 * @pre game play is not started
 * @post updates the playerScore associated with the playerName
 */
int takeTurn(char* playerName, int playerScore);

/*
 * @brief displays the score with two char strings and two ints
 * @param player1Name string for name of player1
 * @param player1Score int for score of player1
 * @param player2Name string for name of player2
 * @param player2Score int for score of player2
 * @return N/A
 * @pre doesn't display values
 * @post player1Name and player2Name are unchanged, player1Score and player2Score are updated
 */
void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score);

/*
 * @brief winningPlayer based on comparison of two ints
 * @param player1Score int for score of player1
 * @param player2Score int for score of player2
 * @return results of comparison of the two ints
 * @pre doesn't return a value
 * @post player1Score and player2Score are unchanged
 */
int winningPlayer(int player1Score, int player2Score);

/*
 * @brief displays the winner with two char strings and two ints
 * @param player1Name char string for name of player1
 * @param player1Score int for score of player1
 * @param player2Name char string for name of player2
 * @param player2Score int for score of player2
 * @return N/A
 * @pre doesn't display winner
 * @post displays message
 */
void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score);

#endif  // PEX02FUNCS_H