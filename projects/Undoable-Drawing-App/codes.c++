#include <iostream>
#include <vector>
using namespace std;

class Stack{
    private:
    vector<string> arr;
    public:
    void push(string item){
        arr.push_back(item);
    }
    string pop(){
        if(arr.empty()) return "";
        string item = arr.back();
        arr.pop_back();
        return item;
    }
    void display(){
        if(arr.empty()){
            cout << "Canvas is empty!\n";
            return;
        }
        cout <<"Current Canvas:\n";
        for(int i=0;i<arr.size();i++){
            cout<<i+1<<". "<<arr[i]<<endl;
        }
    }
};

int main(){
    Stack undostack;
    Stack redostack;
    int choice;
    string shape;
    do{
        cout<<"\n=== Undoable Drawing App ===\n";
        cout<<"1. Draw Shape\n";
        cout<<"2. Undo\n";
        cout<<"3. Redo\n";
        cout<<"4. Show Canvas\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin>ignore();
        switch(choice){
            case 1:
            cout<<"Enter shape description (e.g., Circle at (2,3)): ";
            getline(cin,shape);
            undostack.push(shape);
            while(!redostack.isEmpty()) redostack.pop();
            cout<<"Shape added!\n";
            break;
            case 2:
            if(!undostack.isEmpty()){
                string undoneshape = undostack.pop();
                redostack.push(undoneshape);
                cout<<"Undid: "<<undoneshape<<endl;
            }else{

                cout<<"Nothing to undo!\n";
            }
            break;
            case 3:
            if(!redostack.isEmpty()){
                string redoneshape = redostack.pop();
                undostack.push(redoneshape);
                cout<<"Redid: "<<redoneshape<<endl;
            }else{
                cout<<"Nothing to redo!\n";
            }
            break;
            case 4:
            undostack.display();
            break;
            case 5:
            cout<<"Exiting...\n";
            break;
            default:
            cout<<"Invalid choice!\n";
        }
    }while(choice!=5);
    return 0;
}