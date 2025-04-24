#include <iostream>
using namespace std;

int main()
{
	srand(time(0));

	//9.1
	/*const int m = 4, n = 12;
	int a[m][n];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}


	int row_max = 0, col_max = 0;
	int max = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			if (a[j][i] > max)
			{
				max = a[j][i];
				row_max = i;
				col_max = j;
			}
		}

		cout << "Max: " << max << " at [" << row_max << "][" << col_max << "]" << endl;
		row_max = 0, col_max = 0, max = a[m][0];
	}*/

	
	//9.2
	/*const int x = 3, y = 3, z = 2;
	int T[x][y][z];
	int multi = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int n = 0; n < z; n++)
			{
				T[i][j][n] = rand() % 10;
				
				cout << T[i][j][n] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	for (int i = 0; i < z; ++i) {
		multi *= T[i][i][i];
	}

	cout << "Multiply of main diagonal: " << multi << endl;*/
}