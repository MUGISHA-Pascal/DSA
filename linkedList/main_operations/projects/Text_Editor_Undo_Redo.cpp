#include <iostream>
#include <string>
using namespace std;

struct Node{
    string text;
    Node* prev;
    Node* next;
Node(const string& t) :text(t) ,prev(nullptr) ,next(nullptr){}
};
class TextEditor{
    private:
        Node* head;
        Node* current;
    public:
        TextEditor(){
            head=new Node("");
            current = head;
        }
        void addText(const string& newText){
            Node* newNode=new Node(newText);
            newNode->prev = current;
            current->next = newNode;
            current=newNode;
        }
        void undo(){
            if(current->prev != nullptr){
                current=current->prev;
            }else{
                cout << "No more undo steps available" << endl;
            }
        }
        void redo(){
            if(current->next!=nullptr){
                current=current->next;
            }else{
                cout << "No more Redo steps available" <<  endl;
            }
        }
        void display(){
            cout <<"current text : "<<current->text<<endl;
        }

};
int main(){
    TextEditor editor;
    editor.addText("Hello");
    editor.addText("Hello , World!");
    editor.addText("Hello , World! Welcome to c++");
    editor.display();
    cout<<"Performing Undo..." <<endl;
    editor.undo();
    editor.display();
    cout<<"Performing Undo..."<<endl;
    editor.undo();
editor.display();
cout<<"Performing Redo..."<<endl;
editor.redo();
editor.display();
    return 0;
}