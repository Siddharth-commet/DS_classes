#include <iostream>
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
        if (isFull()) return;
        if (isEmpty()) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }


    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
        return x;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

class StackTwoQueues {
    Queue q1, q2;
public:
    void push(int x) {
        q1.enqueue(x);
    }
    int pop() {
        if (q1.isEmpty()) return -1;

        while (true) {
            int x = q1.dequeue();
            if (q1.isEmpty()) {
                return x; // last element
            }
            q2.enqueue(x);
        }

        // swap q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
};
