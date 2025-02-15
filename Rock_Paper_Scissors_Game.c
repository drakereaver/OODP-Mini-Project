#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));                                  // random seed generator for rand() function
    int score = 0;                                      // player score
    int rnum = 0;                                       // random number
    char options[3][10] = {"rock","paper","scissors"};  // 2D array of options
    char pChoice[10] = {'\0'};                          // player choice
    char cmpChoice[10];                                 // computer choice
    printf("Welcome To Rock Paper Scissors Game\n");
    printf("type '!score' to view score or type '!stop' to exit:\n");
    while (1) {
        printf("Enter your choice (rock, paper, scissors): \n");
        fgets(pChoice, sizeof(pChoice), stdin);         // read input with newline character
        pChoice[strcspn(pChoice, "\n")] = '\0';         // remove newline character if present
        if (strcmp(pChoice,"!stop") == 0){
            printf("Thank You for playing our Game!!\n");
            return 0;                                      
        } 
        else if (strcmp(pChoice, "!score") == 0)
        {
            printf("Your score is: %d\n",score);
            continue;
        }
        else if (!(strcmp(pChoice, "rock") == 0 || strcmp(pChoice, "paper") == 0 || strcmp(pChoice, "scissors") == 0)){  // 0 equal 1 1st string -1 2nd string
            printf("Invalid input\n");
            continue;
        }
        
        rnum = rand() % 3;                             
        strncpy(cmpChoice, options[rnum], sizeof(cmpChoice) - 1);
        puts(cmpChoice);

        if (strcmp(pChoice, cmpChoice) == 0) {
            printf("It's a draw!\n");
        } else if ((strcmp(pChoice, "rock") == 0 && strcmp(cmpChoice, "scissors") == 0) ||
               (strcmp(pChoice, "paper") == 0 && strcmp(cmpChoice, "rock") == 0) ||
               (strcmp(pChoice, "scissors") == 0 && strcmp(cmpChoice, "paper") == 0)) {
            printf("You win!\n");
            score++;
        } else {
            printf("You lose!\n");
            if (score >0 ){
            score--;}

        }
    }
    return 0;
}
