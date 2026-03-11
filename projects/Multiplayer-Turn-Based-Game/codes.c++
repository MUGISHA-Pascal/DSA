#include <iostream>

using namespace std;

struct Player{
    string name;
    Player* next;
}

class TurnBasedGame {
    private:
    Player* tail;
    public:
    TurnBasedGame(){
        tail = nullptr;
    }

    void addPlayer(string name){
        Player* newPlayer = new Player();
        newPlayer->name=name;
        if(tail == nullptr){
            tail = newPlayer;
            tail->next = tail;
        }else{
         newPlayer->next=tail->next;
         tail->next=newPlayer;
         tail=newPlayer;   
        }
    }

    void displayPlayers(){
        if(!tail){
            cout << "No players in the game.\n";
            return;
        }

        Player* temp = tail->next;
        do{
            cout << temp->name << " -> ":
            temp = temp->next;
        }while(temp != tail->next);
        cout<<"(Back to start)\n"; 
    }

    void playGame(int turns){
        if(!tail)return;

        Player* current = tail->next;
        for(int i=1;i<=turns;i++){
            cout << "Turn "<<i<<": "<<current->name<<"'s move\n";
            current = current->next;
        }
    }

    void removePlayer(string name){
        if(!tail) return;

        Player* current = tail->next;
        Player* prev=tail;
        do{
            if(current->name == name){
                if(current == tail && current == tail->next){
                    delete current;
                    tail=nullptr;
                }else{
                    prev->next=current->next;
                    if(current==tail)tail=prev;
                    delete current;
                }
                cout<<name<<" has been removed from the game.\n";
                return;
            }
            prev=current;
            current=current->next;
        }while(current != tail->next);
        cout<<"Player not found.\n";
    }

    int CountPlayers(){
        if(tail->next==tail){
            return 1;
        }else if(tail == nullptr){
            return 0;
        }else{
                    int count = 0;
                    Player* temp = tail->next;
                    do{
                        temp=temp->next;
                        count++;
                    }while(temp!=tail->next);
                    return count;

        }
    }
};

int main(){
    TurnBasedGame game;
     game.addPlayer("Alice");
    game.addPlayer("Bob");
    game.addPlayer("Charlie");
    game.addPlayer("Diana");

    cout << "Players in the game:\n";
    game.displayPlayers();
    cout <<"\nSimulating 6 turns:\n";
    game.playGame(6);
    cout<<"\nEliminating Bob:\n";
    game.removePlayer("Bob");
    game.displayPlayers();
    cout<<"\nSimulating 5 more turns:\n";
    game.playGame(5);
    cout<<"\nTotal Players remaining: "<<game.CountPlayers()<<endl;

}