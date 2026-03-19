#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insert(Node*& head,int value){
    Node* newNode = new Node{value,NULL};

    if(!head){
        head=newNode;
        return;
    }

    Node* temp = head;
    while(temp->next)temp=temp->next;
    temp->next=newNode;
}

void display(Node* head){
    while(head){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

Node* getMiddle(Node* head){
    if(!head) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left,Node* right){
    if(!left) return right;
    if(!right) return left;

    Node* result = NULL;

    if(left->data <= right->data){
        result=left;
        result->next=merge(left->next,right);
    }else{
        result=right;
        result->next=merge(left,right->next);
    }

    return result;
}

Node* mergeSort(Node* head){
    if(!head || !head->next)return head;

    Node* mid = getMiddle(head);
    Node* right  = mid->next;
    mid->next=NULL;

    Node* left = head;
    left=mergeSort(left);
    right=mergeSort(right);
    return merge(left,right);
}

int main(){
    Node* head = NULL;

    int n,value;
    cout <<"Enter number of elements: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout <<"Enter value: ";
        cin>>value;
        insert(head,value);
    }

    cout <<"\nOriginal List:\n";
    display(head);

    head=mergeSort(head);

    cout <<"\nSorted List:\n";
    display(head);
    return 0;
}
