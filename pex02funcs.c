/** pex02funcs.c
 * ===========================================================
 * Name: C2C Lisa McCormick
 * Section: T6/7
 * Project: PEX 02 - Pig!
 * Purpose: Write an application that implements the two-player dice game, Pig.
 *
 * =========================================================== */

#include "pex02funcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// checks to see if a user-entered character is valid
char getCharSafe() {
    char valued;
    char scanfReturnd = 0;

    scanfReturnd = scanf(" %c", &valued);
    fflush(stdin);

    if (scanfReturnd != 1) {
        fprintf(stderr, "Bad char input - terminating\n");
        exit(1);
    }
    return valued;
}
// uses the random function to simulate a random dice roll on a 6 sided dice
int rollDie() {
    int value = rand() % 6 + 1;
    return value;
}
// begins loop for each player turn
int takeTurn(char* playerName, int playerScore) {
    char c;
    int pointsEarned = 0;
    int diceRoll;
    int totalScore = playerScore;
    // displays message to let players know who's turn it is
    printf("\n");
    printf("It's your turn, %s\n", playerName);
    // a loop for turn play, if the dice "lands" on 1, the players turn is over,
    // if not, the players score updates by adding the points earned in the current turn to their
    // total. the loop will continue to run unless the the player decides to end their turn
    do {
        diceRoll = rollDie();
        if (diceRoll == 1) {
            printf("You pigged out! Turn over.\n");
            totalScore = totalScore - pointsEarned;
            return totalScore;
        } else {
            pointsEarned = pointsEarned + diceRoll;
            totalScore = pointsEarned + playerScore;
            printf(
                "You rolled a %d and have a turn score of %d, bringing your total score to %d.\n",
                diceRoll, pointsEarned, totalScore);
            printf("Roll Again? ");
            c = getCharSafe();
        }
    } while (c == 'Y' || c == 'y');
    // returns the updated total score of the player after their turn is over
    return totalScore;
}
// displays the current score for each player in a scoreboard type format
void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score) {
    printf("    Score Player\n");
    printf("        %d %s\n", player1Score, player1Name);
    printf("        %d %s\n", player2Score, player2Name);
}
// checks to see which player won, if any, based on their total scores and
// the number of points needed to win
int winningPlayer(int player1Score, int player2Score) {
    if (player1Score >= POINTS_TO_WIN && player1Score > player2Score) {
        return 1;
    } else if (player2Score >= POINTS_TO_WIN && player2Score > player1Score) {
        return 2;
    } else if (player1Score == player2Score) {
        return 3;
    } else {
        return 0;
    }
}
// displays a winning (or tie) message based on what the winningPlayer function returns
// for which player won the game or if the players tied
void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score) {
    int playerwin = winningPlayer(player1Score, player2Score);
    // if statement to check which message to display
    if (playerwin == 1) {
        printf("%s, you won!\n", player1Name);
    } else if (playerwin == 2) {
        printf("%s, you won!\n", player2Name);
    } else {
        printf("You tied. There are no winners here.\n");
    }
}
