#include<string>
using namespace std;
class Student
{
public:
	int id;
	string FIO;
	int ma_grade;
	int it_grade;
	int os_grade;
	int ag_grade;

	Student() : id(0), ma_grade(0), it_grade(0), os_grade(0), ag_grade(0) {}
	Student(int id, string FIO, int ma_grade, int it_grade, int os_grade, int ag_grade) :
		id(id), FIO(FIO), ma_grade(ma_grade), it_grade(it_grade), os_grade(os_grade), ag_grade(ag_grade) {}
};

