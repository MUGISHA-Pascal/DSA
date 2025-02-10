#include<iostream>
using namespace std;
class Stack{
    int *arr;
    int nextIndex;
    int capacity;
    public:
     Stack(){
        capacity=4;
        arr=new int[capacity];
        nextIndex=0;
     }
     void push(int ele){
        if(nextIndex==capacity){
            int *intArr = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newArr[i]=arr[i]
            }
            delete []arr;
            arr=newArr;
            capacity =  2*capacity;
        }
        arr[nextIndex]= ele;
        nextIndex++;
     }
}
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    return 0;
}