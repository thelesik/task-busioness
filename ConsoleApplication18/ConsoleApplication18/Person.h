#pragma once
#ifndef PERSON_H 
#define PERSON_H 
#include <iostream> 
using namespace std;

class Person {
private:
    // attributes 
    string name;
    string ssn;
    string birthDate;

public:
    // accessors 
    string getName() {
        return name;
    }
    string getSsn() {
        return ssn;
    }
    string getBirthDate() {
        return birthDate;
    }
    // mutators 
    void setName(string name) {
        this->name = name;
    }
    void setSsn(string ssn) {
        this->ssn = ssn;
    }
    void setBirthDate(string birthDate) {
        this->birthDate = birthDate;
    }
    virtual string category() = 0;
};
#endif /* PERSON_H */ 