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

    cout << "Enter the edges in the format (u v weight):\n";
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

    int source;
    cout << "Enter the source vertex (0-indexed): ";
    cin >> source;

    if (source < 0 || source >= V) {
        cout << "Invalid source vertex!" << endl;
        return 1;
    }

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
