#include <iostream>
#include <string>

using namespace std;

struct Post{
    string author;
    string timestamp; // "YYYY-MM-DD HH:MM"
    int likes;
    string content;
};

long timestampToNumber(string t){
    string numbstr= t.substr(0,4)+ t.substr(5,2) + t.substr(8,2) + t.substr(11,2) + t.substr(14,2);
    return stol(numbstr);
}

int sortChoice; 
// 1 = latest timestamp first
// 2 = most liked first

bool compare(Post a,Post b){
    if(sortChoice == 1)return timestampToNumber(a.timestamp) > timestampToNumber(b.timestamp);
    else 
    return a.likes > b.likes;
}

void merge(Post arr[],int left , int mid ,int right){
    int n1 = mid-left+1;
    int n2 = right - mid;

    Post L[n1],R[n2];

    for(int i=0;i<n1;i++) L[i] = arr[left + i];
    for(int j=0;j<n2;j++) R[j] = arr[mid+1+j];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(compare(L[i],R[j])) arr[k++]=L[i++];
        else arr[k++] = R[j++];
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(Post arr[],int left,int right){


    if(left < right){
        int mid = (left+right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

void displayFeed(Post arr[],int n){
    cout <<"\nSocial Media Feed:\n";

    for(int i=0;i<n;i++){
        cout <<"["<<arr[i].timestamp<<"]"<<arr[i].author<<" ("<<arr[i].likes<<" likes): "<<arr[i].content <<endl;
    }
}

int partition(Post arr[],int low,int high){
    Post pivot = arr[high];

    int i=low-1;

    for(int j=low;j<high;j++){
        if(compare(arr[j],pivot)){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(Post arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    cout<<"Enter number of posts: ";
    cin>>n;
    cin.ignore();
    
    Post posts[n];

    for(int i=0;i<n;i++){
        cout << "Author: ";
        getline(cin,posts[i].author);

        cout<<"Timestamp (YYYY-MM-DD HH-MM): ";
        getline(cin,posts[i].timestamp);

        cout<<"Likes: ";
        cin>>posts[i].likes;
        cin.ignore();

        cout<<"Content: ";
        getline(cin,posts[i].content); 
    }

    cout<<"\nSort Options:\n";
    cout<<"1. Latest first\n";
    cout<<"2. Most liked first\n";
    cout<<"Choice: ";
    cin>>sortChoice;

    int algoChoice;
    cout<<"\nChoose sorting algorithm:\n";
    cout<<"1. Merge Sort\n";
    cout<<"2. Quick Sort\n";
    cin>>algoChoice;

    if(algoChoice == 1)mergeSort(posts,0,n-1);else quickSort(posts,0,n-1);
    displayFeed(posts,n);
    return 0;
}