#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick sort 
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//bubble sort
void bubbleSort(vector<int>& arr ,int n){
bool swapped;
for(int i=0;i<n-1;++i){
    swapped=false;
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        swapped=true;
        };
    }
    if(!swapped) break;
}
}

int main() {
    while (true) {
        int choice;
        cout << "Enter your choice : " << endl;
        cout << "1. Quick sort" << endl;
        cout << "2. Bubble sort" << endl;
        cout << "3. Merge sort" << endl;
        cout << "4. Selection sort" << endl;
        cout << "5. Insertion sort" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter the choice: ";
        cin >> choice;  
        
        switch (choice) {
            case 1: {
                int n;
                vector<int> array;
                cout << "Enter the size of the array: ";
                cin >> n;
                array.resize(n);
                cout << "Enter the " << n << " elements of the array (format: xxx): ";
                for (int i = 0; i < n; i++) {
                    cin >> array[i];
                }
                cout << "The original array: ";
                printArray(array);
                quickSort(array, 0, n - 1); 
                cout << "The sorted array using quick sort: ";
                printArray(array);
                break;
            }
            case 2:{
                cout<<"Enter the array size : ";
                int n;
                cin >> n;
                
                vector<int> array;
                array.resize(n);
                cout << "Enter the "  << n << " elements of the array (format: xxx) : ";
                for(int i=0 ;i < n ; i++ ){
                    cin >> array[i];
                }
                cout << endl;
                cout << "The entered array is : " << printArray(array);
                cout<<endl;
                bubbleSort(array,n);
                cout << "The sorted array is : " << printArray(array);
                cout<<endl;
                break;
            }
            case 3:
                // Merge sort implementation goes here
                break;
            case 4:
                // Selection sort implementation goes here
                break;
            case 5:
                // Insertion sort implementation goes here
                break;
            case 6:
                cout << "Exiting....." << endl;
                return 0;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
    return 0;
}
