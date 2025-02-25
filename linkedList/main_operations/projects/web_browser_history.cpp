#include<iostream>
#include<string>

using namespace std;

struct Node{
    string url;
    Node* next;
    Node* prev;
    Node(string url):url(url),prev(nullptr),next(nullptr){}
};
class BrowserHistory{
    private:
        Node* current;
    public:
         BrowserHistory(){
            current=nullptr;
         }
         void visit(string url){
            Node* newPage=new Node(url);
            if(current){
                current->next=newPage;
                newPage->prev=current;
            }
            current=newPage;
            cout << "Visited : "<<url<<endl;
         }
         void back(){
            if(current && current->prev){
                current=current->prev;
                cout<<"Back to : "<<current->url << endl;
            }else{
                cout << "No previous page!" << endl;
            }
         }
         void forward(){
            if(current&&current->next){
                current=current->next;
                cout <<"forward to : "<<current->url<<endl;
            }else{
                cout << "No forward page!" <<endl;
            }
         }
         void currentPage(){
            if(current){
                cout<<"current page : "<< current->url<<endl;
            }else{
                cout<<"No page visited yet!"<<endl;
            }
         }
};
int main(){
    BrowserHistory browser;
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");
    browser.back();
    browser.back();
    browser.forward();
    browser.forward();
    browser.forward();
    browser.currentPage();
    return 0;
}