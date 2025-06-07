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
    Task *temp = head,*prev = nullptr;
    while(temp != nullptr && temp->id != id){
        prev  = temp;
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Task not found. \n ";
    return;
    }
    if(prev == nullptr){
        head = head->next;
    }else{
        prev->next = temp->next;
    }
    delete temp;
    cout << "Task deleted! \n";
}

void searchTask(const string& name){
    Task* temp = head;
    bool found = false;
    while(temp != nullptr){
        if(temp->name == name){
            cout<<"Found Task - id : "<<temp->id<<" , Description : " << temp->description<<"\n";
            found = true;
        }
        temp = temp->next;
    }
    if(!found){
        cout << "No task with the name found . \n";
    }
}
int main() {
    int choice, id;
    string name, description;
    while (true) {
        cout << "\n==== Task Manager ====\n";
        cout << "1. Add Task\n2. View All Tasks\n3. Delete Task by ID\n4. Search Task by Name\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter ID: "; cin >> id; cin.ignore();
                cout << "Enter name: "; getline(cin, name);
                cout << "Enter description: "; getline(cin, description);
                addTask(id, name, description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter ID to delete: "; cin >> id;
                deleteTask(id);
                break;
            case 4:
                cout << "Enter name to search: "; getline(cin >> ws, name);
                searchTask(name);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}