#include<iostream>
using namespace std;

int CountOccurrence(int number,int digit){
if(number==0){
    return 0;
}
int smallAnswer = CountOccurrence(number/10,digit);
int lastDigit = number % 10;
if(lastDigit == digit ){
    return 1+ smallAnswer;
}else
{
return smallAnswer;    
}
}
int main(){
    cout<<CountOccurrence(113,1);
    return 0;
}