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

    // Getters for first and last name
    std::string getFirstName() const;
    std::string getLastName() const;

    // Getters for birthdate
    int getBirthDay() const;  // Returns the day
    //int getBirthMonth() const; // Returns the month
    int getBirthYear() const;  // Returns the year

    // Getters for address (inside addressType)
    std::string getStreet() const;
    std::string getCity() const;
    std::string getState() const;
    int getZipCode() const;


    // Print function
    void print() const override;

   // Operator Overloads declaration (only declaration here, no definition)
    bool operator>=(const extPersonType& other) const;
    bool operator==(const extPersonType& other) const;
    bool operator!=(const extPersonType& other) const;



private:
    std::string phoneNumber; // Phone number of the person
    std::string relationship; // Relationship of the person (Family, Friend, Business)
    dateType birthdate; // Date of birth
    AddressType address; // Address of the person
};


