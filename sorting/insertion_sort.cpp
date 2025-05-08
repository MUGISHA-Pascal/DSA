#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void printArray(int arr[],int n){
for(int i=0;i<n;i++){
    std::cout << arr[i] << " ";
}
cout << endl;
}
int main(){

int arr[]={12,11,24,68,90,94};
int n=sizeof(arr)/sizeof(arr[0]);
 cout << "original array :";
 printArray(arr,n);
 cout << "sorted array :";
 insertionSort(arr,n);
 printArray(arr,n);
    return 0;
}