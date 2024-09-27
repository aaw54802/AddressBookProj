#pragma once
#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>
#include <iostream>

class extPersonType : public personType {
public:
    // Constructor
    extPersonType(std::string firstName = "", std::string lastName = "",
        int month = 1, int day = 1, int year = 1900,
        std::string street = "", std::string city = "",
        std::string state = "XX", int zipcode = 10000,
        std::string phoneNumber = "", std::string relationship = "None");

    // Setters
    void setPhoneNumber(const std::string& phoneNumber);
    void setRelationship(const std::string& relationship);

    // Getters
    std::string getPhoneNumber() const;
    std::string getRelationship() const;
    int getBirthMonth() const;

    // Print function
    void print() const override;

private:
    std::string phoneNumber; // Phone number of the person
    std::string relationship; // Relationship of the person (Family, Friend, Business)
    dateType birthdate; // Date of birth
    AddressType address; // Address of the person
};

