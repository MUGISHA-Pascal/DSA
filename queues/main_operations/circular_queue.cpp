#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class CircularQueue{
    private:
     Node* rear;
    public:
      CircularQueue(){
        rear=NULL;
      } 
      void enqueue(int value){
        Node* newNode= new Node();
        newNode->data=value;
        if(rear == NULL){
             newNode->next=newNode;
             rear=newNode;
        }else{
            newNode->next=rear->next;
            rear->next=newNode;
            rear=newNode;
        }
      }
      void dequeue(){
        Node* front=new Node();
        if(rear == NULL){
            cout<<"the queue is empty"<<endl;
        }else{
    front = rear->next;
    rear->next=front->next;
   
        }
        delete front;
      }
      void display(){
        Node* temp=new Node();
        temp=rear->next;
        if(rear == NULL){
            cout<<"the queue is empty"<<endl;
        }else{
        do{
cout << temp->data << "->";
temp=temp->next;
            
        }while(temp != rear->next);}
      }
};
int main(){
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Circular Queue: ";
    cq.display();
    cq.dequeue();
    cout << "After dequeue: ";
    cq.display();
    return 0;
}