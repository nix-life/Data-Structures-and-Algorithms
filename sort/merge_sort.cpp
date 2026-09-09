#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& list1, vector<int>& list2) {
    vector<int> merged_list;

    int i = 0, j = 0;

    while (i < list1.size() && j < list2.size()) {
        if (list1[i] < list2[j]) {
            merged_list.push_back(list1[i]);
            i++;
        } else {
            merged_list.push_back(list2[j]);
            j++;
        }
    }

    if (i < list1.size()) {
        for (int z = i; z < list1.size(); z++) {
            merged_list.push_back(list1[z]);
        }
    } else {
        for (int z = j; z < list2.size(); z++) {
            merged_list.push_back(list2[z]);
        }
    }

    return merged_list;
}

vector<int> mergeSort(vector<int>& list) {
    if (list.size() <= 1) {
        return list;
    }

    int mid = list.size() / 2;

    vector<int> left(list.begin() + 0, list.begin() + mid);
    vector<int> right(list.begin() + mid, list.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    vector<int> list = {64, 34, 25, 12, 22, 11, 90, 5};

    list = mergeSort(list);

    for (int i = 0; i < list.size(); i++) cout << list[i] << "\n";

    return 0;
}
