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
    vector<int> cards;

    cout << "~~ Welcome to 24 Game Solver ~~\n" << endl;

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

    // All card permutations
    for (auto it = perm.begin(); it != perm.end(); it++) {
        auto permVector = *it;
        for (int j = 0; j < permVector.size(); j++) {
            cout << permVector[j] << " ";
        }
        cout << endl;
    }

    cout << endl << perm.size() << endl;

    return 0;
}