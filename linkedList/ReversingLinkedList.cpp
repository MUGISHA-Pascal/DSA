#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};
Node* reverseIterative(Node* head){
    Node* prev=nullptr;
    Node* current = head;
    Node* next= nullptr;
    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to insert a node at the beginning
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);

    cout << "Original List: ";
    printList(head);

    head = reverseIterative(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}