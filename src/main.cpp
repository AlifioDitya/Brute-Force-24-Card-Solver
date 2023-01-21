#include <iostream>
#include <limits>
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

    bool running = true;

    while (running) {
        do {
            cout << "How would You like your cards generated?" << endl;
            cout << "1. Input manually." << endl;
            cout << "2. Randomly generated.\n" << endl;
            cout << "Option: ";

            cin >> option;

            cout << endl;

            if (cin.fail() || (option != 1 && option != 2)) {
                cout << "Invalid option, please pick either 1 or 2.\n" << endl;
                cin.clear();
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (option != 1 && option != 2);

        if (option == 1) {
            cards = inputCards();
            while (cards.size() != 4) {
                cards = inputCards();
            }
        } else {
            cards = generateRandomCards();
        }
        
        cout << "Your cards are:" << endl;
        printCards(cards);
        cout << endl;

        string blank;
        cout << "Click enter to see solutions." << endl;
        getline(cin, blank);

        auto perm = permuteCards(cards, 0, cards.size()-1);

        vector<string> solution = solve24(perm);

        if (solution.size() != 0) {
            cout << "Solutions to 24:" << endl;
            printSolutions(solution);
            cout << endl << solution.size() << " unique solutions found.\n" << endl;    
        } else {
            cout << "No solutions found for the given card hand.\n" << endl;
        }

        char option2;
        do {
            cout << "Would you like to try again? [y/n]\n\nOption: ";
            cin >> option2;
            cout << endl;

            if (option2 == 'n') {
                running = false;
                cout << "Goodbye!" << endl;
            }

        } while (option2 != 'y' && option2 != 'n');
    }

    return 0;
}