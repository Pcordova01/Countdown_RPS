//Tool box that includes all the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

//The "computer" and the "friend" are used synonymously - it's the player's oppenent

//Array of available choices (rock, paper, scissors)
char* choices[] = {"rock", "paper", "scissors"};

//Game funcionality 
int game(){

    //Stores players choice as a string
    char choice_plr[10];

    //Stores computer's choice as an integer
    int choice_com;

    //Random number (0-2)
    choice_com = rand() % 3;

    //Prompt user to enter their choice
    printf("Enter your choice (rock/paper/scissors):");
    scanf("%s", choice_plr);

    //If the user doesn't enter a valid choice (rock, paper, scissors) then they lose the round
    if (strcmp(choice_plr, "rock") != 0 && strcmp(choice_plr, "paper") != 0 && strcmp(choice_plr, "scissors") != 0) {
        printf("That's not a choice! You lose this round!\n");

        //Player loses a point
        return -1;  
    }

    //Displays the computer's choice
    printf("Your friend chose: %s\n", choices[choice_com]);

    // If the player and the computer choose the same move, its a tie and no one gets points
    if (strcmp(choice_plr, choices[choice_com]) == 0) {
        printf("You guys tied!!\n");
        return 0;
    } 

    // If the player choses a move that wins against the computer's move, the player receives 1 point 
    else if ((strcmp(choice_plr, "rock") == 0 && choice_com == 2) || (strcmp(choice_plr, "paper") == 0 && choice_com == 0) || (strcmp(choice_plr, "scissors") == 0 && choice_com == 1)) {
        printf("You win!! Here's a point!!\n");
        return 1;
    } 

    //If the player choses a move that loses against the computer's move, the player loses 1 point 
    else {
        printf("You lose!!\n");
        return -1;
    }
}

//Recursive function to make countdown 
void countdown(int seconds){

    //Base case that terminates recursive function (at 0 seconds))
    if(seconds == 0){
        printf ("Liftoff!\n");
        return;
    }

    //Prints each individual second of the countdown
    printf("%d\n", seconds);

    //Creates a 1 second sleep delay 
    sleep(1);

    //recursive call
    countdown(seconds - 1);
}

//Main function
int main(){
    
    //Player's score, Friend's score, and number of rounds
    int score_plr = 0;
    int score_com = 0;
    int num_rounds = 1;

    //Begins random number generator with a different number each time the program runs
    srand(time(NULL));

    //Tells the player the story
    printf("You and your bestfriend have stumbled upon an abandoned spaceship that you both want for yourselves! \nAfter arguing for hours, the decision was made to play rock paper scissors over who gets leave with \nthe spaceship and who gets left behind...\n");

    //While loop to ensure the game is best 2 out of 3 
    while (num_rounds < 4){
    
        //Displays the round number
        printf("\nRound %d\n", num_rounds);
    
        //Determines result of each round
        int result = game();  // Calls the game function
    
        //If player wins the round 
        if (result == 1) {

            //Score of player is incrimented 
            score_plr++;
            //Number of rounds is incrimented 
            num_rounds++;
        } 

        //If player looses the round
        else if (result == -1) {

            //Score of the computer is incrimented
            score_com++;
            //Number of rounds is incrimented
            num_rounds++;
        }

        //If the player or computer has won the first two rounds, they have won best 2 out of 3 
        if (score_plr >= 2 || score_com >= 2) {
            break; //game is ended
        }
    
    }
    
    //Displays the final score 
    printf("\nFinal Score - You: %d, Friend: %d\n", score_plr, score_com);

    //If the player has more points than computer 
    if (score_plr > score_com) {

        //Congratulate the player
        printf("Congratulations! You won the game and get to launch the spaceship!\n");

        //Dramatic 5 second sleep delay
        sleep(5);

        //Initiates launch sequence text
        printf("Initiating launch sequence...\n");

        //3 second sleep delay to allow player to read all the text
        sleep(3);

        //Initiates recursive countdown function
        countdown(10);

        //Dramatic 2 second sleep delay 
        sleep(2);

        //End game message
        printf("You've ditched your bestfriend... hope you're happy!");
    } 

    //If the computer has a higher score than the player
    else {

        //Let the player know they lost
        printf("Your friend has won, prepare to be left behind...\n");

        //Dramatic 5 second sleep delay
        sleep(5);
        
        //Initiates launch sequence text
        printf("Initiating launch sequence...\n");

        //3 second sleep delay to allow player to read all the text
        sleep(3);

        //Initiates recursive countdown function
        countdown(10);

        //Dramatic 2 second sleep delay
        sleep(2);

        //End game message
        printf("Your best friend has ditched you... you will never see them again...");
    }
    return 0;
}