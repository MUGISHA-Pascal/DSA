#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include "Employee.hpp"
#include "Department.hpp"
#include "payroll.hpp"
#include <vector>
using namespace std;
class Menu{
    public:
    static void displayMenu(){
        cout << "1. Add Employee"<< endl;
                cout << "2. View Employee Details"<< endl;
        cout << "3. Generate Payroll"<< endl;
        cout << "4. Exit"<< endl;
    }
    static void handleInput(vector<Employee*>& employees,Department& dept,Payroll& payroll){
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                int id;
                string name,position;
                int age;
                double salary;
                cout << "Enter Employee ID : ";
                cin >> id ;
                cout << "Enter Name : ";
                cin>>name;
                cout << "Enter Age : ";
                cin>>age;
                cout << "Enter Position : ";
                cin>>position;
                cout << "Enter Salary : ";
                cin>>salary;
                Employee* newEmp = new Employee(id,name,age,"N/A",position,salary);
                employees.push_back(newEmp);
                dept.addEmployee(newEmp);
                break;
            }
            case 2:
             dept.viewEmployees();
             break;
             case 3:{
             for(auto& emp : employees){
                payroll.generatePayroll(emp);
             }
             break;}
             case 4:
             cout << "Exiting ... "<<endl;
             exit(0);
             default:
             cout<<"Invalid option!"<<endl;
        }
    }
};


#endif
