#include <iostream>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int* arr;

    Queue(int n) {
        front = 0;
        rear = 0;
        capacity = n;
        arr = new int[capacity];
    }

    void enqueue(int data) {
        if (rear == capacity) {
            cout << "Queue is overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = data;
        
    }

    int frontF() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return -1;  
        }
        return arr[front];
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        front++;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.frontF() << endl;
    q.dequeue();
    cout << "Front after dequeue: " << q.frontF() << endl;
    return 0;
}
