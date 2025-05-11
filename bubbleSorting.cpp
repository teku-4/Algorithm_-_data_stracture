#include <iostream>
using namespace std;
void bubbleSorting();
int main()
{
/***********************************************************************
 algorithm of buble sorting.
 1 start.
 2 declaring  the temp variable and the lists of nubers.
 3 looping in decrement throught the lists to compare each elemnet exept the last one element. with nearest to the right toit.
 4 looping in increamnt to  conpare  each elements  exept the last one.
 4.1 if they are not ordered swaping the elemnts.
 4.2 put the greater elments to the right of at every elements.
 4.3 reapeat the step 4 up to 4.2 until it is true.
 5 reapiting the step from step 3 until  all elemnts area compard with each other.
 6 print sorted.
 7 end
  ************************************************************************************/

  bubbleSorting();
 
    
return 0;
    
}
void bubbleSorting()
{
    int lists[]={4,3,8,7,9,20,40,24,38,78,65,45,60};
    int temp;
    int len=sizeof(lists)/sizeof(lists[0]);
    for(int i=len-2;i>=0; i--)
    {
        for(int j=0; j<=i; j++)
        {
            if(lists[j]>lists[j+1])
            {
                temp=lists[j];
                lists[j]=lists[j+1];
                lists[j+1]=temp;
            }
        }
    }
    for(int a:lists )
    {
        cout<<a<<"  ";
    }
}

