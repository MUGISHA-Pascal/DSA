// not finished
#include <iostream>
using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;
};

void addEdge(Node* adjacencyList[], int u, int v, int w) {
    Node* newNode = new Node{v, w, adjacencyList[u]};
    adjacencyList[u] = newNode;
}

void displayAdjacencyList(Node* adjacencyList[], int vertices) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        Node* temp = adjacencyList[i];
        while (temp) {
            cout << "(" << temp->vertex << ", " << temp->weight << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void freeMemory(Node* adjacencyList[], int vertices) {
    for (int i = 0; i < vertices; i++) {
        Node* temp = adjacencyList[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Node* adjacencyList[vertices];
    for (int i = 0; i < vertices; i++) {
        adjacencyList[i] = nullptr;
    }

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges with weights (format: u v w):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(adjacencyList, u, v, w);
    }

    displayAdjacencyList(adjacencyList, vertices);

    freeMemory(adjacencyList, vertices);

    return 0;
}