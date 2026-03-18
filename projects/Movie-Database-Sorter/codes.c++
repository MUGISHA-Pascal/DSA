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