#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits> 
using namespace std;

struct Edge {
    int dest;
    int weight;
};

class Graph {
private:
    int V;
    vector<vector<Edge>> adj; 

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        src--; 
        dest--; 

        Edge edge1 = {dest, weight};
        adj[src].push_back(edge1);

        Edge edge2 = {src, weight};
        adj[dest].push_back(edge2);
    }

    void primMST() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int src = 0;

        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        pq.push(make_pair(0, src));
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) {
                continue;
            }

            inMST[u] = true;

            for (const Edge& edge : adj[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        cout << "Edge \tWeight\n";
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << "\t" << key[i] << endl;
            totalWeight += key[i];
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter the edges in the format (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    g.primMST();

    return 0;
}
