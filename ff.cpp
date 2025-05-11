#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;
using Clock = chrono::high_resolution_clock;

// 1) Classical Selection Sort
void classicalSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

// 2) Two‑Pointer Selection Sort (your variant)
void twoPointerSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        int left = i + 1;
        int right = n - 1;
        while (left <= right) {
            if (arr[left] < arr[min_index]) min_index = left;
            if (arr[right] < arr[min_index]) min_index = right;
            left++;
            right--;
        }
        swap(arr[i], arr[min_index]);
    }
}

// 3) Min‑Max Selection Sort (adaptive dual selection)
void minMaxSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int min_index = start, max_index = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[min_index]) min_index = i;
            if (arr[i] > arr[max_index]) max_index = i;
        }
        swap(arr[start], arr[min_index]);
        if (max_index == start)  // account for swapped‑out max
            max_index = min_index;
        swap(arr[end], arr[max_index]);
        start++; end--;
    }
}

int main() {
    const int N = 20000;               // size of test array
    static int master[N];              // original data
    static int a[N], b[N], c[N];       // working copies

    // fill master with random data
    mt19937_64 rng(12345);
    uniform_int_distribution<int> dist(1, N);
    for (int i = 0; i < N; i++) {
        master[i] = dist(rng);
    }

    // Helper to copy and time one sort
    auto run = [&](auto sortFunc, int arr[], const char* name) {
        // copy master into arr
        memcpy(arr, master, sizeof(master));
        auto t0 = Clock::now();
        sortFunc(arr, N);
        auto t1 = Clock::now();
        double ms = chrono::duration<double, milli>(t1 - t0).count();
        cout << name << ": " << ms << " ms\n";
    };

    cout << "Timing on N = " << N << " random integers\n";
    run(classicalSelectionSort, a, "Classical Selection Sort   ");
    run(twoPointerSelectionSort, b, "Two‑Pointer Selection Sort ");
    run(minMaxSelectionSort,    c, "Min‑Max Selection Sort     ");

    return 0;
}
