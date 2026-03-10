#include <iostream>

using namespace std;

struct Node{
    string processName;
    int burstTime;
    Node* next;
}

class RoundRobinScheduler {
    private:
    Node* tail;
    public:
    RoundRobinScheduler(){
        tail=NULL;
    }

    void addProcess(string name,int burst){
        Node* newNode = new Node();
        newNode->processName=name;
        newNode->burstTime=burst;

        if(tail == NULL){
            tail = newNode;
            tail->next = tail;
        }else{
            newNode->next = tail->next;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void displayProcesses(){
        if(tail == NULL){
            cout << "No processes in the scheduler.\n";
            return;
        }
        Node* temp=tail->next;
        do{
            cout << temp->processName << " (Burst: "<<temp->burstTime <<") -> ";
            temp=temp->next;
        }while(temp != tail->next);
        cout <<"(Back to start)\n";
    }

    void execute(int quantum){
        if(tail == NULL){
            cout <<"No processes to execute.\n";
            return;
        }

        Node* current  = tail->next;
        Node* prev = tail;

        cout <<"\n--- Starting Round Robin Execution ---\n";

        while(tail != NULL){
            cout << "Executing: "<<current->processName<<" for "<<min(quantum,current->burstTime)<<" unit(s).\n";
            current->burstTime -= quantum;

            if(current->burstTime <=0){
                cout << current->processName << " finished execution.\n";

                if(current == tail && current == tail->next){
                    delete current;
                    tail = NULL;
                    break;
                }else{
                    prev->next=current->next;
                    if(current == tail) tail = prev;
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                    continue;
                }
            }
            prev=current;
            current=current->next;
        }
        cout << "--- All processes finished ---\n";
    }
};

int main(){
    RoundRobinScheduler scheduler;
    scheduler.addProcess("P1", 5);
    scheduler.addProcess("P2", 3);
    scheduler.addProcess("P3", 8);
    scheduler.addProcess("P4", 6);
    scheduler.displayProcesses();
    int quantum = 2;
    scheduler.execute(quantum);
    scheduler.displayProcesses();
    return 0;
}