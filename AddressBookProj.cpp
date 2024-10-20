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
    cout << "5: Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Main function
int main() {
    AddressBookType addressBook;  // Use linked list-based address book

    // Initialize entries from the file
    addressBook.initEntry("AddressBookData.txt");

    int choice;
    do {
        choice = showMenu(); // Display the menu and get user choice

        switch (choice) {
        case 1:
            addressBook.print(); // Display all entries
            break;
        case 2: {
            string lastName, firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter first name: ";
            cin >> firstName;
            addressBook.findPerson(lastName, firstName);  // now passing both names
            break;
        }
        case 3: {
            int month;
            cout << "Enter birth month (1-12): ";
            cin >> month;
            addressBook.findBirthdays(month); // Find birthdays in a given month
            break;
        }
        case 4: {
            string relationship;
            cout << "Enter relationship (Business, Friend, Family): ";
            cin >> relationship;
            addressBook.findRelations(relationship); // Find relations by relationship type
            break;
        }
        case 5:
            cout << "Quitting the program." << endl; // Quit the program
            break;
        default:
            cout << "Invalid choice. Please try again." << endl; // Handle invalid input
        }
        cout << endl; // Print an empty line for better readability
    } while (choice != 5);

    return 0; // Return success
}
