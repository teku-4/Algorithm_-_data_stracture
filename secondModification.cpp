#include <iostream>
#include <chrono>
#include <algorithm> // for std::copy
using namespace std;
using namespace std::chrono;

int main() {
    // Test data (10 elements)
    int arr[10] = {64, 25, 12, 22, 11, 10, 89, 31, 53, 42};
    int n = 10;

    // --- Classic Selection Sort ---
    int classic_arr[10];
    copy(begin(arr), end(arr), begin(classic_arr));

    auto classic_start = high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // Linear scan for minimum
        for (int j = i + 1; j < n; j++) {
            if (classic_arr[j] < classic_arr[min_idx]) 
                min_idx = j;
        }
        swap(classic_arr[i], classic_arr[min_idx]);
    }
    auto classic_stop = high_resolution_clock::now();

    // --- Two-Pointer Selection Sort ---
    int two_ptr_arr[10];
    copy(begin(arr), end(arr), begin(two_ptr_arr));

    auto two_ptr_start = high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++) {
        int left = i + 1, right = n - 1;
        int min_idx = i;
        // Two-pointer minimum search
        while (left <= right) {
            if (two_ptr_arr[left] < two_ptr_arr[min_idx]) 
                min_idx = left;
            if (two_ptr_arr[right] < two_ptr_arr[min_idx]) 
                min_idx = right;
            left++;
            right--;
        }
        swap(two_ptr_arr[i], two_ptr_arr[min_idx]);
    }
    auto two_ptr_stop = high_resolution_clock::now();

    // --- Results ---
    cout << "CLASSIC SORT:\n";
    cout << "Time: " << duration_cast<nanoseconds>(classic_stop - classic_start).count() << " ns\n";
    cout << "Sorted Array: ";
    for (int x : classic_arr) cout << x << " ";

    cout << "\n\nTWO-POINTER SORT:\n";
    cout << "Time: " << duration_cast<nanoseconds>(two_ptr_stop - two_ptr_start).count() << " ns\n";
    cout << "Sorted Array: ";
    for (int x : two_ptr_arr) cout << x << " ";

    return 0;
}