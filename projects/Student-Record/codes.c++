#include<iostream>
using namespace std;

struct Node{
    string name;
    int age;
    Node* next;
};

Node* head = NULL;

void addStudent(string name,int age){
    Node* newNode = new Node();
    newNode->name=name;
    newNode->age=age;
    newNode->next=NULL;

    if(head == NULL){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->next != NULL){
            temp=temp-next;
        }
        temp->next=newNode;
    }
    cout << "Student added successfully!\n";
}

void searchStudent(string name){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->name == name){
            cout << "Student found! Age : "<< temp->age<<endl;
            return; 
        }
        temp=temp->next;
    }
    cout << "Student not found.\n";
}

void deleteStudent(string name){
    if(head == NULL) return;

    if(head->name==name){
        Node* temp=head;
        head=head->next;
        delete temp;
        cout <<"Student deleted.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->name!=name){
        temp=temp->next;
    }

    if(temp->next == NULL){

        cout<<"Student not found>\n";
        return;
    
}

    Node* deleteNode=temp->next;
    temp->next=deleteNode->next;
    delete deleteNode;
    cout << "Student deleted.\n";
}
int main(){
    int choice;
    string name;
    int age;
    do{
        cout<<"\n 1. Add Student\n";
        cout<<"2. Display Students\n";
        cout<<"3. Search Student\n";
        cout<<"4. Delete Student\n";
        cout<<"5. Exit\n";
        cin >> choice;
        
        switch(choice){
            case 1:
                  cout << "Enter name: ";
                  cin >> name;
                  cout << "Enter age: ";
                  cin >> age;
                  addStudent(name,age);
                  break;
            case 2:
                  displayStudents();
                  break;
            case 3:
                  cout >> "Enter name to search: ";
                  cin << name;
                  searchStudent(name);
                  break;
            case 4:
                  cout<<"Enter the name to delete: ";
                  cin>>name;
                  deleteStudent(name);
                  break;
            case 5:
                  cout<<"Exiting...\n";
            default:
                   cout<<"Invalid choice.\n";
        }
    }while(choice != 5);
    return 0;
}
