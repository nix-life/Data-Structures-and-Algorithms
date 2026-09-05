#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> list = { 64, 34, 25, 12, 22, 11, 90, 5 };

    for (int i = 0; i < list.size(); i++) {
        int idx = i;
        for (int j = i; j < list.size(); j++) {
            if (list[idx] > list[j]) {
                idx = j;
            }
        }
        int temp = list[i];
        list[i] = list[idx];
        list[idx] = temp;
    }

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }

    return 0;
}
