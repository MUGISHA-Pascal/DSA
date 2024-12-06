#ifndef COURSE_HPP
#define COURSE_HPP

#include<string>
using namespace std;
class Course {
    private:
    string courseName;
    int courseID;
    int credicts;
 public:
 Course(std::string,courseName,int courseID, int credits);
 string getName() const;
 int getID() const;
 int getCredits() const; 
}
#endif
