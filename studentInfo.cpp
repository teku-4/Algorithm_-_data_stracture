#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;

struct stud {
    int ID;
    string Name;
    float Mark;
    stud *next;
} *head = NULL;

void addingFront(int id, string name, float mark) {
    stud *data = new stud;
    data->ID = id;
    data->Name = name;
    data->Mark = mark;
    data->next = head; 
    head = data;
}
void addingEnd(int id,string name,float mark){
	stud *temp=new stud;
	temp->ID=id;
	temp->Name=name;
	temp->Mark=mark;
	temp->next=NULL;
	if(!head){
		head=temp;
		
	}
	stud *temp1=head;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next=temp;
	
	
}
//------------------------------------------------------------
void addingSpecific( int pos ,int id,string name,float mark){
	//getting the length of thhe data for error handling purpose

   int 	count=0;
	stud *length=head;
	while(length!=NULL){
		length=length->next;
		count++;
	}
	stud *temp2=new stud;
	temp2->ID=id;
	temp2->Name=name;
	temp2->Mark=mark;
     if(pos>count || pos<1){
		 cout<<"the given position is out of the range"<<endl;
		 delete temp2;
		 
	 }
	 else if(pos==1){
		 addingFront(id,name,mark);
	 }
	 else if(pos==count){
		 addingEnd(id,name,mark);
	 }
	 else{
		 stud *temp3=head;
		 int i=1;
		 while(i<pos-1){
			 temp3=temp3->next;
			 i++;
		 }
		 temp2->next=temp3->next;
		 temp3->next=temp2;
		 
	 }
	
}
//------------------------------------------------------
void deleteFront(){
	stud *temp=new stud;
	if(!head){
		cout<<"there is no data to delete"<<endl;
	}
	else{
	 temp=head;
	 head=head->next;
	 delete temp;}
}
//---------------------------------------------------------------------------
void deleteEnd(){
	
	if(!head){
		cout<<"there is no data to delete"<<endl;
	}
	else if(!(head->next)){
		deleteFront();
	}
	else{
		stud *pre;
		stud *post=head;
		while(post->next!=NULL){
			pre=post;
			post=post->next;
		}
	   pre->next=NULL;
	   delete post;
		
	}
}
//----------------------------------------------------------------------------
void deleteSpecificposition(){
	stud *length=head;
	int count=0;
	int i=2;
	int pos;
	while(length!=NULL){
		length=length->next;
		count++;
	}
	if(!head){
		cout<<"there is no data to delete"<<endl;
	}
	cout<<"Enter position: "<<endl;
	cin>>pos;
	if(pos>1 || pos <1){
		cout<<"the position is out of the range"<<endl;
	}
   else	if(pos==1){
		deleteFront();
	}
	else if(pos==count){
		deleteEnd();
	}
	else{
	stud *pre;
	stud *post=head;
	while(i!=pos){
		pre=post;
		post=post->next;
		i++;
		
	}
	
		pre->next=post->next;
		delete post;
		
	
	}
}
//--------------------------------------------------------------------
void Sort(){

	
stud *primary=new stud;
stud *secondery=head;

while(secondery!=NULL){
	primary=secondery;
	
   secondery=secondery->next;
	if(primary->Name > secondery->Name){
		string temp=primary->Name;
	    primary->Name=secondery->Name;
	    secondery->Name=temp;}
}
 stud *temp1 = head;
    while (temp1 != NULL) {
        cout << temp1->ID << "\t" << temp1->Name << "\t\t" << temp1->Mark << endl;
        temp1 = temp1->next;
    }
}
void save(){
	
}
void search(){

	int keyid;
   int index=0;
   cout<<"Enter the key id  "<<endl;
   int i=1;
   stud *temp=head;
   while(temp!=NULL){
	   temp=temp->next;
	   i++;
	   if(temp->ID==keyid){
		   index=i;
	   }
   }
   if(index==0){
	   cout<<"there is no such students "<<endl;
   }
   else{
	   cout<<"the student you search is found at "<<index<<endl;
	   cout<<"name: "<<temp->Name<<" "<<"mark: "<<temp->Mark<<endl;
   }
}
void displaySaved(){
	
}
void displayMenu() {
    cout << "\n\n";
    cout << setfill('=') << setw(40) << "\n";
    cout << "  STUDENT RECORD MANAGEMENT SYSTEM  \n";
    cout << setfill('=') << setw(40) << "\n";
    cout << setfill(' ');
    
    cout << "\n1.  Add Student at Front\n";
    cout << "2.  Add Student at End\n";
    cout << "3.  Add Student at Specific Position\n";
    cout << "4.  Delete from Front\n";
    cout << "5.  Delete from End\n";
    cout << "6.  Delete from Specific Position\n";
    cout << "7.  Display All Students\n";
    cout << "8.  search Students\n";
    cout << "9.  sort All Students\n";
    cout << "0.  Exit\n";
    cout << setfill('-') << setw(40) << "\n";
    cout << setfill(' ');
    cout << "Enter your choice: ";
}


void display() {
    stud *temp = head;
    while (temp != NULL) {
        cout << temp->ID << "\t" << temp->Name << "\t\t" << temp->Mark << endl;
        temp = temp->next;
    }
}

void clearScreen(){

    cout << string(20, '\n'); 
}

int main() {
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
     
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(choice) {
            case 1: { 
                int count;
                cout << "\nHow many students to add at front? ";
                cin >> count;
                cin.ignore();
                
                for (int i = 0; i < count; i++) {
                    int id;
                    float mark;
                    string name;
                    
                    cout << "\nStudent " << i+1 << ":\n";
                    cout << "ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Name: ";
                    getline(cin, name);
                    cout << "Mark: ";
                    cin >> mark;
                    
                    addingFront(id, name, mark);
                }
                cout << count << " students added at front!\n";
                break;
            }
            
            case 2: { 
                int count;
                cout << "\nHow many students to add at end? ";
                cin >> count;
                cin.ignore();
                
                for (int i = 0; i < count; i++) {
                    int id;
                    float mark;
                    string name;
                    
                    cout << "\nStudent " << i+1 << ":\n";
                    cout << "ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Name: ";
                    getline(cin, name);
                    cout << "Mark: ";
                    cin >> mark;
                    
                    addingEnd(id, name, mark);
                }
                cout << count << " students added at end!\n";
                break;
            }
            
            case 3: { 
                int pos, count;
                cout << "\nEnter position to insert: ";
                cin >> pos;
                cout << "How many students to add at position " << pos << "? ";
                cin >> count;
                cin.ignore();
                
                for (int i = 0; i < count; i++) {
                    int id;
                    float mark;
                    string name;
                    
                    cout << "\nStudent " << i+1 << ":\n";
                    cout << "ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Name: ";
                    getline(cin, name);
                    cout << "Mark: ";
                    cin >> mark;
                    
                    addingSpecific(pos + i, id, name, mark); 
                }
                break;
            }
            
            case 4:
                deleteFront();
                cout << "Front student deleted!\n";
                break;
                
            case 5:
                deleteEnd();
                cout << "Last student deleted!\n";
                break;
                
            case 6: { 
               
                deleteSpecificposition();
                break;
            }
                
            case 7: 
                display();
                break;
            case 8:
            	search();
            	break;
            case 9:
            	Sort();
                
            case 0: // Exit
                cout << "Exiting program...\n";
                break;
                
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            clearScreen();
        }
        
    } while(choice != 0);
    
    return 0;
}
