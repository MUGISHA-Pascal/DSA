#include<iostream>
using namespace std;

struct Student { 
int rollNumber;
string name;
float marks;
Student* next;
};
Student* head = nullptr;
void addStudent(int rollNumber,string name, float marks){
    Student* newStudent = new Student{rollNumber,name,marks,nullptr};
    if(head == nullptr){
        head = newStudent;
    }else{
        Student* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
            }
            temp->next = newStudent;   
    }
    cout<<"Student added successfully\n";
}
void displayStudents(){
    if(head == nullptr){
        cout<<"No student records found. \n";
        return;
    }
    Student* temp = head;
    cout<<"\n Student Records:\n";
    while(temp!=nullptr){
        cout<<"Roll No: "<<temp->rollNumber<<" , Name : "<<temp->name<<" , marks : "<<temp->marks<<endl;
        temp=temp->next;
    }
}
void searchStudent(int rollNumber){
    Student* temp = head;
    while(temp!=nullptr){
        if(temp->rollNumber == rollNumber){
            cout<<"Student Found : "<<"Name : "<<temp->name<<" , Marks : "<<temp->marks<<endl;
            return;
        }
        temp=temp->next;
    }
    cout << "Student with roll number "<<rollNumber<<" Not found. \n";
}
void deleteStudent(int rollNumber){
    if(head == nullptr){
        cout<<"List is empty";
        return;
    }
    if(head->rollNumber == rollNumber){
        Student* toDelete = head;
        head=head->next;
        delete toDelete;
        cout<<"Student deleted successfully.\n";
        return;
    }
    Student *prev = head;
    Student *curr = head->next;
    while(curr !=nullptr && curr->rollNumber !=rollNumber){
        prev= curr;
        curr = curr->next;
    }
    if(curr==nullptr){
        cout<<"Student with Roll No "<<rollNumber<<" not found.\n";
    }else{
        prev->next=curr->next;
        delete curr;
        cout<<"Student deleted successfully.\n";
    }
}
int main(){
    int choice, rollNumber;
    string name;
    float marks;
    do{
        cout << "\n==== Student Record Management ====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> rollNumber;
                cout << "Enter Name: ";
                cin.ignore(); // to avoid getline issue after cin
                getline(cin, name);
                cout << "Enter Marks: ";
                cin >> marks;
                addStudent(rollNumber, name, marks);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                cin >> rollNumber;
                searchStudent(rollNumber);
                break;
            case 4:
                cout << "Enter Roll Number to Delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }while (choice != 5);
    return 0;
}