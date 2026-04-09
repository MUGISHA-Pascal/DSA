#include <iostream>
#include <string>

using namespace std;

struct Player{
    string name;
    int score;
}

//bubble sort
void bubbleSort(Player players[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(players[j].score < players[j+1].score){ // descending
                swap(players[j],players[j+1]);
            }
        }
    }
}

//insertion sort
void insertionSort(Player players[],int n){
    for(int i=0;i<n;i++){
        Player key=players[i];
        int j=i-1;
        while(j>=0 && players[j].score < key.score){
            players[j+1] = players[j];
            j--;
        }
        players[j+1]=key;
    }
}

//selection sort
void selectionSort(Player players[],int n){
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(players[j]<players[minIndex]){
                minIndex=j;
            }
        }
        swap(players[i],players[minIndex]);
    }
}

//merge sort helper
void merge(Player players[],int left,int mid ,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    Player L[n1],R[n2];

    for(int i=0;i<n1;i++)L[i]=players[left+i];
    for(int j=0;j<n2;j++)R[j]=players[mid+1+j];

    int i,j,k=0;

    while(i<n1 && j<n2){
        if(L[i].score>=R[j].score){
            players[k++]=L[i++];
        }else{
            players[k++]=R[j++];
        }
    }

    while(i<n1){
        players[k++]=L[i++];
    }
    while(j<n2){
        players[k++]=R[j++];
    }

    delete[] L;
    delete[] R;
}

//merge sort
void mergeSort(Player players[],int left ,int right){
    if(left<right){
        int mid = left+(right-left)/2
        mergeSort(players,left,mid);
        mergeSort(players,mid+1,right);
        merge(players,left,mid,right);
    }
}

//quick sort helper
int partition(Player players[],int low,int high){
    int pivot = players[high].score;
    int i=low-1;

    for(int j=low;j<high;j++){
        if(players[j].score>=pivot){
            i++;
            swap(players[i],players[j]);
        }
    }
    swap(players[i+1],players[high]);
    return i+1;
}

//quick sort
void quickSort(Player players[],int low,int high){
    if(low<high){
        int pi=partition(players,low,high);
        quickSort(players,low,pi-1);
        quickSort(players,pi+1,high);
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