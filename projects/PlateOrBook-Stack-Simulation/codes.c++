#include  <iostream>
using namespace std;

#define MAX 100

class Stack{
    private:
    string arr[MAX];
    int top;
    public:
    Stack(){
        top=-1;
    }
    bool isFull(){
        return top==MAX-1;
    }
    bool isEmpty(){
        return  top==-1;
    }
    void push(string item){
        if(isFull()){
            cout << "Stack is full! Cannot add more plates/books.\n";
            return;
        }
        arr[++top]=item;
        cout<<item<<" added to the stack.\n";
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty! Nothing to remove.\n";
            return;
        }
        cout<<arr[top--]<<" removed from the stack.\n";
    }
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty!\n";
            return;
        }
        cout<<"Top of the stack: "<<arr[top]<<endl;
    }
    void display(){
        if(isEmpty()){
            cout << "Stack is empty!\n";
            return;
        }
        cout  <<"Stack from top to bottom:\n";
        for(int i=top;i>=top;i--){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
  Stack stack;
  int choice;
  string item;
  do{
    cout<<"\n=== Plate/Book Stack Simulation ===\n";
    cout<<"1. Add Plate/Book\n";
    cout<<"2. Remove Plate/Book\n";
    cout<<"3. Peek Top\n";
    cout<<"4. Display Stack\n";
    cout<<"5. Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter the name of the plate/book: ";
        cin.ignore();
        getline(cin,item);
        stack.push(item);
        break;
        case 2:
        stack.pop();
        break;
        case 3:
        stack.peek();
        break;
        case 4:
        stack.display();
        break;
        case 5:
        cout<<"Exiting...\n";
        break;
        default:
        cout<<"Invalid choice! Try again.\n";
    }
  }while(choice!=5);
return 0;
}