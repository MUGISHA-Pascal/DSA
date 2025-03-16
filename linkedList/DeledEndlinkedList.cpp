#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){}
    Node(int d){
        data=d;
        next=NULL;
    }
};
Node* deleteEnd(Node *head){
    Node *temp=head;
    Node *secondLast = head;
    while(secondLast->next->next != NULL){
        secondLast=secondLast->next;
    }
    delete secondLast->next;
    secondLast->next = NULL;
    return temp;
}
void display(Node *head){
    while(head != NULL){
        cout<< head -> data << "->" ;
        head= head->next;
    }
    cout << "NULL \n";
}
int main(){
    Node *n1= new Node();
    Node *n2= new Node();
        Node *n3= new Node();
            Node *n4= new Node();
        Node *n5= new Node();
  n1->data=50;
      n1->next=n2;
      n2->data=10;
      n2->next=n3;
      n3->data=35;
      n3->next=n4;
      n4->data=20;
      n4->next=n5;
      n5->data=40;
      n5->next=NULL;
      
      display(n1);
      deleteEnd(n1);
            display(n1);

      return 0;
}