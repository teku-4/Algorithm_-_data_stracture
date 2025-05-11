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
	for(int i=0;i<n;i++){
		if(lists[i]==key)
		{
			
			index=i;
			cout<<"The Elements you search found at" <<index<<" position"<<endl;
		}
	}
	if(index==0){
		cout<<"This elemnts ("<<key<<") is not found in this lists:"<<endl;
	}
	t2=clock();
	int t=t2-t1;
	int timeTaken=t/1000;
	cout<<"The time "<<timeTaken<<" second is taken to search elemnts"<<endl;
}
int main(){
	search();
	return 0;
	
}