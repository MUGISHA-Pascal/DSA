#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        DisjointSet ds(V);

        int mstWeight = 0;
        vector<Edge> mstEdges;

        for (Edge &e : edges) {
            int u = e.src;
            int v = e.dest;

            if (ds.find(u) != ds.find(v)) {
                ds.unionSets(u, v);
                mstEdges.push_back(e);
                mstWeight += e.weight;
            }
        }

        cout << "Following are the edges in the constructed MST:\n";
        for (Edge &e : mstEdges) {
            cout << e.src + 1 << " -- " << e.dest + 1 << " == " << e.weight << endl; 
        }
        cout << "Total weight of MST: " << mstWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    if (V <= 0 || E <= 0) {
        cout << "Number of vertices and edges must be positive integers!" << endl;
        return 1;
    }

    Graph g(V);

    cout << "Enter the edges in the format (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        u -= 1;
        v -= 1;

        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid edge input: vertex out of bounds." << endl;
            i--;  
            continue;
        }

        g.addEdge(u, v, w);
    }

    g.kruskalMST();

    return 0;
}
