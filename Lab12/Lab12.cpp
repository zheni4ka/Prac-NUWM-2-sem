#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> splitWords(const string& text) {
    vector<string> words;
    stringstream ss(text);
    string word;

    while (getline(ss, word, ',')) {
        if (!word.empty() && word.back() == '.') {
            word.pop_back();
        }
        words.push_back(word);
    }

    return words;
}

void task1()
{
    string A[] = {
       "Alpha", "Bravo", "Charlie", "Delta", "Echo",
       "Foxtrot", "Golf", "Hotel", "India", "Juliet",
       "Kilo", "Lima", "Mike", "November", "Oscar"
    };

    // Print the vector
    for (int i = 0; i < 15; i++)
    {
        cout << A[i] << " ";
    }

    cout << "-------------------------" << endl;
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < 15; ++i) {
        if (A[i].length() < A[minIndex].length()) {
            minIndex = i;
        }
        if (A[i].length() > A[maxIndex].length()) {
            maxIndex = i;
        }
    }

    // ќбм≥н елемент≥в м≥сц€ми
    swap(A[minIndex], A[maxIndex]);

    // ¬иведенн€ результату
    cout << "\ntext array after editing:\n";
    for (int i = 0; i < 15; ++i) {
        cout << "A[" << i << "] = " << A[i] << endl;
    }
}
void task2()
{
    string F = "apple,pear,banana,orange,plum,peach,cherry,lemon,melon,watermelon,kiwi,mango,pineapple,fig,grape";
	cout << F << endl;

    for (int i = 0; i < F.length(); i++) if (F[i] == ',') F[i] = ' ';
	cout << F << endl;
}
void task3()
{
	string F = "apple,pear,banana,orange,plum,peach,cherry,lemon,melon,watermelon,kiwi,mango,pineapple,fig,grape.";
	vector<string> words = splitWords(F);
    for (int i = 1; i + 1 < words.size(); ++i) {
        if (words[i - 1] < words[i] && words[i + 1] > words[i]) {
            cout << words[i] << endl;
        }
    }
}

int main()
{
    task3();
}