#include<iostream>
using namespace std;
bool isSorted(int a[],int n){
    if(n==0||n==1){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    return isSorted(a+1,n-1);
}
int main(){
    int arr[]={2,3};
    cout<<"if array is sorted : "<<isSorted(arr,2);
return 0;
}