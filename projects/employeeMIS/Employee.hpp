#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include<iostream>
#include<string>
using namespace std;

class Employee {
    protected:
    int id;
    string name;
    int age;
    string address;
    string position;
    double salary;

    public:
    Employee(    int id,
    string name,
    int age,
    string address,
    string position,
    double salary):id(id),name(name),age(age),address(address),position(position),salary(salary){}

virtual void viewDetails(){
    cout<<"Employee ID : "<<id<<endl;
    cout<<"Name : "<<name<<endl;
     cout<<"Age : "<<age<<endl;
      cout<<"Address : "<<address<<endl;
       cout<<"Position : "<<position<<endl;
        cout<<"Salary : "<<salary<<endl;
}
virtual int getId(){
    return id;
}
virtual double calculateSalary(){
    return salary;
}
virtual ~Employee(){}
};
class Manager : public Employee{
public:
Manager(int id,string name,int age,string address,string position,double salary):Employee(id,name, age,address,position,salary){}
void viewDetails() override {
    Employee::viewDetails();
    cout<<"This employee is a manager."<<endl;
}
double calculateSalary() override {
    return salary * 1.2;
}
};
class HR: public Employee {
    public:
    HR(int id,string name,int age , string address, string position,double salary):Employee(id,name,age,address,position,salary){}
    void viewDetails() override {
        Employee::viewDetails();
        cout<<"This employee is in HR"<<endl;
    }
    double calculateSalary() override {
        return salary * 1.1;
    }
};
#endif 

