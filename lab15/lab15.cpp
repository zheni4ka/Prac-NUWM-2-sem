#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "StudentManagement.h"
#include "Person.h"
#include "Male.h"
#include "Female.h"
using namespace std;




void Task1()
{
	StudentManagement sm;
	sm.InitializeStudents();

	cout << endl << endl;

	cout << "Student Table:" << endl;
	sm.PrintStudentTable();

	cout << endl << endl;

	cout << "Average Math Grade: " << sm.AvgMath() << endl;
	cout << "Average IT Grade: " << sm.AvgIT() << endl;
	cout << "Average OS Grade: " << sm.AvgOS() << endl;
	cout << "Average AG Grade: " << sm.AvgAG() << endl;
	cout << endl << endl;
}

void Task2() 
{
    vector<Person*> people;
    int numPeople;

    cout << "Enter the number of people: ";
    cin >> numPeople;
    cin.ignore();

    for (int i = 0; i < numPeople; ++i) {
        cout << "\nEnter information for person " << i + 1 << ":" << endl;
        string surname, address;
        int birthYear;
        char genderChoice;

        cout << "Surname: ";
        getline(cin, surname);
        cout << "Year of birth: ";
        cin >> birthYear;
        cin.ignore();
        cout << "Address: ";
        getline(cin, address);
        cout << "Gender (m/f): ";
        cin >> genderChoice;
        cin.ignore();

        if (genderChoice == 'm' || genderChoice == 'M') {
            char militaryChoice;
            double salary;
            cout << "Military service (y/n): ";
            cin >> militaryChoice;
            cout << "Salary: ";
            cin >> salary;
            cin.ignore();
            people.push_back(new Male(surname, birthYear, address, (militaryChoice == 'y' || militaryChoice == 'Y'), salary));
        }
        else if (genderChoice == 'f' || genderChoice == 'F') {
            int childrenCount;
            char marriedChoice;
            double salary;
            cout << "Number of children: ";
            cin >> childrenCount;
            cout << "Married (y/n): ";
            cin >> marriedChoice;
            cout << "Salary: ";
            cin >> salary;
            cin.ignore();
            people.push_back(new Female(surname, birthYear, address, childrenCount, (marriedChoice == 'y' || marriedChoice == 'Y'), salary));
        }
        else {
            cout << "Invalid gender. Skipping person." << endl;
        }
    }

    // Display the information in a table
    cout << "\n-----------------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "Surname" << setw(10) << left << "Birth Year"
        << setw(20) << left << "Address" << setw(8) << left << "Gender"
        << setw(10) << left << "Military" << setw(10) << left << "Salary"
        << setw(10) << left << "Children" << setw(10) << left << "Married"
        << setw(15) << left << "Salary (Female)" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

    for (const Person* p : people) {
        p->display(cout);
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------" << endl;

    // 5. Find the total salary of men exempt from military duty.
    double totalSalaryExemptMen = 0;
    for (const Person* p : people) {
        if (p->isMalePerson() && !p->isMilitaryPerson()) {
            totalSalaryExemptMen += p->getSalary();
        }
    }

    cout << "\nTotal salary of men exempt from military duty: " << totalSalaryExemptMen << endl;

    // Clean up allocated memory
    for (Person* p : people) {
        delete p;
    }
    people.clear();
}

int main()
{
    Task2();
}