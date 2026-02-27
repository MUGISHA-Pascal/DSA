#include <iostream>
using namespace std;

#define MAX 10

class CallCenterQueue{
    private:
            string callers[MAX];
            int front;
            int rear;
            int totalServed;
    public:
           CallCenterQueue(){
            front=rear=-1;
            totalServed=0;
           }

           bool isEmpty(){
            return front==-1&&rear==-1;
           }

           bool isFull(){
            return rear == MAX-1;
           }

           void addCaller(string name){
            if(isFull()){
                cout << "Queue is full! Cannot accept more callers.\n";
                return;
            }

            if(isEmpty()){
                front=rear=0;
            }else{
                rear++;
            }
            callers[rear]=name;
            cout<<name<<" has joined the queue.\n";
           }

           void serveCaller(){
            if(isEmpty()){
                cout << "No callers to serve!\n";
                return;
            }

            cout<<"Serving caller: "<<callers[front]<<endl;
            totalServed++;
            if(front == rear){
                front=rear=-1;
            }else{
                front++
            }
           }
           
           void peekNextCaller(){
            if(isEmpty()){
                cout<<"No callers waiting.\n";
            }else{
                cout<<"Next Caller: "<< callers[front]<<endl;
            }
           }

           void displayQueue(){
            if(isEmpty()){
                cout<<"No callers in the queue.\n";
                return;
            }

            cout<<"Callers waiting:\n";
            for(int i=front; i<=rear;i++){
                cout<<i-front+1<<". "<<callers[i]<<endl;
            }
           }

           void showTotalServed(){
            cout <<"Total callers served: "<<totalServed<<endl;
           }
};

int main(){
    CallCenterQueue cc;
    int choice;
    string callerName;

    do{
        cout<<"\n=== Call Center Simulation ===\n";
        cout<<"1. Add Caller\n";
        cout<<"2. Serve Caller\n";
        cout<<"3. View Next Caller\n";
        cout<<"4. Display Waiting Callers\n";
        cout<<"5. Total Callers Served\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            cout <<"Enter caller name:";
            cin.ignore();
            getline(cin,callerName);
            cc.addCaller(callerName);
            break;
            case 2:
            cc.serveCaller();
            break;
            case 3:
            cc.peekNextCaller();
            break;
            case 4:
            cc.displayQueue();
            break;
            case 5:
            cc.showTotalServed();
            break;
            case 6:
            cout<<"Exiting Call Center Simulation...\n";
            break;
            default:
            cout<<"Invalid choice! Try again.\n";

        }
    }while(choice!=6);
    return 0;
}