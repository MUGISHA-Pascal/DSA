#include<iostream>
#include<string>
using namespace std;
struct Customer{
    int ticketNumber;
    string name;
    Customer* next;
};
class CustomerQueue{
 private:
     Customer* front;
     Customer* rear;
     int ticketcounter;
public:
      CustomerQueue(){
        front = rear = nullptr;
        ticketcounter = 1;
      }
      void enqueue(const string& name){
        Customer* newCustomer = new Customer;
        newCustomer->name= name;
        newCustomer->ticketNumber = ticketcounter++;
        newCustomer->next = nullptr;
        if(rear == nullptr){
            front=rear=newCustomer;
        }else{
            rear->next = newCustomer;
            rear = newCustomer;
        }
        cout<<"Customer "<<name<<" added with ticket #"<<newCustomer->ticketNumber<<".\n";
      }
      void dequeue(){
        if(front == nullptr){
            cout<<"No customers in the queue.\n";
            return;
        }
        Customer* temp = front;
        cout<<"Serving Customer "<<temp->name<<" (Ticket #"<<temp->ticketNumber<<").\n";
        front= front->next;
        if(front==rear){
            rear=nullptr;
        }
        delete temp;
    }
    void displayQueue(){
        if(front==nullptr){
            cout<<"The queue is empty.\n";
            return;
        }
        Customer* temp=front;
        cout<<"Current queue:\n";
        while(temp!=nullptr){
            cout<<"Ticket #"<<temp->ticketNumber<<" - "<<temp->name<<"\n";
            temp=temp->next;
        }
    }
    ~CustomerQueue (){
      while(front!=nullptr){
        Customer* temp = front;
        front = front->next;
        delete temp;
      }
    }
};
int main() {
    CustomerQueue queue;
    int choice;
    string name;

    do {
        cout << "\n--- Customer Service System ---\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Show Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                queue.enqueue(name);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.displayQueue();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}