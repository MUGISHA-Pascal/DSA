#include<iostream>
#include<string>
using namespace std;

struct Page{
    string url;
    Page* next;
}

class BrowserHistory{
    Page* head;
    public:
          BrowserHistory(){head=nullptr}
          
          void visitPage(const string& url){
            Page* newPage = new Page{url , nullptr};
            if(!head){
                head = newPage;
                cout<<"Visited : "<<url<<endl;
                return;
            }
            Page* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newPage;
            cout<<"Visited : "<<url<<endl;
          }

          void showHistory(){
            if(!head){
                cout>>"History is empty.\n";
                return;
            }
            Page* temp = head;
            int pos =1;
            cout<<"\n Browser History : \n";
            while(temp){
                cout<<pos++ <<". "<<temp->url<<endl;
                temp=temp->next;
            }
          }

          void goBack(){
            if(!head){
                cout<<"No pages to go back to. \n";
                return;
            }
            if(!head->next){
                cout << "Going Back from : "<< head->url<<endl;
                delete head;
                head=nullptr;
                return;
            }
            Page* temp=head;
            while(temp->next->next) temp=temp->next;
            cout << "Going back from : "<<temp->next->url<<endl;
            delete temp->next;
            temp->next=nullptr;
          }

          void searchPage(const string& url){
            Page* temp=head;
            int pos = 1;
            while(temp){
                if(temp->url == url){
                    cout <<"Found "<<url<<"at position "<< pos <<endl;
                    return;
                }
                temp=temp->next;
                pos++
            }
            cout<<urk<<" not found in history.\n";
          }

          void clearHistory(){

            Page* temp = head;
            while(temp){
                Page* toDelete=temp;
                temp=temp->next;
                delete toDelete;
            }
            head = nullptr;
            cout<<"History cleared. \n";
          }

          void reverseHistory(){
            Page *prev = nullptr, *current = head, *next=nullptr;
            while(current){
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            head=prev;
            cout <<"History reversed. \n";
          }

};

int main(){
    BrowserHistory browser;
    int choice;
    string url;
    while(true){
        cout <<"\n ---Browser History menu---\n";
        cout << "1. Visit Page\n2. Show History\n3. Go Back\n4. Search Page\n5. Clear History\n6. Reverse History\n7. Exit\n";
        cout << "Enter choice: ";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:
                  cout<<"Enter URL to visit: ";
                  getline(cin,url);
                  browser.visitPage(url);
                  break;
            case 2:
                  browser.showHistory();
                  break;
            case 3:
                  browser.goBack();
                  break;
            case 4:
                  cout<<"Enter URL to search: ";
                  getline(cin,url);
                  browser.searchPage(url);
                  break;
            case 5:
                  browser.clearHistory();
                  break;
            case 6: 
                  browser.reverseHistory();
                  break;
            case 7:
                  cout<<"Exiting browser simulator.\n";
                  return 0;
            default:
                   cout<<"Invalid choice. Try again.\n";
                   
        } 
    }
}