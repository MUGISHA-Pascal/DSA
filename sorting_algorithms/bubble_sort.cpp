#include<iostream>
#include<vector>
using namespace std;

void bubblesort(vector<int>& arr){
    int n = arr.size();
    bool swapped;
    for(int i=0;i<n-1;++i){
        swapped= false;
    for(int j=0;j<n-1;j++){
       if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
        swapped=true;
       }
    }
    if(!swapped) break;
    }    
}

void printArray(const vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
     }
     cout << endl;
}

int main(){
    vector<int> arr = {54,75,34,25,78,88};
    cout<<"unsorted array: ";
    printArray(arr);
    bubblesort(arr);
    cout<< "sorted array :";
    printArray(arr);
return 0;
}