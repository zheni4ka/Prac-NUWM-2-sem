#include <iostream>
#include <iomanip>
#include "StudentManagement.h"
using namespace std;

void StudentManagement::InitializeStudents()
{
    int n, id = 0;
    cout << "Enter number of students: ";
    cin >> n;

	students.resize(n); 

    for (int i = 0; i < n; ++i) {
        this->students[i].id = ++id;
        cout << "Enter FIO: ";
        cin >> this->students[i].FIO;
        cout << "Enter grades (Math, Info, OS, Eng): ";
        cin >> this->students[i].ma_grade >> this->students[i].it_grade >> this->students[i].os_grade >> this->students[i].ag_grade;
    }
}

int StudentManagement::AvgMath()
{
	int sum = 0;
	for (const auto& student : this->students) {
		sum += student.ma_grade;
	}
	return (this->students.empty()) ? 0 : sum / this->students.size();
}

int StudentManagement::AvgIT()
{
	int sum = 0;
	for (const auto& student : this->students) {
		sum += student.it_grade;
	}
	return (this->students.empty()) ? 0 : sum / this->students.size();
}

int StudentManagement::AvgOS()
{
	int sum = 0;
	for (const auto& student : this->students) {
		sum += student.os_grade;
	}
	return (this->students.empty()) ? 0 : sum / this->students.size();
    
}

int StudentManagement::AvgAG()
{
	int sum = 0;
	for (const auto& student : this->students) {
		sum += student.ag_grade;
	}
	return (this->students.empty()) ? 0 : sum / this->students.size();
}

void StudentManagement::PrintStudentTable()
{
    if (this->students.empty()) {
        cout << "No data to display." << endl;
        return;
    }


    int maxFIOLength = 3; // "FIO"
    for (const auto& student : this->students) {
        if (student.FIO.length() > maxFIOLength) {
            maxFIOLength = student.FIO.length();
        }
    }

    maxFIOLength += 2;

    int maxIdLength = 2;
    for (const auto& student : this->students) {
        int idLength = to_string(student.id).length();
        if (idLength > maxIdLength) {
            maxIdLength = idLength;
        }
    }
    maxIdLength += 2;


    cout << setfill('-');
    cout << "+" << setw(maxFIOLength) << "-" << "+"
        << setw(maxIdLength) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+" << endl;

    cout << setfill(' ');
    cout << "|" << setw(maxFIOLength) << " FIO " << "|"
        << setw(maxIdLength) << "  ID " << "|"
        << setw(8) << " Math " << "|"
        << setw(8) << " IT " << "|"
        << setw(8) << " OS " << "|"
        << setw(8) << " Eng " << "|" << endl;

    cout << setfill('-');
    cout << "+" << setw(maxFIOLength) << "-" << "+"
        << setw(maxIdLength) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+" << endl;
    cout << setfill(' ');


    for (const auto& student : this->students) {
        cout << "|" << setw(maxFIOLength) << student.FIO << "|"
            << setw(maxIdLength) << student.id << "|"
            << setw(8) << student.ma_grade << "|"
            << setw(8) << student.it_grade << "|"
            << setw(8) << student.os_grade << "|"
            << setw(8) << student.ag_grade << "|" << endl;
    }
    cout << setfill('-');
    cout << "+" << setw(maxFIOLength) << "-" << "+"
        << setw(maxIdLength) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+"
        << setw(8) << "-" << "+" << endl;
    cout << setfill(' ');
}
