#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& list, int low, int high) {
    int pivot = list[high];
    int i = low-1;

    for (int j = low; j < high; j++) {
        if (list[j] < pivot) {
            i++;
            int temp = list[j];
            list[j] = list[i];
            list[i] = temp;
        }
    }

    int temp = list[i+1];
    list[i+1] = list[high];
    list[high] = temp;

    return i+1;
}

void quicksort(vector<int>& list, int low, int high) {
    if (low < high) {
        int idx = partition(list, low, high);
        quicksort(list, low, idx-1);
        quicksort(list, idx+1, high);
    }
}

int main() {
    vector<int> list = { 64, 34, 25, 12, 22, 11, 90, 5 };

    quicksort(list, 0, list.size()-1);
    

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }

    return 0;
}
