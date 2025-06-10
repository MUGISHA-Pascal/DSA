#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;
class HashTable {
static const int HASH_GROUPS = 10;
vector<list<pair<int, string>>> table;
public:
    HashTable() {
        table.resize(HASH_GROUPS);
    }

    int hashFunction(int key) {
        return key % HASH_GROUPS;
    }

    void insert(int key, string value) {
        int hashvalue = hashFunction(key);
        auto& cell = table[hashvalue];
        for (auto& pair : cell) {
            if (pair.first == key) {
                pair.second = value; 
                return;
            }        
    }
        cell.emplace_back(key, value);
    }
    void remove(int key) {
        int hashvalue = hashFunction(key);
        auto& cell = table[hashvalue];
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it);
                return;
            }
        }
    
    }
    string search(int key) {
        int hashvalue = hashFunction(key);
        auto& cell = table[hashvalue];
        for (const auto& pair : cell) {
            if (pair.first == key) {
                return pair.second; 
            }}return "key Not Found";}
            void display() {
                for (int i = 0; i < HASH_GROUPS; ++i) {
                    cout << "Bucket " << i << ": ";
                    for (const auto& pair : table[i]) {
                        cout << "[" << pair.first << ": " << pair.second << "] ";
                    }
                    cout << endl;
                    }
    }
};
int main(){
    HashTable ht;
    ht.insert(905, "john");
    ht.insert(201, "jane");
    ht.insert(332, "tom");
    ht.insert(32, "ange");
    ht.insert(124, "mike");
    ht.insert(154, "micheal");
    ht.insert(127, "chael");
    ht.insert(107, "alice");
ht.display();
cout<<"Search for key 201 : "<< ht.search(201) << endl;
ht.remove(201);
cout<<"After removing key 201 : \n ";
ht.display();
    return 0;
}

