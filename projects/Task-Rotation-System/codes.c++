#include <iostream>
using namespace std;

struct Task{
    string name;
    Task* next;
};

class TaskRotation{
    private:
    Task* tail;
    Task* current;
    public:
    TaskRotation(){
        tail=NULL;
        current=NULL;
    }

    void addTask(string name){
        Task* newTask = new Task();
        newTask->name =name;
        
        if(tail==NULL){
            tail=newTask;
            tail->next=tail;
            current=tail;
        }else{
            newTask->next = tail->next;
            tail->next=newTask;
            tail=newTask;
        }
        cout << "Task added: "<<name<<endl;

    }

    void displayTasks(){
        if(tail==NULL){
            cout<<"No tasks available\n";
            return;
        }
        Task* temp = tail->next;
        cout << "\nTasks:\n";
        do{
            if(temp==current)cout <<"[CURRENT] ";
            cout << temp->name << " -> ";
            temp=temp->next;
        }while(temp != tail->next);
        cout <<"(back to start)\n";
    }

    void nextTask(){
        if(current == NULL)return;
        current=current->next;
        cout<<"Now doing: "<<current->name<<endl;
    }
    void removeTask(string name){
        if(tail == NULL) return;
        Task* temp = tail->next;
        Task* prev = tail;
        do{
            if(temp->name == name){
                if(temp==tail && temp == tail->next){
                    tail=NULL;
                    current=NULL;
                }else{
                    prev->next = temp->next;
                    if(temp==tail)tail=prev;
                    if(current == temp)current=temp->next;
                }
                cout  << "Task removed: "<<name<<endl;
                delete temp;
                return;
            }

            prev=temp;
            temp=temp->next;
        }while(temp!=tail->next);
        cout <<"Task not found\n";
    }
};

int main(){

    TaskRotation system;

    system.addTask("Study");
    system.addTask("Exercise");
    system.addTask("Code");
    system.addTask("Rest");

    system.displayTasks();

    cout << "\nRotating tasks:\n";

    system.nextTask();
    system.nextTask();

    system.displayTasks();

    cout << "\nRemoving task:\n";
    system.removeTask("Exercise");

    system.displayTasks();

    return 0;
}