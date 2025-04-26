
#include <iostream>
#include <utility>

using namespace std;
int main(){
    //buble sort
    string studs[]={"Abebe Beleachew","Makbel Kebede","Bereket Natneal","Barkot Samuel","Getachew Alemu","Abebe Alemayehu","Yayobe Shambel"};
  int len=sizeof(studs)/sizeof(studs[0]);
  
   int minidex=0;
   for(int i=0;i<len-1;i++){
    minidex=i;
    for(int j=i+1;j<len;j++){
        if(studs[j]<studs[minidex])
            minidex=j;
    }
        if(minidex!=i){
            swap(studs[minidex],studs[i]);
        
    }
   }

   for(string name:studs){
    cout<<name<<endl;
   }
   int numbers[] = {10, 4, -2, 12, 5, 2, 15, -5, 0};
   int len2 = sizeof(numbers)/sizeof(numbers[0]);
   for(int i=1;i<len2;i++){
    for(int j=i;j>=1;j--){
        if(numbers[j-1]>numbers[j]){
            swap(numbers[j-1],numbers[j]);
        }
        else{
            break;
        }
    }
   }
   for(int number:numbers){
    cout<<number<<" ";
   }
 for(int i=1;i<len;i++){
    for(int j=i;j>=1;j--){
        if(studs[j-1]>studs[j]){
            swap(studs[j-1],studs[j]);

        }
        else{
            break;

        }
    }
 }
 for(string nam:studs){
    cout<<"\n"<<nam<<endl;
 }
    return 0;
}