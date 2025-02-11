#include<iostream>
using namespace std;

int main(){
int arr[3]={10,100,200};
int i;
int sum;
sum = *arr;
for(i=0;i<3;i++){
    sum += *(arr+i);
}
cout<<"the sum is "<<sum<<endl;
    return 0;
}