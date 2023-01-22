// Helper functions declarations

#ifndef FUNC_H
#define FUNC_H

#include <vector>
#include <set>
#include <string>

using std::vector;
using std::set;
using std::string;

vector<double> inputCards();
// Returns vector of elements in range 1-13 resembling card numbers.

vector<double> generateRandomCards();
// Returns vector with randomly generated hand of 4 cards (1-13). 

void printCards(vector<double> cards);
// Outputs all cards in a vector.

void swapDoubles(double &a, double &b);
// Swap values between two double typed variables.

set<vector<double>> permuteCards(vector<double> &cards, int l, int r);
// Generate all possible permutations of a card vector.

vector<string> getSolutions(vector<double> cards);
// Get all possible arithmetic equations from a given card vector.

vector<string> solve24(set<vector<double>> permCards);
// Solve the 24 Game from a set of permutated cards.

void printSolutions(vector<string> solutions);
// Print all solutions.

string stringifyCardVector(vector<double> vec);
// Create a string from a vector of cards.

void saveVectorToFile(const vector<string> &vec, const string &fileName, const string cards);
// Save the contents of a vector of strings inside a text file.

#endif