#include <iostream>
#include "AddressBookType.h"

using namespace std;

// Function to display the menu
int showMenu() {
    int choice;
    cout << "On-line Address Book" << endl;
    cout << "Select an option:" << endl;
    cout << "1: Display all entries in the address book." << endl;
    cout << "2: Display an entry by a persons last name." << endl;
    cout << "3: Display all entries with a given birth month." << endl;
    cout << "4: Display all entries with a given relationship tag (Business, Friend, Family)." << endl;
    cout << "5: Sort entries by last name." << endl;
    cout << "6: Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Main function
int main() {
    const int MAX_ENTRIES = 100; // Maximum number of entries
    AddressBookType addressBook(MAX_ENTRIES); // Create an address book object

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
            string lastName;
            cout << "Enter last name: ";
            cin >> lastName;
            addressBook.findPerson(lastName); // Find a person by last name
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
            addressBook.sortEntries(); // Sort entries by last name
            cout << "Entries sorted by last name." << endl;
            break;
        case 6:
            cout << "Quitting the program." << endl; // Quit the program
            break;
        default:
            cout << "Invalid choice. Please try again." << endl; // Handle invalid input
        }
        cout << endl; // Print an empty line for better readability
    } while (choice != 6);

    return 0; // Return success
}
