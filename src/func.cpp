// Helper functions definitions
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "func.h"

using std::vector;
using std::string;
using std::stringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

vector<int> inputCards() {
    string input;
    cout << "Enter 4 face cards separated by spaces: ";
    getline(cin, input);
    vector<int> output;
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
                cout << "Invalid input, only numbers 2-10 or J, Q, K, A are allowed.\n" << value << endl;
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

    /* Note for self : Pengguna dapat memilih apakah program 
    meminta input dari pengguna atau generate sendiri. */

    return output;
}

