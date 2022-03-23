
#include <iostream> 
#include <vector> 
#include <istream> 
#include <string> 
#include "Header.h"


const int MaxDataBase = 10000;
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
    void setName(string Name) {
        name = Name;
    }
    void setSsn(string Ssn) {
        ssn = Ssn;
    }
    void setBirthDate(string BirthDate) {
        birthDate = BirthDate;
    }
    virtual string category() = 0;
};



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
    void setBusinessPercentage(double BusinessPercentage) {
        businessPercentage = BusinessPercentage;
    }
    void setOwnerDate(string OwnerDate) {
        ownerDate = OwnerDate;
    }
    string category() {
        return "Owner";
    }
};


class Manager : public Person {
private:
    // attributes 
    string department;
    string empId;
    double salary;
public:
    // accessors 
    string getDepartment() {
        return department;
    }
    string getEmpId() {
        return empId;
    }
    double getSalary() {
        return salary;
    }
    // mutators 
    void setDepartment(string Department) {
        department = Department;
    }
    void setEmpId(string EmpId) {
        empId = EmpId;
    }
    void setSalary(double Salary) {
        salary = Salary;
    }
    string category() {
        return "Manager";
    }
};

class Laborer : public Person {
private:
    string job;
    string empId;
    double hourlySalary;
    double hoursWorked;
public:
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
    void setJob(string Job) {
        job = Job;
    }
    void setEmpId(string EmpId) {
        empId = EmpId;
    }
    void setHourlySalary(double HourlySalary) {
        hourlySalary = HourlySalary;
    }
    void setHoursWorked(double HoursWorked) {
        hoursWorked = HoursWorked;
    }
    string category() {
        return "Laborer";
    }
};

void MainPart()
{
    vector<Person*> persons;

    for (int i = 0; i <= MaxDataBase; i++) {
        int choice;
        cout << "1. Add Laborer" << endl;
        cout << "2. Add Manager" << endl;
        cout << "3. Add Owner" << endl;
        cout << "4. Display All" << endl;
        cout << "5. To Exit" << endl;        choice = ReadValue<double>("Enter choice ");
        cin.ignore();
        if (choice == 1) {
            string name, ssn, birthDate, job, empId;
            double hourlySalary, hoursWorked;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter social security number: ";
            getline(cin, ssn);
            cout << "Enter birth date: ";
            getline(cin, birthDate);
            cout << "Enter job: ";
            getline(cin, job);
            cout << "Enter employee id: ";
            getline(cin, empId);
            cout << "Enter hourly salary: ";
            cin >> hourlySalary;
            cin.ignore();
            cout << "Enter hours worked: ";
            cin >> hoursWorked;
            Laborer* lab = new Laborer();
            lab->setName(name);
            lab->setSsn(ssn);
            lab->setBirthDate(birthDate);
            lab->setJob(job);
            lab->setEmpId(empId);
            lab->setHourlySalary(hourlySalary);
            lab->setHoursWorked(hoursWorked);
            persons.push_back(lab);
        }


        else if (choice == 2) {
            string name, ssn, birthDate, department, empId;
            double salary;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter social security number: ";
            getline(cin, ssn);
            cout << "Enter birth date: ";
            getline(cin, birthDate);
            cout << "Enter department: ";
            getline(cin, department);
            cout << "Enter employee id: ";
            getline(cin, empId);
            cout << "Enter salary: ";
            cin >> salary;
            cin.ignore();
            Manager* man = new Manager();
            man->setName(name);
            man->setSsn(ssn);
            man->setBirthDate(birthDate);
            man->setDepartment(department);
            man->setEmpId(empId);
            man->setSalary(salary);
            persons.push_back(man);
        }
        else if (choice == 3) {
            string name, ssn, birthDate, ownDate;
            double businessPercentage;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter social security number: ";
            getline(cin, ssn);
            cout << "Enter birth date: ";
            getline(cin, birthDate);
            cout << "Enter business Percentage: ";
            cin >> businessPercentage;
            cin.ignore();
            cout << "Enter the date you became an owner: ";
            getline(cin, ownDate);
            Owner* owner = new Owner();
            owner->setName(name);
            owner->setSsn(ssn);
            owner->setBirthDate(birthDate);
            owner->setBusinessPercentage(businessPercentage);
            owner->setOwnerDate(ownDate);
            persons.push_back(owner);
        }
        else if (choice == 4) { // need to change
            cout << endl;
            if (persons.size() > 0) {
                cout << "Total Persons in vector: " << persons.size() << endl;
                for (int index = 0; index < persons.size(); index++) {
                    cout << "Category: " << persons.at(index)->category() << endl;
                    cout << "Name: " << persons.at(index)->getName() << endl;
                    cout << "Social security number: " << persons.at(index)->getSsn() << endl;
                    cout << "Birth Date: " << persons.at(index)->getBirthDate() << endl;


                    if (persons.at(index)->category() == "Laborer") {
                        Laborer* lab = dynamic_cast<Laborer*>(persons.at(index));
                        cout << "Job: " << lab->getJob() << endl;
                        cout << "Employee Id: " << lab->getEmpId() << endl;
                        cout << "Hourly salary: " << lab->getHourlySalary() << endl;
                        cout << "Hours Worked: " << lab->getHoursWorked() << endl;
                    }
                    else if (persons.at(index)->category() == "Manager") {
                        Manager* man = dynamic_cast<Manager*>(persons.at(index));
                        cout << "Department: " << man->getDepartment() << endl;
                        cout << "Employee Id: " << man->getEmpId() << endl;
                        cout << "Salary: " << man->getSalary() << endl;
                    }
                    else if (persons.at(index)->category() == "Owner") {
                        Owner* own = dynamic_cast<Owner*>(persons.at(index));
                        cout << "Business Percentage: " << own->getBusinessPercentage() << endl;
                        cout << "Owner Date: " << own->getOwnerDate() << endl;
                    }
                    cout << endl << endl;
                }
            }
            else if (choice == 5 ){
                goto Check1;
            }
  
        }

    }

    Check1:
}

int main(){
    MainPart(); 
    return 0;
}
/*In this assignment, you will be creating a list of people and their respective positions within a company (owner, management, labor).
Start off by creating a base class called Person.  
This class should contain a name, social security number and birth date as well as the appropriate accessors and mutators.
From the Person class, derive a Laborer class that also includes job, employee id, hourly salary and hours worked.  (With accessors and mutators)
From the Person class, derive a Manager class that also includes department, employee id, salary (With accessors and mutators)
From the Person class, derive an Owner class that also includes the percentage of the business they own and the date they became an owner 
(With accessors and mutators)
For each of the derived classes, also provide a function that describes what category the person is in (Laborer, Owner, Manager)
Write a program that will display a menu allowing the user to add laborers, managers and owners. 
As the user enters the information to each, it will be added to a vector.  There should be a menu option to display the vector which will show all data for all entries in the vector.  Checkout example6.C from the videos for an example.  There should also be an option to quit.*/