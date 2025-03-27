#include<iostream>
using namespace std;
void displayAdjacencyMatrix(int** matrix,int vertices){
    cout<<"Adjacency Matrix : "<<endl;
    for(int i=0;i < vertices;i++){
        for(int j=0 ; j<vertices;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int vertices,edges;
    cout << "Enter the number of vertices : ";
    cin >> vertices;
    int ** adjacencyMatrix = new int*[vertices];
    for(int i=0;i<vertices;i++){
        adjacencyMatrix[i]=new int[vertices];
        for(int j=0;j<vertices;j++){
            adjacencyMatrix[i][j]=0;
        }
    }
    cout<<"Enter the number of edges : ";
    cin>>edges;
    cout << "Enter the edges with weights (format : u v w):"<<endl;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adjacencyMatrix[u][v]=w;
    }
    displayAdjacencyMatrix(adjacencyMatrix,vertices);
    for(int i=0;i<vertices;i++){
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
    return 0;
}