// Written By: Kasib Abdullah
// TESU ID: 0683165

#include <iostream>
#include <string>
#include "AddressBookOperations.h"
using namespace std;

int main() {
    int choice;
    
    do {
        showMenu();
        cout << "Enter a number to choose an option: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                string name, address, birth, anny;
                cout << "Enter Name: ";
                cin >> name;
                tolower(name[0]);
                cin.ignore();  

                cout << "Enter Address: ";
                getline(cin, address);

                cout << "Enter Birthday (MM/DD): ";
                birth = checkdateInput();

                cout << "Enter Anniversary (MM/DD): ";
                anny = checkdateInput();

                prepend(name, address, birth, anny);
                insertionSort(head);
            }
                break;

            case 2: {
                string name;
                cout << "Enter First Name: ";
                cin >> name;
                tolower(name[0]);
                Delete(name);
            }
                break;

            case 3: {
                cout << "1. Name" << endl << "2. Date" << endl;
                cout << "Pick a search parameter: ";
                int choice;
                cin >> choice;
                switch (choice) {
                    case 1: {
                        string name;
                        cout << "What name is going to be changed? ";
                        cin >> name;
                        tolower(name[0]);
                        Search(name);
                        break;
                    }
                    case 2: {
                        string date;
                        cout << "What date is going to be changed? ";
                        cin >> date;
                        Search(date);
                        break;
                    }
                }
                insertionSort(head);
            }
                break;

            case 4: {
                string date;
                cout << "Enter the recepient's birth date (MM/DD): ";
                date = checkdateInput();
                searchBirthDay(date);
                
            }
                break;

            case 5: {
                string date;
                cout << "Enter the recepient's anniversary (MM/DD): ";
                date = checkdateInput();
                searchAnniversaryDay(date);
            }
                break;
                
            case 6:{
                printList();
            }
            break;

            case 7:{
                cout << "Press Enter to Exit";
                cin.get();
                cin.get();
            }
        }
        cout << endl;
        cin.clear();
    }
    while (choice != 7);
}