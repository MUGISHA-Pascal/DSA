#ifndef REPORT_HPP
#define REPORT_HPP

#include "Student.hpp"
#include "Grade.hpp"
#include<iostream>
using namespace std;
class Report{
    public:
    static void generateReport(const Student& student ,const Grade& gradeBook);
};

#endif 
