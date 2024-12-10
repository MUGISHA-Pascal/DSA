#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 void printArray(const vector<int>& arr){
        for (int num : arr){
            cout << num  << " ";
        }
    cout << endl;
    };
    //quick sort
            int partition(vector<int>& arr , int low, int high){
                int pivot = arr[high];
                int i = low-1;
                for(int j=low;j<high;j++){
                    if(arr[j]<=pivot){
                        i++;
                        swap(arr[i],arr[j]);
                    }
                }
                swap(arr[i+1],arr[high]);
                return i+1;
        };
        void quickSort(vector<int>& arr , int low , int high){
            if(low<high){
                int pi = partition(arr,low,high);
                quickSort(arr,low,pi-1);
                quickSort(arr,pi+1,high);
            }
        };
int main(){
   
    while(true){
        int choice;
    cout<<"Enter your choice : "<<endl;
    cout<<"1. quick sort"<<endl;
    cout<<"2. bubble sort"<<endl;
    cout<<"3. merge sort"<<endl;
    cout<<"4. selection sort"<<endl;
    cout<<"5. insertion sort"<<endl;
    cout<<"6. exit"<<endl;
    cout<<"Enter the choice : "<<choice<<endl;
    switch (choice)
    {
        case 1:

     int n;
     vector<int> array;
     cout << "Enter the size of the array : ";
     cin >> n ;
     array.resize(n);
     cout<<"Enter the "<< n <<" elements of the array (format:xxx) : ";
     for(int i=0;i<n;i++){
        cin>>array[i];
     } 
     cout<<endl;
     cout<<"The original array : " << printArray(array);
     quickSort(array,0,n);
     cout<<"The sorted array using quick sort : " << printArray(array);
     cout<<endl;

        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        cout<<"Exiting....."<<endl;
        return 0;
        break;
    default:
    cout << "invalid input"<<endl;
        break;
    };
    };
    return 0;
}