#include <iostream>
#include <ctime>
using namespace std;
void search(){
	int t1,t2;
	t1=clock();
	int key,index=0,n;
	cout<<"How many elements do you want to enter?"<<endl;
	cin>>n;
	cout<<"Enter the elments: " <<endl;
	int lists[n];
	for(int i=0;i<n;i++){
		cin>>lists[i];
	}
	cout<<"Enter the key elements to search: "<<endl;
	cin>>key;
	int left=0,right=0,mid;
	right=n-1;
	while(left<=right){
		mid=(right+left)/2;
		if(lists[mid]==key)
		{
			
			index=mid;
			
		 break;
		}
        else if(lists[mid]<key)
		{
				left=mid+1;
			}
        else{
				
			right=mid-1;
			}
		}
	
	
	
	if(index==0)
	{
		cout<<"This elemnts ("<<key<<") is not found in this lists:"<<endl;
	}
	else{
	
		cout<<"The Elements you search found at " <<index<<" position"<<endl;
	}
	t2=clock();
	int t=t2-t1;
	double timeTaken=t/1000;
	cout<<"The time "<<timeTaken<<" second is taken to search elemnts"<<endl;
}
int main(){
	search();
	return 0;
	
}