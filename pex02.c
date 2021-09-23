/** pex02.c
 * ===========================================================
 * Name: C2C Lisa McCormick
 * Section: T6/7
 * Project: PEX 02
 * Purpose: Write an application that implements the two-player dice game, Pig.
 *
 * Documentation: I received help from Lt Col de Freitas, Captain Kiekhaefer, and Dr. Bouvier.
 * Lt Col de Freitas helped to explain the use of the do while loop in the takeTurn
 * function. Captain Kiekhaefer explained that my code was out of order in the takeTurn function and
 * how to reorder it properly based on the conditions I wanted met. Dr. Bouvier explained the issue
 * with my game loop in the main game play, and helped to explain the logic behind the game rule of
 * player2 rolling even if player1 reaches 100 first.
 *
 * =========================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pex02funcs.h"

// in the main function gameplay occurs by calling the functs established in the .h and .c files
int main() {
    char player1Name[20];
    char player2Name[20];
    int player1Score = 0;
    int player2Score = 0;
    srand(time(0));
    // introduction to the game, welcomes users, player names are recorded by user input
    printf("    Welcome to the Pigs! game.\n");
    printf("\n");
    printf("Player one, what is your name: ");
    scanf("%s", player1Name);
    printf("PLayer two, what is your name: ");
    scanf("%s", player2Name);
    // loop for game play, shows the current score before each player rolls and then again after
    // each player rolls, alternating turns as long as no player has enough points to win and
    // player2 got a chance to roll again
    do {
        displayGameState(player1Name, player1Score, player2Name, player2Score);
        player1Score = takeTurn(player1Name, player1Score);
        displayGameState(player1Name, player1Score, player2Name, player2Score);
        player2Score = takeTurn(player2Name, player2Score);
    } while (player1Score < POINTS_TO_WIN && player2Score < POINTS_TO_WIN);
    // displays the current score based on the dice rolls after a player reaches 100
    displayGameState(player1Name, player1Score, player2Name, player2Score);
    // checks to see if player(s) won or tied based on their scores
    winningPlayer(player1Score, player2Score);
    // displays a message for the winning player or a tie
    displayWinner(player1Name, player1Score, player2Name, player2Score);
    // ends the game with a thank you message to the users
    printf("Thanks for playing Pig!\n");

    return 0;
}
