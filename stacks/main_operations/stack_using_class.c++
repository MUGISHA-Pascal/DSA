#include<iostream>
using namespace std;

class Stack{
    private:
       int *arr;
       int top;
       int capacity;
    public:
      Stack(int cpty){
        capacity=cpty;
        top=-1;
        arr=new int[capacity];
      }
      ~Stack(){
        delete[] arr;
      }
      bool isFull(){
        return top == capacity-1;
      }
      bool isEmpty(){
        return top == -1;
      }
      void push(int value){
        if(isFull()){
            cout << "Stack Overflow"<<endl;
            return;
        }
        arr[++top]=value;
      }
      int peek(){
        if(isEmpty()){
            cout << "the stack is empty"<<endl;
            return -1;
        }
        return arr[top];
      }
      int pop(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
          return -1;
        }
        return arr[top--];
      }
      int size(){
        return top + 1;
      }
};
int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << stack.pop() << " popped from stack" << endl;
    cout << "Top element is " << stack.peek() << endl;
    cout << "Stack size is " << stack.size() << endl;
    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is the stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    return 0;
}