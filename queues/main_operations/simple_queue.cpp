#include <iostream>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int *queue;

    // Constructor to initialize the queue
    Queue(int cpty) {
        front = rear = -1;
        capacity = cpty;
        queue = new int[capacity];
    }

    // Function to enqueue an element
    void enqueue(int val) {
        if (rear == capacity - 1) {
            cout << "Queue overflow" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            queue[rear] = val;
            cout << "Inserted " << val << " into the queue" << endl;
        }
    }

    // Function to dequeue an element
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue when empty
        }
    }

    // Function to display queue elements
    void display() {
        if (front == -1) {
            cout << "The queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }

    // Function to read the front element
    void readFront() {
        if (front == -1) {
            cout << "The queue is empty" << endl;
        } else {
            cout << "Front element: " << queue[front] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    
    Queue q(size);
    
    while (true) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Add element to the queue\n";
        cout << "2. View the front element\n";
        cout << "3. View all elements\n";
        cout << "4. Dequeue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter the element: ";
                cin >> val;
                q.enqueue(val);
                break;
            }
            case 2:
                q.readFront();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.dequeue();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
