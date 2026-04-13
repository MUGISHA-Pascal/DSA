#include <iostream>
#include <string>
using namespace std;

struct Patient{
    string name;
    int severity;
    int arrivalTime;
};

void swap(Patient &a,Patient &b){
    Patient temp=a;
    a=b;
    b=temp;
}

//comparato
bool compare(Patient a, Patient b, int choice){
    if(choice == 1) return a.severity > b.severity;   // highest severity first
    if(choice == 2) return a.age > b.age;             // oldest first
    if(choice == 3) return a.arrivalTime < b.arrivalTime; // earliest first
    return false;
}

//bubble sort
void bubbleSort(Patient arr[],int n,int choice){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(!compare(arr[j],arr[j+1])){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//selection sort
void selectionSort(Patient arr[],int n,int choice){
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(compare(arr[j],arr[minIndex])){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

//merge sort helper
void merge(Patient arr[],int left,int mid,int right,int choice){
    int n1=mid-left+1;
    int n2=right-mid;

    Patient L[n1],R[n2];

    for(int i=0;i<n1;i++)L[i]=arr[left+i];
    for(int j=0;j<n2;j++)R[j]=arr[mid+1+j];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(compare(L[i],R[j])){
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1)arr[k++]=L[i++];
    while(j<n2)arr[k++]=R[j++];
}

//merge sort
void mergSort(Patient arr[],int left,int right,int choice){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid,choice);
        mergeSort(arr,mid+1,right,choice);
        merge(arr,left,mid,right);
    }
}

//insertion sort
void insertionSort(Patient arr[],int n,int choice){
    for(int i=1;i<n;i++){
     Patient key=arr[i];
     int j=i-1;
     while(j>=0 && !compare(arr[j],key,choice)){
        arr[j+1]=arr[j];
        j--;
     }
     arr[j+1]=key;
    }
}

//quick sort helper
int partition(Patient arr[],int low,int high,int choice){
    Patient pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(compare(arr[j],pivot,choice)){
            i++;
            swap(arr[i],arr[j])
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

//quick sort
void quickSort(Patient arr[],int low,int high,int choice){
    for(low<high){
        int pi = partition(arr,low,high,choice);
        quickSort(arr,low,pi-1,choice);
        quickSort(arr,pi+1,high,choice);
    }
}

int main(){
    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    Patient arr[n];

    for(int i=0;i<n;i++){
        cout << "\nPatient " << i+1 << endl;
        cout << "Name: ";
        cin >> arr[i].name;

        cout << "Age: ";
        cin >> arr[i].age;

        cout << "Severity (1-10): ";
        cin >> arr[i].severity;

        cout << "Arrival time: ";
        cin >> arr[i].arrivalTime;
    }

    int choice, algo;

    cout << "\nSort by:\n";
    cout << "1. Emergency (Severity)\n";
    cout << "2. Age\n";
    cout << "3. Arrival Time\nChoice: ";
    cin >> choice;

    cout << "\nAlgorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\nChoice: ";
    cin >> algo;

    switch(algo){
        case 1: bubbleSort(arr,n,choice); break;
        case 2: selectionSort(arr,n,choice); break;
        case 3: insertionSort(arr,n,choice); break;
        case 4: mergeSort(arr,0,n-1,choice); break;
        case 5: quickSort(arr,0,n-1,choice); break;
        default: cout << "Invalid choice\n";
    }
        display(arr,n);
}