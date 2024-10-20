#include "extPersonType.h"
#include <iostream>

// Constructor implementation
extPersonType::extPersonType(std::string firstName, std::string lastName,
    int month, int day, int year,
    std::string street, std::string city,
    std::string state, int zipcode,
    std::string phoneNumber, std::string relationship)
    : personType(firstName, lastName),
    birthdate(month, day, year),
    address(street, city, state, zipcode)
{
    setPhoneNumber(phoneNumber);
    setRelationship(relationship);
}

// Setters
void extPersonType::setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
void extPersonType::setRelationship(const std::string& relationship) {
    if (relationship == "Family" || relationship == "Friend" || relationship == "Business") {
        this->relationship = relationship;
    }
    else {
        this->relationship = "None"; // Default if invalid
    }
}

// Getters
std::string extPersonType::getPhoneNumber() const { return phoneNumber; }
std::string extPersonType::getRelationship() const { return relationship; }
int extPersonType::getBirthMonth() const { return birthdate.getMonth(); }

std::string extPersonType::getFirstName() const { return personType::getFirstName(); }
std::string extPersonType::getLastName() const { return personType::getLastName(); }

// Getter implementations for birthdate
int extPersonType::getBirthDay() const { return birthdate.getday(); }
int extPersonType::getBirthYear() const { return birthdate.getYear(); }

// Getter implementations for address
std::string extPersonType::getStreet() const { return address.getAddress(); }
std::string extPersonType::getCity() const { return address.getCity(); }
std::string extPersonType::getState() const { return address.getState(); }
int extPersonType::getZipCode() const { return address.getZipcode(); }

// Print function
void extPersonType::print() const {
    personType::print(); // Call print from personType
    std::cout << "\nPhone Number: " << phoneNumber
        << "\nRelationship: " << relationship
        << "\nBirthdate: ";
    birthdate.print(); // Call print from dateType
    std::cout << "\nAddress: ";
    address.print(); // Call print from addressType
}

// Operator Overloads
bool extPersonType::operator>=(const extPersonType& other) const {
    std::string thisKey = getLastName() + getFirstName();
    std::string otherKey = other.getLastName() + other.getFirstName();
    return thisKey >= otherKey;
}

bool extPersonType::operator==(const extPersonType& other) const {
    std::string thisKey = getLastName() + getFirstName();
    std::string otherKey = other.getLastName() + other.getFirstName();
    return thisKey == otherKey;
}


bool extPersonType::operator!=(const extPersonType& other) const {
    std::string thisKey = getLastName() + getFirstName();
    std::string otherKey = other.getLastName() + other.getFirstName();
    return thisKey != otherKey;  // Compare the keys
}

