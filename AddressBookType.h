#pragma once
#include "extPersonType.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std; // For convenience

class AddressBookType {
public:
    AddressBookType(int maxSize); // Constructor
    ~AddressBookType(); // Destructor
    void initEntry(const string& filename); // Initialize entries from a file
    void addEntry(const extPersonType& person); // Add an entry
    void findPerson(const string& lastName) const; // Find a person by last name
    void findBirthdays(int month) const; // Find birthdays in a given month
    void findRelations(const string& relationship) const; // Find relations by relationship type
    void print() const; // Print all entries
    void sortEntries(); // Sort entries

private:
    extPersonType* addressList; // Array of extPersonType objects
    int length; // Current number of entries
    int maxSize; // Maximum number of entries

};
