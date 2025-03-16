#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
void insertEnd(Node*& head,int data){
    Node* newNode =  new Node;
    newNode->data = data;
    newNode->next=nullptr;
    if(!head){
        head=newNode;
        newNode->next=head;
    }else{
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }}
    void deleteNode(Node*& head,int key){
        if(!head) return;
        Node *curr = head,*prev = nullptr;
        while(curr->data !=key){
            if(curr->next==head){
                cout<<"Node not found"<<endl;
                return;
            }
            prev=curr;
            curr=curr->next;
        }
        if(curr == head && curr->next ==head){
            head = nullptr;
        }else if(curr==head){
            prev=head;
            while(prev->next != head ) prev = prev->next;
            head= head->next;
            prev->next=head;
        }else{
            prev->next=curr->next;
        }
        delete curr;
    }
    void display(Node* head){
  if(!head){
    cout << "list is empty";
    return;
  }
  Node* temp=head;
  do{
    cout<<temp->5data<<"->";
    temp = temp->next;
  }while(temp!=head);
  cout << "(HEAD)\n";
    }
    int main() {
        Node* head = nullptr;
        
        insertEnd(head, 10);
        insertEnd(head, 20);
        insertEnd(head, 30);
        insertEnd(head, 40);
        
        cout << "Circular Linked List: ";
        display(head);
        
        cout << "\nDeleting node with value 20...\n";
        deleteNode(head, 20);
        display(head);
        
        return 0;
    }
    