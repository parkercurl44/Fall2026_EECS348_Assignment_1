/*
 * EECS 348 - Assignment 1
 * Number Guessing Game
 *
 * The program picks a fixed secret number between 1 and 10.
 * The user has up to 3 attempts to guess it correctly.
 * After each guess, the program tells the user if their guess
 * was too high, too low, or correct.
 * The loop stops immediately once the correct guess is made.
 */

#include <stdio.h>

int main(void) {
    const int secretNumber = 7;   // Fixed secret number between 1 and 10
    const int maxTries = 3;       // Maximum number of guesses allowed
    int guess;                    // Stores the user's guess
    int won = 0;                  // Flag to track whether the user won

    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess a number between 1 and 10. You have %d tries.\n", maxTries);

    // Loop allows up to maxTries attempts
    for (int attempt = 1; attempt <= maxTries; attempt++) {
        printf("\nAttempt %d of %d - Enter your guess: ", attempt, maxTries);
        scanf("%d", &guess);

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
