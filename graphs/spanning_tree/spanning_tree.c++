#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

// DFS to build a spanning tree
void dfs(int node, int parent) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            cout << node << " - " << neighbor << endl;  // Edge in spanning tree
            dfs(neighbor, node);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    adj.resize(vertices + 1);
    visited.resize(vertices + 1, false);

    cout << "Enter edges (format: node1 node2):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    cout << "\nSpanning Tree Edges:\n";
    dfs(1, -1);  
    return 0;
}
