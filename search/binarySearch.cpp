#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  
        } 
        else if (arr[mid] < target) {
            left = mid + 1; 
        } 
        else {
            right = mid - 1; 
        }
    }
    
    return -1;  
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6, 7, 8};  // Sorted array

    int target;
    cout << "Enter the number to search: ";
    
    while (!(cin >> target)) {
        cout << "Invalid input! Please enter a valid integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = binarySearch(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
