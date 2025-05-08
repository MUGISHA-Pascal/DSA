#include<iostream>
#include<vector>
#include<stack>

using namespace std;
void dfsUsingStack(int startNode,const vector<vector<int>>& graph ){
    int n=graph.size();
    vector<bool> visited(n,false);
    stack<int> s;
    s.push(startNode);
    while(!s.empty()){
        int currentNode = s.top();
        s.pop();
        if(!visited[currentNode]){
            cout<<currentNode<<" ";
            visited[currentNode] = true;
        }
        for(int neighbor:graph[currentNode]){
            if(!visited[neighbor]){
                s.push(neighbor);
            }
        }
    }
}
int main(){
    vector<vector<int>> graph ={
        {1,2},
        {0,3,4},
        {0,4},
        {1,5},
        {1,2,5},
        {3,4}
    };
    int startNode=0;
    cout << "DFS traversal starting from Node "<< startNode<<" : ";
    dfsUsingStack(startNode,graph);
    return 0;
}