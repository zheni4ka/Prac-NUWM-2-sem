#include <iostream>
#include <vector>
using namespace std;

void generateSubmnozhyny(int n, int number, vector<int>& submnozhyna) {
    if (number > n) {
        // Виводимо поточну підмножину
        cout << "{ ";
        for (int x : submnozhyna) {
            cout << x << " ";
        }
        cout << "}" << endl;
        return;
    }

    generateSubmnozhyny(n, number + 1, submnozhyna); // Не включати число

    // Включити index
    submnozhyna.push_back(number);
    generateSubmnozhyny(n, number + 1, submnozhyna);
    submnozhyna.pop_back(); // Повернення до попередньої множини
}

int main() {
    int N;
    vector<int> subset;

    cout << "Введіть N: "; cin >> N;

    generateSubmnozhyny(N, 1, subset);
    return 0;
}
