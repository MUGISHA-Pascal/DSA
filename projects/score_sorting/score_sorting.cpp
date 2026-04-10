#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Student{
    string  name;
    int score;
    Student(string n,int s):name(n),score(s){}
};
void displayStudents(const vector<Student>& students){
    cout<<"Students:\n";
    for(const auto& student:students){
        cout << "Name: "<< student.name<<" , Score: "<<student.score<<endl; 
    }
}
void bubbleSort(vector<Student>& students){
    int n = students.size();
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(students[j].score > students[j+1].score){
                swap(students[j],students[j+1]);
            }
        }
    }
}
void selectionSort(vector<Student>& students){
    int n = students.size();
    for(int i=0;i<n-1;++i){
        int minIndex=i;
        for(int j=i+1;j<n;++j){
            if(students[j].score < students[minIndex].score){
                minIndex=j;
            }
        }
        swap(students[i],students[minIndex]);
    }
}
void insertionSort(vector<Student>& students){
    int n=students.size();
    for(int i=1;i<n;++i){
        Student key=students[i];
        int j= i-1;
        while(j>=0 && students[j].score > key.score){
            students[j+1]=students[j];
            --j;
        }
        students[j+1]=key;
    }
}

int partition(vector<Student>& students ,int low,int high){
    Student pivot = students[high];
    int i=low-1;

    for(int j=low;j<high;++j){
        if(students[j].score < pivot.score){
            i++;
            swap(students[i],students[j]);
        }
    }
    swap(students[i+1],students[high]);
    return i+1;
}

void quickSort(vector<Student>& students , int low,int high){
    if(low<high){
        int pi=partition(students,low,high);
        quickSort(students,low,pi-1);
        quickSort(students,pi+1,high);
    }
}

//merge sort helper
void merge(vector<Student>& students,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    Student L[n1],R[n2];

    for(int i=0;i<n1;i++)L[i]=students[left+i];
    for(int j=0;j<n2;j++)R[j]=students[mid+j+1];

    int i=0,j=0,k=0;

    while(i<n1 && j<n2){
        if(L[i].score <= R[j].score){
            students[k]=students[i++];
            }else{
            students[k]=students[j++];
        }
        k++;
    }

    while(i<n1){
        students[k++]=L[i++];
    }

    while(j<n2){
        students[k++]=R[j++];
    }
}

//merge sort
void mergeSort(vector<Student>& students,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;

        mergeSort(students,left,mid);
        mergeSort(students,mid+1,right);

        merge(students,left,mid,right);
    }
}

int main(){
    vector<Student> students = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"David", 90},
        {"Eve", 88}
    };

    int choice;
    cout << "Choose a sorting algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Quick Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\nBefore Sorting:\n";
    displayStudents(students);

    // Sort based on user choice
    switch (choice) {
        case 1:
            bubbleSort(students);
            cout << "\nAfter Sorting (Bubble Sort):\n";
            break;
        case 2:
            selectionSort(students);
            cout << "\nAfter Sorting (Selection Sort):\n";
            break;
        case 3:
            insertionSort(students);
            cout << "\nAfter Sorting (Insertion Sort):\n";
            break;
        case 4:
               quickSort(students,0,students.size()-1);
               cout << "\nAfter Sorting (Quick Sort):\n";
               break;
        default:
            cout << "Invalid choice. Exiting...\n";
            return 0;
    }

    displayStudents(students);
    return 0;
}