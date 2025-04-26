#include <iostream>
using namespace std;
int main(){
    int numbers[] = {10, 4, -2, 12, 5, 2, 15, -5, 0};
    int len = sizeof(numbers)/sizeof(numbers[0]);
    int start=0;
    int ends=len-1;
    int pivot=numbers[start];
    while(start<ends){
        while(numbers[start]<=pivot){
            start++;
        }
        while(numbers[ends]>pivot){
            ends--;
        }
        if(start<ends){
            swap(numbers[start],numbers[ends]);
          

        }
    }
    swap(numbers[start], numbers[ends]);

    for(int number:numbers){
        cout<<number<<endl;
    }
    return 0;

}