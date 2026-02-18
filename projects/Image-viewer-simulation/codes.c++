#include <iostream>
using namespace std;

struct Node{
    string imageName;
    Node* prev;
    Node* next;
    
    Node(string name){
        imageName=name;
        prev=nullptr;
        next=nullptr;
    }
    
};

class ImageViewer{
    private:
            Node* head;
            Node* tail;
            Node* current;
    public:
           ImageViewer(){
            head=tail=current=nullptr;
           }

           void addImage(string name){
            Node* newNode = new Node(name);

            if(head == nullptr){
                head=tail=current=newNode;
            }else{
                tail->next=newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            cout  << "Image added successfully.\n";
           }

           void viewNext(){
            if(current == nullptr){
                cout << "No images available.\n";
                return;
            }
            if(current->next != nullptr){
                current=current->next;
                cout << "Viewing: "<< current->imageName << endl;
            }else{
                cout << "you are at the last image.\n";
            }
           }

           void viewPrevious(){
            if(current == nullptr){
                cout << "No images available.\n";
                return;
            }
            if(current->prev != nullptr){
                current = current->prev;
                cout <<"Viewing: "<<current->imageName<<endl;
            }else{
                cout << "You are at the first image.\n"; 
            }
           }
}