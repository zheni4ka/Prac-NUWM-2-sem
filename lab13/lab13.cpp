#include <iostream>
using namespace std;

void task1(int**& A, int m, int n)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i < j) {
				sum1 += A[i][j];
			}
			if (i > j) {
				sum2 += A[i][j];
			}
		}
	}

	if (sum1 > sum2) {
		cout << "Sum of elements above the main diagonal is greater. (" << sum1 << ')' << endl;
	}
	else if (sum1 < sum2) {
		cout << "Sum of elements below the main diagonal is greater. (" << sum2 << ')' << endl;
	}
	else {
		cout << "Sums are equal." << endl;
	}
}

void task2(int**& A, int m, int n)
{
	for (int j = 0; j < n; ++j) {
		int minVal = A[0][j];
		int maxVal = A[0][j];

		for (int i = 0; i < m; ++i) {
			if (A[i][j] < minVal) minVal = A[i][j];
			if (A[i][j] > maxVal) maxVal = A[i][j];
		}

		cout << "Column: " << j + 1 << ": " << maxVal - minVal << endl;
	}
}

void task3(int**& A, int m, int n)
{
    double* lengths = new double[m];
    for (int i = 0; i < m; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += A[i][j] * A[i][j];
        }
        lengths[i] = sqrt(sum);
    }

    // Виведення довжин
    cout << "\nLengths of vectors:" << endl;
    for (int i = 0; i < m; ++i) {
        cout << "Vector " << i + 1 << ": " << lengths[i] << endl;
    }

    // Пошук мінімальної довжини
    double minLength = lengths[0];
    int minIndex = 0;
    for (int i = 1; i < m; ++i) {
        if (lengths[i] < minLength) {
            minLength = lengths[i];
            minIndex = i;
        }
    }

    cout << "\nMinimum length: " << minLength << ", vector number: " << (minIndex + 1) << endl;
}

int main()
{
	srand(time(0));
    int rows, cols;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {

        matrix[i] = new int[cols];
        
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
            cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }

	if(rows == cols) task1(matrix, rows, cols);
	if (rows == 6) task3(matrix, rows, cols);
    else task2(matrix, rows, cols);



}
