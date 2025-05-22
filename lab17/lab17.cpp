#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void swapFirstAndLast(Node* head) {
    if (!head || !head->next) return;

    Node* first = head;
    Node* prev = nullptr;
    Node* last = head;

    while (last->next) {
        prev = last;
        last = last->next;
    }

    swap(first->data, last->data);
}


void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void pushFront(Node*& head, int data) {
    Node* newNode = new Node{ data, head };
    head = newNode;
}


int main()
{
    /*int n;
    cout << "Enter size";
    cin >> n;

    stack<double> s;
    vector<double> input(n);


    cout << "Enter " << n << " values xn:\n";
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        s.push(input[i]);
    }

    double result = 0.0;

    for (int i = 0; i < n; ++i) {
        double xi = input[i];
        double xj = s.top(); s.pop();
        result += (xi * xj) / (n - i);
    }

    cout << "Result: " << result << endl;*/

    Node* head = nullptr;

    pushFront(head, 4);
    pushFront(head, 3);
    pushFront(head, 2);
    pushFront(head, 1);

    cout << "Before swapping: ";
    printList(head);

    swapFirstAndLast(head);

    cout << "After swapping: ";
    printList(head);

}