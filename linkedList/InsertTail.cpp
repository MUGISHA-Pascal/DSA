#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node *head = NULL;

void addFirst(Node **head, int val) {
    Node *newNode = new Node(val);
    newNode->next = *head;
    *head = newNode;
}

Node* insertTail(Node* head, int data) {
    Node* temp = head;
    Node* newNode = new Node(data);
    
    
    if (head == NULL) {
        return newNode;  
    }

    while (head->next != NULL) {
        head = head->next;
    }
    
   
    head->next = newNode;
    
    return temp;
}

void display(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    Node* root = NULL;
    Node* second = NULL;
    Node* third = NULL;

    root = new Node(1);
    second = new Node(2);
    third = new Node(3);
    
    root->next = second;
    second->next = third;
    
    head = root;
    
    addFirst(&head, 20);
    addFirst(&head, 30);
    
    head = insertTail(head, 40);
    
    display(head);
    
    return 0;
}
