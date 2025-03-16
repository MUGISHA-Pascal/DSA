#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {  // Proper constructor
        data = val;
        next = NULL;
    }
};

// Function to display the linked list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Insert at the beginning
void insertAtBegin(int val, Node*& head) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertAtTail(int val, Node*& head) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position
void insertAtPosition(int val, int position, Node*& head) {
    if (position == 1) {
        insertAtBegin(val, head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the first node
void deleteAtTop(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete a node at a given position
void deleteAtPosition(int position, Node*& head) {
    if (head == NULL) return;
    if (position == 1) {
        deleteAtTop(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return;
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Delete the last node
void deleteAtTail(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// Search for a value at a given position
void search(int position, Node* head) {
    int index = 1;
    while (head != NULL) {
        if (index == position) {
            cout << "Element at position " << position << " is " << head->data << endl;
            return;
        }
        index++;
        head = head->next;
    }
    cout << "Position " << position << " not found in the list." << endl;
}

int main() {
    Node* head = NULL;
    
    // Insert elements
    insertAtBegin(10, head);
    insertAtBegin(20, head);
    insertAtBegin(30, head);
    insertAtTail(40, head);
    insertAtTail(50, head);
    insertAtPosition(25, 3, head);
    
    cout << "Linked List after insertions: ";
    display(head);

    // Delete elements
    deleteAtTop(head);
    cout << "After deleting top element: ";
    display(head);

    deleteAtTail(head);
    cout << "After deleting last element: ";
    display(head);

    deleteAtPosition(2, head);
    cout << "After deleting element at position 2: ";
    display(head);

    // Search elements
    search(2, head);
    search(5, head);
    
    return 0;
}
