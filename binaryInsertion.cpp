#include <iostream>
using namespace std;
int main(){
    int lists[]={34,-5,7,0,1002,4,1,3,7,5,6,9,8,};
    int min=0;
    int len=sizeof(lists)/sizeof(lists[0]);
for(int i=1;i<len;i++){
    int left=0;
    int key=lists[i];
    int right=i-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(lists[mid]>key){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    for(int j=i-1;j>=left;j--){
        lists[j+1]=lists[j];
    }
    lists[left]=key;
}
for(int i:lists){
    cout<<i<<" ";
}

return 0;
}