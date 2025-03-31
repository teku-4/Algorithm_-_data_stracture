#include <iostream>
using namespace std;
void simpleSorting();
int main()
{
/***********************************************************************
 algorithm of simple sorting.
 1 start.
 2 declaring  the temp variable and the lists.
 3 looping throught lists up to length of lists.
 4 comparing the frist element with in the second element if frist element is greater swaping these elements else lists
  left as it is and passing to the next elemnts to compare with precceding element.
 5 reapiting the loop until all elemnts area compard with each other.
 6 print sorted.
 7 end
  ************************************************************************************/

  simpleSorting();
 
    
return 0;
    
}
void simpleSorting()
{
int temp;    
    
int  lists[]={10,90,40,50,80,70,60,20,30,5,100,25};
int len=sizeof(lists)/sizeof(lists[0]);
for(int i=0; i<len-1;i++)
{
    for(int j=i+1;j<len;j++)
    {
        if(lists[j]<lists[i])
        {
            temp=lists[i];
            lists[i]=lists[j];
            lists[j]=temp;
        }
        
    }
    
}
// displaying the sorted 
for(int a:lists){
    cout<<a<<"  ";
}
}
