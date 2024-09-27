#include "AddressBookType.h"

// Constructor
AddressBookType::AddressBookType(int maxSize) : maxSize(maxSize), length(0) {
    addressList = new extPersonType[maxSize]; // Dynamic array allocation
}

// Destructor
AddressBookType::~AddressBookType() {
    delete[] addressList; // Clean up
}

// Initialize entries
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
void AddressBookType::addEntry(const extPersonType& person) {
    if (length < maxSize) {
        addressList[length++] = person; // Add person to the array and increment length
    }
    else {
        cout << "Address book is full." << endl; // Handle full array case
    }
}

// Find a person by last name
void AddressBookType::findPerson(const string& lastName) const {
    for (int i = 0; i < length; ++i) {
        if (addressList[i].getLastName() == lastName) {
            addressList[i].print(); // Print details if found
            return;
        }
    }
    cout << "Person not found." << endl; // Handle not found case
}

// Find birthdays in a given month
void AddressBookType::findBirthdays(int month) const {
    cout << "Birthdays in month " << month << ":" << endl;
    for (int i = 0; i < length; ++i) {
        if (addressList[i].getBirthMonth() == month) {
            cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << endl;
        }
    }
}

// Find relations by relationship type
void AddressBookType::findRelations(const string& relationship) const {
    cout << "Entries with relationship '" << relationship << "':" << endl;
    for (int i = 0; i < length; ++i) {
        if (addressList[i].getRelationship() == relationship) {
            cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << endl;
        }
    }
}

// Print all entries in the address book
void AddressBookType::print() const {
    for (int i = 0; i < length; ++i) {
        addressList[i].print(); // Print each person's details
        cout << endl;
    }
}

// Sort entries using insertion sort
void AddressBookType::sortEntries() {
    for (int current = 1; current < length; current++) {
        int index = current;
        bool placeFound = false;

        // Lambda for comparing by last name
        auto compare = [](const extPersonType& a, const extPersonType& b) {
            return a.getLastName() < b.getLastName(); // Assuming you have a getter for lastName
            };

        while (index > 0 && !placeFound) {
            if (compare(addressList[index], addressList[index - 1])) {
                extPersonType temp = addressList[index];
                addressList[index] = addressList[index - 1];
                addressList[index - 1] = temp;
                index--;
            }
            else {
                placeFound = true; // Found the correct place for the current element
            }
        }
    }
}


