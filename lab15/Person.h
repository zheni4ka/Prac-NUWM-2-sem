#pragma once
#include<string>
#include<iomanip>
using namespace std; 

class Person {
protected:
    string surname;
    int birthYear;
    string address;
    bool isMale;

public:
    Person(const string& surname, int birthYear, const string& address, bool isMale)
        : surname(surname), birthYear(birthYear), address(address), isMale(isMale) {}

    virtual ~Person() = default;

    const string& getSurname() const { return surname; }
    int getBirthYear() const { return birthYear; }
    const string& getAddress() const { return address; }
    bool isMalePerson() const { return isMale; }

    virtual double getSalary() const { return 0.0; }
    virtual int getChildrenCount() const { return 0; }
    virtual bool isMarriedPerson() const { return false; }
    virtual bool isMilitaryPerson() const { return false; }

    virtual void display(ostream& os) const {
        os << setw(15) << left << surname
            << setw(10) << left << birthYear
            << setw(20) << left << address
            << setw(8) << left << (isMale ? "Male" : "Female");
    }
};

