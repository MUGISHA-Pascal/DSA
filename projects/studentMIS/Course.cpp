#include "Course.hpp"
using namespace std;
Course::Course(std::string courseName , int courseID, int credits ):courseName(courseName),courseID(courseID),credicts(credicts){}
string Course::getName() const {
    return courseName;
}
int Course::getID() const{
    return courseID;
}
int Course::getCredits() {
    return credicts;
}