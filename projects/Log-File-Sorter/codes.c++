#include <iostream>
using namespace std;

struct Log{
    string time;
    string message;
}

int toMinutes(string t){
    int hour = stoi(t.substr(0,2));
    int minute  = stoi(t.substr(3,2));
    return hour * 60 + minute;
}

void merge(Log arr[],int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right-mid;

    Log L[n1],R[n2];

    for(int i=0;i<n1;i++)L[i]=arr[left+i];
    for(int j=0;j<n2;j++)R[j]=arr[mid+1+j];

    int i=0,j=0,k=left;

    while(i<n1&&j<n2){
        if(toMinutes(L[i].time<toMinutes)){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(Log arr[],int left , int right){
    if(left<right){
        int mid = (left+right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

int main(){
    int n;
    cout<<"Enter number of logs: ";
    cin>>n;

    cin.ignore();

    Log logs[n];
    for(int i=0;i<n;i++){
        cout<<"\n Enter log(HH:MM Message): ";
        getline(cin,logs[i].message);

        logs[i].time=log[i].message.substr(0,5);
    }

    mergeSort(logs,0,n-1);
    cout<<"\nSorted Logs:\n";
    for(int i=0;i<n;i++){
        cout<<logs[i].message<<endl;
    }
    return 0;
}