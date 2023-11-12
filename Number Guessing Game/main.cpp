#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;
int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int userGuess;
   int attempts = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    do {
        cout << "Enter your guess (between 1 and 100): ";
        cin >> userGuess;
        attempts++;
        if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        }
    } while (userGuess != secretNumber);
    return 0;
}