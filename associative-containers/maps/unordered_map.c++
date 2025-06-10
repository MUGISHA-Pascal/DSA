#include<iostream>
#include <unordered_map>
using namespace std;
int main() {
 unordered_map<int, string> um={{1,"Rwanda"},
                                 {2,"Coding"},
                                 {3,"Academy"},
                                 };
                                 for(auto i:um){
                                    cout<<i.first<<" : "<<i.second<<endl;
                                 }
    return 0;
}