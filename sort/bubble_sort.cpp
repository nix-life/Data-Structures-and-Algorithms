#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> list = { 64, 34, 25, 12, 22, 11, 90, 5 };

    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list.size()-i-1; j++) {
            int temp = list[j];
            if (list[j] > list[j+1]) {
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }

    return 0;
}
