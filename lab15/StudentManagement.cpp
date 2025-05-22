#include <iostream>     // Для вводу/виводу (наприклад, cout, cin)
#include <fstream>      // Для файлових операцій (наприклад, ifstream, ofstream)
#include <string>       // Для string
#include <vector>       // Для vector
#include <iomanip>      // Для setw, left, right (для форматування виводу)
#include <limits>       // Для numeric_limits
#include <sstream> 

#include "StudentManagement.h"
using namespace std;

void StudentManagement::InitializeStudents()
{
    int n, id = 0;
    cout << "Enter number of students: ";
    cin >> n;

	students.resize(n); 

    for (int i = 0; i < n; i++) {
        this->students[i].id = i+1;
		cout << "Enter FIO: ";
		cin >> this->students[i].FIO;
		cout << "Enter address: ";
		cin >> this->students[i].address;
		cout << "Enter year of birth: ";
		cin >> this->students[i].birth_year;
		cout << "Enter Math grade: ";
		cin >> this->students[i].ma_grade;
		cout << "Enter IT grade: ";
		cin >> this->students[i].it_grade;
		cout << "Enter OS grade: ";
		cin >> this->students[i].os_grade;
		cout << "Enter AG grade: ";
		cin >> this->students[i].ag_grade;
		cout << "Enter exam grade: ";
		cin >> this->students[i].exam_grade;
		cout << endl;
    }
}
void StudentManagement::SaveToFile(const string& filename) {
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "Error: failed to open the file: " << filename << endl;
		return;
	}
	for (const auto& student : students) {
		outputFile << student.get_string() << endl;
	}
	outputFile.close();
	cout << "Successfully saved to file: '" << filename << "'." << endl;
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

void StudentManagement::printStudentsByBirthYear(int year)
{
	cout << "Students born in " << year << ":" << endl;
	for (const auto& student : students) {
		if (student.birth_year == year) {
			cout << student.FIO << endl;
		}
	}
}

void StudentManagement::LoadFromFile(const string& filename)
{
	students.clear();

	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		cerr << "Error! Unable to read file " << filename << ". Creatin a new one..." << endl;
		return;
	}

	string line;
	while (getline(inputFile, line)) {
		stringstream ss(line);
		string segment;
		vector<string> seglist;

		while (getline(ss, segment, ',')) {
			seglist.push_back(segment);
		}

		if (seglist.size() == 10) {
			try {
				Student s;
				s.id = stoi(seglist[0]);
				s.FIO = seglist[1];
				s.address = seglist[2];
				s.gender = seglist[3][0];
				s.birth_year = stoi(seglist[4]);
				s.ma_grade = stoi(seglist[5]);
				s.it_grade = stoi(seglist[6]);
				s.os_grade = stoi(seglist[7]);
				s.ag_grade = stoi(seglist[8]);
				s.exam_grade = stoi(seglist[9]);
				students.push_back(s);
			}
			catch (const exception& e) {
				cerr << "Error while parsing line: " << line << " - " << e.what() << endl;
			}
		}
		else {
			cerr << "Error: incorrect string format in file: " << line << endl;
		}
	}
	inputFile.close();
	cout << "Students data succesfully loaded from file '" << filename << "'." << endl;
}




void StudentManagement::PrintStudentTable()
{
	const int ID_WIDTH = 5;
	const int FIO_WIDTH = 25;
	const int ADDRESS_WIDTH = 20;
	const int YEAR_WIDTH = 12;
	const int GRADE_WIDTH = 8; // For all individual grades

	// Print table header
	cout << left
		<< setw(ID_WIDTH) << "ID"
		<< setw(FIO_WIDTH) << "Full Name"
		<< setw(ADDRESS_WIDTH) << "Address"
		<< setw(YEAR_WIDTH) << "Birth Year"
		<< setw(GRADE_WIDTH) << "MA Grd"
		<< setw(GRADE_WIDTH) << "IT Grd"
		<< setw(GRADE_WIDTH) << "OS Grd"
		<< setw(GRADE_WIDTH) << "AG Grd"
		<< setw(GRADE_WIDTH) << "Exam Grd"
		<< endl;

	cout << setfill('-') << setw(ID_WIDTH + FIO_WIDTH + ADDRESS_WIDTH + YEAR_WIDTH + (GRADE_WIDTH * 5)) << ""
		<< setfill(' ') << endl; 

	for (const auto& student : students) {
		cout << left
			<< setw(ID_WIDTH) << student.id
			<< setw(FIO_WIDTH) << student.FIO
			<< setw(ADDRESS_WIDTH) << student.address
			<< setw(YEAR_WIDTH) << student.birth_year
			<< setw(GRADE_WIDTH) << student.ma_grade
			<< setw(GRADE_WIDTH) << student.it_grade
			<< setw(GRADE_WIDTH) << student.os_grade
			<< setw(GRADE_WIDTH) << student.ag_grade
			<< setw(GRADE_WIDTH) << student.exam_grade
			<< endl;
	}
}
