#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr,int left ,int mid , int right){
    int n1 = mid-left + 1;
    int n2 = right - mid;
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);
    for(int i=0;i<n1;i++){
        leftArray[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        rightArray[j]=arr[mid + 1 +j];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(leftArray[i] <= rightArray[j]){
            arr[k] = leftArray[i];
            i++;
        }else{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
       while(i<n1){
        arr[k]=leftArray[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr,int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid + 1,right );
        merge(arr,left,mid,right);
    }
}

int main(){
    vector<int> arr={43,46,7,87,9,89};
    cout<<"Original array : ";
    for(int num :arr){ 
        cout<<num<<" ";    }
        cout<<endl;
        mergeSort(arr,0,arr.size()-1);
        cout<<"Sorted Array : ";
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<endl;
    return 0;
}