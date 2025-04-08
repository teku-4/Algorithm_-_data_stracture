#include <iostream>
using namespace std;
struct node{
	int ID;
	string Name;
	node *next;
	node *prev;
	
}*start=NULL,*tail=NULL;

//implematation
//-----------------------------------------------------------------
void addFront(int id, string name){
	node *temp=new node;
	temp->ID=id;
	temp->Name=name;
	temp->next=NULL;
	temp->prev=NULL;
	if(!start){
		start=temp;
		tail=temp;
	}
	else{
		temp->next=start;
		start->prev=temp;
		start=temp;
	}
}


//----------------------------------------------------------------------------------------
void addEnd(int id,string name){
	node *temp=new node;
    temp->ID=id;
	temp->Name=name;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(!start){
		start=temp;
		tail=temp;
	}
	else{
		temp->prev=tail;
		tail->next=temp;
		tail=temp;
	}
}
//--------------------------------------------------------------------------------------------
void addToRight(int keyid,int id,string name){
	node *temp=new node;

	temp->ID=id;
	temp->Name=name;
	temp->next=NULL;
	temp->prev=NULL;
	if(!start){
		start=temp;
		tail=temp;
		cout<<"data is added to empty lists "<<endl;
		
	}
	
	else if(start->ID==keyid){
		if(!start->next){
			tail=temp;
		}
		else{
			temp->prev=start;
			start->next->prev=temp;
			start->next=temp;

			
		}
		
		
	}
	else{
		node *temp1=start;
		while(temp1->ID!=keyid && temp1->next!=NULL){
			temp1=temp1->next;
		}
		if(!temp1){
			cout<<"key is not found added at end:"<<endl;
			addEnd(id,name);
		}
		else{
		temp->prev=temp1;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		temp1->next=temp;}
	
		
	}
	
	
	
	
}
//-------------------------------------------------
void deleteEnd(){
	node *temp=tail;
	if(!start){
		cout<<"Empty element lists"<<endl;
	}
	else{
		tail=temp;
		tail=tail->prev;
		tail->next=NULL;
		delete temp;
		cout<<"data is succesfullY! deleted from the end"<<endl;
	}
	
	
}
//---------------------------------------------------------------
void deleteFront(){
	
	if(!start){
		cout<<"No available data to delete"<<endl;
	}
	else{
    node *temp=start;
	start=start->next;
	start->prev=NULL;
	delete temp;
	cout<<"the frist data is succefullY deleted"<<endl;
	
	}
}
//----------------------------------------------------------------------------
void deleteByid(int id){
	if(!start){
		cout<<"Empty elements list"<<endl;
	}
	node *temp=start,*curr;
	while(temp->ID!=id && temp->next!=NULL){
		curr=temp;
		temp=temp->next;
	}
	if(!temp){
		cout<<"your entered id is not found so the data at end is deled"<<endl;
		
	}
	curr->next=temp->next;
	temp->next->prev=temp;
	delete temp;
	cout<<"the data :"<<temp->Name<<" is deleted succefully!"<<endl;
	
	
	
	
}
void search(int id){
	if(!start){
		cout<<"Empty lists"<<endl;
	}
	node *curr=start;
	while(curr->ID!=id&&curr->next!=NULL){
		curr=curr->next;
	}
	if(curr->ID==id){
		cout<<"Name: "<<curr->Name<<endl;
	}
	else{
		cout<<"the student you search is not found in this data"<<endl;
	}
}
void sortById(){
	if(!start||!start->next){
		cout<<"only one data or No avilable data to sort"<<endl;
	}
	bool swaped;
	do{
		swaped=false;
	
		node *curr=start;
		while(curr->next!=NULL){
			if(curr->ID>curr->next->ID){
				swap(curr->ID,curr->next->ID);
				swap(curr->Name,curr->next->Name);
				
				swaped=true;
			}
			curr=curr->next;
		}
		
		
	}
	while(swaped);
	cout<<"==============sorted====="<<endl;
		node *temp=start;
	  while (temp != NULL) {
        cout << temp->ID << "\t" << temp->Name  << endl;
        temp = temp->next;
    }
}
//-------------------------------------------------------------
void display() {
    node *temp = start;
    while (temp != NULL) {
        cout << temp->ID << "\t" << temp->Name  << endl;
        temp = temp->next;
    }
}
int main(){
	addFront(10,"Abel");
	addEnd(20,"Makbel");
	addFront(11,"Kebede");
	addFront(13,"abebe");
	addFront(15,"dani");
	addFront(21,"bereket");
	
	
	
	display();
	int keyid;
	cout<<"Enter key id: ";
	cin>>keyid;
	addToRight(keyid,9,"Asche");
	cout<<"after to the right of given id"<<endl;
	display();
	cin.get();
	deleteEnd();
	display();
	deleteFront();
	display();
	int id;
	cout<<"enter the id to delete: ";
	cin>>id;
	deleteByid(id);
	display();
	cout<<"\nEnter id to search: ";
	cin>>id;
	search(id);
	sortById();
	
	
	
	return 0;
}








