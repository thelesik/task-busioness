#pragma once
// Laborer.h 
#ifndef LABORER_H 
#define LABORER_H 
#include "Person.h" 

#include <iostream> 
using namespace std;
class Laborer : public Person {
private:
    // attributes 
    string job;
    string empId;
    double hourlySalary;
    double hoursWorked;
public:
    // accessors 
    string getJob() {
        return job;
    }
    string getEmpId() {
        return empId;
    }
    double getHourlySalary() {
        return hourlySalary;
    }
    double getHoursWorked() {
        return hoursWorked;
    }
    // mutators 
    void setJob(string job) {
        this->job = job;
    }
    void setEmpId(string empId) {
        this->empId = empId;
    }
    void setHourlySalary(double hourlySalary) {
        this->hourlySalary = hourlySalary;
    }
    void setHoursWorked(double hoursWorked) {
        this->hoursWorked = hoursWorked;
    }
    string category() {
        return "Laborer";
    }
};
#endif /* LABORER_H */ 