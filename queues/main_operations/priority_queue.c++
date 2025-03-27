#include <iostream>

using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        if (front == nullptr || priority < front->priority) { 
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority < priority) {  
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << "(" << temp->data << ", " << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    PriorityQueue pq;
    
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.enqueue(40, 0);
    
    cout << "Priority Queue after insertions:\n";
    pq.display();
    
    cout << "Peek: " << pq.peek() << "\n";
    
    pq.dequeue();
    cout << "Priority Queue after one deletion:\n";
    pq.display();
    
    return 0;
}
