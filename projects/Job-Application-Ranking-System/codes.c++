#include <iostream>
#include <string>
using namespace std;

struct Applicant{
    string name;
    int experience;
    int testScore;
    int interviewScore;
}

void Swap(Applicant a,Applicant b){
    Applicant temp=a;
    a=b;
    b=temp;
}

// ---------- OVERALL SCORE ----------
float overallScore(Applicant a){
    return a.testScore * 0.5 + a.interviewScore * 0.4 + a.experience * 10;
}

// ---------- COMPARATOR ----------
bool compare(Applicant a, Applicant b, int choice){
    if(choice == 1) return a.testScore > b.testScore;
    if(choice == 2) return a.experience > b.experience;
    if(choice == 3) return a.interviewScore > b.interviewScore;
    if(choice == 4) return overallScore(a) > overallScore(b);
    return false;
}

void bubbleSort(Applicant arr[],int n,int choice){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(!compare(arr[j],arr[j+1],choice)){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionSort(Applicant arr[],int n,int choice){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(compare(arr[j],arr[minIndex])){
                minIndex=j;
            }
        }    
        swap(arr[i],arr[minIndex]);
    }
}

void insertionSort(Applicant arr[],int n,int choice){
    for(int i=0;i<n;i++){
        Applicant key=arr[i];
        j=i-1;

        while(j>=0 && !compare(arr[j],key,choice)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// ---------- MAIN ----------
int main(){
    int n;
    cout << "Enter number of applicants: ";
    cin >> n;

    Applicant arr[n];

    for(int i=0;i<n;i++){
        cout << "\nApplicant " << i+1 << endl;
        cout << "Name: ";
        cin >> arr[i].name;

        cout << "Experience (years): ";
        cin >> arr[i].experience;

        cout << "Test score: ";
        cin >> arr[i].testScore;

        cout << "Interview score: ";
        cin >> arr[i].interviewScore;
    }

    int choice, algo;

    cout << "\nSort by:\n";
    cout << "1. Test Score\n";
    cout << "2. Experience\n";
    cout << "3. Interview Score\n";
    cout << "4. Overall Ranking\nChoice: ";
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

