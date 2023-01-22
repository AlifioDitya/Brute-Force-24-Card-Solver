// Helper functions definitions

#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <set>
#include <cmath>
#include "func.h"

using std::vector;
using std::string;
using std::stringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::fabs;
using std::to_string;
using std::ofstream;

vector<double> inputCards() {
    string input;
    cout << "Enter 4 card faces separated by spaces: ";
    getline(cin, input);
    vector<double> output = {};
    string token;
    stringstream ss(input);

    // Process input stream as tokenized strings separated by spaces
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
                    // Invalid character involved
                    cout << "Invalid input, only numbers 2-10 or J, Q, K, A are allowed.\n" << endl;
                    return vector<double>();
                } else {
                    value = value * 10 + (c - '0');
                }
            }

            if (value < 2 || value > 10) {
                // Invalid character/number involved
                cout << "Invalid input, only numbers 2-10 or J, Q, K, A are allowed.\n" << endl;
                return vector<double>();
            } else {
                output.push_back(value);
            }

        }
    }

    if (output.size() != 4) {
        // Invalid card size or input format
        cout << "Invalid input, please enter 4 valid face cards separated by spaces.\n" << endl;
        return vector<double>();
    }

    return output;
}

vector<double> generateRandomCards() {
    vector<double> output;

    // Generate random seed using current time
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        int randCard = rand() % 13 + 1;
        output.push_back(randCard);
    }
    
    return output;
}

void swapDoubles(double &a, double &b) {
    // Swap between doubles
    double temp = a;
    a = b;
    b = temp;
}

set<vector<double>> permuteCards(vector<double> &cards, int l, int r) {
    // Permutations saved in a set of vectors
    set<vector<double>> permutations;

    // Base case: Last element of vector reached, save permutated cards
    if (l == r) {
        permutations.insert(cards);
    } else {
    // Recursion: Permute sub sections of cards
        for (int i = l; i <= r; i++) {
            swapDoubles(cards[l], cards[i]);
            auto subPerm = permuteCards(cards, l + 1, r);
            permutations.insert(subPerm.begin(), subPerm.end());
            swapDoubles(cards[l], cards[i]);
        }
    }

    return permutations;
}


double eval(double num1, char op, double num2) {
    // Evaluate operations
    if (op == '+') {
        return num1 + num2;
    } else if (op == '-') {
        return num1 - num2;
    } else if (op == '*') {
        return num1 * num2;
    } else if (op == '/') {
        // Note: Zero division of doubles results in `inf`
        return num1 / num2;
    }
}

vector<string> getSolutions(vector<double> cards) {
    vector<string> solutions = {};
    string equation;

    vector<char> ops = {'+', '-', '*', '/'};

    // Iterate through all permutation of operations
    for (int i = 0; i < ops.size(); i++) {
        for (int j = 0; j < ops.size(); j++) {
            for (int k = 0; k < ops.size(); k++) {
                // Parentheses style 1: ((num1 op1 num2) op2 num3) op3 num 4
                if (fabs(eval(eval(eval(cards[0], ops[i], cards[1]), ops[j], cards[2]), ops[k], cards[3]) - 24.0) < 1e-8) {
                    equation = "((" + to_string((int) cards[0]) + " " + ops[i] + " " + to_string((int) cards[1]) + ") " + ops[j] + " " + to_string((int) cards[2]) + ") " + ops[k] + " " + to_string((int) cards[3]);
                    solutions.push_back(equation);
                }

                // Parentheses style 2: (num1 op1 (num2 op2 num3)) op3 num4
                if (fabs(eval(eval(cards[0], ops[i], eval(cards[1], ops[j], cards[2])), ops[k], cards[3]) - 24.0) < 1e-8) {
                    equation = "(" + to_string((int) cards[0]) + " " + ops[i] + " " + "(" + to_string((int) cards[2]) + " " + ops[j] + " " + to_string((int) cards[3]) + "))" + " " + ops[k] + " " + to_string((int) cards[3]);
                    solutions.push_back(equation);
                }

                // Parentheses style 3: (num1 op1 num2) op2 (num3 op3 num4)
                if (fabs(eval(eval(cards[0], ops[i], cards[1]), ops[j], eval(cards[2], ops[k], cards[3])) - 24.0) < 1e-8) {
                    equation = "(" + to_string((int) cards[0]) + " " + ops[i] + " " + to_string((int) cards[1]) + ") " + ops[j] + " (" + to_string((int) cards[2]) + " " + ops[k] + " " + to_string((int) cards[3]) + ")";
                    solutions.push_back(equation);
                }

                // Parentheses style 4: num1 op1 ((num2 op2 num3) op3 num4)
                if (fabs(eval(cards[0], ops[i], eval(eval(cards[1], ops[j], cards[2]), ops[k], cards[3])) - 24.0) < 1e-8) {
                    equation = to_string((int) cards[0]) + " " + ops[i] + " ((" + to_string((int) cards[1]) + " " + ops[j] + " " + to_string((int) cards[2]) + ") " + ops[k] + " " + to_string((int) + cards[3]) + ")";
                    solutions.push_back(equation);
                }

                // Parentheses style 5: num1 op1 (num2 op2 (num3 op3 num4))
                if (fabs(eval(cards[0], ops[i], eval(cards[1], ops[j], eval(cards[2], ops[k], cards[3]))) - 24.0) < 1e-8) {
                    equation = to_string((int) cards[0]) + " " + ops[i] + " (" + to_string((int) cards[1]) + " " + ops[j] + " (" + to_string((int) cards[2]) + " " + ops[k] + " " + to_string((int) cards[3]) + "))";
                    solutions.push_back(equation);
                }
            }
        }
    }

    return solutions;
}

vector<string> solve24(set<vector<double>> permCards) {
    vector<string> solutions;
    vector<string> permSols;

    // Sequentially iterate through a set of permutated cards
    for (auto it = permCards.begin(); it != permCards.end(); it++) {
        auto permVector = *it;
        permSols = getSolutions(permVector);
        solutions.insert(solutions.end(), permSols.begin(), permSols.end());
    }

    return solutions;
}

void printCards(vector<double> cards) {
    // Iterate through vector to output all cards
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
            cout << (int) cards[i] << " ";
        }
    }
    cout << endl;
}

void printSolutions(vector<string> solutions) {
    // Outputs solution vector
    for (int i = 0; i < solutions.size(); i++) {
        cout << (i+1) << ". " << solutions[i] << endl;
    }
}

string stringifyCardVector(vector<double> vec) {
    string strVec = "";
    for (int i = 0; i < vec.size(); i++) {
        if ((int) vec[i] == 1) {
            strVec += "A";
        } else if ((int) vec[i] == 11) {
            strVec += "J";
        } else if ((int) vec[i] == 12) {
            strVec += "Q";
        } else if ((int) vec[i] == 13) {
            strVec += "K";
        } else {
            strVec += to_string((int) vec[i]);
        }
        strVec += " ";
    }

    return strVec;
}

void saveVectorToFile(const vector<string> &vec, const string &fileName, const string cards) {
    ofstream outFile;
    outFile.open(fileName);
    outFile << "Cards: " << cards << endl << endl;
    for (const auto &line : vec) {
        outFile << line << endl;
    }
    outFile.close();
}
