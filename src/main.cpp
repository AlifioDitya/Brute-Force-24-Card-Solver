// Main program

#include <iostream>
#include <limits>
#include <chrono>
#include "func.h"

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::getline;

int main() {

    int option;
    vector<double> cards;

    cout << "<<< Welcome to the 24 Game Solver >>>\n" << endl;

    // Loop until program is terminated
    bool running = true;

    while (running) {
        do {
            cout << "How would You like your cards generated?" << endl;
            cout << "1. Input manually." << endl;
            cout << "2. Randomly generated.\n" << endl;
            cout << "Option: ";

            cin >> option;

            cout << endl;

            // Handle invalid option
            if (cin.fail() || (option != 1 && option != 2)) {
                cout << "Invalid option, please pick either 1 or 2.\n" << endl;
                cin.clear();
            }

            // Clear input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (option != 1 && option != 2);

        if (option == 1) {
            // Manual input
            cards = inputCards();
            while (cards.size() != 4) {
                cards = inputCards();
            }
        } else {
            // Random generated
            cards = generateRandomCards();
        }
        
        cout << "Your cards are:" << endl;
        printCards(cards);
        cout << endl;

        string blank;
        cout << "Click enter to see solutions." << endl;
        getline(cin, blank);

        // Start clock
        auto start = std::chrono::high_resolution_clock::now();

        // Get all possible card permutations
        auto perm = permuteCards(cards, 0, cards.size()-1);

        // Get solutions in vector of strings
        vector<string> solution = solve24(perm);

        if (solution.size() != 0) {
            // Solutions found
            cout << "Solutions to 24:" << endl;
            printSolutions(solution);
            cout << endl << solution.size() << " unique solutions found.\n" << endl;    
        } else {
            // No solutions
            cout << "No solutions found for the given card hand.\n" << endl;
        }

        // End clock
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        cout << "Runtime: " << duration.count() << "ms\n" << endl;

        // Option to save the solutions
        if (solution.size() != 0) {
            char saveOpt;
            do {
                cout << "Would you like to save the solution? [y/n]\n\nOption: ";
                cin >> saveOpt;
                cout << endl;

                if (saveOpt == 'y') {
                    // Note: ".txt" extension has to be entered in order to save as a text file
                    string filename;
                    cout << "Enter save file name: ";
                    cin >> filename;
                    cout << endl;
                    saveVectorToFile(solution, filename);
                    cout << "Solution saved in " << filename << endl << endl;
                }
            } while (saveOpt != 'y' && saveOpt != 'n');
        }

        // Option to re-run or terminate
        char rerun;
        do {
            cout << "Would you like to try the game again? [y/n]\n\nOption: ";
            cin >> rerun;
            cout << endl;

            if (rerun == 'n') {
                running = false;
                cout << "Goodbye!" << endl;
            }
        } while (rerun != 'y' && rerun != 'n');
    }

    return 0;
}