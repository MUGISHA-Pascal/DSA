#include<iostream>
using namespace std;

struct Queue{
    int front;
    int rear;
    int capacity;
    int *queue;
    Queue(){

    }
    Queue(int cpty){
      front=rear=-1;
    capacity=cpty;
      queue=new int[capacity];
    }
}
void enqueue(int val){
if(rear == n-1){
    cout << "queue overflow"<<end;
}else{
    if(front == -1){
        front=0;
    }
    rear++;
    queue[rear]=val;
}
}
void dequeue(){
if(front == -1 || front > rear){
    cout << "queue underflow"<<endl;
}
cout<<queue[front]<<endl;
front++;
}