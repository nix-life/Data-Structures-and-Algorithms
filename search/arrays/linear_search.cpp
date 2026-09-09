#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> list = {64, 34, 25, 12, 22, 11, 90, 5};

    int tryValue = 11;
    int idx = -1;

    for (int i = 0; i < list.size(); i++) {
        if (list[i] == 11) {
            idx = i;
            break;
        }
    }

    if (idx != -1) cout << "Index at: " << idx << "\n";
    else cout << "Number not found. \n";

    return 0;
}
