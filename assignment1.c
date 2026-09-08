/* 
 * Program: EECS 348 Assignment 1 - Number Guessing Game 
 * 
 * Description: 
 * This C program uses a fixed secret number between 1 and 10. 
 * The user gets up to 3 attempts to guess the secret number. 
 * The program tells the user whether each guess is too high, 
 * too low, or correct, and displays a final win or lose message. 
 * 
 * Inputs: 
 * An integer guess entered by the user through the keyboard. 
 * 
 * Outputs: 
 * Messages displayed in the terminal showing the result of each guess 
 * and a final win or lose message. 
 * 
 * Collaborators: 
 * None. 
 * 
 * Other Sources: 
 * Claude AI was used to generate the original version of this code. 
 * 
 * Author: 
 * Parker Curl 
 * 
 * Creation Date: 
 * September 8, 2026 
 * 
 * Revision Date: 
 * September 8, 2026 
 * 
 * Revisions: 
 * Modified the original Claude-generated code to improve input handling, 
 * comments, and maintainability. 
 */ 
 
#include <stdio.h> 
 
int main(void) {  //main func, guessing game gets executed here  
    const int secretNumber = 7;   // Fixed secret number between 1 and 10 
    const int maxTries = 3;       // Maximum number of guesses allowed 
    int guess;                    // Stores the user's guess 
    int won = 0;                  // Flag to track whether the user won 
 
    printf("Welcome to the Number Guessing Game!\n"); //simple print line to let user know it started 
    printf("Guess a number between 1 and 10. You have %d tries.\n", maxTries); //prompt user  
 
    // Loop allows up to maxTries attempts 
    for (int attempt = 1; attempt <= maxTries; attempt++) { 
        printf("\nAttempt %d of %d - Enter your guess: ", attempt, maxTries); 
         
                 //Source: Combination of Claude code and Parker Curl 
                // Read the user's guess and make sure an integer was entered. 
        if (scanf("%d", &guess) != 1) { 
            printf("Invalid input. Please enter a whole number.\n"); //let user know input was invalid  

            // Clear the invalid input from the input buffer. 
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { 
                // Discard invalid characters. 
            } 

            // Do not count an invalid input as an attempt. 
            attempt--; 
            continue; //restarts loop so it will ask user for another guess/input  
        } 
 
        // Check the guess against the secret number 
        if (guess == secretNumber) { 
            printf("Congratulations! You guessed the correct number: %d\n", secretNumber); 
            won = 1;   // Mark that the user won 
            break;     // Stop the loop immediately since the guess is correct 
        } else if (guess > secretNumber) { 
            printf("Too high! Try again.\n"); 
        } else { 
            printf("Too low! Try again.\n"); 
        } 
    } 
 
    // Final message depending on whether the user won or lost 
    if (!won) { 
        printf("\nSorry, you didn't guess the number. The correct number was %d.\n", secretNumber); 
    } else { 
        printf("You win!\n"); 
    } 
 
    return 0; 
}