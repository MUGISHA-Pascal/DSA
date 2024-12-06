#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP
#include <iostream>
#include <vector>
#include "Employee.hpp"

using namespace std;
class Department{
    private:
    string departmentName;
    vector<Employee*> employees;
public:
Department(string name):departmentName(name){}
void addEmployee(Employee* employee){
    employees.push_back(employee);
}
void viewEmployees(){
    cout << "Employees in "<<department<< "Department : "<<endl;
    for(auto& emp:employees){
        emp->viewDetails();
        cout<<endl;
    }
}
};

#endif 
