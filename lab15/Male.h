#pragma once
#include<string>
#include<iomanip>
#include "Person.h"
using namespace std;

class Male : public Person {
private:
    bool isMilitary;
    double salary;

public:
    Male(const string& surname, int birthYear, const string& address, bool isMilitary, double salary)
        : Person(surname, birthYear, address, true), isMilitary(isMilitary), salary(salary) {}

    bool isMilitaryPerson() const override { return isMilitary; }
    double getSalary() const override { return salary; }

    void display(ostream& os) const override {
        Person::display(os);
        os << setw(10) << left << (isMilitary ? "Yes" : "No")
            << setw(10) << left << salary
            << setw(10) << left << ""
            << setw(10) << left << ""
            << setw(15) << left << "";
    }
};