#include "AddressBookType.h"
#include <fstream>
#include <iostream>

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

// Function to add a new entry interactively
void AddressBookType::addInteractiveEntry() {
    string firstName, lastName, street, city, state, phoneNumber, relationship;
    int month, day, year, zipCode;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter birthdate (month day year): ";
    cin >> month >> day >> year;
    cout << "Enter street address: ";
    cin.ignore(); // to clear the input buffer
    getline(cin, street);
    cout << "Enter city: ";
    getline(cin, city);
    cout << "Enter state: ";
    cin >> state;
    cout << "Enter zip code: ";
    cin >> zipCode;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cout << "Enter relationship (Family, Friend, Business): ";
    cin >> relationship;

    extPersonType person(firstName, lastName, month, day, year, street, city, state, zipCode, phoneNumber, relationship);
    addEntry(person);
    cout << "Entry added successfully!" << endl;
}

// Function to delete an entry by name
void AddressBookType::deleteEntry(const string& firstName, const string& lastName) {
    extPersonType key(firstName, lastName);
    deleteNode(key);
    cout << "Entry deleted successfully!" << endl;
}

void AddressBookType::savePersonToFile(std::ofstream& outFile, const extPersonType& person) const {
    // Redirect the person's `print` output to the file stream
    std::streambuf* coutBuf = std::cout.rdbuf();  // Save the original buffer
    std::cout.rdbuf(outFile.rdbuf());             // Redirect std::cout to outFile

    person.print();  // This prints the person's details to the file

    std::cout.rdbuf(coutBuf);  // Reset to the original buffer
    outFile << std::endl;      // Add a newline after each entry
}

void AddressBookType::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::trunc);  // Open file for writing, truncating any existing data

    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Traverse the linked list and save each person's details
    nodeType<extPersonType>* current = this->first;

    while (current != nullptr) {
        const extPersonType& person = current->info;

        // Save in the original input format
        outFile << person.getFirstName() << " " << person.getLastName() << "\n";  // First and Last Name
        outFile << person.getBirthMonth() << " "
            << person.getBirthDay() << " "
            << person.getBirthYear() << "\n"
            << person.getStreet() << "\n"
            << person.getCity() << "\n"
            << person.getState() << "\n"
            << person.getZipCode() << "\n"
            << person.getPhoneNumber() << "\n"
            << person.getRelationship() << "\n";

        current = current->link;  // Move to the next node
    }

    outFile.close();  // Close the file after writing
}