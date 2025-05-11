#include <iostream>
using namespace std;

struct node {
    string Fullname;
    int id;
    node* prev;
    node* next;
} *start = NULL, *tail = NULL;

void addingFront(string name, int id) {
    node* temp = new node;
    temp->Fullname = name;
    temp->id = id;
    temp->prev = nullptr;
    temp->next = nullptr;
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
void addingEnd(string name,int id){
    node * temp=new node;
    temp->Fullname=name;
    temp->id=id;
    temp->next=nullptr;
    temp->prev=nullptr;
    if(!start){
        start=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void addingPrePosition(int id, string name,int kid){
    node *temp=new node;
    temp->Fullname=name;
    temp->id=id;
    temp->next=nullptr;
    temp->prev=nullptr;

    if(!start){
        cout<<"empty data to entered by id"<<endl;
        start=temp;
        tail=temp;
    }
    else if(start->id==kid){
        cout<<"only one data"<<endl;
        addingFront( name,  id);
    }
    else {
        node *curr=start;
        while(curr&&curr->id!=kid){
            curr=curr->next;
        }
        if(!curr){
            cout<<"their is no such id nin this lists  simply the data is added at end"<<endl;
            addingEnd(name, id);
        }
        else{
            temp->next=curr;
            temp->prev=curr->prev;
            curr->prev->next=temp;
        }
    }
}
void addingaftrepos(int id,string name,int kid){
    node *temp=new node;
    temp->Fullname=name;
    temp->id=id;
    temp->prev=nullptr;
    temp->next=nullptr;
    if(!start){
        cout<<"empty lists"<<endl;
        start=temp;
        tail=temp;
    }
    else if(tail->id==kid){
        cout<<"element is found at end so added end"<<endl;
        addingEnd( name, id);
    }
    else {
        node *curr=start;
        while(curr&&curr->id!=kid){
            curr=curr->next;
        }
       if(!curr){
        cout<<"not found id added front"<<endl;
        addingFront( name, id);

        }
        else{
            temp->next=curr->next;
            temp->prev=curr;
            curr->next->prev=temp;
            curr->next=temp;

        }
       }
    }
void update(int kid){
    if(!start)cout<<"empty"<<endl;
    node *curr=start;

    while(curr&&curr->id!=kid)
    {
    curr=curr->next;
    }
    if(curr->id==kid){
        cout<<"Name: "<<curr->Fullname<<" is udated"<<endl;
        curr->Fullname="Adane Girma";
        
       }
       else cout<<"not found";
}    
void deletsendFront(){
    node *temp=start;
    if(!start){
        cout<<"empty";
    }
  else if(!start->next){
    start=nullptr;
    tail=nullptr;
  }
  else{
    start=start->next;
    start->prev=nullptr;

  }
  delete temp;
  cout<<"deleation succesfuulyy";
}
void deletsend(){
    node *temp=tail;
    if(!start){
        cout<<"empty";
    }
    else if(!tail->prev)
    {
        tail=nullptr;
        start=nullptr;
    }
    else{
        tail=tail->prev;
        tail->next=nullptr;

    }
    delete temp;
    cout<<" end deleatio succesfully";
}
void byiddelation(int kid){
    node *temp=start;
    if(!start)cout<<"empty";
    else if(start->id==kid){
        deletsendFront();
    }
    else if(tail->id==kid){
        deletsend();
    }
    else {
        node *temp=start;
        while(temp&&temp->id!=kid)
        {
            temp=temp->next;
        }
        if(!temp){
            cout<<"not found";
        }
        else{
            
        }
    }
}
void printList() {
   node *curr;
   cout<<"ID \t  "<<"Name:"<<endl;
   cout<<"_____________________________"<<endl;
   for(curr=start;curr;curr=curr->next){
    cout<<curr->id<<"\t "<<curr->Fullname<<endl;
   }
}

int main() {
  
    addingFront("John Doe", 10);
    addingFront("Jane Smith", 20);
    addingFront("Bob Johnson", 30);
    addingFront("Abel Kebede", 40);
    addingEnd("Dani Baye", 50);
    update(10);

    addingPrePosition(60, "Abebe Kebede", 70);
    addingaftrepos(25, "Getachew Damtow", 110);
    printList();
    deletsendFront();
    printList();
    deletsend();
    printList();

    
    return 0;
}