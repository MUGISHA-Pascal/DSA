 #include<iostream>
 #include<vector>
using namespace std;
 int partition(std::vector<int>& arr , int low , int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            std::swap(arr[i],arr[j]);
        }
    } 
    std::swap(arr[i+1],arr[high]);
    return i+1;
 }

 void quickSort(std::vector<int>& arr , int low , int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
 }

 void printArray(const std::vector<int>& arr){
    for(int num:arr){
        std::cout<<num<<" ";
    }
    std::cout <<std::endl;
 }

 int main(){
    std::vector<int> arr = {13,23,5,68,98,5,3};
    int num = arr.size();
    std::cout<<"Original array : ";
    printArray(arr);
    std::cout<<"Sorted array : ";
    quickSort(arr,0,num-1);
    printArray(arr);
        return 0;  
 }