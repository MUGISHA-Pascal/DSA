#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Student{
    string  name;
    int score;
    Student(string n,int s):name(n),score(s){}
};
void displayStudents(const vector<Student>& students){
    cout<<"Students:\n";
    for(const auto& student:students){
        cout << "Name: "<< student.name<<" , Score: "<<student.score<<endl; 
    }
}
void bubblesort(vector<Student>& students){
    int n = students.size();
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(students[j].score > students[j+1].score){
                swap(students[j],students[j+1]);
            }
        }
    }
}
void selectionSort(vector<Students>& students){
    int n = students.size();
    for(int i=0;i<n-1;++i){
        int minIndex=i;
        for(int j=i+1;j<n;++j){
            if(students[j].score < students[minIndex].score){
                minIndex=j;
            }
        }
        swap(students[i],students[minIndex]);
    }
}