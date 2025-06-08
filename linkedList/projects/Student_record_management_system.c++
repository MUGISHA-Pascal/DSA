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