#ifndef PAYROLL_HPP
#define PAYROLL_HPP

#include <iostream>
#include "Employee.hpp"
using namespace std;
class Payroll{
    public:
    void generatePayroll(Employee* employee){
        double finalSalary = employee->calculateSalary();
        cout << "Payroll  for Employees ID"<<employee->getId()<<" generated."<<endl;
        cout << "Final Salary: $"<< finalSalary << endl; 
    }};

#endif 