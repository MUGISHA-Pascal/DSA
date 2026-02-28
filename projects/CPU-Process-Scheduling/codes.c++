#include <iostream>
using namespace std;

#define MAX 10

struct Process{
    int pid;
    int burstTime;
    int remainingTime;
}

class CPUQueue{
    private:
    Process processes[MAX];
    int front;
    int rear;
    public:
    CPUQueue(){
        front=rear=-1;
    }
    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return (rear+1) % MAX == front;
    }

    void enqueue(Process p){

        if(isFull()){
            cout <<"Queue is full\n";
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear = (rear +1 )%MAX;
        }
        processes[rear]=p;
    }

    Process dequeue(){

        Process temp =
         processes[front];
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1)%MAX;
        }
        return temp;
    }
};

int main(){
    CPUQueue queue;
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout <<"Enter Time Quantum: ";
    cin >> timeQuantum;
    for(int i=0;i<n;i++){
        Process p;
        p.pid = i+1;
        cout << "Enter burst time for Process "<<p.pid<<": ";
        cin >> p.burstTime;
        p.remainingTime = p.burstTime;
        queue.enqueue(p);
    }

    cout << "\n--- Starting Round Robin Scheduling ---\n";
    while(!queue.isEmpty()){
        Process current = queue.dequeue();
        cout << "\nProcessing P"<<curent.pid<<endl;
        if(current.remainingTime > timeQuantum){
            current.remainingTime -= timeQuantum;
            cout << "Executed for "<<timeQuantum<< " units. Remaining time: "<<current.remainingTime<<endl;
            queue.enqueue(current);
        }else{
            cout<<"Executed for "<<current.remainingTime<<" units. Process p"<<curent.pid<<" completed.\n";
        }
    }
    cout <<"\n All processes completed!\n";
    return 0;
}