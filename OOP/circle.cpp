#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;
class Circle{
    private:
        double radius;
    public:
    Circle(double r){
        if(r<0){
             cerr<<"Radius cannot be negative, Setting to 0."<<  endl;
            radius=0;
        }else{
            radius=r;
        }
    }
     void  setRadius (double r){
        if(r<0){
             cerr<<"Radius cannot be negative, Setting to 0."<<  endl;
            radius=0 ;
        }else{
            radius=r;
        }
    }
    double getRadius() const{
        return radius;
    }
    double calculateArea() const{
        return M_PI * radius * radius;
    }
    double calculateCircumference() const{
        return 2 * M_PI * radius;
    }
    void display() const {
         cout<<"Circle details :"<<  endl;
         cout<<"Radius :"<<radius<<  endl;
         cout<<"area :"<<calculateArea()<<  endl;
         cout<<"circumference :"<<calculateCircumference() <<  endl;

    }
};
int main(){
    Circle mycircle(0.5);
    mycircle.display();
    mycircle.setRadius(10.0);
             cout<<"after changing radius :" << endl;
            mycircle.display();
            return 0;

}

