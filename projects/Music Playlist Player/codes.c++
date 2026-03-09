#include <iostream>

using namespace std;

struct Node{
    string song;
    Node* next;
}

class Playlist{
    private:
    Node* tail;
    public:
    Playlist(){
        tail=NULL;
    }

    void addSong(string name){
        Node* newNode = new Node();
        newNode->song = name;

        if(tail == NULL){
            tail=newNode;
            tail->next = tail;
        }else{
            newNode->next = tail->next;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void display(){
        if(tail == NULL){
            cout << "Playlist is empty\n";
            return;
        }
        Node* temp = tail->next;
        do{
            cout << temp->song << " -> ";
            temp=temp->next;
        }while(temp != tail->next);
        cout << "(Back to start)\n";
    }

    void playNext(Node*& current){
        if(current != NULL) current = curent->next;
        cout  << "Now playing: "<< current -> song << endl;
    }

    void deleteSong(string name){
        if(tail==NUll) return;

        Node* curr = tail->next;
        Node* prev = tail;

        do{
            if(curr->song == name){
                if(curr == tail && curr == tail->next){
                    tail=NULL;
                }
            }else{
                prev->next = curr->next;
                if(curr == tail) tail=prev;
            }
            delete curr;
            cout << "Song deleted\n";
            return;
        }while(curr != tail->next);
        cout <<"Song not found\n";

    }

    Node* getHead(){
        if(tail==NULL) return NULL;
        return tail->next;
    }
    
    int songNumber(){
        if(tail==NULL){return 0;}else{
                    int count=0;

        Node* temp=tail->next;
        do{
            count++;
            temp=temp->next;
        }while(temp!=tail->next);
        return count;
    }
}
};

int main(){
    Playlist p;

    p.addSong("Believer");
    p.addSong("Shape of You");
    p.addSong("Blinding Lights");
    p.addSong("Perfect");

    p.display();

    Node* current = p.getHead();

    cout <<"\nPlaying songs:\n";
    for(int i=0;i<p.songNumber();i++){
        p.playNext(current);
    }

    cout << "\nDeleting song:\n";
    p.deleteSong("Perfect");
    
    p.display();
}