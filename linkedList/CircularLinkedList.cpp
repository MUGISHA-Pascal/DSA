#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Inserting
void insert(Node*& tail, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!tail) { 
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Deleting a node
void deleteAtBeginning(Node*& tail) {
    if (!tail) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node* head = tail->next;
    if (head == tail) {
        delete head;
        tail = nullptr;
    } else {
        tail->next = head->next;
        delete head;
    }
}

// Displaying
void display(Node* tail) {
    if (!tail) {
        cout << "List is empty." << endl;
        return;
    }
    Node* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

// Searching
bool search(Node* tail, int value) {
    if (!tail) return false;
    Node* current = tail->next;
    do {
        if (current->data == value) return true;
        current = current->next;
    } while (current != tail->next);
    return false;
}

// Delete a node with a specific value from the circular linked list
void deleteByValue(Node*& tail, int value) {
    if (!tail) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* current = tail->next;
    Node* prev = tail;
    do {
        if (current->data == value) {
            if (current == tail && current->next == tail) { 
                delete current;
                tail = nullptr;
            } else {
                prev->next = current->next;
                if (current == tail) tail = prev;
                delete current;
            }
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);

    cout << "Value " << value << " not found in the list." << endl;
}

int main() {
    Node* tail = nullptr;

    // Insert elements
    insert(tail, 10);
    insert(tail, 20);
    insert(tail, 30);
    insert(tail, 40);

    cout << "Circular Linked List: ";
    display(tail);

    // Delete at the beginning
    cout << "Deleting at the beginning...\n";
    deleteAtBeginning(tail);
    display(tail);

    // Search for an element
    int searchValue = 30;
    cout << "Searching for " << searchValue << ": "
         << (search(tail, searchValue) ? "Found" : "Not Found") << endl;

    // Delete a specific value
    cout << "Deleting value 20...\n";
    deleteByValue(tail, 20);
    display(tail);

    // Delete a non-existing value
    cout << "Deleting value 50...\n";
    deleteByValue(tail, 50);

    return 0;
}
