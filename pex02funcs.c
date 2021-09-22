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


// char* player1Name[20];
// int player1Score;
// char* player2Name[20];
// int player2Score;
// char* playerName[20];
// int playerScore;
// char name;
// int value = 0;

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
    
    int pointsEarned = 0;

    // DO WHILE LOOP
        // Roll Die
        int diceroll = rollDie();

        // Adjust points (or pig out)

        // Ask them if they want to roll again
        // use getCharSafe
        char c = getCharSafe();

    // 
    return playerScore + pointsEarned;
}

/*int takeTurn(char* playerName, int playerScore){

if(player1Score == 0){
    playerName = *player1Name;
printf("It's your turn, %s\n", playerName);
}
else {
    playerName = *player2Name;
printf("It's your turn, %s\n", playerName);    
}
    name = playerName;
    return name;

playerScore = playerScore + value;
 player1Score = playerScore;
 printf("You rolled a %d and have a turn score of %d, bringing your total score to %d.\n", value, playerScore, player1Score);

 printf("Roll Again?");
 scanf(" %c");

if ( %c = "Y"){

}
else if ( %c = "y"){

}
else{
    return turn score + game score
}

if (value = 1){
    printf("You pigged out! Turn over.");
}
}

*/

void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score){

printf("    Score Player\n");
printf("        %d %s\n", player1Score, player1Name);
printf("        %d %s\n", player2Score, player2Name);
printf("\n");
}

int winningPlayer(int player1Score, int player2Score){

    if (player1Score >= 100){
        return 1;
    }
    else if (player2Score >= 100){
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

if (player1Score >= 100){
printf("%s, you won!", player1Name);
}
else if (player2Score >= 100){
printf("%s, you won!", player2Name);
}
else {
    printf("You tied. There are no winners here.\n");
}
}
