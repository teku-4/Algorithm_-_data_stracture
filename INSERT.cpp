#include <iostream>
#include <utility>
using namespace std;
int main(){
    int lists[]={20,-2,2,4,1,3,7,5,6,9,8,};
    int min=0;
    int len=sizeof(lists)/sizeof(lists[0]);
 
 for(int i=1;i<len;i++){
    for(int j=i;j>=1;j--){
        if(lists[j-1]>lists[j]){
            swap(lists[j-1],lists[j]);
        }
        else{
            break;
        }
    }
 }
 for(int l:lists){
    cout<<l<<" ";
 }
 
    return 0;
}