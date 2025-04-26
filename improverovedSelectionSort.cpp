#include <iostream>
using namespace std;

int main() {
    int numbers[] = {10, 4, -2, 12, 5, 2, 15, -5, 0};
    int len = sizeof(numbers)/sizeof(numbers[0]);
    
   
    int minFront[len] = {0};
    int frontSize = 0;
    
    for (int i = 0; i < len - 1; i++) {
      
        int minIndex = i;
        
        // Check if we have a smaller element in our front
        for (int f = 0; f < frontSize; f++) {
            if (minFront[f] < i) continue; // Already placed
            
            if (numbers[minFront[f]] < numbers[minIndex]) {
                minIndex = minFront[f];
            }
        }
        
        // Still need to check remaining elements
        for (int j = i + 1; j < len; j++) {
            if (numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }
        
       
        if (frontSize < len) {
            minFront[frontSize++] = minIndex;
        }
        
       
        if (minIndex != i) {
            swap(numbers[i], numbers[minIndex]);
        }
    }
    

    for (int i = 0; i < len; i++) {
        cout << numbers[i] << " ";
    }
    
    return 0;
}