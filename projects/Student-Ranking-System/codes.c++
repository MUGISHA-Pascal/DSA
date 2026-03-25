#include <iostream>
using namespace std;

struct Student{
    string name;
    int score;
};

int partition(Student arr[],int low ,int high){
    int pivot = arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j].score>pivot){
            i++;
            swap(arr[i],arr[j]);            
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(Student arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);

    }
}

void merge(Student arr[],int left,int mid , int right){
    int n1 = mid - left + 1;
    int n2 =right - mid;
    
    Student L[n1],R[n2];

    for (int i=0;i<n1;i++)L[i] = arr[left+i];
    for (int j=0;j<n2;j++)R[j]= arr[mid+1+j];

    int i=0 , j=0,k=left;

    while (i<n1&&j<n2){
        if(L[i].score>R[j].score){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(Student arr[],int left,int right){
    if(left<right){
        int mid = (left+right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left ,mid,right);
    }
}

void display(Student arr[],int n){
    cout <<"\nStudent Rankings:\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<". "<<arr[i].name<<" - "<<arr[i].score<<endl;
    }
}

int main(){
    int n,method;
    cout<<"Enter method number for sorting (1 >> quick sort , 2 >> Merge Sort) :";
    cin>>method;

cin.ignore();
    cout<<"Enter number of students: ";
    cin>>n;
    

    Student students[n];

    for(int i=0;i<n;i++){
        cout <<"\nEnter name: ";
        cin>>student[i].name;

        cout<<"Enter score: ";
        cin>>students[i].score;
    }
switch(method){
    case 1:
    quickSort(students,0,n-1);
    display(students,n);
    break;
    case 2:

    mergeSort(students,0,n-1);
    display(students,n);
    break;
    default:
         mergeSort(students,0,n-1);
    display(students,n);
    break;
}
return 0;
}