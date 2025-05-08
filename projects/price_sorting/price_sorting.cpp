#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct product{
    string name;
    double price;
    Product(string n,double p):name(n),price(p){}
};

void displayProducts(const vector<Product>& products){
    cout << "Products: \n";
    for(const auto& product:products){
        cout << "Name: "<<product.name<<", Price: $"<<product.price<<endl;
    }
}
