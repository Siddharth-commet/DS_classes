// Write a program that checks if an expression has balanced parentheses.

#include <iostream>
using namespace std;

class Stack {
    public:
    char arr[40];
    int top;

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

    char peek(){
        return arr[top];
    }
};

int main(){
    Stack A;
    char curParren;
    char arr[40];
    char ch;
    cout<<"Enter the expression: ";
    for (int i = 0; i < 40; i++)
    {
        cin.get(ch);
        if (ch == '\n')
        {
            break;
        }
        A.push(ch); 
    }

    while (A.top>-1)
    {
        if(A.peek()=='}' || A.peek()==']' || A.peek()==')'){
            curParren = 
        }
    }
    
    
    
    
    return 0;
}