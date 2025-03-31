#include <iostream>
using namespace std;
void selectionSorting();
int main()
{
/***********************************************************************
 algorithm of selection sorting.
 1 start.
 2 declaring  the temp, and minindex variable and the lists of nubers.
 3 looping  throught the lists by inrementing to find the minimum nuber index and
 3.1 if nuber is lethan the number at min index puts the minimum number of index to minindex.
 3.2 reapeats the step 3.1 untill the condition is true.
 4 if min index is not equals to the frist i value swaping the number
 5 reapeates the step from stem  3 untill 4 upto th condition is true.
 6 print sorted.
 7 end
  ************************************************************************************/

  selectionSorting();
 
    
return 0;
    
}
void selectionSorting()
{
    int lists[]={4,3,8,7,9,20,40,24,38,78,65,45,60,-2,0,-45};
    int temp,minindex;
    int len=sizeof(lists)/sizeof(lists[0]);
    for(int i=0; i<len-1;i++)
    {
        minindex=i;
        for(int j=i+1; j<len; j++)
        {
            if(lists[j]<lists[minindex])
            {
            minindex=j;
      
                }
        }
        if(minindex!=i)
        {
            temp=lists[i];
            lists[i]=lists[minindex];
            lists[minindex]=temp;
        }
    }
    for(int a:lists )
    {
        cout<<a<<"  ";
    }
}

