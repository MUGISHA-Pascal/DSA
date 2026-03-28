#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout <<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    bubbleSort(arr,n);
    cout <<"Sorted array: ";
    for(int i=0;i<n;i++) cout << arr[i]<<" ";

}