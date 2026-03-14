#include <iostream>

using namespace std;

struct Tab{
    string title;
    Tab* next;
}

class Browser{
    private:
    Tab* tail;
    Tab* current;
    public:
    Browser(){
        tail=NULL;
        current=NULL;
    }
    void openTab(string name){
        Tab* newTab = new Tab();
        newTab->title = name;
        if(tail==NULL){
            tail=newTab;
            tail->next=tail;
            current=tail;
        }else{
            newTab->next=tail->next;
            tail->next=newTab;
            tail=newTab;
        }
        cout << "Opened tab:"<<name<<endl;
    }
 
    void showTabs(){
        if(tail==NULL){
            cout <<"No tabs open\n";
            return;
        }

        Tab* temp=tail->next;
        cout << "\nTail:\n";
        do{
            if(temp==current){
                cout<<"[ACTIVE] ";
                cout << temp->title<<" -> ";
                temp=temp->next;
            }
        }while(temp!=tail->next);
        cout <<"(Back to start)\n";
    }

    void nextTab(){
        if(current == NULL) return;
        current=current->next;
        cout<<"Switched to: "<<current->title<<endl;
    }

    void closeCurrentTab(){
        if(tail==NULL)return;

        Tab* temp=tail->next;
        Tab* prev = tail;
        do{
            if(temp==current){
                if(temp==tail && temp == tail->next){
                    tail=NULL;
                    current=NULL;
                }else{
                    prev->next = temp->next;
                    if(temp==tail)tail=prev;
                    current=temp->next;
                }
                cout <<"Closed tab: "<<temp->title<<endl;
                delete temp;
                return;
            }
            prev=temp;
            temp=temp->next;
        }while(temp!=tail->next);
    }
};

int main(){
    Browser browser;
     browser.openTab("Google");
    browser.openTab("YouTube");
    browser.openTab("GitHub");
    browser.openTab("ChatGPT");
    browser.showTabs();
    cout<<"\nSwitching tabs:\n";
       browser.nextTab();
    browser.nextTab();

    browser.showTabs();

    cout << "\nClosing current tab\n";
    browser.closeCurrentTab();

    browser.showTabs();
    return 0; 
}