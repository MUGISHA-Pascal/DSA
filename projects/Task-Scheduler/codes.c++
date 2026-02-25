#include <iostream>
using namespace std;

#define MAX 10

class TaskScheduler{
    private:
            string tasks[MAX];
            int front;
            int rear;
    public:
           TaskScheduler(){
            front = -1;
            rear =-1;
           }

           bool isEmpty(){
            return front == -1 && rear == -1;
           }

           bool isFull(){
            return rear == MAX-1;
           }

           void addTask(string taskName){
            if(isFull()){
                cout << "Task queue is full! Cannot add more tasks.\n";
                return;
            }
            if(isEmpty()){
                front = rear = 0;
            }else{
                rear++
            }

            tasks[rear]=taskName;
            cout<<"Task \""<<taskName<<"\" added to the queue.\n";
           }

           void executeTask(){
            if(isEmpty()){
                cout <<"No tasks to execute!/n";
                return;
            }

            cout <<"Executing task: "<<tasks[front]<<endl;
            if(front == rear){
                front = rear = -1;
            }else{
                front++;
            }
           }

           void peekNextTask(){
            if(isEmpty()){
                cout << "No tasks pending.\n";
            }else{
                cout<<"Next task to execute: "<<tasks[front]<<endl;
            }
           }

           void displayTasks(){
            if(isEmpty()){
                cout<<"No tasks in the queue.\n";
                return;
            }

            cout << "Pending tasks:\n";
            for(int i=front;i<=rear;i++){
                cout<<i-front+1 <<". "<<tasks[i]<<endl;
            }
           }
};

int main(){
    TaskScheduler scheduler;
    int choice;
    string taskName;

    do{
        cout <<"\n=== Task Scheduler ===\n";
        cout <<"1. Add Task\n";
        cout <<"2. Execute Task\n";
        cout <<"3. View Next Task\n";
        cout <<"4. Display All Tasks\n";
        cout <<"5. Exit\n";
        cout <<"Enter your choice: ";
        cin >>choice;

        switch(choice){
            case 1:
                   cout << "Enter task name: ";
                   cin.ignore();
                   getline(cin,taskName);
                   scheduler.addTask(taskName);
                   break;
            case 2:
                   scheduler.executeTask();
                   break;
            case 3:
                   scheduler.peekNextTask();
                   break;
            case 4:
                   scheduler.displayTasks();
                   break;
            case 5:
                   cout<<"Exiting Task Scheduler...\n";
                   break;
            default:
                    cout<< "Invalid choice! Try again.\n";

        }
    }while(choice!=5);
    return 0;
}