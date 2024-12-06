#include <iostream>
#include <vector>
#include "Employee.hpp"
#include "Department.hpp"
#include "payroll.hpp"
#include "Menu.hpp"
#include "FileManager.hpp"
//not debugged
using namespace std;
int main(){
    vector<Employee*> employees;
    Department sales("Sales");
    Payroll payroll;
    FileManager::loadEmployeeData(employees);
    while (true)
    {
        Menu::displayMenu();
        Menu::handleInput(employees,sales,payroll);
    }
    return 0;
}