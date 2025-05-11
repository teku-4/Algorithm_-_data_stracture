#include <iostream>
using namespace std;
const int max_size=10;
int stack_arr[max_size];
int top=-1;
void  push(int data ){
if(top>=max_size-1)cout<<"Stack over flow";
stack_arr[++top]=data;

}
void pop(){
    if(top<=-1)cout<<"stack under flow"<<endl;
    else stack_arr[--top];
}
void display(){
    if(top==-1)cout<<"Stack underflow";
    else{
    for(int i=0;i<top;i++){
        cout<<" "<<stack_arr[i];
    }
}}
bool isEpty(){
    return (top==-1);
}
bool isFull(){
    return(top==max_size-1);
}
int main(){
    //array implimentation of stack
if(isEpty())cout<<"Stack is Empty!\n";
else cout<<"\nStack is not empty";
push(10);
push(20);
if(isEpty())cout<<"Stack is Empty!"<<endl;
else cout<<"\nStack is not empty there are : "<<(top+1)<<" elements"<<endl;
push(30);
push(40);
push(50);
push(60);
push(70);
push(80);


push(90);
push(100);
push(100);
push(100);
display();
if(isFull())cout<<"\nStck is full"<<endl;
else cout<<"stack is not full"<<endl;
pop();
pop();
pop();
pop();
pop();
pop();
pop();
pop();
pop();
pop();
display();
if(isFull())cout<<"\nStck is full"<<endl;
else cout<<"\nstack is not full"<<endl;

    return 0;
}