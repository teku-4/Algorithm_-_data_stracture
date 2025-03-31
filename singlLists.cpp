#include <iostream>
using namespace std;

// linked list stracture.
// ----------------------------------------------------------------------------------------------------
struct Node
{
    int data;
    Node *next;
};
// global head pointer.
Node *head=NULL;
// -----------------------------------------------------------------------------------------------------


// opration on singlylinked list.





/**********************************************************************************
                  Algorithms to insert at thebeginning
 1 start
 2 creating new Node
 3 assigning the value to Node's data.
 4 pointing the new Node's next pointer to current head.
 5 update the linklist head as new node.
 6 display
 7 end
 **********************************************************************************/
//  -----------------------------------------------------------------------------------------------------
// function toinsert at the begninning of linked list.
void insertAtbegninning(int value)
{
    Node *newNode= new Node;
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}
// -----------------------------------------------------------------------------------------------------





/**************************************************************************************************
               Algorithms to insert at endl
    1 start
    2 creat new node by allocating memory dynamically.
    3 assigning value to Node's data.
    4 pointing new Node's next pointer to NULL.
    5 display the value.
    6 end
    
 **************************************************************************************************/

// -----------------------------------------------------------------------------------------------------
//function to insert at the end.
void insertAtend(int value)
{
    Node *newNode= new Node;
    newNode->data=value;
    newNode->next=nullptr;
    
    // checking the value in list's data.
    if(head==NULL)
    cout<<"Null lists."<<endl;
    
    // traversing the node.
    Node *temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    // updating the last element to new node.
    temp->next=newNode;
}

// -----------------------------------------------------------------------------------------------------------------
// iserting to the right of given position
/******************************************************************************************************
                   Algorithms:
    1 start
    2 check the user provides position to be valid.
    3 creating new node.
    4 assigning the value to Node's data.
    5 traverse the node to temp variable.
    6 fintd the vlue to the position-1.
    7 update the next pointer of new node to the next pointe of current node.
    8 update the next pointer of new node to the new node.
    9 display
    10 end.
*******************************************************************************************************/
//------------------------------------------------------------------------------------------------------------------
//function to insert at specified position.
void insertAtspecifiedpos(int value, int position)
{
 if(position < 1)
 {
  cout<<"position must be greater than 1."<<endl;
 
 }
 else if( position==1)
 {
     insertAtbegninning(value);
 }
 
 Node *newNode=new Node;
 newNode->data=value;
 if(head==NULL)
 {
     cout<<"Null lists."<<endl;
 }
 Node *temp=head;
 for(int i=1;i<position-1 && temp;i++)
 {
    temp=temp->next; 
 }
 
    newNode->next=temp->next;
    temp->next=newNode;
}
// ------------------------------------------------------------------------------------------------------------------
//deleting the the value fromthe begnning.
/************************************************************************************************************
                   Algorithms:
    1 start
    2 create create temporar pointer temp.
    3 check weather the Node's data is empty.
    4 assign head to temp.
    5 updates the head to the next head.
    6 deletes the temp which is temporar variable.
    7 display the result.
    8 end.
*****************************************************************************************************************/
//function to delete from the begninning.
// ---------------------------------------------------------------------------------------------------------------
void delFromBegninning()
{
 Node *temp;
 if(head==NULL)
 {
     cout<<"Empity lists."<<endl;
 }
 temp=head;
 head=head->next;
 delete temp;
}
// ------------------------------------------------------------------------------------------------------------------

/**************************************************************************************************************
                   Algorithms:
    
    1 start
    2 create two temp1 and temp2 pointer.
    3 check weather the list is empity or not.
    4 asign head to temp1.
    5 looping throught lists untill the next temp1 pointer to be null.
    5.1 assign temp1 to temp2.
    5.2 update temp1 to next adress.
    6 points temp2 to null.
    7 delete temp which is temporar pointer.
    8 display the result.
    9 end.
 * *************************************************************************************************************/
// ------------------------------------------------------------------------------------------------------------------
void delFromEnd()
{
    Node *temp1, *temp2;
    if(!head)
    {
        cout<<"Epity lists"<<endl;
    }
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
        
    }
    temp2->next=NULL;
    delete temp1;
}
// -------------------------------------------------------------------------------------------------------------
// function to display the linked list.
void display()
{
    // cheking wether null or not.
    if(head==NULL)
    {
    cout<<"list is NULL:"<<endl;
    }
    
    // traversing node.
    Node *temp=head;
    while(temp)
    {   cout<<temp->data<<" "<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL."<<endl;
}
// ----------main function-------------------------------------------------------------------------------------------------------
int main()
  
{   insertAtbegninning(30);
    insertAtbegninning(20);  
    insertAtbegninning(10);
    insertAtbegninning(1);
    display();
    insertAtend(100);
    insertAtend(200);
    insertAtend(300);
    display();
    insertAtspecifiedpos(3000,3);
    insertAtspecifiedpos(5000,5);
    insertAtspecifiedpos(10000,-1);
    display();
    delFromBegninning();
    delFromBegninning();
    
    display();
    
    delFromEnd();
    delFromEnd();
    display();
    return 0;
}
// ------------------------------------------------------------------------------------------------------------------
