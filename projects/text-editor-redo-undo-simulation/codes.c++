#include <iostream>
#include <string>
using namespace std;

struct Node{
    string text;
    Node* prev;
    Node* next;
    Node(string t){
        text=t;
        next=nullptr;
        prev=nullptr;
    }

};

class TextEditor{
    private:
           Node* head;
           Node* current;
    public:
          TextEditor(){
            head=nullptr;
            current=nullptr;
          }
          void type(string text){
            Node* newNode = new Node(text);
            if (head==nullptr){
                head=newNode;
                current=newNode;
            }else{
                Node* temp = current->next;
                while(temp != nullptr){

                    Node* toDelete = temp;
                    temp=temp->next;
                    delete toDelete;
                }
                current->next=newNode;
                newNode->prev = current;
                current = newNode;
            }
          }
          void undo(){
            if(current != nullptr && current->prev != nullptr){
                current = current->prev;
            }else{
                cout << "Nothing to undo!\n";
            }

          }
          void redo(){
            if(current != nullptr && current->next != nullptr){
                current = current->next;
            }else{
                cout<<"Nothing to redo!\n";
            }
          }
          void show(){
            if(current != nullptr){
                cout << "Current Text: "<<current->text<<endl;
            }else{
                cout<<"Editor is empty.\n";
            }
          }
};

int main(){
    TextEditor editor;
    int choice;
    string text;
    while(true){
        cout<<"\n1. Type\n2. Undo\n3. Redo\n4. Show\n5. Exit\nChoice: ";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:
                  cout << "Enter text: ";
                  getline(cin,text);
                  editor.type(text);
                  break;
            case 2:
                  editor.undo();
                  break;
            case 3:
                  editor.redo();
                  break;
            case 4:
                  editor.show();
                  break;
            case 5:
                  cout<<"\nExiting---"
                  return 0;
            default:
                   cout<<"Invalid choice!\n";

        }
    }
}
