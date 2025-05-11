#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct node{
    string Name;
    string Lname;
    node *next;
} *start=NULL;
void addFront(string name,string lname) {
    node *temp=new node;
    temp->Name=name;
    temp->Lname=lname;
    temp->next=start;
    start=temp;
}
void addEnd(string name,string lname){
    node *temp=new node;
    temp->Name=name;
    temp->Lname=lname;
    temp->next=NULL;
    if(!start)start=temp;
    else {
    node *curr=start;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;}
}
void addToleft(string kname,string name,string lname){
    node *temp=new node;
    temp->Name=name;
    temp->Lname=lname;
    if(!start || start->Name==kname)addFront(name, lname);
    else{
        node *curr=start;
        node *curr2;
 while(curr->Name!=kname && curr->next!=0){
    curr2=curr;
    curr=curr->next;

 }
 if(curr==NULL)addEnd( name, lname);

 else{
 temp->next=curr;
 curr2->next=temp;

 }
    }
}
void aDDtoRight(string kname,string name,string lname){
    node *temp=new node;
    temp->Name=name;
    temp->Lname=lname;
    
    if(!start)addFront( name, lname);
    else{
        node *curr=start;
        while(curr->Name!=kname && curr->next!=NULL){
            curr=curr->next;
        }
        if(curr==NULL){
           addEnd( name,  lname);
        }
        else{
       temp->next=curr->next;
       curr->next=temp;
        }

    }
}

 void sort(){
    if(!start||!start->next)cout<<"only one data or empty";
    node *temp1=start;
    node *temp2=NULL;
    bool swaped;
    do{
        swaped=false;
        while (temp1->next!=NULL){
            if(temp1->Name>temp1->next->Name) {
            swap(temp1->Name,temp1->next->Name);
            swap(temp1->Lname, temp1->next->Lname);
            swaped=true;
            temp1=temp1->next;
            }
            

            
        }
        temp2=temp1;
   
    }
    while(swaped);
 }
void savedTofile(string filename){
    ofstream outFile;
    outFile.open(filename,ios::app);
    if(!outFile)cout<<"opning error"<<endl;
    node *data=start;
    int count=0;
    
    // coutFile.wrire("Frits Name"<<"\t "<<"Last Name");
    while(data!=NULL){
        outFile<<++count<<". "<<data->Name<<"\t\t"<<data->Lname<<endl;
    data=data->next;
    }

}
void display(){
    
    if(!start) cout<<"Empty lists";
    node *data=start;
    cout<<"Frits Name"<<"\t "<<"Last Name"<<endl;
    while(data!=NULL){
        cout<<data->Name<<"\t\t "<<data->Lname<<endl;
        data=data->next;
    }
}
int main(){
 addFront("Abebe", "Bekele");
addFront("Abebe", "Kebede");

addEnd("Abel", "Lemma");
addEnd("Habtamu", "Tadese");
addToleft("Abel", "Mekonin", "hayle");

aDDtoRight("Abel", "Leta", "Kasahun");
sort();
display();
savedTofile("info.txt");

return 0;
}