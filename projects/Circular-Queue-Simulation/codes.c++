#include <iostream>
#include <string>

using namespace std;

class CircularQueue{
    private:
    int front;
    int rear;
    int size;
    string* queue;
    public:
    CircularQueue(int s){
        size = s;
        queue=new string[size];
        front=-1;
        rear=-1;
    }
    bool isFull(){
        return (front == 0 && rear == size - 1) || (rear+1 == front);
    }
    bool isEmpty(){
        return front == -1;
    }
    void enqueue(string name){

        if(isFull()){
            cout <<"The queue is full! "<<name<<" cannot wait.\n";
            return;
        }

        if(front == -1) front = 0;

        rear = (rear + 1)%size;
        queue[rear] = name;
        cout << name <<" has joinedd the queue.\n";
    }
    void dequeue(){
        if(isEmpty()){
            cout <<"The queue is empty! No one to serve.\n";
            return;
        }
        cout << queue[front] <<" has been served and leaves the queue.\n";
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front + 1) % size;
        }
    }
    void display(){
        if(isEmpty()){
            cout << "The queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        int i=front;
        while(true){
            cout << queue[i];
            if(i==rear) break;
            cout << "<-";
            i=(i+1)%size;
        }
        cout << "\n";
    }
};

int main(){
    int maxSize;
    cout << "Enter the maximum size of the queue: ";
    cin>>maxSize;

    CircularQueue q(maxSize);
    int choice;
    string name;

    do{
        cout << "\n--- Ice Cream Queue Menu ---\n";
        cout << "1. Add person to queue\n";
        cout << "2. Serve Person\n";
        cout << "3. Show queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice";
        cin  >> choice;

        switch(choice){
            case 1:
                   cout <<"Enter person's name: ";
                   cin  >>name;
                   q.enqueue(name);
                   break;
            case 2:
                   q.dequeue();
                   break;
            case 3: 
                   q.display();
                   break;
            case 0:
                   cout << "Exiting...\n"
                   break;
            default:
            cout <<"Invalid choice! Try again.\n";
        }
    }while(choice!=0);
    return 0;
}