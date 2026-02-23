#include <iostream>
using namespace std;

#define MAX 5

class BankQueue{
    private:
            string arr[MAX];
            int front;
            int rear;
    public:
           BankQueue(){
            front=-1;
            rear=-1;
           }

           bool isEmpty(){
            return (front == -1 && rear  == -1);
           }

           bool isFull(){
            return (rear == MAX-1);
           }

           void enqueue(string name){
            if(isFull()){
                cout << "Queue is full! Cannot add more customers.\n";
                return;
            }
            if(isEmpty()){
                front=rear=0;
            }else{
                rear++;
            }

            arr[rear]=name;
            cout<<name<<" joined the queue.\n";

           }

           void dequeue(){
            if(isEmpty()){
                cout <<"Queue is empty! No customers to serve.\n";
                return;
            }
            cout << arr[front] << " has been served.\n";
            if (front == rear){
                front=rear=-1;
            }else{
                front++;
            }
           }
}