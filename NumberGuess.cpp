#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I'm thinking of a number between 1 and 100.\n";

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        attempts++;

        if (userGuess == randomNumber) {
            std::cout << "Congratulations! You guessed the correct number.\n";
            std::cout << "It took you " << attempts << " attempts.\n";
            break;
        } else if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try again.\n";
        } else {
            std::cout << "Your guess is too low. Try again.\n";
        }
    }

    return 0;
}
