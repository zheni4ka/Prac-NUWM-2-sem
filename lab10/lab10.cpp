#include <iostream>
using namespace std;

double sum(int start, int count, double number)
{
	double sum = 0;
	for (int i = start; i <= count; i++) sum += number;
	return sum;
}


int main()
{

	//10.1
	/*int a[] = { -1, 1, 2, 4, 5, 6, -2, 4, 0, 5};
	int b[] = { 1, 4, 3, 6, 1, 3, -2, 1, -3, 3};
	int x = 6, z = 0.9;

	for (int i = 0; i < 10; i++)
	{
		double q = (sum(1, 5, (a[i] - pow(b[i], 3))) / (cos(x * z - 1.7))) - (cos(3.6 - x*x))/(sum(2, 4, (pow(b[i], 2) - pow(a[i], 3)))) + (sum(2, 5, (pow(b[i], 3) - pow(a[i], 3)))) / (cos(x = 0.3*z));
		cout << "q = " << q << endl;
	}*/

	//10.2
	int R[10] = { 5,6,7,8,4,3,2,5,9,12 };
	int n = 5, choice = 0;
	double result = 0;

	cout << "1. Parallel\n2. Consistent\nEnter choice >>> ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		for (int i = 0; i < 10; i++)
		{
			result += sum(1, n, R[i]);
		}
		cout << "Parallel = " << result << endl;
		break;
	case 2:
		for (int i = 0; i < 10; i++)
		{
			result += sum(1, n, 1.0/R[i]);
		}
		result = 1.0 / result;
		cout << "Consistent = " << result << endl;
		break;
	}




}