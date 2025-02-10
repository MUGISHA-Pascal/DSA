#include<iostream>
using namespace std;

struct Stack {
    int *arr;
    int nextIndex;
    int capacity;
    
    public:
     Stack(int cap){
        capacity = cap;
        arr = new int[capacity];  
        nextIndex = 0;
     }

     ~Stack() {
        delete[] arr;  
     }

     void push(int val){
         if(isFull()){
            cout<<"Stack Overflow"<<endl;
         }else{
            arr[nextIndex] = val;
            nextIndex++;
         }
     }

     void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        } else {
            cout<<"The removed element is: " << arr[nextIndex-1] << endl;
            nextIndex--;
        }
     }

     bool isEmpty(){
         return nextIndex == 0;
     }

     bool isFull(){
         return nextIndex == capacity;
     }

     int peek(){
        if(isEmpty()){
            return -1;
        }
        return arr[nextIndex-1];
     }

     void display(){
        if(isEmpty()){
            cout << "Stack is empty." << endl;
            return;
        }
        for(int i = 0; i < nextIndex; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
     }
};

int main(){
    Stack *myStack = new Stack(5);
    
    cout << "Start adding elements" << endl;
    myStack->push(10);
    myStack->push(20);
    myStack->push(30);
    myStack->push(40);
    myStack->push(50);
    myStack->push(60);  
    
    myStack->display();
    
    cout << "The top element in my stack: " << myStack->peek() << endl;
    myStack->pop();
    myStack->pop();
    
    myStack->display();
    
    cout << "The top element in my stack: " << myStack->peek() << endl;
    
    myStack->pop();
    myStack->pop();
    myStack->pop();
    myStack->pop();  
    
    delete myStack;  
    return 0;
}
