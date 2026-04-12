#include <iostream>
using namespace std;

struct Product{
    string name;
    float price;
    float rating;    
};

int choice;
// 1 = price (low → high)
// 2 = price (high → low)
// 3 = rating (high → low)

bool compare(Product a,Product b){
    if(choice == 1)return a.price < b.price;
    else if(choice == 2)
    return a.price>b.price;
    else return a.rating > b.rating;
}

//merge sort helper
void merge(Product arr[],int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right-mid;

    Product L[n1],R[n2];

    for(int i=0; i<n1 ;i++){
        L[i]=arr[left+i];
    }

    for(int j=0; j<n2 ; j++){
        R[i] =arr[mid+1+j];
    }

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(compare(L[i],R[j])){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }

    while(i<n1)arr[k++]=L[i++];
    while(j<n2)arr[k++]=R[j++];
}

//merge sort
void mergeSort(Product arr[],int left ,int right){
    if(left<right){
        int min = (left + right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

void display(Product arr[],int n){
    cout <<"\nSorted Products:\n";
    for(int i=0; i<n;i++){
        cout<<arr[i].name<<" | Price: "<<arr[i].price<<" | Rating: "<<arr[i].rating<<endl;
    }
}

//quick sort partitioner
int partition(Product arr[],int low,int high){
    Product pivot = arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(compare(arr[j],pivot)){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

//quick sort
void quickSort(Product arr[],int low ,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,low+1,high);
    }
}

//selection sort
void selectionSort(Product arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(compare(arr[j],arr[minIndex])){
                minIndex=j;
            }
        }
        if(minIndex != i){
            swap(arr[i],arr[minIndex]);
        }
    }
}

// insertion sort
void insertionSort(Product arr[],int n){
    for(int i=1;i<n;i++){
        Product key = arr[i];
        int j=i-1;
        while(j>=0 && !compare(arr[j],key)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//bubble sort
void bubbleSort(Product arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(!compare(arr[j],arr[j+1])){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
        int method;
        cout<<"Enter the sorting method number (1 >> quick sort,2 >> merge sort): ";
        cin >> method;
        int n;
        cout<<"Enter number of products: ";
        cin >>n;

        cin.ignore();

        Product products[n];

        for(int i=0;i<n;i++){
            cout<<"\nEnter product name: ";
            getline(cin,products[i].name);

            cout<<"Enter price: ";
            cin>>products[i].price;

            cout<<"Enter rating: ";
            cin>>products[i].rating;

            cin.ignore();
        }

        cout << "\nSort Options:\n";
        cout << "1. Price (Low → High)\n";
        cout << "2. Price (High → Low)\n";
        cout << "3. Rating (High → Low)\n";
        cout << "Enter choice: ";
        cin >> choice;
    switch(method){
        case 1:
        quickSort(products,0,n-1);
        display(products,n);
        break;
        case 2:
        mergeSort(products, 0, n - 1);

        display(products, n);
    break;
    default:
    mergeSort(products, 0, n - 1);

        display(products, n);
    break;
    }
        
        return 0;
}