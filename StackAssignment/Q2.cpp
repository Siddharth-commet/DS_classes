#include <iostream>
using namespace std;

class Stack {
    char arr[40];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << ch << "\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 39;
    }
};

int main() {
    Stack stringRev;
    char ch;

    cout << "Enter a string: ";

    while (cin.get(ch) && ch != '\n') {
        stringRev.push(ch);
    }

    cout << "Reversed string: ";
    while (!stringRev.isEmpty()) {
        cout << stringRev.pop();
    }
    cout << "\n";

    return 0;
}
