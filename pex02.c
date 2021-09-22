/** pex02.c
 * =========================================================== 
 * Name: C2C Lisa McCormick
 * Section: T6/7
 * Project: PEX 02
 * Purpose: Write an application that implements the two-player dice game.
 *        
 * Documentation: enter here
 * =========================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pex02funcs.h"

int main(){

  char player1Name[20];
  char player2Name[20];
  int player1Score = 0;
  int player2Score = 0;
  int currentPlayer = 1;
  int chanceToPlay = 0;
  srand(time(0));
 

  printf("    Welcome to the Pigs! game.\n");
    printf("\n");
  printf("Player one, what is your name: ");
    scanf("%s", player1Name);
  printf("PLayer two, what is your name: ");
    scanf("%s", player2Name);

  // For each turn
  // LOOP
  while (player1Score <= POINTS_TO_WIN && player2Score <= POINTS_TO_WIN){
    displayGameState(player1Name, player1Score, player2Name, player2Score);
  // IF PLAYER 1'S TURN
    if (currentPlayer == 1){
      printf("\n");
      printf("It's your turn, %s\n", player1Name);
    player1Score = takeTurn(player1Name, player1Score);
    currentPlayer = 2;
    }
  // ELSE
  // Player 2's turn
    else{
      printf("\n");
      printf("It's your turn, %s\n", player2Name);
    player2Score = takeTurn(player2Name, player2Score);
    currentPlayer = 1;
    chanceToPlay = chanceToPlay + 1;
    }
  }
displayGameState(player1Name,player1Score, player2Name, player2Score);
if (chanceToPlay != 0){
winningPlayer(player1Score, player2Score);
}
displayWinner(player1Name, player1Score, player2Name, player2Score);

printf("Thanks for playing Pig!\n");

return 0;
}
