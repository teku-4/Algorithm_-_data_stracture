#include <iostream>
using namespace std;
void insertionSorting();
int main()
{
/***********************************************************************
 algorithm of selection sorting.
 1 start.
 2 declaring  the temp and the lists of nubers.
 3 looping  throught the lists by inrementing until the last element.
 3.1 looping in decreament up to j=1 to comper eachelement in lists.
 3.2 if the second greater than the frist elemnet swaping the number
 3.3 if the second not greater than the frist elemnts breake the inner loop.
 3.4 reapet from step 3.1 utill 3.3 up to the condition is true. 
 5 reapeates the whole step starting from step 3 upto th condition is true.
 6 print sorted.
 7 end
  ************************************************************************************/

  insertionSorting();
 
    
return 0;
    
}
void insertionSorting()
{
    int lists[]={4,3,8,7,9,20,40,24,38,78,65,45,60,-2,0,-45};
    int temp;
    int len=sizeof(lists)/sizeof(lists[0]);
    for(int i=1; i<=len-1;i++)
    {
        for(int j=i; j>=1; j--)
        {
            if(lists[j]<lists[j-1])
            {
             temp=lists[j];
             lists[j]=lists[j-1];
             lists[j-1]=temp;
            }
            else
            {
                break;
            }
        }
    }
    for(int a:lists )
    {
        cout<<a<<"  ";
    }
}

