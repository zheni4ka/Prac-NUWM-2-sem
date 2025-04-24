#include <iostream>
using namespace std;

double sum(int start, int count, int number)
{
	double sum = 0;
	for (int i = start; i <= count; i++)
	{
		sum += number;
	}
	return sum;
}


int main()
{
	int a[] = { -1, 1, 2, 4, 5, 6, -2, 4, 0, 5};
	int b[] = { 1, 4, 3, 6, 1, 3, -2, 1, -3, 3};
	int x = 6, z = 0.9;

	for (int i = 0; i < 10; i++)
	{
		double q = (sum(1, 5, (a[i] - pow(b[i], 3))) / (cos(x * z - 1.7))) - (cos(3.6 - x*x))/(sum(2, 4, (pow(b[i], 2 - pow(a[i], 3))))) + (sum(2, 5, (pow(b[i], 3) - pow(a[i], 3)))) / (cos(x = 0.3*z));
		cout << "q = " << q << endl;
	}
}