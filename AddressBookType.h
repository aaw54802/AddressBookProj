#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#pragma once
#include "orderedLinkedList.h"
#include "extPersonType.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std; // For convenience

class AddressBookType : public orderedLinkedList<extPersonType> {
public:
    AddressBookType();  // Constructor declaration
    void initEntry(const std::string& filename); // Initialize entries from a file
    void addEntry(const extPersonType& entry); // Add an entry
    void findPerson(const std::string& lastName, const std::string& firstName) const; // Find a person by last name
    void findBirthdays(int month) const; // Find birthdays in a given month
    void findRelations(const std::string& relationship) const;; // Find relations by relationship type
    void print() const; // Print all entries
};

#endif
