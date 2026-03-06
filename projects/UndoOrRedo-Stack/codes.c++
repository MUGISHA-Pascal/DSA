#include <iostream>
#include <string>

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
    void push(string item){
        if(top>=MAX-1){
            cout<<"Stack Overflow!\n";
            return;
        }
        arr[++top] = item;
    }

    void pop(){
        if(top == -1) return "";
        return arr[top--];
    }

    void isEmpty(){
        return top == -1;
    }

    void clear(){
        top = -1;
    }

    void display(){
        if(isEmpty()){
            cout << "(No actions)\n";
            return;
        }
        for(int i=0; i<=top;i++){
            cout << i+1 << ". "<<arr[i]<<endl;
        }
    }
};

int main(){
    Stack undoStack;
    Stack redoStack;
    int choice;
    string action;

    do{
        cout <<"\n=== Undo/Redo Feature Simulation ===\n";
        cout <<"1. Do action\n";
        cout <<"2. Undo\n";
        cout <<"3. Redo\n";
        cout <<"4. Show Actions\n";
        cout <<"5. Exit\n";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                   cout << "Enter action description: ";
                getline(cin,action);
                undoStack.push(action);
                redoStack.clear();
                cout << "Action done: "<<action<<endl;
                break;
            case 2:
            if(undoStack.isEmpty()){
                cout <<"Nothing to undo!\n";
            }else{
                string undone = undoStack.pop();
                redoStack.push(undone);
                cout << "Undone: "<<undone<<endl;
             
            }
            break;
            case 3:
            if(redoStack.isEmpty()){
                cout <<"Nothing to redo!\n";
            }else{
                string redone = redoStack.pop();
                undoStack.push(redone);
                cout<<"Redone: "<<redone<<endl;
            }
            break;
            case 4:
            cout<<"Current Actions:\n";
            undoStack.display();
            break;
            case 5:
            cout <<"Exiting...\n";
            break;
            default:
            cout<<"Invalid choice! Try again.\n";

         
        }

    }while(choice!=5);
    return 0;
}