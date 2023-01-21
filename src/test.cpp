#include <iostream>
#include "func.cpp"

using namespace std;

int main() {
    vector<int> v = {1,2,3,4};

    auto perm = permuteCards(v, 0, v.size()-1);

    // for (int i = 0; i < perm.size(); i++) {
    //     for (int j = 0; j < perm[i].size(); j++) {
    //         cout << perm[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << endl << perm.size() << endl;

    return 0;
}