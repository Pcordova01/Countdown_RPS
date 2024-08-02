#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

char* choices[] = {"rock", "paper", "scissors"};

int game(){
    char choice_plr[10];
    int choice_com;

    choice_com = rand() % 3;

    printf("Enter your choice (rock/paper/scissors):");
    scanf("%s", choice_plr);

    if (strcmp(choice_plr, "rock") != 0 && strcmp(choice_plr, "paper") != 0 && strcmp(choice_plr, "scissors") != 0) {
        printf("That's not a choice! You lose this round!\n");
        return -1;  
    }

    printf("Your friend chose: %s\n", choices[choice_com]);

    if (strcmp(choice_plr, choices[choice_com]) == 0) {
        printf("You guys tied!!\n");
        return 0;
    } 
    else if ((strcmp(choice_plr, "rock") == 0 && choice_com == 2) || (strcmp(choice_plr, "paper") == 0 && choice_com == 0) || (strcmp(choice_plr, "scissors") == 0 && choice_com == 1)) {
        printf("You win!! Here's a point!!\n");
        return 1;
    } 
    else {
        printf("You lose!!\n");
        return -1;
    }
}

void countdown(int seconds){
    if(seconds == 0){
        printf ("Liftoff!\n");
        return;
    }

    printf("%d\n", seconds);
    sleep(1);
    countdown(seconds - 1);
}

int main(){
    int score_plr = 0;
    int score_com = 0;
    int num_rounds = 1;

    srand(time(NULL));

    printf("You and your bestfriend have stumbled upon an abandoned spaceship that you both want for yourselves! \nAfter arguing for hours, the decision was made to play rock paper scissors over who gets leave with \nthe spaceship and who gets left behind...\n");

    while (num_rounds < 4){
        printf("\nRound %d\n", num_rounds);
    
        int result = game();
    
        if (result == 1) {
            score_plr++;
            num_rounds++;
        } 
        else if (result == -1) {
            score_com++;
            num_rounds++;
        }

        if (score_plr >= 2 || score_com >= 2) {
            break;
        }
    }
    
    printf("\nFinal Score - You: %d, Friend: %d\n", score_plr, score_com);

    if (score_plr > score_com) {
        printf("Congratulations! You won the game and get to launch the spaceship!\n");
        sleep(5);
        printf("Initiating launch sequence...\n");
        sleep(3);
        countdown(10);
        sleep(2);
        printf("You've ditched your bestfriend... hope you're happy!");
    } 
    else {
        sleep(5);
        printf("Your friend has won, prepare to be left behind...\n");
        sleep(3);
        countdown(10);
        sleep(2);
        printf("Your best friend has ditched you... you will never see them again...");
    }
    return 0;
}