#include <iostream>
using namespace std;
int main(){
    string fruits[]={"apple","juice","mango","chery","avocado"};
   int len=sizeof(fruits)/sizeof(fruits[0]);
    
   for(int i=0;i<len-1;i++)
    {
    for(int j=i+1;j<len;j++){
        if(fruits[i]>fruits[j]){
            swap(fruits[i],fruits[j]);
        }
    }
    
    }
    for(string strs:fruits){
        cout<<strs<<endl;
    }
    //binary search
   string target;
   cout<<"enter the element you want to search"<<endl;
  cin>>target;
    int midle=0;
    int left=0;
    int right=len-1;
    bool found=false;
    while(left<=right){
        midle=(left+right)/2;
        if(fruits[midle]==target){
            cout<<"elemets you want to search found at "<<midle<<endl;
            found=true;
            break;
        }
        else if(fruits[0]==target){
            cout<<"the elements you want to search is found at front"<<endl;
            found=true;
            break;
        }
        else if(fruits[len-1]==target){
            cout<<"the element you search is found at end"<<endl;
            found=true;
            break;

        }
        else if(fruits[midle]>target){
            right=midle-1;
        }
        else if(fruits[midle]<target){
            left=midle+1;
        }
    }
    if(!found){
        cout<<"there is no such fruits in this file";
    }
    return 0;
}