#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int terms;
    cout << "enter the number of terms for the fibonacci :" ;
    cin >> terms;
    if (terms <=0){
        std::cout << "please enter a positive number ." << std::endl;
    }else{
        cout << "fibonacci for terms : "<< terms << endl;
        for(int i=0; i<terms;i++ ){
            cout << fibonacci(i) << " ";
        }
        std::cout << std::endl;
    }
return 0;
}