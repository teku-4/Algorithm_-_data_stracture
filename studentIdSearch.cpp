#include <iostream>
#include <ctime>
using namespace std;
void menu(){
	cout<<"press 1 to search sequentially:"<<endl;
	cout<<"press 2 to search using binary:"<<endl;
	cout<<"press 0 to exit"<<endl;

}
void lenear_search(){
	int t1,t2;
	t1=clock();
	int key,index=0,n;
	cout<<"How many elements do you want to enter?"<<endl;
	cin>>n;
	cout<<"Enter the id of students: " <<endl;
	int lists[n];
	for(int i=0;i<n;i++){
		cin>>lists[i];
	}
	cout<<"Enter the id students to search: "<<endl;
	cin>>key;
	for(int i=0;i<n;i++){
		if(lists[i]==key)
		{
			
			index=i;
			cout<<"The students you search found at" <<index<<" position"<<endl;
		}
	}
	if(index==0){
		cout<<"This elemnts ("<<key<<") is not found in this lists:"<<endl;
	}
	t2=clock();
	int t=t2-t1;
	int timeTaken=t/1000;
	cout<<"The time "<<timeTaken<<" second is taken to search students"<<endl;
}
void binary_search()
{
	
	int t1,t2;
	t1=clock();
	int key,index=0,n;
	cout<<"How many students do you want to enter?"<<endl;
	cin>>n;
	cout<<"Enter the id of students: " <<endl;
	int lists[n];
	for(int i=0;i<n;i++){
		cin>>lists[i];
	}
	cout<<"Enter the key id to search: "<<endl;
	cin>>key;
	int left=0,mid=0;
	int right=n-1;
	while(left<=right)
	{
		
		mid=(left+right)/2;
		if(lists[mid]==key){
			index=mid;
			break;
		}
		else if(lists[mid]>key){
			right=mid-1;
			
		}
		else{
			left=mid+1;
		}
		
	}
	if(index==0){
		cout<<"there is no "<<key<<" id students in lists"<<endl;
	}
	else{
     cout<<"the students you want found at "<<index<<endl;
	}
    t2=clock();
	int t=t2-t1;
	int timeTaken=t/1000;
	cout<<"The time "<<timeTaken<<" second is taken to search students"<<endl;
}
	



int main(){
	while(1){
	int choice;
	menu();
	cout<<"Enter your choice from the main menu"<<endl; 
	cin>>choice;
		if(choice==0){
		  
			cout<<"Goodbye!!!"<<endl;
			break;
			
	}
	switch(choice){
		case 1:
        lenear_search();
        break;
        case 2:
        binary_search();
		break;
	    default:
			cout<<"wrong input"<<endl;
						
	}
	
	}
	return 0;
	
}