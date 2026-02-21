#include <iostream>
#include <string>

using namespace std;

struct Player{
    string name;
    int score;
}

void bubbleSort(Player players[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(players[j].score < players[j+1].score){ // descending
                swap(players[j],players[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cout << "Number of playes: ";
    cin>>n;
    Player players[n];
    for(int i=0; i<n;i++){
        cout << "Player "<<i+1<<" name: ";
        cin >> players[i].name;
        cout >> "Score: ";
        cin>>players[i].score;
    }
    bubbleSort(players,n);
    cout << "\nLeaderboard:\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<". "<<players[i].name<<" - "<<players[i].score<<"\n";
    }
    return 0;
}