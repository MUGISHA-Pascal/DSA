#include "Student.hpp"
#include <vector>
#include <iostream>
using namespace std;
Student::Student(string name,int studentID,int age): name(name),studentID(studentID),age(age){}
void Student::enrollCourse(const Course& course){
    enrolledCourses.push_back(course);
}
void Student::displayInfo() const {
    cout << "Name : "<< name  << "\n ID : "<<studentID<<"\n Age : "<<age<<"\n Enrolled Courses : ";
    for(const auto& course : enrolledCourses){
        cout << course.getName() << " ";
    } 
    cout << endl;
}

vector<Course> Student::getCourses() const {
    return enrolledCourses;
}
int Student::getId() const{
    return studentID;
}