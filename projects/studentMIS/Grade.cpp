#include "Grade.hpp"
#include <iostream>
using namespace std;

void Grade::assignGrade(int studentID,int courseID,char grade){
gradeBook[studentID][courseID]=grade;
}
char Grade::getGrade(int studentID,int courseID) const {
    auto studentIt= gradeBook.find(studentID);
    if(studentIt != gradeBook.end()){
        auto courseIt = studentIt->second.find(courseID);
     if(courseIt != studentIt -> second.end()){
        return courseIt->second;
     }
    }
    return 'N';
}
void Grade::displayGrades(int studentID) const {
    auto studentIt = gradeBook.find(studentID);
    if(studentIt != gradeBook.end()){
        for(const auto& pair : studentIt->second){
            auto courseID = pair.first;
            auto grade = pair.second;
            cout << "Course ID : "<< courseID << " Grade  : "<< grade << endl;
        }
    }else{
        cout << "No grades found for student ID : " <<studentID <<endl;
    }
}