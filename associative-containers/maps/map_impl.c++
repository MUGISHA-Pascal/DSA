#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string,int> myStock;
    myStock["apples"] = 100;
    myStock["bananas"] = 200;
    myStock["cherry"] = 300;
    int qty= myStock["bananas"];
    cout << "Bananas in stock: " << qty << endl;
    myStock["bananas"] = 250;
    qty = myStock["bananas"]; 
    cout << "Updated bananas in stock: " << qty << endl;
    myStock.erase("cherry");
  cout<<"key-value pairs in myStock :"<<endl;
    for( const auto& pair : myStock){
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}