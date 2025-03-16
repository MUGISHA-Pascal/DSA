#include<iostream>
using namespace std;

int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n * factorial(n-1);
}
int main(){
    int num;
    cout << "Enter the number to calculate its factorial : "<< endl;
    cin >> num ;
    if(num <0 ){
        cout << "factorial of negative number is not defined "<< endl;
    } else{
        cout << "factorial of " << num << " is "<< factorial(num) <<endl;
    }
    return 0;
}