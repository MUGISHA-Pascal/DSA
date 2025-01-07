#include<iostream>
using namespace std;
template<typename T>
class Node
{
    public:
    T data;
    Node *next;
    Node(){}
Node(T d){
    data=d;
    next=NULL;
}
};
template<typename T>
void display(Node<T> *head){
    while(head !=NULL){
     cout<<head->data <<"->";
     head=head->next;
    }
    cout<<"Null";
}
int main(){
    Node<int> *n1=new Node<int> ();
     Node<int> *n2=new Node<int> ();
      Node<int> *n3=new Node<int> ();
      n1->data=10;
      n1->next=n2;
      n2->data=12.3;
      n2->next=n3;
      n3->data=13;
      n3->next=NULL;
      display(n1);
      return 0;
}