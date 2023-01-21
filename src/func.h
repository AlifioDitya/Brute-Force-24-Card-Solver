// Helper functions declarations

#ifndef FUNC_H
#define FUNC_H

#include <vector>

using std::vector;

vector<int> inputCards();
// Returns vector with integer elements from 1-13 resembling face cards.

vector<int> generateRandomCards();
// Returns vector with randomly generated hand of 4 cards (1-13). 

void printCards(vector<int> cards);
// Outputs all cards in a vector

#endif