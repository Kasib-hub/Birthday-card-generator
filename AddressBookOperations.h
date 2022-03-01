// Written By: Kasib Abdullah
// TESU ID: 0683165

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>
using namespace std;

struct node {
    string name;
    string address;
    string birthday;
    string anniversary;
    node* next;
};

node* head;
node* sorted;

void showMenu () {
    cout << "---------- MENU ----------" << endl;
    cout << "1. Enter Name" << endl;
    cout << "2. Delete Name" << endl;
    cout << "3. Change Name or Date" << endl;
    cout << "4. Generate Birthday Cards" << endl;
    cout << "5. Generate Anniversary Cards" << endl;
    cout << "6. Display Address Book" << endl;
    cout << "7. Exit" << endl;
    cout << "--------------------------" << endl;
}
// checks user input is a valid date entry
string checkdateInput () {
    string value;
    cin >> value;
    while (value.size() != 5 || value[2] != '/') {
        cout << "Invalid entry. please enter date: ";
        getline(cin, value);
    }
    return value;
}

// stores nodes in a linked list at the head
void prepend (string n, string a, string b, string y) {
    if (head == NULL) {
        head = new node();
        head->name = n;
        head->address = a;
        head->birthday = b;
        head->anniversary = y;
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new node();
    current->next->name = n;
    current->next->address = a;
    current->next->birthday = b;
    current->next->anniversary = y;
}
// sorting the newest entry to linked list
void sortedInsert(node* newnode) {
    if (sorted == NULL || sorted->name.compare(newnode->name) >= 0) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        node* current = sorted;
        while (current->next != NULL && current->next->name.compare(newnode->name) < 0) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
// the parameter is the linked list starting from its head.
void insertionSort(node* oldhead) {
    sorted = NULL;
    node* current = oldhead;

    while (current != NULL) {
        node* next = current->next;
        sortedInsert(current);
        current = next;
    }
    head = sorted;
}

void Delete(string key) {
    if (head == NULL) return;
    if (head->name == key) {
        head = head->next;
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        if (current->next->name == key) {
            current->next = current->next->next;
            return;
        }
        else {
            cout << "Name not found" << endl;
            return;
        }
        current = current->next;
    }
}
// Searching address book to make edits
void Search(string key) {
    node* current = head;
    while(current != NULL) {
        if (key == current->name) {
            string newname;
            cout << "Enter new name: ";
            cin >> newname;
            current->name = newname;
        }
        else if (key == current->birthday) {
            string newbirth;
            cout << "Enter new date: ";
            cin >> newbirth;
            current->birthday = newbirth;
        }
        else if (key == current->anniversary) {
            string newanni;
            cout << "Enter new date: ";
            cin >> newanni;
            current->birthday = newanni;
        }
        current = current->next;
    }
}
// Prints the entire address book
void printList() {
    cout << "=-=-=-ADDRESS*BOOK-=-=-=" << endl;
    node* current = head;
    while(current != NULL) {            
        cout << "Name: " << current->name << endl;
        cout << "Address: " << current->address << endl;
        cout << "Birthday: " << current->birthday << endl;
        cout << "Anniversary: " << current->anniversary << endl;
        cout << "=-=-=-=-=-=-=-=" << endl;   
        current = current->next;               
    }
    cout << endl;  
}

void genBirthCard(string value) {
    string name;
    cout << "What is your name? ";
    cin >> name;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl << endl;
    cout << "Dear " << value << endl;
    cout << endl;
    cout << "Happy belated birthday, I wish you a great day and many more!" << endl;
    cout << endl;
    cout << "Sincerely," << endl;
    cout << endl;
    cout << name << endl << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
}

void genAnniversaryCard(string value) {
    string name;
    cout << "What is your name? ";
    cin >> name;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl << endl;
    cout << "Dear " << value << endl;
    cout << endl;
    cout << "Happy anniversary, I hope you've had a great day to celebrate " << endl;
    cout << "your longevity together!" << endl;
    cout << endl;
    cout << "Sincerely," << endl;
    cout << endl;
    cout << name << endl << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
}

void searchBirthDay(string key) {
    node* current = head;
    while(current != NULL) {
        if (key == current->birthday) {
            genBirthCard(current->name);
        }
        current = current->next;
    }   
}

void searchAnniversaryDay(string key) {
    node* current = head;
    while(current != NULL) {
        if (key == current->anniversary) {
            genAnniversaryCard(current->name);
        }
        current = current->next;
    }   
}

#endif

