#pragma once

#ifndef OWNER_H 
#define OWNER_H 
#include "Person.h" 

#include <iostream> 
using namespace std;

class Owner : public Person {
private:
    // attributes 
    double businessPercentage;
    string ownerDate;
public:
    // accessors 
    double getBusinessPercentage() {
        return businessPercentage;
    }
    string getOwnerDate() {
        return ownerDate;
    }
    // mutators 
    void setBusinessPercentage(double businessPercentage) {
        this->businessPercentage = businessPercentage;
    }
    void setOwnerDate(string ownerDate) {
        this->ownerDate = ownerDate;
    }
    string category() {
        return "Owner";
    }
};
#endif /* OWNER_H */ 