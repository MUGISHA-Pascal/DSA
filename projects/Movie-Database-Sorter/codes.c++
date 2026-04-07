#include <iostream>

using namespace std;

struct Movie{
    string title;
    int year;
    float rating;
};

int choice;

bool compare(Movie a,Movie b){
    if(choice == 1){
        return a.rating > b.rating;
    }else{
        return a.year>b.year;
    }
}

void merge(Movie arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    Movie L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    };

    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(compare(L[i],R[j])){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }

    while(i<n1)arr[k++]=L[i++];
    while(j<n2)arr[k++]=R[j++];
}

void mergeSort(Movie arr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void display(Movie arr[],int n){
    cout << "\nSorted Movie:\n";
    for(int i=0;i<n;i++){
        cout << arr[i].title << " | Year: "<<arr[i].year<<" | Rating: "<<arr[i].rating<<endl;
    }
}

void insertionSort(Movie arr[],int n){
    for(int i=1;i<n;i++){
        Movie key = arr[i];
        int j = i-1;
        while(j>=0 && compare(key,arr[j])){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void selectionSort(Movie arr[],int n){
 for(int i=0;i<n-1;i++){
    int best=i;
    for(int j=i+1;j<n;j++){
        if(compare(arr[j],arr[best])){
            best=j
        }
    }
    swap(arr[i],arr[best]);
 }
}

void bubbleSort(Movie arr[],int n){
    for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
    if(!compare(arr[j],arr[j+1])){
    swap(arr[j],arr[j+1]);
    }
    }
    }
}

int partition(Movie arr[],int low ,int high){
    Movie pivot = arr[high];
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

void quickSort(Movie arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high):
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;

    cout <<"Enter number of movies: ";
    cin>>n;
    cin.ignore();

    Movie movies[n];
    
    for(int i=0;i<n;i++){
        cout <<"\nEnter title: ";
        getline(cin,movies[i].title);

        cout <<"Enter year: ";
        cin>>movies[i].year;

        cout <<"Enter rating: ";
        cin>>movies[i].rating;

        cin.ignore();
    }

    cout <<"\nSort by:\n";
    cout <<"1. Rating\n2. Year\nChoice: ";
    cin>>choice;

    mergeSort(movies,0,n-1);

    display(movies,n);

    return 0;
}