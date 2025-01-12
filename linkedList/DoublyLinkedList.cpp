#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head; 

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        }

        delete temp;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Search for a value
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Delete a node by value
    void deleteByValue(int key) {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        // If the key is at the head
        if (temp->data == key) {
            head = temp->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        // Traverse to find the key
        while (temp && temp->data != key) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value not found in the list!" << endl;
            return;
        }

        // Adjust pointers
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }
};

int main() {
    DoublyLinkedList dll;

    // Insert elements
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);

    cout << "List after insertion: ";
    dll.display();

    // Delete from the beginning
    dll.deleteFromBeginning();
    cout << "List after deleting from beginning: ";
    dll.display();

    // Search for an element
    int key = 20;
    if (dll.search(key)) {
        cout << key << " is found in the list." << endl;
    } else {
        cout << key << " is not found in the list." << endl;
    }

    // Delete a specific value
    dll.deleteByValue(30);
    cout << "List after deleting 30: ";
    dll.display();

    // Delete a non-existent value
    dll.deleteByValue(50);

    return 0;
}
