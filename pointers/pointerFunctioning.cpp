#include<iostream>
using namespace std;

void addElement(int *&arr,int &size,int newElement);
void displayElement(int *arr,int size);
void removeElement(int *&arr,int &size,int index);

int main(){
    int *arr = nullptr;
    int size = 0;
    while(true){
        cout<< "\n Dynamic array management system \n";
        cout<<"1. Add Element \n";
        cout<<"2. Display Element \n";
        cout << "3. Remove Element \n";
        cout  <<"4. exit\n";
        cout <<"Enter the choice : ";
        int choice;
        cin >> choice;
  if (choice == 1){
    int newElement;
    cout << "Enter the element to add : ";
    cin >> newElement;
    addElement(arr,size,newElement);
  }else if(choice==2){
     displayElement(arr,size);
  }else if(choice==3){
    int index;
    cout << "Enter the index of the element to remove : ";
    cin>>index;
    removeElement(arr,size,index);
  }else if(choice == 4){
break;
  }else{
    cout<<"invalid input , try again";
  }
    }
    delete[] arr;
    return 0;
}

void addElement(int *&arr,int &size,int newElement){
    int *newArr = new int[size+1];
    for(int i=0;i<size;i++){
        newArr[i]=arr[i];
    }
    newArr[size]=newElement;
    delete[] arr;
    arr=newArr;
    size++;
    cout<<"Element added successfully";
}
void displayElement(int *arr,int size){
    if(size==0){
        cout << "Array is empty \n";
        return;
    }
    cout<<"Array elements : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    }

    void removeElement(int *&arr,int &size,int index){
        if(index<0||index >= size){
            cout << "invalid index";
            return;
        }
        int *newArr= new int[size-1];
     for(int i=0,j=0; i<size;i++){
    if(i!=index){
newArr[j++]=arr[i];
    }
     }
     delete[] arr;
     arr=newArr;
     size--;
     cout<<"Element removed successfully";
    }