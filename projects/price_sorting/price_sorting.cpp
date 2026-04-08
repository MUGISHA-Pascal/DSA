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
void selectionSort(vector<Product>& products){
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
//insertion sort
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

//bubble sort
void bubbleSort(vector<Product>& products){
    int n=products.size();
    for(int i=0;i<n-1;i++){
     for(int j=0;j<n-i-1;j++){
        if(products[j].price>products[j+1].price){
            swap(arr[j],arr[j+1]);
        }
     }
    }
}

//merge sort
void merge(vector<Product>& products,int left,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    vector<Product> L(n1),R(n2);
    for(int i=0;i<n1;i++)L[i]=products[left+i];
    for(int j=0;j<n2;j++)R[j]=products[mid+1+j];

    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i].price<=R[j].price){
            products[k]=L[i];
            i++;
        }else{
            products[k]=R[j];
            j++
        }
        k++;
    }
    while(i<n1)products[k++]=L[i++];
    while(j<n2)products[k++]=R[j++];
}

//merge sort
void mergeSort(vector<Product>& products,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2
        mergeSort(products,left,mid);
        mergeSort(products,mid+1,right);
        merge(products,left,mid,right);
    }
}

//quick sort
int partition(vector<Product>& products,int low,int high){
    double pivot=products[high].price;
    int i=low-1
    for(int j=low;j<high;j++){
        if(products[j].price<=pivot){
            i++;
            swap(products[i],products[j]);
        }
    }
    swap(products[i+1],products[high]);
    return i+1;
}

//quick sort
void quickSort(vector<Product>& products,int low,int high){
    if(low<high){
        int pi=partition(products,low,high);
        quickSort(products,low,partition-1);
        quickSort(products,pi+1,high);
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