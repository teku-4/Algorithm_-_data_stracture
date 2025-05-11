#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

int main() {
    // Configuration
    const int SIZE = 10000;  // Test with 100, 1000, 10000
    int* arr = new int[SIZE];  // Dynamic array for memory tracking
    
    // Initialize array with random values
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100000;
    }
    int target = arr[SIZE - 1];  // Worst-case scenario

    // Track memory usage (approximate)
    size_t memory_used = sizeof(int) * SIZE;
    cout << "Memory used by array: " << memory_used / 1024 << " KB\n\n";

    // ===== 1. Pure Linear Search =====
    auto start1 = high_resolution_clock::now();
    int found1 = -1;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == target) {
            found1 = i;
            break;
        }
    }
    auto stop1 = high_resolution_clock::now();
    auto time1 = duration_cast<nanoseconds>(stop1 - start1).count();

    // ===== 2. Two-Pointer Search =====
    auto start2 = high_resolution_clock::now();
    int found2 = -1;
    int left = 0, right = SIZE - 1;
    while (left <= right) {
        if (arr[left] == target) {
            found2 = left;
            break;
        }
        if (arr[right] == target) {
            found2 = right;
            break;
        }
        left++;
        right--;
    }
    auto stop2 = high_resolution_clock::now();
    auto time2 = duration_cast<nanoseconds>(stop2 - start2).count();

    // ===== 3. Jump+Linear Search =====
    auto start3 = high_resolution_clock::now();
    int found3 = -1;
    int step = sqrt(SIZE);
    int prev = 0;
    
    // Jump phase
    while (prev < SIZE && arr[prev] <= target) {
        if (arr[prev] == target) {
            found3 = prev;
            break;
        }
        prev += step;
    }
    // Linear phase
    if (found3 == -1) {
        int start = max(0, prev - step);
        for (int i = start; i < min(prev, SIZE); i++) {
            if (arr[i] == target) {
                found3 = i;
                break;
            }
        }
    }
    auto stop3 = high_resolution_clock::now();
    auto time3 = duration_cast<nanoseconds>(stop3 - start3).count();

    // ===== Results =====
    cout << "RESULTS (Array Size: " << SIZE << " | Target at index " << SIZE-1 << ")\n";
    cout << "-------------------------------------------------\n";
    cout << "| Algorithm          | Time (ns) | Space (KB) |\n";
    cout << "-------------------------------------------------\n";
    cout << "| Pure Linear        | " << time1 << " | " << memory_used/1024 << " |\n";
    cout << "| Two-Pointer        | " << time2 << " | " << memory_used/1024 << " |\n";
    cout << "| Jump+Linear        | " << time3 << " | " << memory_used/1024 << " |\n";
    cout << "-------------------------------------------------\n";

    delete[] arr;  // Free memory
    return 0;
}