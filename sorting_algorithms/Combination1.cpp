#include <iostream>
#include <vector>
using namespace std;
#int main(){
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
        }        
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
        exit(0);
        break;
    default:
    cout << "invalid input"<<endl;
        break;
    }
    }
    return 0;
}