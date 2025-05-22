#include<string>
#include<vector>
#include"Student.h"
using namespace std;

class StudentManagement
{
private:
	vector<Student> students;
public:
	void PrintStudentTable();
	void InitializeStudents();
	void SaveToFile(const string& filename);
	void LoadFromFile(const string& filename);
	void printStudentsByBirthYear(int year);

	int AvgMath();
	int AvgIT();
	int AvgOS();
	int AvgAG();
};

