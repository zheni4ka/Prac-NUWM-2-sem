#include<string>
using namespace std;
class Student
{
public:
	int id;
	string FIO;
	string address;
	char gender;
	int birth_year;
	int ma_grade;
	int it_grade;
	int os_grade;
	int ag_grade;
	int exam_grade;

	string get_string() const {
		return to_string(id) + "," + FIO + "," + address + "," + gender + "," +
			to_string(birth_year) + "," + to_string(ma_grade) + "," +
			to_string(it_grade) + "," + to_string(os_grade) + "," +
			to_string(ag_grade) + "," + to_string(exam_grade);
	}

	Student() : id(0), ma_grade(0), it_grade(0), os_grade(0), ag_grade(0) {}
	Student(int id, string FIO, int ma_grade, int it_grade, int os_grade, int ag_grade) :
		id(id), FIO(FIO), ma_grade(ma_grade), it_grade(it_grade), os_grade(os_grade), ag_grade(ag_grade) {}
};

