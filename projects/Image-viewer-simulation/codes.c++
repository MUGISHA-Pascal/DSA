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

           void deleteCurrent(){
            if(current == nullptr){
                cout<<"No Images to delete.\n";
            }

            Node* temp = current;
            if(head == tail){
                head=tail=current=nullptr;
            }else if(current == head){
             head = head->next;
             head->prev=nullptr;
             current=head;
            }else if(current==tail){
                tail = tail->prev;
                tail->next=nullptr;
                current=tail;
            }else{
                current->prev->next=current->next;
                current->next->prev=current->prev;
                current=current->next;
            }
            delete temp;
            cout>>"Image deleted successfully.\n";
           }

           void showForward(){
            if(head==nullptr){
                cout<<"No images available.\n";
                return;
            }
            Node* temp=head;
            cout<<"Images (forward):\n";
            while(temp!=nullptr){
                cout<<temp->imageName<<" ";
                temp=temp->next;
            }
            cout<<endl;
           }

           void showBackward(){
            if(tail==nullptr){
                cout<<"No images available.\n";
                return;
            }
            Node* temp=tail;
            cout <<"Images (Backward):\n";
            while(temp!=nullptr){
                cout << temp->imageName <<" ";
                temp=temp->prev;
            }
            cout<<endl;
           }

           void showCurrent(){
            if(current != nullptr){
                cout<<"Current Image: "<<current->imageName<<endl;
            }else{
                cout<<"No current image.\n";
            }

           }

};

int main(){
    ImageViewer viewer;
    int choice;
    string name;
    do{
        cout<<"\n--- Image Viewer Menu ---\n";
        cout<<"1. Add Image\n2. View Next\n3. View Previous\n4. Delete Current Image\n5. Show Images Forward\n6. Show Images Backward\n7. Show Current Image\n0. Exit\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                    cout<<"Enter image name: ";
                    cin>>name;
                    viewer.addImage(name);
                    break;
            case 2:
                   viewer.viewNext();
                   break;
            case 3:
                   viewer.viewPrevious();
                   break;
            case 4:
                   viewer.deleteCurrent()
                    break;
            case 5:
                   viewer.showForward();
                   break;
            case 6:
                   viewer.showBackward();
                   break;
            case 7:
                   viewer.showCurrent();
                   break;
            case 0:
                   cout<<"Exiting...\n";
                   break;
            default:
                    cout<<"Invalid choice.\n";
                   
                   


        }
    }while(choice !=0);
    return 0;
}