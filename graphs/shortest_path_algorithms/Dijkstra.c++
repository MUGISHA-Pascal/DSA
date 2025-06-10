#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

class Graph {
private:
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int vertices) {
        this->V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex index!" << endl;
            return;
        }
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dijkstra(int src) {
        if (src < 0 || src >= V) {
            cout << "Invalid source vertex!" << endl;
            return {};
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, numeric_limits<int>::max());
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist;
    }
};

int main() {
    int V = 9;  // Number of vertices
    int E = 14;  // Number of edges

    Graph g(V);

    // Manually add edges (use 0-based indexing)
    g.addEdge(1, 0,4);
    g.addEdge(0,7,8);
    g.addEdge(1,7,11);
    g.addEdge(1,2,8);
    g.addEdge(7,8,7);
    g.addEdge(7,6,1);
    g.addEdge(2,8,2);
    g.addEdge(8,6,6);
    g.addEdge(6,5,2);
    g.addEdge(5,2,4);
    g.addEdge(5,3,14);
    g.addEdge(3,2,7);
    g.addEdge(5,4,10);
    g.addEdge(3,4,6);
    g.addEdge(3,4,9);


    int source = 1; // Source vertex (0-indexed)

    vector<int> distances = g.dijkstra(source);

    if (distances.empty()) {
        return 1;
    }

    cout << "Shortest distances from source vertex " << source << ":" << endl;
    for (int i = 0; i < distances.size(); i++) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
