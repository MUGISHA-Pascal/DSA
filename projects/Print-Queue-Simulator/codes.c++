#include <iostream>
using namespace std;

#define MAX 5

struct PrintJob{
    string documentName;
    int pages;
}

class PrintQueue{
    private:
            PrintJob jobs[MAX];
            int front;
            int rear;
    public:
           PrintQueue(){
            front=rear=-1;
           }

           bool isEmpty(){
            return front == -1 && rear == -1;
           }

           bool isFull(){
            return rear == MAX-1;
           }

           void addJob(string name,int pages){
            if(isFull()){
                cout << "Print queue is full! Cannot add more jobs.\n";
                return;
            }

            if(isEmpty()){
                front=rear=0;
            }else{
                rear++;
            }

            jobs[rear].documentName=name;
            jobs[rear].pages=pages;
            cout << "Print job \""<<name<<"\" ("<<pages<<" pages) added to the queue.\n";
           }

           void processJob(){
            if(isEmpty()){
                cout << "No print jobs to process!\n";
                return;
            }

            cout << "Printing \""<<jobs[front].documentName<<"\" ("<<jobs[front].pages<<" pages)... Done!\n";
            if(front == rear){
                front=rear=-1;
            }else{
                front++;
            }
           }

           void peekNextJob(){
            if(isEmpty()){
                cout << "No print jobs pending.\n";
            }else{
                cout<<"Next job: \""<<jobs[front].documentName<<"\" ("<<jobs[front].pages<<" pages)\n";
            }
           }

           void displayQueue(){
            if(isEmpty()){
                cout << "Print queue is empty.\n";
                return;
            }

            cout <<"Pending print jobs: \n";
            for(int i = front;i<=rear;i++){
                cout<<i-front+1<<". "<<jobs[i].documentName<<" ("<<jobs[i].pages<<" pages)\n";
            }
           }
};

int main(){
    PrintQueue pq;
    int choice,pages;
    string docName;

    do{
        cout<<"\n=== Print Queue Simulator ===\n";
        cout<<"1. Add Print Job\n";
        cout<<"2. Process Next Job\n";
        cout<<"3. View Next Job\n";
        cout<<"4. Display All Jobs\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1: 
                   cout<<"Enter document name: ";
                   cin.ignore();
                   getline(cin,docName);
                   cout<<"Enter number of pages: ";
                   cin>>pages;
                   pq.addJob(docName,pages);
                   break;
            case 2:
                   pq.processJob();
                   break;
            case 3:
                   pq.peekNextJob();
                   break;
            case 4:
                   pq.displayQueue();
                   break;
            case 5:
                   cout<<"Exiting Print Queue Simulator...\n";
                   break;
            default:
                    cout<<"Invalid choice! Try again.\n";
        }
    }while(choice !=5);

return 0; 
}