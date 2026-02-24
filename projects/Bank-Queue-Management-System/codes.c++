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

           void display(){
            if(isEmpty()){
                cout <<"Queue is empty.\n";
                return;
            }
            cout << "Customers in queue:\n";
            for(int i=front;i<=rear;i++){
                cout << i-front+1 <<". "<<arr[i]<<endl;
           }
           
           void peek(){
            if(isEmpty()){
                cout<<"Queue is empty.\n";
            }else{
                cout<<"Next customer: "<<arr[front]<<endl;
            }
           }
        }
};

int main(){
    BankQueue queue;
    int choice;
    string name;

    do{
        cout << "\n=== Bank Queue System ===\n";
        cout<<"1. Add Customer\n";
        cout <<"2. Serve Customer\n";
        cout<<"3. View Next Customer\n";
        cout<<"4. Display Queue\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                  cout<<"Enter customer name: ";
                  cin>>name;
                  queue.enqueue(name);
                  break;
            case 2:
                   queue.dequeue();
                   break;
            case 3:
                   queue.peek();
                   break;
            case 4:
                   queue.display();
                   break;
            case 5:
                   cout<<"Exiting...\n";
                   break;
            default:
                    cout<<"Invalid choice.\n";
                
        }
    }while(choice!=5);
    return 0;
}