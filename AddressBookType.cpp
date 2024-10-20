#include "AddressBookType.h"

// Constructor
AddressBookType::AddressBookType() : orderedLinkedList<extPersonType>() {
}

// Initialize entries from a file
void AddressBookType::initEntry(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string firstName, lastName, street, city, state, phoneNumber, relationship;
    int month, day, year, zipcode;

    while (inFile >> firstName >> lastName >> month >> day >> year
        >> ws && getline(inFile, street)
        >> ws && getline(inFile, city)
        >> state >> zipcode >> phoneNumber >> relationship) {
        extPersonType person(firstName, lastName, month, day, year,
            street, city, state, zipcode,
            phoneNumber, relationship);
        addEntry(person);
    }
}

// Add an entry to the address book
void AddressBookType::addEntry(const extPersonType& entry) {
    insert(entry); // Insert uses the ordered linked list's insert method
}

// Find person by name
void AddressBookType::findPerson(const std::string& lastName, const std::string& firstName) const {
    nodeType<extPersonType>* current = first;
    extPersonType key(firstName, lastName);  // Create a key with both first and last names

    while (current != nullptr) {
        if (current->info == key) {
            current->info.print();
            return;
        }
        current = current->link;
    }
    std::cout << "Person not found!" << std::endl;
}

// Find birthdays in a given month
void AddressBookType::findBirthdays(int month) const {
    nodeType<extPersonType>* current = this->first;  // 'first' is the head of the linked list
    bool found = false;

    while (current != nullptr) {
        if (current->info.getBirthMonth() == month) {
            current->info.print();
            found = true;
        }
        current = current->link;  // Move to the next node
    }

    if (!found) {
        std::cout << "No birthdays found for month " << month << "." << std::endl;
    }
}

// Find relations by relationship type
void AddressBookType::findRelations(const std::string& relationship) const {
    nodeType<extPersonType>* current = this->first;  // 'first' is the head of the linked list
    bool found = false;

    while (current != nullptr) {
        if (current->info.getRelationship() == relationship) {
            current->info.print();
            found = true;
        }
        current = current->link;  // Move to the next node
    }

    if (!found) {
        std::cout << "No entries found for relationship: " << relationship << "." << std::endl;
    }
}

// Print all entries in the address book
void AddressBookType::print() const {
    nodeType<extPersonType>* current = this->first; // Use pointer for traversal
    while (current != nullptr) {
        current->info.print(); // Call print on extPersonType
        current = current->link;
    }
}

