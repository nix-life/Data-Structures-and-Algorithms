#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> list = {64, 34, 25, 12, 22, 11, 90, 5};

    int maximum = *max_element(list.begin(), list.end());
    int exp = 1;

    vector<vector<int>> radix(10);

    while (maximum / exp > 0) {
        for (int val : list) {
            int radixIdx = (val / exp) % 10;
            radix[radixIdx].push_back(val);
        }

        list.clear();

        for (auto& bucket : radix) {
            for (int val : bucket) {
                list.push_back(val);
            }
            bucket.clear();
        }

        exp *= 10;
    }

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }

    return 0;
}
