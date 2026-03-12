#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

struct Light{
    string color;
    int duration;
    Light* next;
}

class TrafficLightSystem{
    private:
    Light* tail;
    public:
    TrafficLightSystem(){
        tail=nullptr;
    }

    void addLight(string color,int duration){
        Light* newLight = new Light();
        newLight->color= color;
        newLight->duration = duration;

        if(!tail){
            tail=newLight;
            tail->next=tail;
        }else{
            newLight->next=tail->next;
            tail->next=newLight;
            tail=newLight;
        }
    }

    void displayLights(){
        if(!tail){
            cout << "No lights in the system.\n";
            return; 
        }
        Light* temp = tail->nex;
        do{
            cout << temp->color << " ("<<temp->duration<<"s) -> ";
            temp=temp->next;
        }while(temp!=tail->next);
        cout<<"(Back to start)\n";
    }

    void run(int cycles){
        if(!tail) return;

        Light* current = tail->next;
        for(int i=0;i<cycles;i++){
            cout << "Light: "<<current->color << " | Duration: "<<current->duration<<" seconds\n";
            this_thread::sleep_for(chrono::seconds(current->duration));
        }
    }
};

int main(){
    TrafficLightSystem tls;
     tls.addLight("Red", 5);
    tls.addLight("Green", 3);
    tls.addLight("Yellow", 2);

    cout<<"Traffic Light System:\n";
    tls.displayLights();

    cout<<"\nRunning traffic lights for 10 cycles:\n";
    tls.run(10);
}