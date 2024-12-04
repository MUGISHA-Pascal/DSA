#include<iostream>
#include<vector>

void SelectionSort(std::vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n-1;++i){
        int minIndex=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        std::swap(arr[i],arr[minIndex]);
    }
}
void printArray(const std::vector<int>& arr){
    for(int num:arr){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> arr = {12,2,4,6,8,7};
    std::cout<<"Original array : ";
    printArray(arr);
    SelectionSort(arr);
    std::cout<<"Sorted array : ";
    printArray(arr);
    return 0;
}