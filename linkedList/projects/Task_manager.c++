#include<iostream>
using namespace std;

struct Task {
    int id;
    string name;
    string description;
    Task* next;
};

Task* head = nullptr;
void addTask(int id ,string name,string description){
    Task* newTask = new Task{id,name,description,nullptr};
    if(head == nullptr ){
        head = newTask;
    }else{
        Task* temp = head;
        while(temp->next != nullptr){temp = temp->next;}
        temp->next = newTask;
    }
    cout << "Task added! \n";
}
void viewTasks(){
    Task* temp = head;
    if(!temp){
        cout<<"No tasks available. \n";
        return;
    }
    while(temp != nullptr){
        cout<<" id : "<< temp->id << " , name : "<<temp->name<<" , description : "<<temp->description<<" \n";
        temp = temp->next;
    }
}
void deleteTask(int id){
    Task *temp = head, *prev = nullptr;
    while(temp != nullptr && temp->id != id){
        prev = temp;
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Task not found. \n";
        return;
    }
    if(prev == nullptr){
        head = head->next;
    }
}
