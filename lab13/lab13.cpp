#include <iostream>
using namespace std;

void task1()
{
	int size = 12;
	float* arr = new float[12] {-2.3, 4.0, -8.9, 6.3, 4.9, -7.8, -6.5, 5.1, 3.8, -4.3, -5.1, 7.2};
	for (int i = 0; i < size; i++)	cout << arr[i] << "\t";

	cout << endl << endl;

	for (int i = 0; i < size; i++)
	{if (i++ % 2 == 0 && arr[i] < 0) cout << arr[i] << "\t";}
}

void task2()
{
	int size = 7;
	float* arr = new float[size] {-2.3, 0.1, -2.3, 4.1, -3.2, 2.0, -4.0};
	for (int i = 0; i < size; i++) cout << arr[i] << "\t";
	cout << endl << endl;
	for (int i = 0, count = 0; i < size; i++, count++) if (arr[i] < 0 && (count == 2 || count == 4)) cout << arr[i] << "\t";
}

void task3()
{
	int size = 9, neg = 0, pos = 0;
	int* arr = new int[size] { -5, 2, 10, -3, 3, 1, 0, -3, -5 };
	
	for (int i = 0; i < size; i++) cout << arr[i] << "\t";

	
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			if (arr[i] < 0) neg++;
			else pos++;
		}
		else break;
	}
	cout << "\n\nNegative: " << neg << "\tPositive: " << pos << endl;

}

int main() {task3();}