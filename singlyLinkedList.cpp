#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int id;
    string name;
    float mark;
    Node* next;
};

Node* start = NULL;

// Function to add node at the beginning
void addAtBeginning(int id, string name, float mark) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->name = name;
    newNode->mark = mark;
    newNode->next = start;
    start = newNode;
}

// Function to add node at the end
void addAtEnd(int id, string name, float mark) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->name = name;
    newNode->mark = mark;
    newNode->next = NULL;
    
    if (start == NULL) {
        start = newNode;
        return;
    }
    
    Node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add node at nth position (1-based)
void addAtPosition(int pos, int id, string name, float mark) {
    if (pos == 1) {
        addAtBeginning(id, name, mark);
        return;
    }
    
    Node* newNode = new Node;
    newNode->id = id;
    newNode->name = name;
    newNode->mark = mark;
    
    Node* temp = start;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Position out of range. Adding at the end." << endl;
        addAtEnd(id, name, mark);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node by ID
void deleteNode(int id) {
    if (start ==NULL) {
        cout << "List is empty." << endl;
        return;
    }
    
    Node* temp = start;
    Node* prev = NULL;
    
    // If the node to be deleted is the first node
    if (temp != NULL && temp->id == id) {
        start = temp->next;
        delete temp;
        cout << "Node with ID " << id << " deleted." << endl;
        return;
    }
    
    // Search for the node to be deleted
    while (temp !=NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Node with ID " << id << " not found." << endl;
        return;
    }
    
    // Unlink the node from the list
    prev->next = temp->next;
    delete temp;
    cout << "Node with ID " << id << " deleted." << endl;
}

// Function to display the list
void displayList() {
    Node* temp = start;
    if (temp == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    
    cout << "List contents:" << endl;
    cout << "ID\tName\tMark" << endl;
    while (temp != NULL) {
        cout << temp->id << "\t" << temp->name << "\t" << temp->mark << endl;
        temp = temp->next;
    }
}

// Function to save list to file
void saveToFile() {
    ofstream myFile("studFile.txt");
    if (!myFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    
    Node* temp = start;
    while (temp != NULL) {
        myFile << temp->id << endl;
        myFile << temp->name << endl;
        myFile << temp->mark << endl;
        temp = temp->next;
    }
    
    myFile.close();
    cout << "Data saved to file successfully." << endl;
}

int main() {
    int choice, id, pos;
    string name;
    float mark;
    
    while (true) {
        cout << "\nSingly Linked List Operations" << endl;
        cout << "1. Add at beginning" << endl;
        cout << "2. Add at end" << endl;
        cout << "3. Add at position" << endl;
        cout << "4. Delete node" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Save to file" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter mark: ";
                cin >> mark;
                addAtBeginning(id, name, mark);
                break;
                
            case 2:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter mark: ";
                cin >> mark;
                addAtEnd(id, name, mark);
                break;
                
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter mark: ";
                cin >> mark;
                addAtPosition(pos, id, name, mark);
                break;
                
            case 4:
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteNode(id);
                break;
                
            case 5:
                displayList();
                break;
                
            case 6:
                saveToFile();
                break;
                
            case 7:
                return 0;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}
