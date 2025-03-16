#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val),next(nullptr){}
};
class LinkedList{
    private:
        Node* head;
        void splitList(Node* source,Node** front,Node** back){
            Node* slow=source;
            Node* fast=source->next;
            while(fast && fast->next){
                slow=slow->next;
                fast=fast->next->next;
            }
            *front = source;
            *back=slow->next;
            slow->next=nullptr;
        }
        Node* mergeSortedLists(Node* a,Node* b){
          if(!a) return b;
          if(!b) return a;
          Node* result=nullptr;
          if(a->data<=b->data){
            result=a;
            result->next=mergeSortedLists(a->next,b);
          }else{
            result=b;
            result->next=mergeSortedLists(a,b->next);
          }
          return result;
        }
        Node* mergeSort(Node* head){
            if(!head || !head->next) return head;
            Node *front=nullptr;
            Node* back=nullptr;
            splitList(head,&front,&back);
            front=mergeSort(front);
            back=mergeSort(back);
            return mergeSortedLists(front,back);
        }
    public:
        LinkedList():head(nullptr){}
        void insert(int val){
            Node* newNode=new Node(val);
            if(!head){
                head=newNode;
            return;
            }
            Node* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        void sort(){
            head=mergeSort(head);
        }
        void display(){
            Node* temp=head;
            while(temp){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};
int main(){
    LinkedList list;
    list.insert(4);
    list.insert(2);
    list.insert(8);
    list.insert(5);
    list.insert(1);
     cout<<"Original List : ";
     list.display();
     list.sort();
     cout<<"Sorted List : ";
     list.display();
     return 0;
}