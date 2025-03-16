#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median(vector<int>& arr, vector<int>& arr2) {
    int n = arr.size();
    int n2 = arr2.size();
    vector<int> arr3;
    
    for (int i = 0; i < n; i++) {
        arr3.push_back(arr[i]);
    }
    for (int i = 0; i < n2; i++) {
        arr3.push_back(arr2[i]);
    }
    
    sort(arr3.begin(), arr3.end());
    
    int n3 = arr3.size();
    int midpoint = n3 / 2;
    return arr3[midpoint]; 
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {6, 7, 8, 9, 10};
    cout << "The median of two sorted arrays is: " << median(arr, arr2) << endl;
    return 0;
}
