#include <iostream>
#include "func.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<int> cards = inputCards();

    while (cards.empty()) {
        cards = inputCards();
    }

    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i] << " ";
    }
    return 0;
}