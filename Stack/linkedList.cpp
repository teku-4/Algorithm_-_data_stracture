#include <iostream>
#include <fstream>

using namespace std;
struct stacknode{
    int data;
    stacknode *next;
} *top=nullptr;
void  push(int value){
    stacknode *temp=new stacknode;
     temp->data=value;
     temp->next=top;
     top=temp;
}
void  pop(){
    if(!top)cout<<"stack under flow"<<endl;

  else{
    stacknode *temp=top;
    top=top->next;
    delete temp;
  }
}
bool isEmpty(){
    return (!top);
}
void display(){
    stacknode *temp=top;
    cout<<"    top    "<<endl;
    while(temp!=nullptr){
        cout<<"|   "<<temp->data<<"  |"<<endl;
       
        temp=temp->next;
    }
    cout<<"__bottom__"<<endl;
}
int size(){
    stacknode *curr=top;
    int count=0;
    while(curr){
        curr=curr->next;
        count++;
    }
    return count;
}
void saveFile(string fileName){
    if(!top)cout<<"stack under flow"<<endl;
    ofstream myFile(fileName);
    if(!myFile)cout<<"file opning error!"<<endl;

    stacknode *temp=top;
    myFile<<"    top    "<<endl;
    while(temp!=nullptr){
        myFile<<"|   "<<temp->data<<"  |"<<endl;
       
        temp=temp->next;
    }
    myFile<<"__bottom__"<<endl;
    myFile.close();
    cout<<"file is succesfully saved"<<endl;
}
int main(){
push(10);
push(20);
push(30);
push(50);
push(60);
push(70);
saveFile("stackFile.txt");
display();
cout<<"the number of  elements in stack is: "<<size()<<endl;
pop();
pop();
pop();
pop();
pop();
pop();
pop();
display();

if(isEmpty())cout<<"Empty!"<<endl;
else cout<<"not empty!"<<endl;

return 0;
}

