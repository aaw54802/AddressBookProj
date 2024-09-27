#pragma once
#include <string>
#include <iostream>

class personType {
private:
    std::string firstName;  // First name of the person
    std::string lastName;   // Last name of the person

public:
    // Constructor
    personType(std::string firstName = "", std::string lastName = "")
        : firstName(firstName), lastName(lastName) {}

    // Setters
    void setFirstName(const std::string& firstName) {
        this->firstName = firstName;
    }

    void setLastName(const std::string& lastName) {
        this->lastName = lastName;
    }

    // Getters
    std::string getFirstName() const {
        return firstName;
    }

    std::string getLastName() const {
        return lastName;
    }

    // Print function
    virtual void print() const {  // Declare as virtual
        std::cout << "Name: " << firstName << " " << lastName;
    }
};

