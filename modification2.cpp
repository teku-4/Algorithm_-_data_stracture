#include <iostream>
using namespace std;

int main() {
    // Small test array (10 elements)
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 80; // Target to search
    int n = 10;      // Array size

    // Jump Search Phase (block size = √n ≈ 3)
    int step = 3;    // Since √10 ≈ 3
    int prev = 0;

    // Jump through blocks
    while (prev < n && arr[prev] <= target) {
        if (arr[prev] == target) {
            cout << "Found at index (Jump Phase): " << prev << endl;
            return 0;
        }
        prev += step; // Jump ahead
    }

    // Two-Pointer Linear Search (within the identified block)
    int left = max(0, prev - step); // Start of block
    int right = min(prev, n - 1);   // End of block

    while (left <= right) {
        if (arr[left] == target) {
            cout << "Found at index (Left Pointer): " << left << endl;
            return 0;
        }
        if (arr[right] == target) {
            cout << "Found at index (Right Pointer): " << right << endl;
            return 0;
        }
        left++;  // Move left forward
        right--; // Move right backward
    }

    // If not found
    cout << "Target not found!" << endl;
    return 0;
}