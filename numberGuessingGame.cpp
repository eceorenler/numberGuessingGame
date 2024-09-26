#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumber;
int numberOGuesses;  
int attempts = 1;   
char again;     

void easyGame() {
    cout << "Easy level: Guess a number between 1 and 10 (unlimited guesses)" << endl;
    randomNumber = rand() % 10 + 1;
    numberOGuesses = -1;  
}

void mediumGame() {
    cout << "Medium level: Guess a number between 1 and 50 (10 guesses)" << endl;
    randomNumber = rand() % 50 + 1;
    numberOGuesses = 10;
}

void hardGame() {
    cout << "Hard level: Guess a number between 1 and 100 (8 guesses)" << endl;
    randomNumber = rand() % 100 + 1;
    numberOGuesses = 8;
}

void getRandomNumber(int level) {
    srand(time(nullptr));  // Initialize random seed
    if (level == 1) {
        easyGame();
    } else if (level == 2) {
        mediumGame();
    } else if (level == 3) {
        hardGame();
    } else {
        cout << "Invalid level number." << endl;
    }
}

void opening() {
    int level;
    cout << "Welcome to the number-guessing game!" << endl;

    do {
        cout << "Choose a level to play:\n 1. EASY\n 2. MEDIUM\n 3. HARD\nEnter 1, 2, or 3: ";
        cin >> level;

        if (level == 1 || level == 2 || level == 3) {
            getRandomNumber(level);  
            break;
        } else {
            cout << "Invalid level! Please try again.\n";
        }
    } while (true);
}

int main() {
    opening();

    do {
        int guess;
        cout << "Enter your guess here: ";
        cin >> guess;

        if (guess < randomNumber) {
            if (numberOGuesses != -1) {
                cout << "Too low! " << numberOGuesses - attempts << " guesses remaining." << endl;
            } else {
                cout << "Too low! Try again." << endl;  
            }
        } else if (guess > randomNumber) {
            if (numberOGuesses != -1) {
                cout << "Too high! " << numberOGuesses - attempts << " guesses remaining." << endl;
            } else {
                cout << "Too high! Try again." << endl; 
            }
        } else {
            cout << "Congratulations! You guessed the number!" << endl;
            break;
        }

        attempts++;

        if (numberOGuesses != -1 && attempts > numberOGuesses) {
            cout << "You are out of guesses. Game over." << endl;
            break;
        }

    } while (true);

    return 0;
}
