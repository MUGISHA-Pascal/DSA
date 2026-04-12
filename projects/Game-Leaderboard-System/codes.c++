#include <iostream>
#include <string>

using namespace std;

struct Player{
    string username;
    int score;
    int level;
    int timePlayed; //in minutes
}

//swap method
void swap(Player &a,Player &b){
    Player temp=a;
    a=b;
    b=temp;
}

//comparator
bool compare(Player a,Player b,int choice){
       if(choice == 1) return a.score > b.score;        // highest score
    if(choice == 2) return a.level > b.level;        // highest level
    if(choice == 3) return a.timePlayed < b.timePlayed; // least time
    return false;
}

//insertion sort
void insertionSort(Player arr[],int n,int choice){
    for(int i=1;i<n;i++){
        Player key=arr[i];
        int j=i-1;
        while(j>=0 && !compare(arr[j],key,choice)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//quick sort partitoner
int partition(Player arr[],int low,int high,int choice){
    Player pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(compare(arr[j],pivot,choice)){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

//quick sort
void quickSort(Player arr[],int low,int high,int choice){
    if(low<high){
        int pi=partition(arr,low,high,choice);
        quickSort(arr,low,pi-1,choice);
        quickSort(arr,pi+1,high,choice);
    }
}

//selection sort
void selectionSort(Player arr[],int n,int choice){
   for(int i=0;i<n;i++){
    int minIndex = arr[i];
    for(int j=i+1;j<n;j++){
        if(compare(arr[j],arr[minIndex],choice)){
            minIndex=j;
        }
    }
    swap(arr[i],arr[minIndex]);
   }
}

//bubble sort
void bubbleSort(Player arr[],int n,int choice){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(!compare(arr[j],arr[j+1],choice)){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//merge sort helper
void merge(Player arr[],int left,int mid,int right,int choice){
    int n1=mid-left+1;
    int n2=right-mid;

    Player L[n1],R[n2];

    for(int i=0;i<n1;i++) L[i]=arr[left+i];
    for(int j=0;j<n2;j++) R[j]=arr[mid+j+1];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(compare(L[i],R[j],choice)){
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

//merge sort
void mergeSort(Player arr[],int left,int right,int choice){
    if(left<right){
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid,choice);
        mergeSort(arr,mid+1,right,choice);
        merge(arr,left,mid,right,choice);
    }
}

//display
void display(Player arr[], int n){
    cout << "\n--- LEADERBOARD ---\n";
    for(int i=0;i<n;i++){
        cout << i+1 << ". " << arr[i].username
             << " | Score: " << arr[i].score
             << " | Level: " << arr[i].level
             << " | Time: " << arr[i].timePlayed << " mins\n";
    }
}

//top 3
void topThree(Player arr[], int n){
    cout << "\n🏆 TOP 3 PLAYERS:\n";
    for(int i=0;i<3 && i<n;i++){
        cout << i+1 << ". " << arr[i].username << endl;
    }
}

//main
int main(){
    int n;
    cout << "Enter number of players: ";
    cin >> n;

    Player arr[n];

    for(int i=0;i<n;i++){
        cout << "\nPlayer " << i+1 << endl;
        cout << "Username: ";
        cin >> arr[i].username;

        cout << "Score: ";
        cin >> arr[i].score;

        cout << "Level: ";
        cin >> arr[i].level;

        cout << "Time played: ";
        cin >> arr[i].timePlayed;
    }

    int choice, algo;

    cout << "\nSort by:\n";
    cout << "1. Score\n2. Level\n3. Time Played\nChoice: ";
    cin >> choice;

    cout << "\nAlgorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\nChoice: ";
    cin >> algo;

    switch(algo){
        case 1: bubbleSort(arr,n,choice); break;
        case 2: selectionSort(arr,n,choice); break;
        case 3: insertionSort(arr,n,choice); break;
        case 4: mergeSort(arr,0,n-1,choice); break;
        case 5: quickSort(arr,0,n-1,choice); break;
        default: cout << "Invalid choice\n";
    }

    display(arr,n);
}