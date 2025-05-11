#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the current index is the minimum
        int min_index = i;

        // Two-pointer-like search for the smallest element
        int left = i + 1;
        int right = n - 1;

        while (left <= right) {
            if (arr[left] < arr[min_index]) {
                min_index = left;
            }
            if (arr[right] < arr[min_index]) {
                min_index = right;
            }
            left++;
            right--;
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int arr[10] = {64, 25, 12, 22, 11, 10, 89, 31, 53, 42};
    int n = 10;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}