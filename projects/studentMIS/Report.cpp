#include "Report.hpp"
#include <iostream>
using namespace std;

void Report::generateReport(const Student& student, const Grade& gradeBook){
    cout << "Report for studentID : "<< student.getId() <<endl;
    student.displayInfo();
    for(const auto& course : student.getCourses()){
        char grade = gradeBook.getGrade(student.getId(),course.getID());
        cout<<"Course : "<<course.getName() << "Grade : "<< grade << endl;
    }
}