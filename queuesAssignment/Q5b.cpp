#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % MAX == front; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
        return x;
    }

    int size() {
        if (isEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        return MAX - (front - rear - 1);
    }
};

class StackOneQueue {
    Queue q;
public:
    void push(int x) {
        q.enqueue(x);
        int sz = q.size();
        // rotate to bring new element in front
        for (int i = 0; i < sz - 1; i++) {
            q.enqueue(q.dequeue());
        }
    }

    int pop() {
        if (q.isEmpty()) {
            cout << "Stack underflow\n";
            return -1;
        }
        return q.dequeue();
    }
};

int main() {
    StackOneQueue st;
    st.push(100);
    st.push(200);
    st.push(300);

    cout << st.pop() << "\n"; // 300
    cout << st.pop() << "\n"; // 200
    cout << st.pop() << "\n"; // 100
    cout << st.pop() << "\n"; // -1 (underflow)
}
