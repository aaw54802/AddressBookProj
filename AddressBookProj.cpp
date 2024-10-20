#include <iostream>
#include "AddressBookType.h"
#include "orderedLinkedList.h"
#include "extPersonType.h"

using namespace std;

int showMenu() {
    int choice;
    cout << "On-line Address Book" << endl;
    cout << "Select an option:" << endl;
    cout << "1: Display all entries in the address book." << endl;
    cout << "2: Display an entry by a person's name." << endl;
    cout << "3: Display all entries with a given birth month." << endl;
    cout << "4: Display all entries with a given relationship tag (Business, Friend, Family)." << endl;
    cout << "5: Add a new entry." << endl;
    cout << "6: Delete an entry by name." << endl;
    cout << "7: Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    AddressBookType addressBook;

    // Initialize entries from the file
    addressBook.initEntry("AddressBookData.txt");

    int choice;
    do {
        choice = showMenu();

        switch (choice) {
        case 1:
            addressBook.print();
            break;
        case 2: {
            string lastName, firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter first name: ";
            cin >> firstName;
            addressBook.findPerson(lastName, firstName);
            break;
        }
        case 3: {
            int month;
            cout << "Enter birth month (1-12): ";
            cin >> month;
            addressBook.findBirthdays(month);
            break;
        }
        case 4: {
            string relationship;
            cout << "Enter relationship (Business, Friend, Family): ";
            cin >> relationship;
            addressBook.findRelations(relationship);
            break;
        }
        case 5: {
            addressBook.addInteractiveEntry();  // Add new entry
            break;
        }
        case 6: {
            string lastName, firstName;
            cout << "Enter first name to delete: ";
            cin >> lastName;
            cout << "Enter last name to delete: ";
            cin >> firstName;
            addressBook.deleteEntry(lastName, firstName);  // Delete entry
            break;
        }
        case 7:
            addressBook.saveToFile("AddressBookData.txt");  // Save data to file
            cout << "Quitting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

