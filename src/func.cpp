// Helper functions definitions
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <set>
#include "func.h"

using std::vector;
using std::string;
using std::stringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::swap;

vector<int> inputCards() {
    string input;
    cout << "Enter 4 face cards separated by spaces: ";
    getline(cin, input);
    vector<int> output = {};
    string token;
    stringstream ss(input);

    while (ss >> token) {
        if (token == "A") {
            output.push_back(1);
        } else if (token == "J") {
            output.push_back(11);
        } else if (token == "Q") {
            output.push_back(12);
        } else if (token == "K") {
            output.push_back(13);
        } else {
            int value = 0;
            for (char c : token) {
                if (c < '0' || c > '9') {
                    // Error
                    cout << "Invalid input, only numbers 2-10 or J, Q, K, A are allowed.\n" << endl;
                    return vector<int>();
                } else {
                    value = value * 10 + (c - '0');
                }
            }

            if (value < 2 || value > 10) {
                // Error
                cout << "Invalid input, only numbers 2-10 or J, Q, K, A are allowed.\n" << endl;
                return vector<int>();
            } else {
                output.push_back(value);
            }

        }
    }

    if (output.size() != 4) {
        // Error
        cout << "Invalid input, please enter 4 valid face cards.\n" << endl;
        return vector<int>();
    }

    return output;
}

vector<int> generateRandomCards() {
    vector<int> output;
    srand(time(0));

    for (int i = 0; i < 4; i++) {
        int randCard = rand() % 13 + 1;
        output.push_back(randCard);
    }
    
    return output;
}

void printCards(vector<int> cards) {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == 1) {
            cout << "A ";
        } else if (cards[i] == 11) {
            cout << "J ";
        } else if (cards[i] == 12) {
            cout << "Q ";
        } else if (cards[i] == 13) {
            cout << "K ";
        } else {
            cout << cards[i] << " ";
        }
    }
    cout << endl;
}

set<vector<int>> permuteCards(vector<int> &cards, int l, int r) {
    set<vector<int>> permutations;

    if (l == r) {
        permutations.insert(cards);
    } else {
        for (int i = l; i <= r; i++) {
            swap(cards[l], cards[i]);
            auto subPerm = permuteCards(cards, l + 1, r);
            permutations.insert(subPerm.begin(), subPerm.end());
            swap(cards[l], cards[i]);
        }
    }

    return permutations;
}