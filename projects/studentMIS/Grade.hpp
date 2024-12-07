#ifndef GRADE_HPP
#define GRADE_HPP

#include "Student.hpp"
#include "Course.hpp"
#include <map>
using namespace std;

class Grade{
 private:
    map<int,map<int,char>> gradeBook;
    public:
    void assignGrade(int studentID,int courseID,char grade);
    char getGrade(int studentID, int courseID) const;
    void displayGrades(int studentID) const;
};

#endif 
