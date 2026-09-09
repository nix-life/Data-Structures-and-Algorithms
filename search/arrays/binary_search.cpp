#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& list, int target) {
    int left = 0, right = list.size();

    while (left <= right) {
        int mid = (left + right) / 2;
        if (list[mid] == target) return mid;
        else if (list[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> list = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    int target = 15;

    int idx = binarySearch(list, target);

    if (idx != -1) cout << "Index at: " << idx << "\n";
    else cout << "Number not found. \n";

    return 0;
}
