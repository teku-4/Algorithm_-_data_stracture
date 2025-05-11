#include <iostream>
using namespace std;
const int Size=10;
int stack_arr[Size];
int top=-1;
void menu(){
    cout<<"1) to push  "<<endl;
    cout<<"2) to pop from top "<<endl;
    cout<<"3) to check Emptyness"<<endl;
    cout<<"4) to check fullness "<<endl;
    cout<<"5) to display from the top"<<endl;
    cout<<"6) to display all"<<endl;
    cout<<"7) to check available space"<<endl;
    cout<<"0) to logout "<<endl;
}
void push(int data ){
    if(top>=Size-1)cout<<"Stack over flow"<<endl;
    else stack_arr[++top]=data;
}
void pop(){
    if(top<=-1)cout<<"Stack under flow"<<endl;
    else 
    {
    cout<<stack_arr[top]<<" is deleted!"<<endl;
    stack_arr[--top];
}

}
bool isEmpty(){
    return(top==-1);
}
bool isFull(){
    return(top==Size-1);
}
void  checkspace(){
    if(isFull()){
     cout<<"the stack is full!!!"<<endl;

    }
    else if(top<=-1){
        cout<<"stack is under flow!"<<endl;
    }
    else{
 cout<< (Size-top-1)<<" Space is availaible."<<endl;
}
}
void displayTop(){
    if(!isEmpty()){
        cout<<stack_arr[top]<<endl;
    }
    else cout<<"empty"<<endl;
}
void displayAll(){
if(!isEmpty()){
    for(int i=0;i<=top;i++){
        cout<< stack_arr[i]<<" -> ";
    }
}
}
int main(){

int ch;
while(1){
    menu();
    cout<<"Enter your choice ? ";
    cin>>ch;
    switch(ch){
        case 1:
        if(isFull())cout<<"\nthere is not available space "<<endl;
        else{
         int data;
         cout<<"\nEter the data to push! ";
         cin>>data;
         push( data);
         cout<<data<<" is pushed succesfully! "<<endl;
        
        }
       
        
    
    break;
    case 2:
    if(isEmpty())cout<<"Enpty data to delete"<<endl;
    else pop();
    break;
    case 3:
    if( isEmpty())cout<<"the stack is empty !!"<<endl;
    else cout<<"the stack is not empty!!"<<endl;
     break;
    case 4:
    if(isFull())cout<<"the stack is full!!"<<endl;
    else cout<<"the stack is not full"<<endl;;

    break;
    case 5:
    displayTop();
    break;
    case 6:
    displayAll();
    break;
    case 7:
    checkspace();
    break;
    default:
    cout<<"wrong input!!";
    }
    if(ch==0){
       
    cout<<"good bye!!!"<<endl;
    break;
    }

}
    return 0;
}