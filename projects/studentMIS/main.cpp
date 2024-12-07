#include<iostream>
#include "Student.hpp"
#include "Course.hpp"
#include "Grade.hpp"
#include "Report.hpp"
using namespace std;

int main(){
    Course math("Mathematics",101,3);
    Course physics("Physics",102,4);
    Student student("Alice",1,20);
    student.enrollCourse(math);
    student.enrollCourse(physics);
    Grade gradeBook;
    gradeBook.assignGrade(1,101,"A");
    gradeBook.assignGrade(1,102,"B");
    Report::generateReport(student,gradeBook); 
    return 0;
}