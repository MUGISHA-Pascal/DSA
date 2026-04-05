#include <iostream>
#include <fstream>

using namespace std;

void merge(int arr[],int left, int mid,int right){
    int n1 = mid+1-left;
    int n2 = right-mid;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
         L[i]=arr[left+i];
    }

    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
    }
    
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[],int left , int right){
   if(left<right){
    int mid = (left+right)/2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);

    merge(arr,left,mid,right);
   }
}

// selection sort
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
    for(int j=i+1;j<n;j++){
    if(arr[j]<arr[minIndex]){
    minIndex=j;
    }
    }
    swap(arr[i],arr[minIndex]);
        }
}

//insertion sort
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

int main(){
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if(!infile){
        cout<<"Error opening input file!\n";
        return 1;
    }

    int arr[1000];
    int n=0;

    while(infile>>arr[n]){
        n++;
    }

    infile.close();

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        outfile<<arr[i]<<" ";
    }

    outfile.close();

    cout <<"Sorting complete! check output.txt\n";

    return 0;
}

