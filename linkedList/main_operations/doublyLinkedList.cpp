#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertEnd(int value) {
        Node *newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertFront(int value) {
        Node *newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteNode(int value) {
        if (!head) return;

        Node *temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (!temp) return; 

        if (temp == head) { 
            head = head->next;
            if (head) head->prev = NULL;
        } else if (temp == tail) { 
            tail = temp->prev;
            if (tail) tail->next = NULL;
        } else { 
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void displayForward() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        Node *temp = tail;
        while (temp) {
            cout << temp->data << " <- ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    ~DoublyLinkedList() {
        Node *temp = head;
        while (temp) {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.insertFront(5);
    dll.insertFront(2);
    
    cout << "Forward: ";
    dll.displayForward();
    
    cout << "Backward: ";
    dll.displayBackward();
    
    dll.deleteNode(20);
    cout << "After deleting 20, Forward: ";
    dll.displayForward();
    
    return 0;
}
