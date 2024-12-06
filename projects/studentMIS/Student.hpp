#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include "Course.hpp"
using namespace std;
class Student {
    private:
       string name;
       int studentID;
       int age;
       vector<Course> enrolledCourses;
    public:
    Student(string name,int studentID,int age);
    void enrollCourse(const Course& course);
    void displayInfo() const;
    vector<Course> getCourses() const;
    int getId() const;
};

#endif
