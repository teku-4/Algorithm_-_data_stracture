#include <iostream>
using namespace std;

int main() {
    // Initialize an array
    int arr[] = {64, 25, 12, 22, 11, 10, 89, 31, 53, 42};
    int n = 10; // Size of the array

    // Dual-Pointer (Min-Max) Selection Sort
    int start = 0;
    int end = n - 1;

    while (start < end) {
        // Initialize min and max indices
        int min_idx = start;
        int max_idx = end;

        // Scan the unsorted subarray from both ends
        int left = start;
        int right = end;

        while (left < right) {
            // Compare elements at left and right pointers
            if (arr[left] < arr[right]) {
                if (arr[left] < arr[min_idx]) min_idx = left;
                if (arr[right] > arr[max_idx]) max_idx = right;
            } else {
                if (arr[right] < arr[min_idx]) min_idx = right;
                if (arr[left] > arr[max_idx]) max_idx = left;
            }
            left++;
            right--;
        }

        // Handle middle element (if array length is odd)
        if (left == right) {
            if (arr[left] < arr[min_idx]) min_idx = left;
            if (arr[left] > arr[max_idx]) max_idx = left;
        }

        // Swap min to the start
        int temp = arr[start];
        arr[start] = arr[min_idx];
        arr[min_idx] = temp;

        // If max was at start, update its new position
        if (max_idx == start) max_idx = min_idx;

        // Swap max to the end
        temp = arr[end];
        arr[end] = arr[max_idx];
        arr[max_idx] = temp;

        // Shrink the unsorted subarray
        start++;
        end--;
    }

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}