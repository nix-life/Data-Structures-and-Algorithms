#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> list = { 64, 34, 25, 12, 22, 11, 90, 5 };

    for (int i = 1; i < list.size(); i++) {
        int idx = i;
        int value = list[i];

        for (int j = i-1; j >= 0; j--) {
            if (list[j] > value) {
                list[j+1] = list[j];
                idx = j;
            } else break;
        }

        list[idx] = value;
    }

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }

    return 0;
}
