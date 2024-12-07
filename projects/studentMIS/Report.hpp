#ifndef REPORT_HPP
#define REPORT_HPP

#include "Student.hpp"
#include "Grade.hpp"

class Report{
    public:
    static void generateReport(const Student& student ,const Grade& gradeBook);
}

#endif 
