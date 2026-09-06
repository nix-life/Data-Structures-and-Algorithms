#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& array, int high, int low) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return i+1;
}

void quicksort(vector<int>& array, int high, int low = 0) {
    if (low < high) {
        int pivot = partition(array, high, low);
        quicksort(array, pivot-1, low);
        quicksort(array, high, pivot+1);
    }

}

int main() {
    vector<int> list = { 64, 34, 25, 12, 22, 11, 90, 5 };

    quicksort(list, list.size()-1);


    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }

    return 0;
}
