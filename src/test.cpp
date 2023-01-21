#include <iostream>
#include "func.cpp"

using namespace std;

int main() {
    vector<double> v = {6,6,6,6};

    // auto perm = permuteCards(v, 0, v.size()-1);

    // // All card permutations
    // for (auto it = perm.begin(); it != perm.end(); it++) {
    //     auto permVector = *it;
    //     for (int j = 0; j < permVector.size(); j++) {
    //         cout << permVector[j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl << perm.size() << endl;

    vector<string> sols = getSolutions(v);

    for (string sol: sols) {
        cout << sol << endl;
    }

    return 0;
}