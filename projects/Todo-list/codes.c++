#include<iostream>
#include<string>
using namespace std;

struct Task{
    string name;
    Tast* next;
}

void addTask(Task*& head,string taskName){
    Task* newTask = new Task{taskName,nullptr};
    if (head == nullptr){
        head = newTask;
    } else {
        Task* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newTask;
    }
    cout<<"Task added successfully!\n";
}

void deleteTask(Task*& head,string taskName){
    if(head == nullptr){
        cout<<"No tasks to delete.\n";
        return;
    }
    if(head->name == taskName){
        Task* toDelete=head;
        head=head->next;
        delete toDelete;
        cout<<"Task deleted successfully!\n";
        return;
    }
    Task* temp = head;
    while(temp->next!=nullptr && temp->next->name != taskName){
        temp=temp->next;
    }
    if(temp->next == nullptr){
        cout << "Task not found.\n";
    }else{
        Task* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Task deleted successfully!\n";
    }

}

void displayTasks(Task* head){
    if(head == nullptr){
        cout << "No tasks to show.\n";
        return;
    }
    cout<<"\n Your Tasks: \n";
    Task* temp = head;
    int count=1;
    while(temp!=nullptr){
        cout<<count<<". "<<temp->name<<endl;
        temp=temp->next;
        count++;
    }
    cout<<endl;

}

int main() {
    Task* head = nullptr;
    int choice;
    string taskName;
    do{
        cout<<"==== To-Do List Menu ====\n";
        cout<<"1. Add Task\n";
        cout<<"2. Delete Task\n";
        cout<<"3. Display Tasks\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                  cout<<"Enter task name: ";
                  getline(cin,taskName);
                  addTask(head,taskName);
                  break;
            case 2:
                  cout<<"Enter task name to delete: ";
                  getline(cin,taskName);
                  deleteTask(head,taskName);
                  break;
            case 3:
                  displayTasks(head);
                  break;
            case 4:
                  cout<<"Exiting To-Do List...\n";
                  break;
            default:
                   cout<<"Invalid choice! Try again.\n";
                   }
    }while(choice!=4);
    while(head != nullptr){
        Task* temp=head;
        head=head->next;
        delete temp;
    }
    return 0;
}