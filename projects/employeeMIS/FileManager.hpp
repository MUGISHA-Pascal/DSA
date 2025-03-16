#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <iostream>
#include <fstream>
#include "Employee.hpp"
#include <vector>
using namespace std;
class FileManager{
    public:
    static void saveEmployeeData(const vector<Employee*>& employees){
        ofstream outFile("employees.dat",ios::binary);
        for(auto& emp : employees){
            outFile.write((char*)emp,sizeof(Employee));        }
   outFile.close();
    }
static void loadEmployeeData(vector<Employee*>& employees){
    ifstream inFile("employees.dat",ios::binary);
    Employee* emp;
    while (inFile.read((char*)&emp,sizeof(Employee))){
        employees.push_back(emp);
    }
    inFile.close();
}
};
#endif 
