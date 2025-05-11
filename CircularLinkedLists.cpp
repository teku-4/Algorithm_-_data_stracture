#include <iostream>
using namespace std;

struct node {
	int ID;
	string Name;
	node *next;
} *start = NULL;

// Function Prototypes
void addingFront(int id, string name);
void insertAtend(int id, string name);
void addsToleft(int keyid, int id, string name);
void insertToRight(int keyid, int id, string name);
void deleteFront();
void deleteEnd();
void deleteById(int keyid);
void display();
void menu();

// Insert at front
void addingFront(int id, string name) {
	node *temp = new node;
	temp->ID = id;
	temp->Name = name;

	if (!start) {
		start = temp;
		temp->next = start;
	} else {
		node *temp1 = start;
		while (temp1->next != start) {
			temp1 = temp1->next;
		}
		temp->next = start;
		start = temp;
		temp1->next = start;
	}
}

// Insert at end
void insertAtend(int id, string name) {
	node *temp = new node;
	temp->ID = id;
	temp->Name = name;

	if (!start) {
		cout << "Empty list. Data is added at the start." << endl;
		start = temp;
		temp->next = start;
	} else {
		node *temp1 = start;
		while (temp1->next != start) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->next = start;
	}
}

// Insert to left of given id
void addsToleft(int keyid, int id, string name) {
	if (!start) {
		cout << "Empty list. Cannot insert to the left." << endl;
		return;
	}

	if (start->ID == keyid) {
		addingFront(id, name);
		return;
	}

	node *curr = start;
	node *prev = NULL;
	do {
		prev = curr;
		curr = curr->next;
	} while (curr != start && curr->ID != keyid);

	if (curr == start) {
		cout << "ID not found. Inserting at front." << endl;
		addingFront(id, name);
	} else {
		node *temp = new node;
		temp->ID = id;
		temp->Name = name;
		prev->next = temp;
		temp->next = curr;
	}
}

// Insert to right of given id
void insertToRight(int keyid, int id, string name) {
	if (!start) {
		cout << "Empty list. Data is added at the start." << endl;
		addingFront(id, name);
		return;
	}

	node *curr = start;
	do {
		if (curr->ID == keyid) {
			node *temp = new node;
			temp->ID = id;
			temp->Name = name;
			temp->next = curr->next;
			curr->next = temp;
			return;
		}
		curr = curr->next;
	} while (curr != start);

	cout << "ID not found. Inserting at end." << endl;
	insertAtend(id, name);
}

// Delete front
void deleteFront() {
	if (!start) {
		cout << "List is empty." << endl;
		return;
	}
	node *temp = start;
	if (start->next == start) {
		start = NULL;
	} else {
		node *curr = start;
		while (curr->next != start) {
			curr = curr->next;
		}
		start = start->next;
		curr->next = start;
	}
	delete temp;
	cout << "First node deleted successfully." << endl;
}

// Delete end
void deleteEnd() {
	if (!start) {
		cout << "List is empty." << endl;
		return;
	}
	node *curr = start, *prev = NULL;
	while (curr->next != start) {
		prev = curr;
		curr = curr->next;
	}
	if (curr == start) {
		start = NULL;
	} else {
		prev->next = start;
	}
	delete curr;
	cout << "Last node deleted successfully." << endl;
}

// Delete by ID
void deleteById(int keyid) {
	if (!start) {
		cout << "List is empty." << endl;
		return;
	}

	if (start->ID == keyid) {
		deleteFront();
		return;
	}

	node *curr = start, *prev = NULL;
	do {
		prev = curr;
		curr = curr->next;
	} while (curr != start && curr->ID != keyid);

	if (curr == start) {
		cout << "ID not found." << endl;
	} else {
		prev->next = curr->next;
		cout << "ID " << keyid << " deleted successfully." << endl;
		delete curr;
	}
}

// Display the list
void display() {
	if (!start) {
		cout << "List is empty." << endl;
		return;
	}
	node *curr = start;
	cout << "ID\tName" << endl;
	do {
		cout << curr->ID << "\t" << curr->Name << endl;
		curr = curr->next;
	} while (curr != start);
}

// Menu
void menu() {
	int choice;
	do {
		cout << "\n------- Circular Linked List Menu -------\n";
		cout << "1. Insert at Front\n";
		cout << "2. Insert at End\n";
		cout << "3. Insert to Left of Given ID\n";
		cout << "4. Insert to Right of Given ID\n";
		cout << "5. Delete Front\n";
		cout << "6. Delete End\n";
		cout << "7. Delete by ID\n";
		cout << "8. Display\n";
		cout << "9. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		int id, keyid;
		string name;

		switch (choice) {
			case 1:
				cout << "Enter ID and Name: ";
				cin >> id >> name;
				addingFront(id, name);
				break;
			case 2:
				cout << "Enter ID and Name: ";
				cin >> id >> name;
				insertAtend(id, name);
				break;
			case 3:
				cout << "Enter Key ID: ";
				cin >> keyid;
				cout << "Enter New ID and Name: ";
				cin >> id >> name;
				addsToleft(keyid, id, name);
				break;
			case 4:
				cout << "Enter Key ID: ";
				cin >> keyid;
				cout << "Enter New ID and Name: ";
				cin >> id >> name;
				insertToRight(keyid, id, name);
				break;
			case 5:
				deleteFront();
				break;
			case 6:
				deleteEnd();
				break;
			case 7:
				cout << "Enter ID to Delete: ";
				cin >> keyid;
				deleteById(keyid);
				break;
			case 8:
				display();
				break;
			case 9:
				cout << "Exiting Program..." << endl;
				break;
			default:
				cout << "Invalid choice! Try again." << endl;
		}
	} while (choice != 9);
}

int main() {
	menu();
	return 0;
}
