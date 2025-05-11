#include <iostream>
using namespace std;
int main(){
    int lists[]={2,4,1,3,7,5,6,9,8,};
    int min=0;
    int len=sizeof(lists)/sizeof(lists[0]);

    for(int i=0;i<len-1;i++){
        min=i;
        for(int j=i+1; j<len;j++){
            if(lists[min]>lists[j]){
                min=j;
            }

        }

        if(min!=i){
            swap(lists[i],lists[min]);
        }


    }
    for(int a:lists){
        cout<<a<<" ";
    }
    return 0;
}