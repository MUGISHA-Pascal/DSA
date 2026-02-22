#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void printArray(const vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

void bubbleSortVisual(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        cout <<"\n Pass "<<i+1<<":"<<endl;
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
            printArray(arr);
            this_thread::sleep_for(chrono::milliseconds(300))
        }
        cout << "After pass "<<i+1<<": ";
        printArray(arr);
    }
}

int main(){
    srand(time(0))
    int n;
    cout << "Enter the number of elements (5-20 recommended): ";
    cin>>n;
    vector<int> arr(n);
    cout << "Randomly generated array: ";
    for(int i=0;i<n;i++){
        arr[i] = rand()% 100;
        cout << arr[i]<<" ";
    }
    cout<<endl;
    cout << "\nStarting bubble sort animation..."<<endl;
    bubbleSortVisual(arr);
    cout<<"\nFinal sorted array: ";
    printArray(arr);
    return 0;
}