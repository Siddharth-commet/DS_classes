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
    bool isFull() {
        return (rear == SIZE - 1);
    }
    void enqueue(int x) {
        if (isFull()) return;
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
    void display() {
        if (isEmpty()) return;
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Queue q, firstHalf, secondHalf, result;
    int n, x;
    cout<<"size: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }
    int half = q.size() / 2;
    for (int i = 0; i < half; i++) firstHalf.enqueue(q.dequeue());
    while (!q.isEmpty()) secondHalf.enqueue(q.dequeue());
    while (!firstHalf.isEmpty() && !secondHalf.isEmpty()) {
        result.enqueue(firstHalf.dequeue());
        result.enqueue(secondHalf.dequeue());
    }
    result.display();
    return 0;
}