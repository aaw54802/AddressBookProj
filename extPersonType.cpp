#include "extPersonType.h"

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

