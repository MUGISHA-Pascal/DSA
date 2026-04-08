#include <iostream>
using namespace std;

struct Log{
    string time;
    string message;
};

int toMinutes(string t){
    int hour = stoi(t.substr(0,2));
    int minute  = stoi(t.substr(3,2));
    return hour * 60 + minute;
}

void merge(Log arr[],int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right-mid;

    Log L[n1],R[n2];

    for(int i=0;i<n1;i++)L[i]=arr[left+i];
    for(int j=0;j<n2;j++)R[j]=arr[mid+1+j];

    int i=0,j=0,k=left;

    while(i<n1&&j<n2){
        if(toMinutes(L[i].time<toMinutes)){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(Log arr[],int left , int right){
    if(left<right){
        int mid = (left+right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

int partition(Log arr[],int low,int high){

    int pivot = toMinutes(arr[high].time);
    int i=low-1;

    for(int j=low;j<high;j++){
        if(toMinutes(arr[j].time) <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(Log arr[],int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
        
    }
}

void selectionSort(Log arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(toMinutes(arr[j].time) < toMinutes(arr[minIndex].time)){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex];)
    }
}
 
// insertion sort
void insertionSort(Log arr[],int n){
    for(int i=1;i<n;i++){
        Log key=arr[i];
        int j=i-1;
        while(j>=0 && toMinutes(arr[j].time)>toMinutes(key.time)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//bubble sort
void bubbleSort(Log arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(toMinutes(arr[j].time)>toMinutes(arr[j+1].time)){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter number of logs: ";
    cin>>n;

    cin.ignore();

    Log logs[n];
    for(int i=0;i<n;i++){
        cout<<"\n Enter log(HH:MM Message): ";
        getline(cin,logs[i].message);

        logs[i].time=log[i].message.substr(0,5);
    }

    mergeSort(logs,0,n-1);
    cout<<"\nSorted Logs:\n";
    for(int i=0;i<n;i++){
        cout<<logs[i].message<<endl;
    }
    return 0;
}