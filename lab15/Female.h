#pragma once
#include<string>
#include<iomanip>
#include "Person.h"
using namespace std;

class Female : public Person {
private:
    int childrenCount;
    bool isMarried;
    double salary;

public:
    Female(const string& surname, int birthYear, const string& address, int childrenCount, bool isMarried, double salary)
        : Person(surname, birthYear, address, false), childrenCount(childrenCount), isMarried(isMarried), salary(salary) {}

    int getChildrenCount() const override { return childrenCount; }
    bool isMarriedPerson() const override { return isMarried; }
    double getSalary() const override { return salary; }

    void display(ostream& os) const override {
        Person::display(os);
        os << setw(10) << left << ""
            << setw(10) << left << ""
            << setw(10) << left << childrenCount
            << setw(10) << left << (isMarried ? "Yes" : "No")
            << setw(15) << left << salary;
    }
};
