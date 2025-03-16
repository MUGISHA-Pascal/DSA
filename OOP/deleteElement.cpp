#include<iostream>
using namespace std;

void DeleteArrayElement (int arr[],int &n,int index){
    if(index<0 || index >= n){
        cout << "Invalid index "<<endl;
        return;
    }
    for(int i=index;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}
int main(){
    int arr[]={12,34,44,45,64};
    int n=5;
    int index=2;
    cout<<"Original array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    DeleteArrayElement(arr,n,index);
    cout<<"New Array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}