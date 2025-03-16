#include<iostream>
#include<string>
using namespace std;

void ReverseString (string &str,int start ,int end){
    if(start >= end){
        return;
    }
    swap(str[start],str[end]);
    ReverseString(str,start+1,end-1);
}
int main(){
    string str;
    cout << "Enter the string to reverse : ";
    getline(cin,str);
    ReverseString(str,0,str.length()-1);
    cout << "Reversed string : "<< str << endl;
    return 0;
}