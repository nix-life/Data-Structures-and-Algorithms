#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> list = { 64, 34, 25, 12, 22, 11, 90, 5 };

    map<int, int> amount;
    for (int i = 0; i < list.size(); i++) {
        amount[list[i]]++;
    }

    for (auto [i, j] : amount) {
        for (int x = 0; x < j; x++) {
            cout << i << "\n";
        }
    }

    return 0;
}
