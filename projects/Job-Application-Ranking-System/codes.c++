#include <iostream>
#include <string>
using namespace std;

struct Applicant {
    string name;
    int experience;     // years
    int testScore;
    int interviewScore;
};

// ---------- SWAP ----------
void swap(Applicant &a, Applicant &b){
    Applicant temp = a;
    a = b;
    b = temp;
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

// ---------- BUBBLE SORT ----------
void bubbleSort(Applicant arr[], int n, int choice){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(!compare(arr[j], arr[j+1], choice)){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

// ---------- SELECTION SORT ----------
void selectionSort(Applicant arr[], int n, int choice){
    for(int i=0;i<n-1;i++){
        int best = i;
        for(int j=i+1;j<n;j++){
            if(compare(arr[j], arr[best], choice)){
                best = j;
            }
        }
        swap(arr[i],arr[best]);
    }
}

// ---------- INSERTION SORT ----------
void insertionSort(Applicant arr[], int n, int choice){
    for(int i=1;i<n;i++){
        Applicant key = arr[i];
        int j=i-1;

        while(j>=0 && !compare(arr[j], key, choice)){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// ---------- MERGE SORT ----------
void merge(Applicant arr[], int l, int m, int r, int choice){
    int n1 = m-l+1;
    int n2 = r-m;

    Applicant L[n1], R[n2];

    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int j=0;j<n2;j++) R[j] = arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(compare(L[i], R[j], choice)){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(Applicant arr[], int l, int r, int choice){
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(arr,l,m,choice);
        mergeSort(arr,m+1,r,choice);
        merge(arr,l,m,r,choice);
    }
}

// ---------- QUICK SORT ----------
int partition(Applicant arr[], int low, int high, int choice){
    Applicant pivot = arr[high];
    int i = low - 1;

    for(int j=low;j<high;j++){
        if(compare(arr[j], pivot, choice)){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(Applicant arr[], int low, int high, int choice){
    if(low < high){
        int pi = partition(arr,low,high,choice);
        quickSort(arr,low,pi-1,choice);
        quickSort(arr,pi+1,high,choice);
    }
}

// ---------- DISPLAY ----------
void display(Applicant arr[], int n){
    cout << "\n--- APPLICANT RANKING ---\n";
    for(int i=0;i<n;i++){
        cout << i+1 << ". " << arr[i].name
             << " | Exp: " << arr[i].experience
             << " | Test: " << arr[i].testScore
             << " | Interview: " << arr[i].interviewScore
             << " | Overall: " << overallScore(arr[i]) << endl;
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