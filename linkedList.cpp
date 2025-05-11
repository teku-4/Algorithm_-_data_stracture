#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;
struct node{
	int ID;
	string name;
	node *next;
	
};
node *start=NULL;

//---------insert front--------------------------------------------------------
void Insert_front(int id,string names){
	node *temp=new node;
	temp->ID=id;
	temp->name=names;
	temp->next=start;
	start=temp;
	
	
}

//----insert end-------------------------------------------------------------------
void Insert_end(int id,string names){

  node	*temp= new node;
  temp->ID=id;
  temp->name=names;
  temp->next=NULL;
  if(!start){
	  start=temp;
  }	
  node *temp1=start;
  while(temp1->next!=NULL){
	  temp1=temp1->next;
  }
  
  temp1->next=temp;
}
//----------------insert at specific position-------------------------------
void insert_position(int pos,int id,string name)
{
cout<<"not implemented"<<endl;	
	
}
//-----------------delete front----------------------------------
void delete_front(){
	node *temp=new node;
	if(!start){
		cout<<"Empty data to delete"<<endl;
	}
	else if(start->next==NULL){
	     start=NULL;
		 delete temp;	
	}
	else{
		
 temp=start;
  start=start->next;
  delete temp;	
	}
 
}


//---delete end----------------------------------------------------
void delete_end(){
	node *temp=new node;
	if(!start){
		cout<<"Empty data to delete"<<endl;
	}
	else if(start->next==NULL){
	     start=NULL;
		 delete temp;	
	}
	else{
	
	node *temp1=start->next;
	temp=start;
	while(temp1->next!=NULL){
		temp1=temp1->next;
		temp=temp->next;
		
	}
	delete temp1->next;
	temp->next=NULL;
}}

//--display-------------------------------------------------------------
void display(){
	if(!start){
		cout<<"Empty lists"<<endl;
		return;
	}
	else{
		
		cout<<"ID       "<<"Name"<<endl;
		cout<<"================================"<<endl;
		node *temp=start;
		while(temp!=NULL){
			cout<<temp->ID<<"   "<<temp->name<<endl;
			temp=temp->next;
		
			
		}
		cout<<"------------------------------------------"<<endl;

		}
	
}
//--main menu-----------------------------------------------
void menu(){
     cout<<"_____________________________________________"<<endl;
	
	cout<<" 1) to add at the begnning"<<endl;
	cout<<" 2) to add at the end "<<endl;
	cout<<" 3)to add at specific position"<<endl;
	cout<<" 4) to delete from front"<<endl;
	cout<<" 5) to delete from end"<<endl;
	cout<<" 6) to sort by id  "<<endl;
	cout<<" 7) to sort by name"<<endl;
	cout<<" 8) to search by id"<<endl;
	cout<<" 9) to save data "<<endl; 
	cout<<" 10) to display;"<<endl;
	cout<<" 0) exite "<<endl;
	cout<<"_____________________________________________"<<endl;
}
 //----sort by id--------------------------------------------------------
 void sortById(){
 	node *temp=new node;
 	int index=0,count=0;
 	int tp,len;
 	temp=start;
 	
 	while(temp!=NULL){
 		len++;
 	    temp=temp->next;
	 }
	 
	 
 	for(int i=0;i<len-1;i++){
		 for(j=i+1;j<len;j++){
			 if(temp->ID[i]>temp->ID[j])
		 }
	 }
	 
 }
 void sortByName(){
 	
	 
 }
 void searchById(){
	 
 }
 void save(){
	 
 }
int main(){
	
while(true)
	{

    menu();
	int chooce;
	cout<<"enter your choice from the menu"<<endl;
	cin>>chooce;
	if(chooce==0){
		cout<<"Goodbye"<<endl;
		break;
	}
	switch(chooce)
	
	{
	case 1:{
		 int len;
		cout<<"how many data you want to add"<<endl;
		cin>>len;
		string name;
		int id;	
	for(int i=0;i<len;i++)	{
	cout<<" Id:  "<<(i+1)<<" ";
	cin>>id;
	cin.ignore();
	cout<<"\n Name:  ";
	getline(cin,name);
	Insert_front(id,name);
	}
	break;
}
       case 2:{
       		 int len;
		cout<<"how many data you want to add"<<endl;
		cin>>len;
		string name;
		int id;	
	for(int i=0;i<len;i++)	{
	cout<<" Id:  "<<(i+1)<<" ";
	cin>>id;
	cin.ignore();
	cout<<"\n Name:  ";
	getline(cin,name);
	Insert_end(id,name);}
	
	break;
}
       case 3:{
       		 int len,pos;
		cout<<"how many data you want to add:  ";
		cin>>len;
		cout<<"\n Enter the position:  ";
		cin>>pos;
		string name;
		int id;	
		cout<<endl;
	for(int i=0;i<len;i++)	{
	cout<<" Id:  "<<(i+1)<<" ";
	cin>>id;
	cin.ignore();
	cout<<"\n Name:  ";
	getline(cin,name);
	insert_position(pos,id,name);
	}
	
	break;
    }
   
    case 4: 	
    delete_front();
    break;
   case 5:
   	delete_end();
   	break;
    case 6:
    	sortById();
    	break;
    case 7:
    	sortByName();
    	break;
    case 8:
    	searchById();
    	break;
    case 9:
    	save();
   case 10:
   	display();
   	break;
   default:
   	cout<<"invalid input"<<endl;}}
   	
	   return 0;}
