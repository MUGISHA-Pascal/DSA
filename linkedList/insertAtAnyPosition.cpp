#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data):data(data),next(nullptr){};
};
void insertAtPosition(Node*& head,int position,int value){
    Node* newNode= new Node(value);
    if(position == 0){
        newNode->next=head;
        head=newNode;
        return;
    }
    Node* temp = head;
    int count=0;
    while(temp!=nullptr && count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp == nullptr){
        cout<<"Position out of range!\n";
        delete newNode;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    // Insert nodes at different positions
    insertAtPosition(head, 0, 10); // Insert at head
    insertAtPosition(head, 1, 20); // Insert at position 1
    insertAtPosition(head, 1, 15); // Insert at position 1 again
    insertAtPosition(head, 3, 25); // Insert at position 3
    insertAtPosition(head, 5, 30); // Invalid position (out of range)

    cout << "Linked List after insertions:\n";
    printList(head);

    return 0;
}