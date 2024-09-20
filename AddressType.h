#pragma once

#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <iostream>
#include <string>

class AddressType {
private:
    std::string address;    //Street Address
    std::string city;       //City of residence
    std::string state;      //State of residence
    int zipcode;

public:
    // Constructor
    AddressType(std::string addr = "", std::string cityName = "", std::string stateCode = "XX", int zip = 10000)
        : address(addr), city(cityName), state("XX"), zipcode(zip) {
        setState(stateCode);
        setZipcode(zip);
    }

    // Setters
    void setAddress(const std::string& addr) {
        address = addr;
    }

    void setCity(const std::string& cityName) {
        city = cityName;
    }

    void setState(const std::string& stateCode) {
        if (stateCode.length() == 2) {
            state = stateCode;
        }
        else {
            state = "XX";  // Default to "XX" if invalid input
        }
    }

    void setZipcode(int zip) {
        if (zip >= 11111 && zip <= 99999) {
            zipcode = zip;
        }
        else {
            zipcode = 10000;  // Default if ZIP code is invalid
        }
    }

    // Getters
    std::string getAddress() const {
        return address;
    }

    std::string getCity() const {
        return city;
    }

    std::string getState() const {
        return state;
    }

    int getZipcode() const {
        return zipcode;
    }

    // Print function
    void print() const {
        std::cout << address << ", " << city << ", " << state << " " << zipcode << std::endl;
    }
};

#endif

