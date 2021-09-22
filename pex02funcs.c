/** pex02funcs.c
 * =========================================================== 
 * Name: C2C Lisa McCormick
 * Section: T6/7
 * Project: PEX 02 - Pig!
 * Purpose: Write an application that implements the two-player dice game.
 *          
 * =========================================================== */

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "pex02funcs.h"


char getCharSafe(){
	char valued;
	char scanfReturnd = 0;

    scanfReturnd = scanf(" %c", &valued);
    fflush(stdin);

    if (scanfReturnd !=1){
        fprintf(stderr, "Bad char input - terminating\n");
        exit(1);
    }
    return valued;
}

int rollDie(){
    
    int value = rand() % 6 + 1;
    return value;
}

int takeTurn(char* playerName, int playerScore){
    
    printf("It's your turn, %s\n", playerName);

    int pointsEarned = 0;
    int diceRoll = rollDie();
    int turnScore = diceRoll + pointsEarned;
    int totalScore = turnScore + pointsEarned;
    char c = getCharSafe();
    // DO WHILE LOOP
        // Roll Die
        do {
         pointsEarned = pointsEarned + diceRoll;   
        } while (c == 'Y' || c == 'y');
        
        // Adjust points (or pig out)
        if (diceRoll == 1){
            printf("You pigged out! Turn over.\n");
        }
        else{
            totalScore = turnScore + pointsEarned;
        printf("You rolled a %d and have a turn score of %d, bringing your total score to %d.\n", diceRoll, turnScore, totalScore);
        }
        
        // Ask them if they want to roll again
        printf("Roll Again? ");
        if (c != 'Y' || c != 'y'){
            return totalScore + totalScore;
        } 
        else{
        return totalScore;
  }
}

void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score){

printf("    Score Player\n");
printf("        %d %s\n", player1Score, player1Name);
printf("        %d %s\n", player2Score, player2Name);
printf("\n");
}

int winningPlayer(int player1Score, int player2Score){

    if (player1Score >= POINTS_TO_WIN){
        return 1;
    }
    else if (player2Score >= POINTS_TO_WIN){
        return 2;
    }
    else if (player1Score == player2Score){
        return 3;
    }
    else{
    return 0;
    }
}

void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score){
    
    int playerwin = winningPlayer(player1Score, player2Score);
if (playerwin == 1){
printf("%s, you won!\n", player1Name);
}
else if (playerwin == 2){
printf("%s, you won!\n", player2Name);
}
else{
    printf("You tied. There are no winners here.\n");
}
}
