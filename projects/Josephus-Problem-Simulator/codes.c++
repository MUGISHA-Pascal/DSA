#include <iostream>

using namespace std;

struct Node{
    int id;
    Node* next;
};

class Josephus{
    private:
    Node* tail;
    public:
    Josephus(){
        tail=NULL;
    }

    void createCircle(int n){
        for(int i=1;i<=n;i++){
            Node* newNode = new Node();
            newNode->id=i;

            if(tail==NULL){
                tail=newNode;
                tail->next=tail;
            }else{
                newNode->next=tail->next;
                tail->next=newNode;
                tail=newNode;
            }
        }
    }

    void display(){
        if(!tail) return;
        Node* temp = tail->next;

        do{
            cout<<temp->id<<" -> ";
            temp= temp->next;
        }while(temp!=tail->next);
        cout<<"(back to start)\n";
    }

    void solve(int k){
        Node* current = tail->next;
        Node* prev = tail;

        cout<<"\Elimination order:\n";
        while(current->next!=current){
            for(int i=1;i<k;i++){
                prev = current;
                current=current->next;
            }
            cout << "Person "<<current->id<<" eliminated\n";

            prev->next=current->next;

            if(current == tail)tail=prev;

            delete current;
            current = prev->next;
        }

        cout <<"\Survivor: Person "<<current->id<<endl;
    }
};


 int main(){
    Josephus game;
    int n,k;

    cout <<"Enter number of people: ";
    cin>>n;
    cout <<"Enter step count (k): ";
    cin>>k;

    game.createCircle(n);

    cout << "\nPeople in circle:\n";
    game.display();

    game.solve(k);
    return 0
 }

 