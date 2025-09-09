#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1);
    }
    void enqueue(int x) {
        if (rear == SIZE - 1) return;
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return x;
    }
    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

class StackTwoQ {
    Queue q1, q2;
public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        q1.dequeue();
    }
    void top() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << q1.getFront() << "\n";
    }
    void display() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        for (int i = q1.size(); i > 0; i--) {
            int x = q1.dequeue();
            cout << x << " ";
            q1.enqueue(x);
        }
        cout << "\n";
    }
};

int main() {
    StackTwoQ st;
    int choice, val;
    do {
        cout << "1.Push 2.Pop 3.Top 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; st.push(val); break;
            case 2: st.pop(); break;
            case 3: st.top(); break;
            case 4: st.display(); break;
        }
    } while (choice != 5);
    return 0;
}
