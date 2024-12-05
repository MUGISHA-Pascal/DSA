#include<iostream>
using namespace std;
int sumOfArray(int a[],int n){
if(n==0){
    return 0;
}
return a[0]+sumOfArray(a+1,n-1);
}
int main(){
    int arr[]={1,2,67,8};
    cout << "the sum of array is : "<<sumOfArray(arr,4); 
    return 0;
}