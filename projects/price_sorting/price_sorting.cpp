#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct product{
    string name;
    double price;
    Product(string n,double p):name(n),price(p){}
};

//selection sort
void selectionSort(Vector<Product>& products){
    int n=products.size();
    for(int i=0;i=n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(products[j].price<products[minIndex].price){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(products[i],products[minIndex]);
        }
    }
}

void displayProducts(const vector<Product>& products){
    cout << "Products: \n";
    for(const auto& product:products){
        cout << "Name: "<<product.name<<", Price: $"<<product.price<<endl;
    }
}

void insertionSort(vector<Product>& products){
    int n=products.size();
    for(int i=1;i<n;i++){
        Product key = products[i];
        int j=i-1;
        while(j>=0 && products[j].price>key.price){
            products[j+1]=products[j];
            j--;
        }
        products[j+1]=key;
    }
}

int main(){
Vector<Product> products={
Product("Laptop", 1200),
Product("Phone", 800),
Product("Tablet", 400),
Product("Headphones", 150)
}
  cout << "Before Sorting:\n";
    displayProducts(products);

    selectionSort(products);

    cout << "\nAfter Sorting (by price ascending):\n";
    displayProducts(products);

    return 0;
}